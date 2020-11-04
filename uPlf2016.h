#define NUM_PROFESSOR 24   //total de professores
#define NUM_SALA 10	      //total de salas disponiveis
#define NUM_TIPO_SALA 2    //total de tipos de salas
#define NUM_HORARIO 14     //horarios disponiveis da sala
#define NUM_TURMA 14      //quantidade de turmas
#define NUM_OFERTA 80      //quantidade de ofertas de disciplinas
#define NUM_BLOQ 13        //quantidade de ofertas de bloqueadas
#define NUM_DISCIPLINA 72  //quantidade de disciplinas
#define NUM_DIA 5 		   //total de dias da semana
#define NUM_MAX_CANDIDATOS 700 //e o valor de combinacoes possiveis de dias X horas X salas
#define ALFA 0.5          //valor alfa utilizado para fazer o corte na lista de candidatos
#define MAX_SOLUCAO 5      // numero de solucoes que podem ser aramzenadas no vetSol
#define TAXA_RESFRIAMENTO 0.975 //Fator de reducao da temperatura
#define TEMP_INICIAL 1000
#define TEMP_FINAL 0.01
#define NUM_MAX_ITERACOES 500
#define TEMPO_LIMITE  90 //tempo limite de execucao do metodo SA
#define PROB_MOVIMENTO 0.5  //probabilidade de swap 
#define MAX_TEMPO 500.0 //Tempo maximo para execucao do GRASP
#define M_E 2.71828182845904523536   // e
#define ARQ_OFERTAS "arquivos2016/ofertas.txt"
#define ARQ_DISCP "arquivos2016/disciplinas.txt"
#define ARQ_TURMAS "arquivos2016/turmas.txt"
#define ARQ_LOCAIS "arquivos2016/locais.txt"
#define ARQ_TIPOS "arquivos2016/tipos.txt"
#define ARQ_HORARIOS "arquivos2016/horarios.txt"
#define ARQ_PROFS "arquivos2016/professores.txt"
#define ARQ_HORSALA "arquivos2016/horarioSala/"



typedef struct tPosicao {
	int sala;
	int dia;
	int horaIni;
}Posicao;

typedef struct tProblema {
	int quantSalas;
	int quantHorarios;
	int quantProfessores;
	int quantTurmas;
	int quantOfertas;
	int quantDisciplinas;
	int quantTipoSalas;

}Problema;

typedef struct tSala {
	int id;
	char predio[100];
	int idTipoSala;
	int numSala;
	int capacidade;
}Sala;

typedef struct tTipoSala {
	int id;
	char nome[70];
}TipoSala;

typedef struct tHorario {
	int id;
	char inicio[6];
	char fim[6];
	int duracao;
}Horario;

typedef struct tProfessor {
	int id;
	char nome[100];
}Professor;

typedef struct tTurma {
	int id;
	char nome[100];
	int periodo;
	int turnoPreferencial; // 0 - matutino, 1- vespertino, 2 - noturno
}Turma;

typedef struct tOferta {
	int id;
	int idDisciplina;
	int numTurmas; // numero de turmas que a oferta esta disponivel
	int* turmas;	// turmas que a oferta esta disponivel como obrigatoria (curso e periodo, podendo ser por exemplo: CC 1� e EQ 1�)
	int numVagas;  	//vagas ofertadas
	int turno; //1- diuno , 2-noturno
	int idProfessor;
	int idTipoSala;
	int ch; 		//carga horaria da oferta: 1,2,3,4 ou 5h
}Oferta;

typedef struct tDisciplina {
	int id;
	char codigo[10];
	char nome[100];
	int nivel; // 0- normal, 1- dificil
}Disciplina;


typedef struct tGradeHorario {
	int gradeHorario[NUM_HORARIO][NUM_DIA];
}GradeHorario;

typedef struct tSolucao
{
	GradeHorario gradeSala[NUM_SALA];
	GradeHorario gradeProfessor[NUM_PROFESSOR];
	GradeHorario gradeTurma[NUM_TURMA];
	long fo;
	double alfalfa;
}Solucao;

typedef struct tListaOfertas {
	int idOferta;
	int numVagasOferta;
	int idTipoSalaOferta;
	int chOferta;
	int turnoOferta;
}ListaOfertas;

typedef struct tListaCandidatos {
	int idOferta;
	long fo;
	int sala;
	int dia;
	int hora;
	int ch;
}ListaCandidatos;

//****************************************************************************

//************************** Metodos *****************************************

void grasp();
void criarSolucaoInicial(Solucao* sl);
void criarSolucao(Solucao* sl);
bool verificaEspaco(Solucao* sol, int tam, int dia, int horario, int sala);
void ordenaNumVagas(ListaOfertas* listaOfertas);
void carregarHorarioBloqueadoSala(Solucao* sol);
void exportaSala(Solucao* ss, int posR);
void exportaTurma(Solucao* ss, int posR);
void exportaProfessor(Solucao* ss, int posR);
void clonarSolucao(Solucao* original, Solucao* clone);
void simulatedAnnealing(Solucao* s);
void geraSwap(Solucao* solucaoVizinho);
void geraMove(Solucao* solucaoVizinho);
void gera_lectureMove(Solucao* solucaoVizinho);
void printMelhorSolucao();
void printSolucaoInicial();
void imprimirPenalizacoes();
void exportarSolucaoInicial();
void exportarMelhorSolucao();
void exportaParametros(Solucao* sol, double melhorTempo);
// ------------ Calculo da FO
void calcFO(Solucao* sol);
void gerarTabelasPeT(Solucao* sol);
long confAula3h(Solucao* sol);
long confProfessor(Solucao* sol);
long confAula(Solucao* sol);
void iniciaProfessorTurma(Solucao* sl);
void iniciarVariaveis();
//****************************************************************************

//***************** Entrada de dados *****************************************
void lerArquivos();
void lerProfessores();
void lerHorarios();
void lerSalas();
void lerTipoSalas();
void lerTurmas();
void lerOfertas();
void lerDisciplinas();

