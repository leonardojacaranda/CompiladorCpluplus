#include <stdlib.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <string.h>
 #include <iostream>
using namespace std;

 #define TOKEN int
 #define TOKEN_INTEIRO 1
 #define TOKEN_ID 2
 #define TOKEN_FIM_ARQUIVO 3
  #define TOKEN_REAL 4
#define TOKEN_LITERAL 5
#define TOKEN_COMENTARIO 6
#define TOKEN_ESPACO 7
#define TOKEN_OPR 8
#define TOKEN_RCB 9
#define TOKEN_OPM 10
#define TOKEN_AB_P 11
#define TOKEN_FC_P 12
#define TOKEN_PT_V 13
#define TOKEN_ERRO_CADEIA_NAO_ACEITA 14
 #define TOKEN_ERRO 0

 #define COLUNA int
 #define D 0
 #define L 1
 #define ADICAO 2
 #define SUBTRACAO 3
 #define MULTIPLICACAO 4
 #define DIVISAO 5
 #define MENOR 6
 #define MAIOR 7
 #define PONTO 8
 #define PONTO_E_VIRG 9
 #define ASPAS 10
 #define ABRE_COLC 11
 #define FECHA_COLC 12
 #define IGUAL 13
 #define FIM_ARQUIVO 14
 #define E 15
 #define BARRA_N_ESPACO 16
 #define ABRE_PARENT 17
 #define FECHA_PARENT 18
 #define QQ 19
 #define UND 20
#define m 21

typedef int Apontador;

typedef struct Dados{
    int token;
    string lexema;
    string tipo;
}dados;

typedef struct Lista{
    Dados dados[m];
    Apontador inicio;
    Apontador fim;
}lista;

void criarLista(Lista &lista){
    lista.inicio = 0;
    lista.fim = 0;
}

void inserirNaLista(Dados aux, Lista &lista){
    int i;
    int repetido=0;
    if(lista.fim > m){
        cout << "Lista cheia\n";
    }else{
        /*for(i = lista.inicio; i<lista.fim; i++){
                if(aux.lexema == lista.dados[i].lexema){
                        repetido = repetido + 1;
                }
        }
        if(repetido==0){*/
            lista.dados[lista.fim] = aux;
            lista.fim++;
        //}
    }
}



//imprime da lista o token, o lexema e o tipo
void imprimirNaTela(Lista &lista){
    int i;
    for(i = lista.inicio; i<lista.fim; i++){
          if((lista.dados[i].token == TOKEN_INTEIRO)||(lista.dados[i].token == TOKEN_REAL))
            cout <<"TOKEN:  Numero  ";

          if(lista.dados[i].token == TOKEN_ID)
            cout <<"TOKEN:  Id  ";

          if(lista.dados[i].token == TOKEN_LITERAL)
            cout <<"TOKEN:  Literal  ";

          if(lista.dados[i].token == TOKEN_ESPACO)
                cout <<"TOKEN:  Espaco  ";

          if(lista.dados[i].token == TOKEN_COMENTARIO)
                cout <<"TOKEN:  Comentario  ";

          if(lista.dados[i].token == TOKEN_OPR)
            cout <<"TOKEN: OPR  ";

          if(lista.dados[i].token == TOKEN_RCB)
            cout <<"TOKEN: RCB  ";

          if(lista.dados[i].token == TOKEN_OPM)
            cout <<"TOKEN: OPM  ";

          if(lista.dados[i].token == TOKEN_AB_P)
            cout <<"TOKEN:  AB_P  ";

          if(lista.dados[i].token== TOKEN_FC_P)
            cout <<"TOKEN:  FC_P  ";

          if(lista.dados[i].token == TOKEN_PT_V)
            cout <<"TOKEN:  PT_V  ";

          if(lista.dados[i].token == TOKEN_ERRO_CADEIA_NAO_ACEITA)
            cout <<"TOKEN: Erro --> Cadeia não aceita";

          cout <<"LEXEMA:" <<lista.dados[i].lexema << "\n";

    }
}

