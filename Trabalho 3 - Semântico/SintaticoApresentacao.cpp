// Leonardo Jacarandá Neves - 137570
// Paulo Henrique Gonçalves - 142575
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
#include <stack>
#include <sstream>
#include <string>
#include "SintaticoTABELAFINAl.cpp"
#include "AnalisadorLexicoApresentacao.cpp"
//#include "Semantico.cpp"

using namespace std;

std::list<Dados> variaveis;

std::ofstream File ("PROGRAMA.c", std::ofstream::app);

Dados vetor[5];
int contador;
//armazena o estado ou o simbolo
typedef struct tipo{
    int estd;
    string simbol;
    Dados add;
}Tipo;

typedef struct regra{
    int num;
    string var_esq;
    string prd_dir;
    int tam;
}Regra;

stack< Tipo > pilha;


Regra GetSimbolos(int tipo){
    Regra nova;
    nova.num=tipo;
    switch(tipo){
        case 1:{
            nova.var_esq="P'";
            nova.prd_dir= "P";
            nova.tam = 1;
            break;
        }
        case 2:{
            nova.var_esq="P";
            nova.prd_dir= "inicio V A";
            nova.tam = 3;
            break;
        }
        case 3:{
            nova.var_esq="V";
            nova.prd_dir= "varinicio LV";
            nova.tam = 2;
            break;
        }
        case 4:{
            nova.var_esq="LV";
            nova.prd_dir= "D LV";
            nova.tam = 2;
            break;
        }
        case 5:{
            nova.var_esq="LV";
            nova.prd_dir= "varfim ;";
            nova.tam = 2;
            break;
        }
        case 6:{
            nova.var_esq="D";
            nova.prd_dir= "id TIPO ;";
            nova.tam = 3;
            break;
        }
        case 7:{
            nova.var_esq="TIPO";
            nova.prd_dir= "inteiro";
            nova.tam = 1;
            break;
        }
        case 8:{
            nova.var_esq="TIPO";
            nova.prd_dir= "real";
            nova.tam = 1;
            break;
        }
        case 9:{
            nova.var_esq="TIPO";
            nova.prd_dir= "lit";
            nova.tam = 1;
            break;
        }
        case 10:{
            nova.var_esq="A";
            nova.prd_dir= "ES A";
            nova.tam = 2;
            break;
        }
        case 11:{
            nova.var_esq="ES";
            nova.prd_dir= "leia id ;";
            nova.tam = 3;
            break;
        }
        case 12:{
            nova.var_esq="ES";
            nova.prd_dir= "escreva ARG ;";
            nova.tam = 3;
            break;
        }
        case 13:{
            nova.var_esq="ARG";
            nova.prd_dir= "literal";
            nova.tam = 1;
            break;
        }
        case 14:{
            nova.var_esq="ARG";
            nova.prd_dir= "num";
            nova.tam = 1;
            break;
        }
        case 15:{
            nova.var_esq="ARG";
            nova.prd_dir= "id";
            nova.tam = 1;
            break;
        }
        case 16:{
            nova.var_esq="A";
            nova.prd_dir= "CMD A";
            nova.tam = 2;
            break;
        }
        case 17:{
            nova.var_esq="CMD";
            nova.prd_dir= "id rcb LD ;";
            nova.tam = 4;
            break;
        }
        case 18:{
            nova.var_esq="LD";
            nova.prd_dir= "OPRD opm OPRD";
            nova.tam = 3;
            break;
        }
        case 19:{
            nova.var_esq="LD";
            nova.prd_dir= "OPRD";
            nova.tam = 1;
            break;
        }
        case 20:{
            nova.var_esq="OPRD";
            nova.prd_dir= "id";
            nova.tam = 1;
            break;
        }
        case 21:{
            nova.var_esq="OPRD";
            nova.prd_dir= "num";
            nova.tam = 1;
            break;
        }
        case 22:{
            nova.var_esq="A";
            nova.prd_dir= "COND A";
            nova.tam = 2;
            break;
        }
        case 23:{
            nova.var_esq="COND";
            nova.prd_dir= "CABECALHO CORPO";
            nova.tam = 2;
            break;
        }
        case 24:{
            nova.var_esq="CABECALHO";
            nova.prd_dir= " se ( EXP_R ) entao";
            nova.tam = 5;
            break;
        }
        case 25:{
            nova.var_esq="EXP_R";
            nova.prd_dir= "OPRD opr OPRD";
            nova.tam = 3;
            break;
        }
        case 26:{
            nova.var_esq="CORPO";
            nova.prd_dir= "ES CORPO";
            nova.tam = 2;
            break;
        }
        case 27:{
            nova.var_esq="CORPO";
            nova.prd_dir= "CMD CORPO";
            nova.tam = 2;
            break;
        }
        case 28:{
            nova.var_esq="CORPO";
            nova.prd_dir= "COND CORPO";
            nova.tam = 2;
            break;
        }
        case 29:{
            nova.var_esq="CORPO";
            nova.prd_dir= "fimse";
            nova.tam = 1;
            break;
        }
        case 30:{
            nova.var_esq="A";
            nova.prd_dir= "fim";
            nova.tam = 1;
            break;
        }
    }
    return nova;
}

