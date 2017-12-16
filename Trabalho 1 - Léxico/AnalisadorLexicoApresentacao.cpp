//Leonardo Jacarandá  - 137570
//Paulo Henrique - 142575

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>

#define PALAVRA_CHAVE 0
#define INTEIRO 1
#define IDENTIFICADOR 2
#define END_OF_FILE 3
#define REAL 4
#define LITERAL 5
#define COMENTARIO 6
#define ESPACO 7
#define OPR 8
#define RCB 9
#define OPM 10
#define AB_P 11
#define FC_P 12
#define PT_V 13
#define ERRO 14

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
#define UNDERLINE 20

using namespace std;

int coluna;
int linha;

int linhaerro;
int colunaerro;

typedef struct Dados
{
    int token;
    string lexema;
    string tipo;
} dados;

std::list<dados> tabelaSimbolos;
std::list<dados>::iterator it;

int ERROR(){
    printf("\nCARACTER INVALIDO linha: %d coluna: %d\n",linha+1,coluna+1);
    exit(1);
    return 100;
}

/*IMPLEMENTAÇÃO DA TABELA DE TRANSIÇÃO DE ESTADOS DO NFA*/
int tab_transicao [23][21] =
{
//  0    1   2    3    4   5   6   7   8   9   10  11  12  13  14    15  16 17  18  19  20
//  D    L   +    -    *   /   <   >   .   ;   "    {   }   =  EOF   E  \n  (    )  qq   _
    1,   9,  13,  14, 15, 16, 17, 19, -1, 22,  7,  11, -1, 18, 20,  -1,  0, 10, 21, -1, -1, //estado 0
    1,  -1,  -1,  -1, -1, -1, -1, -1,  2, -1, -1,  -1, -1, -1, -1,   4, -1, -1, -1, -1, -1, //estado 1
    3,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 2
    3,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,   4, -1, -1, -1, -1, -1, //estado 3
    6,  -1,   5,   5, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 4
    6,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 5
    6,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 6
    7,   7,   7,   7,  7,  7,  7,  7,  7,  7,  8,   7,  7,  7, -1,   7,  7,  7,  7,  7,  7, //estado 7
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 8
    9,   9,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1,  9, //estado 9
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 10
    11,  11,  11,  11, 11, 11, 11, 11, 11, 11, 11,  11, 12, 11, -1,  11, 11, 11, 11, 11, 11, //estado 11
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 12
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 13
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 14
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 15
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 16
    -1,  -1,  -1,  18, -1, -1, -1, 18, -1, -1, -1,  -1, -1, 18, -1,  -1, -1, -1, -1, -1, -1, //estado 17
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 18
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, 18, -1,  -1, -1, -1, -1, -1, -1, //estado 19
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 20
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 21
    -1,  -1,  -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, //estado 22
};


//imprime da lista o token, o lexema e o tipo
void imprimir()
{
    std::list<dados>::iterator it;
    for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ )
    {

        if((it->token == INTEIRO)||(it->token == REAL))
            cout <<"\nToken: Numero\n";

        if(it->token == LITERAL)
            cout <<"\nToken: Literal\n";

        if(it->token == ESPACO)
            cout <<"\nToken: Espaco\n";

        if(it->token == COMENTARIO)
            cout <<"\nToken: Comentario\n";

        if(it->token == OPR)
            cout <<"\nToken: OPR\n";

        if(it->token == RCB)
            cout <<"\nToken: RCB\n";

        if(it->token == OPM)
            cout <<"\nToken: OPM\n";

        if(it->token == AB_P)
            cout <<"\nToken: AB_P\n";

        if(it->token== FC_P)
            cout <<"\nToken: FC_P\n";

        if(it->token == PT_V)
            cout <<"\nToken: PT_V\n";

        if(it->token == ERRO)
            cout <<"\nToken: ERRO\n";

        if(it->token == END_OF_FILE)
            cout <<"\nToken: END_OF_FILE\n";

        cout <<"Lexema:" <<it->lexema << "\n";
        cout <<"Tipo:" <<it->tipo << "\n";

    }
}
    void LexandType (Dados aux){
        cout <<"Lexema:" <<aux.lexema << "\n";
        cout <<"Tipo:" <<aux.tipo << "\n";
    }