//inserir palavras chaves no main antes do lexico
//Consultar	se	ele	existe	na	tabela	de	símbolos	e	se	é	palavrachave
void busca_dados(Dados aux, string chave, Lista &lista) {
    int i= 0;
    string  palavras_chave[12] = {"inicio", "varinicio", "varfim", "escreva", "leia", "se", "entao", "fimse", "fim", "inteiro", "real", "literal"};

    //Percorrendo todas as posições

       //Caso	o	id	não	esteja	na	tabela	de	símbolos,	criar	 uma	nova	entrada,	armazená-lo	lá	e	retornar	seus	dados	(token,	lexema	e	tipo)
           // inserirNaLista(aux, lista);


        //Se encontrou na tabela de símbolos
        for(i=0;i<12;i++){
            if (aux.lexema.compare(palavras_chave[i]) == 0) {

                    cout << "\nTOKEN: PALAVRA-CHAVE  ";
                    cout << "LEXEMA: " << aux.lexema << "\n";
                    return ;
                  }
        }

                  imprimirNaTela(lista);


    }

/*IMPLEMENTAÇÃO DA TABELA DE TRANSIÇÃO DE ESTADOS DO NFA*/
 int tab_transicao [23][21] =
 { // 0    1   2    3    4   5   6   7   8   9   10   11  12  13  14    15  16 17  18  19  20
   // D    L   +    -    *   /   <   >   .   ;   "     {   }   =  EOF   E  \n  (    )  qq   _
      1,   9,  13,  14, 15, 16, 17, 19, -1, 22,  7,   11, -1, 18, 20,  -1,  0, 10, 21, -1, -1, //estado 0
      1,  -1,  -1,  -1, -1, -1, -1, -1,  2, -1, -1,   -1, -1, -1, -1,   4, -1, -1, -1, -1, -1, //estado 1
      3,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 2
      3,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,   4, -1, -1, -1, -1, -1, //estado 3
      6,  -1,   5,   5, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 4
      6,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 5
      6,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 6
      7,   7,   7,   7,  7,  7,  7,  7,  7,  7,  8,    7,  7,  7, -1,   7,  7,  7,  7,  7,  7, //estado 7
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 8
      9,   9,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1,  9, //estado 9
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 10
     11,  11,  11,  11, 11, 11, 11, 11, 11, 11, 11,   11, 12, 11, -1,  11, 11, 11, 11, 11, 11, //estado 11
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 12
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 13
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 14
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 15
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 16
     -1,  -1,  -1,  18, -1, -1, -1, 18, -1, -1, -1,   -1, -1, 18, -1,  -1, -1, -1, -1, -1, -1, //estado 17
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 18
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, 18, -1,  -1, -1, -1, -1, -1, -1, //estado 19
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 20
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 21
     -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,   -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 22
 };


 //Mapeamento caracter/coluna
int numero_cientifico=0;
 COLUNA mapa_caracter_coluna(char c, int estado)
 {


        if((estado==1)&&(c=='E')){
                numero_cientifico==1;
                return E;
        }
        if ((isalpha(c))&&(estado!=1)){
                return L;
        }
        if (isdigit(c)) return D;
        if (c==' ')     return BARRA_N_ESPACO;
        if (c=='\n')    return BARRA_N_ESPACO;
        if (c=='\t')    return BARRA_N_ESPACO;
        if (c== '\\')    return BARRA_N_ESPACO;
        if (c==EOF)     return FIM_ARQUIVO;
        if (c == '"')  return ASPAS;
        if (c=='+')	return ADICAO;
		if(c=='-')	return SUBTRACAO;
		if(c=='*')	return MULTIPLICACAO;
		if(c=='/')	return DIVISAO;
		if(c=='<')	return MENOR;
		if(c=='>')	return MAIOR;
		if(c=='.')	return PONTO;
		if(c==';')	return PONTO_E_VIRG;

		if(c=='{')	return ABRE_COLC;
		if(c=='}')	return FECHA_COLC;
		if(c=='=')	return IGUAL;
		if(c=='(')	return ABRE_PARENT;
		if(c==')')	return FECHA_PARENT;
		if(c=='_')	return UND;



        return QQ;

 }