//mapeia a coluna da tabela GOTO de acordo com as variáveis
int GO_TO(string simbolo){
    //  P    V     LV    D     TIPO   A      ES     ARG   CMD    LD     OPRD      COND    CABEÇALO   EXP_R   CORPO
        if (simbolo=="P"){
            return 0;
        }
        if(simbolo=="V"){
            return 1;
        }
        if(simbolo=="LV"){
            return 2;
        }
        if(simbolo=="D"){
            return 3;
        }
        if(simbolo=="TIPO"){
            return 4;
        }
        if(simbolo=="A"){
            return 5;
        }
        if(simbolo=="ES"){
            return 6;
        }
        if(simbolo=="ARG"){
            return 7;
        }
        if(simbolo=="CMD"){
            return 8;
        }
        if(simbolo=="LD"){
            return 9;
        }
        if(simbolo=="OPRD"){
            return 10;
        }
        if(simbolo=="COND"){
            return 11;
        }
        if(simbolo=="CABECALHO"){
            return 12;
        }
        if(simbolo=="EXP_R"){
            return 13;
        }
        if(simbolo=="CORPO"){
            return 14;
        }
}

//Saber qual token que ta sendo empilhado
string GetString(Dados *dados){
    int tipo;
    switch(dados->token){
        case 0 :{
            return dados->lexema;
            break;
        }
        case IDENTIFICADOR:{
            return dados->lexema;
            break;
        }
        case PT_V:{
            return ";";
        }
        case LITERAL:{
            return "literal";
        }
        case INTEIRO:{
            return "num";
        }
        case REAL:{
            return "num";
        }
        case RCB:{
            return "rcb";
        }
        case OPM:{
            return "opm";
        }
        case AB_P:{
            return "(";
        }
        case FC_P:{
            return ")";
        }
        case OPR:{
            return "opr";
        }
        case END_OF_FILE:{
            return "$";
        }
    }
}
int TiposLexemas(Dados *data);