//inserir palavras chaves no main antes do lexico
//Consultar	se	ele	existe	na	tabela	de	símbolos	e	se	é	palavrachave
int busca_dados(Dados aux, string chave)
{
    string  palavras_chave[12] = {"inicio", "varinicio", "varfim", "escreva", "leia", "se", "entao", "fimse", "fim", "inteiro", "real", "literal"};

    std::list<dados>::iterator it;
    for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
        if (aux.lexema.compare(it->lexema)==0)
        {
           if(it->token==2){
                cout <<"\nToken: Id\n";
                LexandType(aux);
                return -1;
           }
           if(it->token==0){
                cout <<"\nToken: PALAVRA-CHAVE\n";
                LexandType(aux);
                return -3;
           }
        }
    }
    for(int i=0; i<12; i++)
    {
        if (aux.lexema.compare(palavras_chave[i])==0)
        {
            aux.token=PALAVRA_CHAVE;
            return PALAVRA_CHAVE;
        }
    }
    return IDENTIFICADOR;
}

//Mapeamento caracter/coluna
int numero_cientifico=0;
int mapaear_caracter_coluna(char c, int estado)
{

    if((estado==1)&&(c=='E'))
    {
        numero_cientifico==1;
        return E;
    }
    if((isalpha(c))&&(estado!=1))
    {
        return L;
    }
    if(isdigit(c))return D;
    if(c==' ')return BARRA_N_ESPACO;
    if(c== '\r') return BARRA_N_ESPACO;
    if(c=='\n')return BARRA_N_ESPACO;
    if(c=='\t')return BARRA_N_ESPACO;
    if(c==EOF)return FIM_ARQUIVO;
    if(c== '"')return ASPAS;
    if(c=='+')return ADICAO;
    if(c=='-')return SUBTRACAO;
    if(c=='*')return MULTIPLICACAO;
    if(c=='/')return DIVISAO;
    if(c=='<')return MENOR;
    if(c=='>')return MAIOR;
    if(c=='.')return PONTO;
    if(c==';')return PONTO_E_VIRG;
    if(c=='{')return ABRE_COLC;
    if(c=='}')return FECHA_COLC;
    if(c=='=')return IGUAL;
    if(c=='(')return ABRE_PARENT;
    if(c==')')return FECHA_PARENT;
    if(c=='_')return UNDERLINE;
    if(estado==11 || estado ==7)return QQ;

    return ERROR();
}

