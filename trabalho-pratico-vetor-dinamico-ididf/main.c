#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "BibArquivos.h"
#include <math.h>


int main(int argc, const char * argv[]) {
    char NomeArq[30] = "";
    FILE *vocabulario_geral = NULL;
    char vocabulario[30] = "vocabulario.txt";
    FILE *AR = NULL;      //Arquivo de texto de referência
    FILE *Saida= NULL;    //Arquivo contendo resultado
    char popc = '0';
      int opcao = 0;
//-------------------Gerar o menu--------------------------------//

    while(popc != 'S'){
        printf("\n################## MENU ##################");
        printf("\n");
        printf("\nR - Abrir o Arquivo CSV: ");
        printf("\nT - Gerar vocabulário");
        printf("\nA - Exibir TF-IDFS");
        printf("\nr - Exibir TF-IDFS de uma nota");
        printf("\nS - Sair");
        printf("\nOpção: ");
        scanf("\n%c", &popc);
        switch (popc) {
//--------------------Abrir arquivo CSV----------------------------//
            case 'R':
                printf("Arquivo CSV: ");
                scanf("%s",NomeArq);
                if(AR != NULL)
                    fclose(AR);
                AR = Arquivo_AbreLeitura(NomeArq);
                if(AR == NULL){
                    printf("Erro 1: Arquivo CSV não pode ser aberto\n");
                }
                else
                    printf("Arquivo %s aberto!!!\n", NomeArq);
                break;

//--------------------------------------------------------------------
//------------------ separa por notas --------------------------------
//---------------------------- ---------------------------------------
    


 //------------------Gerar vocabulário--------------------------------

            case 'T':
                vocabulario_geral = fopen("vocabulario.txt","wr");
                if(vocabulario_geral == NULL){
                    printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
                }
               
    separarArquivosPorNota(NomeArq);
    gera_vocabulario(AR,vocabulario_geral);



//----------------------------------------------------------------------
//-----------------------conta todas as palavras do arquivo-------------
//----------------------------------------------------------------------


    int size_word = Arquivo_retorna_word(vocabulario);


//----------------------------------------------------------------------
//-----------------------conta todos os characteres-------------
//----------------------------------------------------------------------

         int size_c =Arquivo_retorna_characters(vocabulario);



//---------------------------------------------------------------------------------------------
//----------------calcula ocorrencias individuais de cada palavra do vocabulario---------------
//---------------------------------------------------------------------------------------------
    FILE *p_todas_palavras;
    FILE *vocabularioOcorrencia;





    /* Try to open file */
    vocabularioOcorrencia = fopen("vocabularioOcorrencia.txt", "wt");

    /* Exit if file not opened successfully */
    if (vocabularioOcorrencia == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }

    unique_ocurrence(vocabulario,vocabularioOcorrencia,size_word,size_c);
//-------------------------------------------------------------------
//-----------------------gera os 5 Vetores---------------------------
//-------------------------------------------------------------------

//--------------------------------------------------------------------
//------------------ GERAR VOCABULARIO DOS 5 VETORES --------------------------------
//---------------------------- ---------------------------------------

  FILE *csv_nota1;
  FILE *csv_nota2;
  FILE *csv_nota3;
  FILE *csv_nota4;
  FILE *csv_nota5;

//--------------------------------------------------------
    csv_nota1 = fopen("nota1.txt","r");
        if(csv_nota1 == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
       

    csv_nota2 = fopen("nota2.txt","r");
        if(csv_nota2 == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
       


    csv_nota3 = fopen("nota3.txt","r");
        if(csv_nota3 == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
       


    csv_nota4 = fopen("nota4.txt","r");
        if(csv_nota4 == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
       


    csv_nota5 = fopen("nota5.txt","r");
        if(csv_nota5 == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
       


//--------------------------------------------------------------------------------------------------
  FILE *vocabulario_geral_nota1;
  FILE *vocabulario_geral_nota2;
  FILE *vocabulario_geral_nota3;
  FILE *vocabulario_geral_nota4;
  FILE *vocabulario_geral_nota5;



//--------------------------------------------------------
    vocabulario_geral_nota1 = fopen("vocabulario_nota1.txt","wr");
        if(vocabulario_geral == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
        

    vocabulario_geral_nota2 = fopen("vocabulario_nota2.txt","wr");
        if(vocabulario_geral == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
        


    vocabulario_geral_nota3 = fopen("vocabulario_nota3.txt","wr");
        if(vocabulario_geral == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
        

    vocabulario_geral_nota4 = fopen("vocabulario_nota4.txt","wr");
        if(vocabulario_geral == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
        


    vocabulario_geral_nota5 = fopen("vocabulario_nota5.txt","wr");
        if(vocabulario_geral == NULL){
            printf("Erro 2: Arquivo de Referência não pode ser aberto\n");
        }
        
//------------------------------------------------------------------------------------------------



    gera_vocabulario(csv_nota1,vocabulario_geral_nota1);
    gera_vocabulario(csv_nota2,vocabulario_geral_nota2);
    gera_vocabulario(csv_nota3,vocabulario_geral_nota3);
    gera_vocabulario(csv_nota4,vocabulario_geral_nota4);
    gera_vocabulario(csv_nota5,vocabulario_geral_nota5);

    FILE *vocabularioOcorrencia_nota1;
  FILE *vocabularioOcorrencia_nota2;
  FILE *vocabularioOcorrencia_nota3;
  FILE *vocabularioOcorrencia_nota4;
  FILE *vocabularioOcorrencia_nota5;

    vocabularioOcorrencia_nota1 = fopen("TFIDF1.txt", "wt");
    vocabularioOcorrencia_nota2 = fopen("TFIDF2.txt", "wt");
    vocabularioOcorrencia_nota3 = fopen("TFIDF3.txt", "wt");
    vocabularioOcorrencia_nota4 = fopen("TFIDF4.txt", "wt");
    vocabularioOcorrencia_nota5 = fopen("TFIDF5.txt", "wt");



  if (vocabularioOcorrencia_nota1 == NULL)
    {
        printf("Unable to open file.[vocabularioOcorrencia_nota1]  \n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }


  if (vocabularioOcorrencia_nota2 == NULL)
    {
        printf("Unable to open file. [vocabularioOcorrencia_nota2]  \n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }


  if (vocabularioOcorrencia_nota3 == NULL)
    {
        printf("Unable to open file [vocabularioOcorrencia_nota3]     .\n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }
  if (vocabularioOcorrencia_nota4 == NULL)
    {
        printf("Unable to open file.[vocabularioOcorrencia_nota4] \n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }

  if (vocabularioOcorrencia_nota5 == NULL)
    {
        printf("Unable to open file.[vocabularioOcorrencia_nota5]  \n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }



char vocabulario_nota1[30] = "vocabulario_nota1.txt";
char vocabulario_nota2[30] = "vocabulario_nota2.txt";
char vocabulario_nota3[30] = "vocabulario_nota3.txt";
char vocabulario_nota4[30] = "vocabulario_nota4.txt";
char vocabulario_nota5[30] = "vocabulario_nota5.txt";

char TFIDF1[30] = "TFIDF1.txt";
char TFIDF2[30] = "TFIDF2.txt";
char TFIDF3[30] = "TFIDF3.txt";
char TFIDF4[30] = "TFIDF4.txt";
char TFIDF5[30] = "TFIDF5.txt";

//-----------------------------------------------------------------------------------
//-------------------------Conta todas as palavras e char ---------------------------
//---------------------------- ------------------------------------------------------


int size_word_nota1 = Arquivo_retorna_word(vocabulario_nota1);
int size_word_nota2 = Arquivo_retorna_word(vocabulario_nota2);
int size_word_nota3 = Arquivo_retorna_word(vocabulario_nota3);
int size_word_nota4 = Arquivo_retorna_word(vocabulario_nota4);
int size_word_nota5 = Arquivo_retorna_word(vocabulario_nota5);

  int size_c_nota1 =Arquivo_retorna_characters(vocabulario_nota1);
  int size_c_nota2 =Arquivo_retorna_characters(vocabulario_nota2);
  int size_c_nota3 =Arquivo_retorna_characters(vocabulario_nota3);
  int size_c_nota4 =Arquivo_retorna_characters(vocabulario_nota4);
  int size_c_nota5 =Arquivo_retorna_characters(vocabulario_nota5);
printf("Vocabulario com Ocorrencia unicas da palavras [vocabularioOcorrencia] criado!!!");
tf_idf(vocabulario_nota1,TFIDF1,size_c,size_word_nota1);
tf_idf(vocabulario_nota2,TFIDF2,size_c,size_word_nota2);
tf_idf(vocabulario_nota3,TFIDF3,size_c,size_word_nota3);
tf_idf(vocabulario_nota4,TFIDF4,size_c,size_word_nota4);
tf_idf(vocabulario_nota5,TFIDF5,size_c,size_word_nota5);
                break;
 //----------- TF-IDF por nota---------------------//
            case 'r':

    if (vocabulario_geral == NULL)
    {
        printf("POR FAVOR GERE O VOCABULARIO ANTES \n");
        break;
    }


    else{
  
 printf("Digite qual nota você deseja ver o TF-IDF:\n");
 printf("1-nota 1\n");
 printf("2-nota 2\n");
 printf("3-nota 3\n");
 printf("4-nota 4\n");
 printf("5-nota 5\n");

 scanf("%i", &opcao);


 if(opcao == 1){
    printf("exibindo TFIDF 1\n");
    tf_idf(vocabulario_nota1,TFIDF1,size_c,size_word_nota1);
     printf("\n");
    printf("O tfidf foi impresso no TFIDF1.txt\n");
 }

 else if (opcao == 2){
     printf("exibindo TFIDF 2\n");
    tf_idf(vocabulario_nota2,TFIDF2,size_c,size_word_nota2);
    printf("\n");
    printf("O tfidf foi impresso no TFIDF2.txt\n");
 }

 else if (opcao == 3){
     printf("exibindo TFIDF 3\n");
    tf_idf(vocabulario_nota3,TFIDF3,size_c,size_word_nota3);
     printf("\n");
    printf("O tfidf foi impresso no TFIDF3.txt\n");
 }

  else if (opcao == 4){
      printf("exibindo TFIDF 4\n");
    tf_idf(vocabulario_nota4,TFIDF4,size_c,size_word_nota4);
     printf("\n");
    printf("O tfidf foi impresso no TFIDF4.txt\n");
 }

  else if (opcao == 5){
      printf("exibindo TFIDF 5\n");
    tf_idf(vocabulario_nota5,TFIDF5,size_c,size_word_nota5);
     printf("\n");
    printf("O tfidf foi impresso no TFIDF5.txt\n");
 }

  else{
    printf("Opção invalida!");
  }
    }

                break;

    case 'A':

    if (vocabulario_geral == NULL)
    {
        printf("POR FAVOR GERE O VOCABULARIO ANTES \n");
        break;
    }
    else if (vocabularioOcorrencia_nota1 == NULL)
    {
        printf("POR FAVOR GERE O TFIDF ANTES \n");
        break;
    }
    else if (vocabularioOcorrencia_nota2 == NULL)
    {
        printf("POR FAVOR GERE O TFIDF ANTES \n");
        break;
    }
    else if (vocabularioOcorrencia_nota3 == NULL)
    {
        printf("POR FAVOR GERE O TFIDF ANTES \n");
        break;
    }
     else if (vocabularioOcorrencia_nota4 == NULL)
    {
        printf("POR FAVOR GERE O TFIDF ANTES \n");
        break;
    }
    else   if (vocabularioOcorrencia_nota5 == NULL)
    {
        printf("POR FAVOR GERE O TFIDF ANTES \n");
        break;
    }

else{
aglomerar ("vocabularioOcorrencia.txt", 49337,"TFIDF1.txt","TFIDF2.txt", "TFIDF3.txt", "TFIDF4.txt", "TFIDF5.txt");
char p_saida[]="Saida.txt";
finale(p_saida);
}

    

//Inserir função que mostra os TF-IDFS

                break;

            case 'S':
                break;
        }
        if(popc == 'S')
            break;
     }
    }