Dados Semantic(Regra regra){
    Dados naoterm;
    string impr;
    int flag=0;
    if (regra.var_esq=="P"){
            //-
            return naoterm;
        }
        if(regra.var_esq=="V"){
            //-
            return naoterm;
        }
        if(regra.var_esq=="LV"){
            if(regra.prd_dir=="varfim ;"){
                File<<"\n";
                File<<"\n";
                File<<"\n";
                return naoterm;
            }
        }
        if(regra.var_esq=="D"){
            naoterm.tipo = vetor[1].lexema;
             for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
                    if(it->lexema==vetor[2].lexema&&it->token==vetor[2].token){
                        flag=1;
                        it->tipo=vetor[1].lexema;
                        break;
                    }
                }
            if(naoterm.tipo=="real"){
                impr = "double ";
                File <<impr<<vetor[2].lexema<<";"<<endl;

            }
            if(naoterm.tipo=="inteiro"){
                impr = "int ";
                File << impr<<vetor[2].lexema<<";"<<endl;

            }
            if(naoterm.tipo=="literal"){
                impr = "char ";
                File <<impr<<vetor[2].lexema<<"[256];"<<endl;

            }
            return naoterm;
        }
        if(regra.var_esq=="TIPO"){
            naoterm=vetor[0];
            return naoterm;
        }
        if(regra.var_esq=="A"){
            //-
            return naoterm;
        }
        if(regra.var_esq=="ES"){
            if(regra.prd_dir=="leia id ;"){
                string tip;
                for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
                    if(it->lexema==vetor[1].lexema&&it->token==vetor[1].token){
                        flag=1;
                        tip=it->tipo;
                        break;
                    }
                }
                if(tip=="real"){
                    impr = "scanf(\"%lf\",&";
                  File << impr<<vetor[1].lexema<<");"<<endl;
                  return naoterm;
                }
                if(tip=="inteiro"){
                    impr = "scanf(\"%d\",&";
                    File << impr<<vetor[1].lexema<<");"<<endl;
                    return naoterm;
                }
                if(tip=="literal"){
                    impr = "scanf(\"%s\",";
                    File << impr<<vetor[1].lexema<<");"<<endl;
                    return naoterm;
                }
                    printf("Erro4: Variavel nao declarada");//botar a linha
                    exit(0);
            }else{
                File << "printf("<<vetor[1].lexema<<");"<<endl;
                return naoterm;
            }
        }
        if(regra.var_esq=="ARG"){

            if(vetor[0].token==INTEIRO||vetor[0].token==REAL||vetor[0].token==LITERAL){
                naoterm=vetor[0];
                return naoterm;
            }
            list<Dados>::iterator it;
            int flag=0;
            if(vetor[0].token==IDENTIFICADOR){
                for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
                    if(it->lexema==vetor[0].lexema&&it->token==vetor[0].token){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    naoterm=vetor[0];
                    return naoterm;
                }else{
                    printf("Erro3: Variável nao declarada");
                    exit(0);
                }
            }
        }
        if(regra.var_esq=="CMD"){
            bool teste =vetor[3].token==IDENTIFICADOR;
            string aux;
            if(vetor[3].token==IDENTIFICADOR){
                for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
                        //cout <<"me achou " << it->lexema <<"  " <<vetor[3].lexema<<" "<<it->token<<"  "<<vetor[3].token<<endl;
                    if(it->lexema==vetor[3].lexema&&it->token==vetor[3].token){
                        flag=1;
                        aux=it->tipo;
                        break;
                    }
                }
                if(flag==1){
                    //cout <<"me achou " << vetor[1].tipo <<"  " <<vetor[3].token<<" "<<vetor[1].lexema<<"  "<<vetor[3].lexema<<endl;
                    if(aux==vetor[1].tipo){//nao sei se ta certo
                        File << vetor[3].lexema<<"="<<vetor[1].lexema<<";"<<endl;
                        return naoterm;
                    }else{
                        printf("Erro: Tipos diferentes para atribuicao");
                        exit(0);
                    }
                }else{
                    printf("Erro2: Variável nao declarada");
                    exit(0);
                }
            }
        }
        if(regra.var_esq=="LD"){
            if(vetor[0].tipo==vetor[2].tipo&&vetor[1].token!=LITERAL){
                stringstream Resultado;
                Resultado << contador;//colocar a variavel global
                contador++;
                naoterm.lexema="T"+Resultado.str();
                naoterm.tipo=vetor[0].tipo;
                File << "int T"<< Resultado.str()<<" = "<< vetor[2].lexema <<vetor[1].lexema<< vetor[0].lexema<<";"<<endl;
                return naoterm;
            }
            if(regra.tam==1){
                naoterm=vetor[0];
                return naoterm;
            }
        }
        if(regra.var_esq=="OPRD"){
            if(vetor[0].token==IDENTIFICADOR){
                for (it = tabelaSimbolos.begin(); it != tabelaSimbolos.end(); it++ ){
                    if(it->lexema==vetor[0].lexema&&it->tipo==vetor[0].tipo){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    naoterm=vetor[0];
                    return naoterm;
                }else{

                    printf("Erro1: Variável nao declarada");
                    exit(0);
                }
            }else{
                naoterm=vetor[0];
                return naoterm;
            }
        }
        if(regra.var_esq=="COND"){
           File <<"}"<<"\n";
           return naoterm;
        }
        if(regra.var_esq=="CABECALHO"){
            File << "if("<<vetor[2].lexema<<"){"<<endl;
            return naoterm;
        }
        if(regra.var_esq=="EXP_R"){
            if(vetor[0].tipo==vetor[2].tipo){
                stringstream Resultado;
                Resultado << contador;
                contador++;
                naoterm.lexema="T"+Resultado.str();// arrumar
              File << "bool T"<<Resultado.str()<<" = "<<vetor[2].lexema<<vetor[1].lexema<<vetor[0].lexema<<";"<<endl;
              return naoterm;
            }else{
                printf("Erro: Operandos com tipos incompativeis");
                exit(0);
            }
        }
        if(regra.var_esq=="CORPO"){
                return naoterm;
        }
}