//VERIFICA O ESTADO QUE RETORNOU DA TABELA DE TRANSIÇÃO E INSERE NA LISTA O TOKEN REFERENTE AO MESMO
Dados mapear_tokens(int estado, string lexema, Dados aux, int flag)
{

    if(estado == 0)
    {
        aux.token = ESPACO;
        return aux;
    }
    if(estado == 1)
    {
        aux.token = INTEIRO;
        aux.tipo="inteiro";
        cout <<"\nToken: Numero\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 3)
    {
        aux.token = REAL;
        aux.tipo="real";
        cout <<"\nToken: Numero\n";
        LexandType(aux);
        return aux;
    }
    if((estado==6)&&(numero_cientifico==1))
    {
        aux.token = REAL;
        aux.tipo="real";
        cout <<"\nToken: Numero\n";
        LexandType(aux);
        return aux;
    }
    if((estado==6)&&(numero_cientifico==0))
    {
        aux.tipo="inteiro";
        aux.token = INTEIRO;
        cout <<"\nToken: Numero\n";
        LexandType(aux);
        return aux;
    }
    if(estado==7&&flag==1){
        printf("\nError: Literal Invalido linha %d coluna %d\n",linhaerro+1,colunaerro+1);
        aux.token = ERRO;
        return aux;
    }
    if(estado==11&&flag==1){
        printf("\nError: Comentario Invalido Linha %d Coluna %d\n",linhaerro+1,colunaerro+1);
        aux.token = ERRO;
        return aux;
    }
    if(estado==4)
    {
        aux.token = ERRO;
        return aux;
    }
    if(estado == 8)
    {
        linhaerro=0;
        colunaerro=0;
        aux.tipo="literal";
        aux.token = LITERAL;
        cout <<"\nToken: Literal\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 9)
    {
        int cont=busca_dados(aux, lexema);
        if(cont>=0){
            aux.token = cont;
            tabelaSimbolos.push_back(aux);
        }else{
            aux.token = cont+3;
            return aux;
        }
        if(aux.token==0){
            cout <<"\nToken: PALAVRA-CHAVE\n";
            LexandType(aux);
            return aux;
        }
        cout <<"\nToken: Id\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 10)
    {
        aux.token = AB_P;
        cout <<"\nToken: AB_P\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 12)
    {
        colunaerro=0;
        linhaerro=0;
        aux.token = COMENTARIO;
        cout <<"\nToken: Comentario\n";
        LexandType(aux);
        return aux;
    }
    if((estado == 13)||(estado == 14)||(estado == 15)||(estado == 16))
    {
        aux.token = OPM;
        cout <<"\nToken: OPM\n";
        LexandType(aux);
        return aux;
    }
    if((estado == 17)||(estado == 18)||(estado == 19))
    {
        aux.token = OPR;
        cout <<"\nToken: OPR\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 18)
    {
        aux.token = RCB;
        cout <<"\nToken: RCB\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 20)
    {
        aux.token = END_OF_FILE;
        cout <<"\nToken: END_OF_FILE\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 21)
    {
        aux.token = FC_P;
        cout <<"\nToken: FC_P\n";
        LexandType(aux);
        return aux;
    }
    if(estado == 22)
    {
        aux.token = PT_V;
        cout <<"\nToken: PT_V\n";
        LexandType(aux);
        return aux;
    }
    aux.token=ERRO;
    return aux;
}

/*Lê os cacacteres to texto fonte pega  caracter por carcter e compara  se for
um estado referente aos caracteres \n, espaço ou \t
ja chama a função que reconhece o token com o estado 0, caso não vai verificando os outros caracteres,
enquanto for referente a um mesmo tokem ele continua lendo caracteres, caso seja diferente (-1) devolve
um caracter ao texto fonte e  retorna um estado não final da tabela de transição para a função main*/
Dados lexico(FILE *texto_fonte,  Dados aux)
{
    int estado=0,state=0;
    char caracter;
    string lexema;
    int flag=0;
    char erro;
    caracter = fgetc(texto_fonte);

    if((caracter == ' ')||(caracter == '\n')||(caracter == '\t')||(caracter == '\r'))
    {
        if(caracter=='\n'){
            linha++;
            coluna=0;
        }
        if(caracter==' '){
            coluna++;
        }
        if(caracter=='\t'){
            coluna=0;
        }
        return mapear_tokens(0, aux.lexema, aux,0);
    }

    do
    {
        if(caracter=='\n'){
            linha++;
            coluna=0;
        }
        if(caracter=='"'||caracter=='{'){
            linhaerro=linha;
            colunaerro=coluna;
        }
        estado = tab_transicao[estado][mapaear_caracter_coluna(caracter,estado)];
        if(caracter!='\n'||caracter!='\r'){
            lexema = lexema +caracter;
        }
        caracter = fgetc(texto_fonte);
        if(estado==7&&caracter==EOF){
            flag=1;
        }
        if(estado==11&&caracter==EOF){
            flag=1;
        }
        coluna++;
    }
    while (tab_transicao[estado][mapaear_caracter_coluna(caracter,estado)] != -1);

    aux.lexema = lexema;
    ungetc(caracter,texto_fonte);  //devolve caracter ao arquivo
    return mapear_tokens(estado, aux.lexema , aux,flag);
}

int main()
{
    linha=0;
    coluna=0;

    FILE *arquivo;

    Dados aux;

    int token;

    arquivo = fopen("texto.alg","r");

    Dados paralaco;
    paralaco = lexico(arquivo, aux);
    //chama a função lexico que iniciará uma sequencia de chamadas  para verificação de tokens e lexemas
    while(paralaco.token != ERRO  && (paralaco.token != END_OF_FILE)) {
        paralaco = lexico(arquivo, aux);
    }

    if(paralaco.token == END_OF_FILE ) printf("\nFim do arquivo\n");
/*
    printf("\nTeste tabela de simbolos\n");

    for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
        cout << "\nToken: " << it->token <<"\nLexema: " << it->lexema <<"\nTipo: " << it->tipo << endl;
    }
*/

    return 0;
}