//VERIFICA O ESTADO QUE RETORNOU DA TABELA DE TRANSIÇÃO E INSERE NA LISTA O TOKEN REFERENTE AO MESMO
 TOKEN mapa_estado_token(int estado, string lexema, Dados aux, Lista lista)
 {

       if(estado == 1){
                 aux.token = TOKEN_INTEIRO;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_INTEIRO;
       }
       if(estado == 3){
                 aux.token = TOKEN_REAL;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_REAL;
       }
       if((estado==6)&&(numero_cientifico==1)){
                 aux.token = TOKEN_REAL;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_REAL;
       }
       if((estado==6)&&(numero_cientifico==0)) {
                 aux.token = TOKEN_INTEIRO;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_INTEIRO;
       }
       if(estado == 8){
                 aux.token = TOKEN_LITERAL;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_LITERAL;
       }
       if(estado == 9){
                 aux.token = TOKEN_ID;
                 inserirNaLista(aux, lista);
                 busca_dados(aux, lexema, lista);
                 return TOKEN_ID;
       }
       if(estado == 20){
                 aux.token = TOKEN_FIM_ARQUIVO;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_FIM_ARQUIVO;
       }
       if(estado == 12){
                aux.token = TOKEN_COMENTARIO;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                return TOKEN_COMENTARIO;
	   }
	   if(estado == 0){
        aux.token = TOKEN_ESPACO;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
       return TOKEN_ESPACO;
	   }
	   if((estado == 17)||(estado == 18)||(estado == 19)) {
	       aux.token = TOKEN_OPR;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
            return TOKEN_OPR;
        }
	   if(estado == 18){
        aux.token = TOKEN_RCB;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                  return TOKEN_RCB;
	   }
	   if((estado == 13)||(estado == 14)||(estado == 15)||(estado == 16)){
         aux.token = TOKEN_OPM;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
                 return TOKEN_OPM;
	   }
	   if(estado == 10){
            aux.token = TOKEN_AB_P;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
        return TOKEN_AB_P;
	   }

	   if(estado == 21){
	       aux.token = TOKEN_FC_P;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
        return TOKEN_FC_P;
	   }
	   if(estado == 22){
	       aux.token = TOKEN_PT_V;
                 inserirNaLista(aux,lista);
                 imprimirNaTela(lista);
        return TOKEN_PT_V;
	   }
	   if(estado==4){
	       aux.token = TOKEN_ERRO_CADEIA_NAO_ACEITA;
                 imprimirNaTela(lista);
        return TOKEN_ERRO_CADEIA_NAO_ACEITA;
	   }


       return TOKEN_ERRO;
 }

/*Lê os cacacteres to texto fonte pega  caracter por carcter e compara  se for
um estado referente aos caracteres \n, espaço ou \t
ja chama a função que reconhece o token com o estado 0, caso não vai verificando os outros caracteres,
enquanto for referente a um mesmo tokem ele continua lendo caracteres, caso seja diferente (-1) devolve
um caracter ao texto fonte e  retorna um estado não final da tabela de transição para a função main*/
 TOKEN lexico(FILE *texto_fonte,  Dados aux, Lista lista, int *col, int *lin)
 {
       int estado = 0 ;
       char caracter;
       string lexema;

       caracter = fgetc(texto_fonte);

                if((caracter == ' ')||(caracter == '\n')||(caracter == '\t')){

                return mapa_estado_token(0, aux.lexema, aux, lista);
                }

           do
           {

             estado = tab_transicao[estado][mapa_caracter_coluna(caracter,estado)];
             lexema = lexema +caracter;
             caracter = fgetc(texto_fonte);

            } while (tab_transicao[estado][mapa_caracter_coluna(caracter,estado)] != -1);

        *col= mapa_caracter_coluna(caracter, estado);
        *lin = estado;
       aux.lexema = lexema;
       ungetc(caracter,texto_fonte);  //devolve caracter ao arquivo

       return mapa_estado_token(estado, aux.lexema , aux, lista);
 }

 int main(int argc, char *argv[])
 {

     FILE *texto_fonte;
     TOKEN token;
     Dados aux;
     Lista lista;
     int col, lin = 0;

     criarLista(lista);//cria a lista que armazenará o token e o lexema e o tipo
     if(argc != 2)
     {
        printf("\nnome do arquivo esperado\n");
        //exit(0);
     }

     texto_fonte = fopen("arquivo.alg","r");
     if(! texto_fonte ) // texto_fonte == NULL
     {
          printf("\nproblema na abertura do arquivo %s\n",argv[1]);
          exit(0);
     }

     //chama a função lexico que iniciará uma sequencia de chamadas  para verificação de tokens e lexemas
     while   (((token = lexico(texto_fonte, aux, lista, &col, &lin)) != TOKEN_ERRO ) &&   (token != TOKEN_FIM_ARQUIVO) ){}

     if(token == TOKEN_FIM_ARQUIVO ) printf("\nfim de arquivo");
     if(token == TOKEN_ERRO )  {

                    printf("\nErro linha: %d coluna: %d ", lin, col );
        }

     getchar();

     return 0;
 }