void Sintatico(){

    FILE *arquivo;

    Dados aux;
    contador=0;
    arquivo = fopen("texto.alg","r");
    Tipo s;
    s.estd=0;
    pilha.push(s);
    aux=lexico(arquivo, aux);
    int estado=pilha.top().estd;

    while(true){
        if(aux.token==COMENTARIO){
            aux=lexico(arquivo,aux);
            while(aux.token==ESPACO){ // verifica se o token é 'espaço'
                aux=lexico(arquivo,aux);
            }
        }
        estado=tabela_acoes[pilha.top().estd][TiposLexemas(&aux)];
        if(estado>100&&estado<999){
            Tipo lex;
            lex.estd=-1; //armazenou um simbolo
            lex.simbol=GetString(&aux);
            lex.add=aux;// adicionando os Dados.
            pilha.push(lex);
            Tipo est;
            est.estd=estado-100;
            pilha.push(est); //empilhou
            aux=lexico(arquivo,aux);

            while(aux.token==7){
                aux=lexico(arquivo,aux);
            }
        }
        else if (estado>0&&estado<31){
            Regra atual;
            atual=GetSimbolos(estado);
            int cont=0;
            while(cont!=atual.tam){
                if(pilha.top().estd==-1){
                    cont++;
                    //printf("%d\n\n",atual.tam);
                    vetor[cont-1]=pilha.top().add;// adicionando os dados a regra para a parte semantica
                    //cout <<"To aqui mano " <<vetor[cont-1].lexema<<endl;
                    //cout <<"To aqui messssmo " <<vetor[cont-1].tipo<<endl;
                }
                pilha.pop();
            }
            Tipo got;
            got.estd=tabela_GOTO[pilha.top().estd][GO_TO(atual.var_esq)];
            Tipo simb;
            simb.estd=-1;
            simb.simbol=atual.var_esq;
            simb.add=Semantic(atual);
            // chamar a semantica mandando a regra. Retornando um Dado
            pilha.push(simb);
            pilha.push(got);
            //cout << "Regra: "<<atual.var_esq <<" -> " << atual.prd_dir<<"\n";
        }
        else if (estado == 999){
            printf("Fim da Analise Sintatica\n");
            return;
        }
        else if (estado < -1){
                switch(estado){
                    case -3:{
                        cout << "Error 0: Esperava-se ler 'inicio' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -4:{
                        cout << "Error 1: expressao nao aceita linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -5:{
                        cout << "Error 2: Esperava-se ler 'varinicio' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -6:{
                        cout << "Error 3: Esperava-se ler 'fim' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -7:{
                        cout << "Error 4: Esperava-se ler 'id' ou 'varfim' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -9:{
                        cout << "Error 6: Esperava-se ler 'leia ', 'fim', 'se' ,'escreva' ou 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -10:{
                        cout << "Error 7: Esperava-se ler 'leia ', 'fim', 'se' ,'escreva' ou 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -11:{
                        cout << "Error 8: Esperava-se ler 'leia ', 'fim', 'se' ,'escreva' ou 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -13:{
                        cout << "Error 10: Esperava-se ler 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -14:{
                        cout << "Error 11: Esperava-se ler 'literal', 'num' ou 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -15:{
                        cout << "Error 12: Esperava-se ler 'rcb' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -16:{
                        cout << "Error 13: Esperava-se ler 'leia ', 'fimse', 'se' ,'escreva' ou 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -17:{
                        cout << "Error 14: Esperava-se ler '(' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -19:{
                        cout << "Error 16: Esperava-se ler 'varfim', 'id' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -20:{
                        cout << "Error 17: Esperava-se ler ';' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -21:{
                        cout << "Error 18: Esperava-se ler 'int', 'real','lit' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -25:{
                        cout << "Error 22: Esperava-se ler ';' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -26:{
                        cout << "Error 23: Esperava-se ler ';' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -30:{
                        cout << "Error 27: Esperava-se ler 'id' ou 'num' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -32:{
                        cout << "Error 29: Esperava-se ler 'fimse', 'leia', 'escreva' , 'id' ou 'se' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -33:{
                        cout << "Error 30: Esperava-se ler 'fimse', 'leia', 'escreva' , 'id' ou 'se' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -34:{
                        cout << "Error 31: Esperava-se ler 'fimse', 'leia', 'escreva' , 'id' ou 'se' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }

                    case -36:{
                        cout << "Error 33: Esperava-se ler 'id', 'num' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -39:{
                        cout << "Error 36:  Esperava-se ler ';' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -45:{
                        cout << "Error 42:  Esperava-se ler ';' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -46:{
                        cout << "Error 43: Esperava-se ler 'opm' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -52:{
                        cout << "Error 49: Esperava-se ler ')' linha: "<< linha <<" coluna: " <<coluna << "\n";
                        break;
                    }
                    case -53:{
                        cout << "Error 50: Esperava-se ler 'opr' Linha: "<< linha <<" Coluna: " <<coluna << "\n";
                        break;
                    }
                    case -55:{
                        cout << "Error 52: Esperava-se ler 'id', 'num'  Linha"<< linha <<" Coluna: " <<coluna << "\n";
                        break;
                    }
                    case -56:{
                        cout << "Error 53: Esperava-se ler 'entao' Linha: "<< linha <<" Coluna: " <<coluna << "\n";
                        break;
                    }
                    case -57:{
                        cout << "Error 54: Esperava-se ler 'id' , 'num' Linha: "<< linha <<" Coluna: " <<coluna << "\n";
                        break;
                    }
                }
            break;
        }
    }
}

//Mapear coluna da tabela de ações
int TiposLexemas(Dados *data){
    // inicio  varinicio  varfim     ;     id     int   real  lit   leia  escreva   literal  num   rcb    opm    se     (     )    entao    opr   fim  fimse  $
    //{"inicio", "varinicio", "varfim", "escreva", "leia", "se", "entao", "fimse", "fim", "inteiro", "real", "literal"}
    int tipo;
    switch(data->token){
        case 0 :{
               if(data->lexema=="inicio"){
                    return 0;
                }
                if(data->lexema=="varinicio"){
                    return 1;
                }
                if(data->lexema=="varfim"){
                    return 2;
                }
                if(data->lexema=="inteiro"){
                    return 5;
                }
                if(data->lexema=="real"){
                    return 6;
                }
                if(data->lexema=="literal"){
                    return 7;
                }
                if(data->lexema=="leia"){
                    return 8;
                }
                if(data->lexema=="escreva"){
                    return 9;
                }
                if(data->lexema=="se"){
                    return 14;
                }
                if(data->lexema=="entao"){
                    return 17;
                }
                if(data->lexema=="fim"){
                    return 19;
                }
                if(data->lexema=="fimse"){
                    return 20;
                }
        }
        case IDENTIFICADOR:{
            return 4;
        }
        case PT_V:{
            return 3;
        }
        case LITERAL:{
            return 10;
        }
        case INTEIRO:{
            return 11;
        }
        case REAL:{
            return 11;
        }
        case RCB:{
            return 12;
        }
        case OPM:{
            return 13;
        }
        case AB_P:{
            return 15;
        }
        case FC_P:{
            return 16;
        }
        case OPR:{
            return 18;
        }
        case END_OF_FILE:{
            return 21;
        }

    }

}


int main(){
    File <<"#include<stdio.h> \n"<<"#include<stdlib.h>"<<endl;
    File << "int main(){"<<endl;
    Sintatico();
    File <<"return 0;"<<endl;
    File << "}"<<endl;

return 0;
}
