
#include "BibArquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


FILE *Arquivo_AbreLeitura(char *PNomeArquivo){
    return fopen(PNomeArquivo,"r");
}

FILE *Arquivo_Novo(char *PNomeArquivo){
    return fopen(PNomeArquivo,"w");
}



void separarArquivosPorNota(char *NomeArq){
    FILE *nota1, *nota2, *nota3, *nota4, *nota5;  
    char * linef = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *AR = NULL;
    nota1 = fopen("nota1.txt", "wt");
    nota2 = fopen("nota2.txt", "wt");
    nota3 = fopen("nota3.txt", "wt");
    nota4 = fopen("nota4.txt", "wt");
    nota5 = fopen("nota5.txt", "wt");
   
    AR = Arquivo_AbreLeitura(NomeArq);
    if(AR == NULL){
        printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
    }
    

    while ((read = getline(&linef, &len, AR)) != -1) {
    
        int x = strlen(linef);
    
        if (linef[x-2]=='1'){
            fprintf(nota1, "%s\n", linef);
        }
        if (linef[x-2]=='2'){
            fprintf(nota2, "%s\n", linef);
        }
        if (linef[x-2]=='3'){
            fprintf(nota3, "%s\n", linef);
        }
        if (linef[x-2]=='4'){
            fprintf(nota4, "%s\n", linef);
        }
        if (linef[x-2]=='5'){
            fprintf(nota5, "%s\n" , linef);
        }
        
    }
    
  
    fclose(nota1);
    fclose(nota2);
    fclose(nota3);
    fclose(nota4);
    fclose(nota5);
    fclose(AR);
    if (linef)
    free(linef);  
    
}

//program para contar as quantidades individuais de cada palavra


//------------------------------------------------------------------------------------------------------------
//---------------program para contar as quantidades individuais de cada palavra-------------------------------
//------------------------------------------------------------------------------------------------------------


void unique_ocurrence(char *parqentrada,FILE *parqsaida, int size_words, int size_c){ //const int totalp){

    FILE *AR = NULL;

    AR = Arquivo_AbreLeitura(parqentrada);
    if(AR == NULL){
    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
    }
    //Dynamically Allocating Memory
    int i=0,j=0, len=0,index=0, isUnique=0;
    char word[1000];
    char (*words)[1000]=malloc(sizeof(char*) * size_c);
  

    // Count of distinct words
    int  count[size_words];
    // Initialize words count to 0
    for (i=0; i<size_words; i++)
        count[i] = 0;

    index = 0;
    
    while (fscanf(AR, "%s", word) != EOF)
    {
        // Convert word to lowercase
        //strlwr(word);

        // Remove last punctuation character
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';


        // Check if word exits in list of all distinct words
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        // If word is unique then add it to distinct words list
        // and increment index. Otherwise increment occurrence 
        // count of current word.
        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    // Close file
    fclose(AR);


    //TF
    
   
   // printf("\nindex:%d\n", index);

    for (i=0; i<index; i++)
    {
        fprintf(parqsaida,"%s\n", words[i]);
    }
               

    free(words);
    words=NULL; 
}

//------------------------------------------------------------------------------------------------------------
//---------------program para contar as quantidades individuais de cada palavra usar no tf-------------------------------
//-------------------------------------------------------------------------------------------------------------
void tf_idf(char *parqentrada_nota,char *parqsaida, int size_c,int size_words_nota){ //const int totalp){

     
     
    FILE *AR = NULL;
    AR = Arquivo_AbreLeitura(parqentrada_nota);
    if(AR == NULL){
    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
    }
    else{
        printf("abriu arquivo %s\n",parqentrada_nota);
    }

    FILE *Saida = NULL;
    Saida = fopen(parqsaida,"w");
    if(Saida == NULL){
    printf("Erro 1: Arquivo de Referência parqsaida não pode ser aberto\n");
    }
 


    //Dynamically Allocating Memory
    int i=0,j=0, len=0, index=0, isUnique=0,tamanho=0;
    char word[1000];
    char (*words)[1000]=malloc(sizeof(char*) * size_c); //
    

    // Count of distinct words
    int  count[size_words_nota];
    // Initialize words count to 0
    for (i=0; i<size_words_nota; i++)
        count[i] = 0;
        

    index = 0;
    
    while (fscanf(AR, "%s", word) != EOF)
    {
        // Convert word to lowercase
        //strlwr(word);

        // Remove last punctuation character
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';


        // Check if word exits in list of all distinct words
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        // If word is unique then add it to distinct words list
        // and increment index. Otherwise increment occurrence 
        // count of current word.
        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;
            

            index++;
        }
        else
        {
            count[i - 1]++;
            
        }
    }

    // Close file
    fclose(AR);

//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
    /*
     * Print occurrences of all words in file. 
     */
 FILE *N_1 = NULL;
  FILE *N_2 = NULL;
   FILE *N_3 = NULL;
    FILE *N_4 = NULL;
     FILE *N_5= NULL;

        N_1 = fopen("vocabulario_nota1.txt","r");
            if(N_1 == NULL){
                printf("Erro 2: Arquivo de Referência vocabulario_nota1  não pode ser aberto\n");
            }
           
        N_2 = fopen("vocabulario_nota2.txt","r");
            if(N_2 == NULL){
                printf("Erro 2: Arquivo de Referência vocabulario_nota2 não pode ser aberto\n");
            }
        
        N_3 = fopen("vocabulario_nota3.txt","r");
        if(N_3 == NULL){
            printf("Erro 2: Arquivo de Referência vocabulario_nota3 não pode ser aberto\n");
        }
    
      N_4 = fopen("vocabulario_nota4.txt","r");
        if(N_4 == NULL){
            printf("Erro 2: Arquivo de Referência vocabulario_nota4 não pode ser aberto\n");
        }
    
      N_5 = fopen("vocabulario_nota5.txt","r");
        if(N_5 == NULL){
            printf("Erro 2: Arquivo de Referência vocabulario_nota5 não pode ser aberto\n");
        }
    
//----------------------------------- 
//---------------------------------------
char* buffer1 =0;
long length1;
if(N_1)
{
    fseek(N_1,0,SEEK_END);
    length1 = ftell(N_1);
    fseek(N_1,0,SEEK_SET);
    buffer1 = malloc(length1);
    if(buffer1)
    {
        fread(buffer1,1,length1,N_1);
    }
    fclose(N_1);
}

//-----------------------------------
//---------------------------------------
char* buffer2 =0;
long length2;
if(N_2)
{
    fseek(N_2,0,SEEK_END);
    length2 = ftell(N_2);
    fseek(N_2,0,SEEK_SET);
    buffer2 = malloc(length2);
    if(buffer2)
    {
        fread(buffer2,1,length2,N_2);
    }
    fclose(N_2);
}

//-----------------------------------
//---------------------------------------
char* buffer3 =0;
long length3;
if(N_3)
{
    fseek(N_3,0,SEEK_END);
    length3 = ftell(N_3);
    fseek(N_3,0,SEEK_SET);
    buffer3 = malloc(length3);
    if(buffer3)
    {
        fread(buffer3,1,length3,N_3);
    }
    fclose(N_3);
}

//-----------------------------------
//---------------------------------------
char* buffer4 =0;
long length4;
if(N_4)
{
    fseek(N_4,0,SEEK_END);
    length4 = ftell(N_4);
    fseek(N_4,0,SEEK_SET);
    buffer4 = malloc(length4);
    if(buffer4)
    {
        fread(buffer4,1,length4,N_4);
    }
    fclose(N_4);
}

//-----------------------------------
//---------------------------------------
char* buffer5 =0;
long length5;
if(N_5)
{
    fseek(N_5,0,SEEK_END);
    length5 = ftell(N_5);
    fseek(N_5,0,SEEK_SET);
    buffer5 = malloc(length5);
    if(buffer5)
    {
        fread(buffer5,1,length5,N_5);
    }
    fclose(N_5);
}
//---------------------------------------
//---------------------------------------
    double idf[index];
    double tf[index];
    double a_tfidf[index];
   
//---------------------------------------
//---------------------------------------
    for (i=0; i<index; i++)
    {
       
//---------------------------------------

        
         
        
        int denominador=0;
        
        if (strstr(buffer1,words[i])!=NULL){
            denominador++;
        }

        if (strstr(buffer2,words[i])!=NULL) {
            denominador++;
        }

        if (strstr(buffer3,words[i])!=NULL) {
            denominador++;
        }

        if (strstr(buffer4,words[i])!=NULL) {
            denominador++;
        }

        if (strstr(buffer5,words[i])!= NULL) {
            denominador++;
        }
       
       
        int five =5;
	
        double numeroArquivosComPalavra =(double)five /(double)denominador;
        //  printf("divisao do idf %d  / %d : = %lf \n",five,denominador,numeroArquivosComPalavra);
        //  printf("COUNT: %d\n",count[i]);

        
        idf[i] = log10(numeroArquivosComPalavra);
        tf[i] = (double)count[i]/(double)size_words_nota;
        //tfidf_saida.fname[i]=words[i];
        a_tfidf[i] = (double)idf[i]*(double)tf[i];
    //--------------------------------------
    //fprintf(parqsaia,"%-15s -> %d -> TF: %lf -> IDF: %lf -> TFIDF: %lf\n", words[i], count[i], tf[i], idf[i], tfidf[i]);   
    fprintf(Saida,"%-30s->TFIDF:%lf\n", words[i], a_tfidf[i]);
     
   //fprintf(parqsaida,"%-30s\n", tfidf_saida.fname[i]);  
} 


FILE *imprimir= NULL;

        imprimir = fopen(parqsaida,"r");
            if(imprimir == NULL){
                printf("Erro 2: Arquivo de Referência imprimir não pode ser aberto\n");
            }

char* imprmir5 =0;
long lengthimprimir;
if(imprimir)
{
    fseek(imprimir,0,SEEK_END);
    lengthimprimir = ftell(imprimir);
    fseek(imprimir,0,SEEK_SET);
    imprmir5 = malloc(lengthimprimir);
    if(imprmir5)
    {
        fread(imprmir5,1,lengthimprimir,imprimir);
    }
    fclose(imprimir);
}




printf("%s\n",imprmir5);

  // terminate
  
  free (buffer1);
    // terminate
  
  free (buffer2);
    // terminate
  
  free (buffer3);
    // terminate
  
  free (buffer4);
    // terminate
  
  free (buffer5);
free(imprmir5);
    free(words);
    words=NULL; 
}
//------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------
//-------Programas para contar a quantidade palavras e caracteres para gerar o vocabulario.--------------------------
//-------------------------------------------------------------------------------------------------------------------

//conta a quantidade de palavras no arquivo
int Arquivo_retorna_word(char *parq){
  
    FILE *AR = NULL;
    char ch;
    int characters, words, lines;
    int *wordss;
    int *c;
    AR = Arquivo_AbreLeitura(parq);
    if(AR == NULL){
    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
    }
    /*
     * Logic to count characters, words and lines.
     */
    characters = words = lines = 0;
    while ((ch = fgetc(AR)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }


    /* Close files to release resources */
    fclose(AR);
    return words;

}


//conta a quantidade de characters no arquivo
int Arquivo_retorna_characters(char *parq)
{

    FILE *AR = NULL;

    char ch;
    int characters, words, lines;
    int *wordss;
    int *c;
    AR = Arquivo_AbreLeitura(parq);
    if(AR == NULL){
    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
    }
    /*
     * Logic to count characters, words and lines.
     */
    characters = words = lines = 0;
    while ((ch = fgetc(AR)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }

    /* Print file statistics */
  /*  printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);

*/
    /* Close files to release resources */
    fclose(AR);
    return characters;

}

//--------------------------------------------------------
//---------------------------- ler cada palavra-----------
//---------------------------- e cria o token-------------
//--------------------------------------------------------

void gera_vocabulario(FILE *AR,FILE *SAIDA){

char* buffer =0;
long length;
//--------------------------------------------------------------------
//------------------ converte o arquivo txt pra bufffer --------------
//---------------------------- ---------------------------------------      
//
if(AR)
{
    fseek(AR,0,SEEK_END);
    length = ftell(AR);
    fseek(AR,0,SEEK_SET);
    buffer = malloc(length);
    if(buffer)
    {
        fread(buffer,1,length,AR);
    }
    fclose(AR);
}



//--------------------------------------------------------
//---------------------------- ler cada palavra-----------
//---------------------------- e cria o token-------------
//--------------------------------------------------------


char * pch;
 // printf ("Splitting string \"%s\" into tokens:\n",buffer);

  
pch = strtok (buffer," ,.-\"_ _Çî :' ':;' '/'");

while (pch != NULL)
{
    if (strlen(pch)>=3){
    //printf ("%s\n",pch);
        if('A' <= pch[0] && pch[0] <= 'Z' || 'a' <= pch[0] && pch[0] <= 'z'){
            fprintf (SAIDA, "%s\n",pch);
        }    
    }
        pch = strtok (NULL, " ,.-\"_ _Çî :' ':;' '/'");
        //imprime em um arquivo as palavras
        //fprintf("");        
}
fclose(SAIDA);
}




// -------------------- EXIBIR
void aglomerar (char *vocabulario, int nVocabulario, char *tfidf_1, char *tfidf_2, char *tfidf_3, char *tfidf_4, char *tfidf_5){
    FILE *VOCABULARIO, *TFIDF1, *TFIDF2, *TFIDF3, *TFIDF4, *TFIDF5;

    VOCABULARIO = Arquivo_AbreLeitura(vocabulario);
    TFIDF1 = Arquivo_AbreLeitura(tfidf_1);
    TFIDF2 = Arquivo_AbreLeitura(tfidf_2);
    TFIDF3 = Arquivo_AbreLeitura(tfidf_3);
    TFIDF4 = Arquivo_AbreLeitura(tfidf_4);
    TFIDF5 = Arquivo_AbreLeitura(tfidf_5);

    FILE *AR;
    AR = fopen("Saida.txt", "wr");

    char VOCA[nVocabulario][50];

    char Linha0[50];
    char Linha1[10];
    char Linha2[10];
    char Linha3[10];
    char Linha4[10];
    char Linha5[10];

    
    char teste[50];

    int i=0;
    char *result;

    while (!feof(VOCABULARIO)){
	    // Lê uma linha (inclusive com o '\n')
        result = fgets(VOCA[i], 100, VOCABULARIO);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result) {
            //printf("Linha %d : %s",i,VOCA[i]);
        } // Se foi possível ler
        i++;
    }


    char a = ' ';
    if(a == ' '){
        //printf("aaaaaaaaaaaaaaaa");
    }
    
    for(int i=0; i<nVocabulario; i++){
        
        while(!feof(TFIDF1)){
            int b=0;
            fgets(Linha0, 50, TFIDF1);
            for (int y=0; y<30;y++ ){
                if(Linha0[y]== ' '){
                    b=y;
                    break;   
                }
                teste[y]=Linha0[y];
                
            }
            teste[b]='\n';
            

            
            if(strcmp(VOCA[i],teste)==0){
                //printf("AGORA sim\n");
                for (int x=39; x<47;x++){
                    //printf("%c",Linha1[x]);
                    Linha1[x-39]=Linha0[x];
                    
                }
                //printf("%s",Linha1);
                break;
            }
            memset(teste,0,strlen(teste));
            //memset(Linha1,0,strlen(Linha1));
        }
        fseek(TFIDF1,0,SEEK_SET);

    //TFDF2
        while(!feof(TFIDF2)){


            //TFIDF3
            int b=0;
            fgets(Linha0, 50, TFIDF2);


            //TFIDF3
            for (int y=0; y<30;y++ ){
                if(Linha0[y]== ' '){
                    b=y;
                    break;   
                }
                teste[y]=Linha0[y];
                
            }
            teste[b]='\n';
            

            
            if(strcmp(VOCA[i],teste)==0){
                //printf("AGORA sim\n");
                for (int x=39; x<47;x++){
                    //printf("%c",Linha1[x]);
                    Linha2[x-39]=Linha0[x];
                    
                }
                //printf("%s",Linha1);
                break;
            }
            memset(teste,0,strlen(teste));
            //memset(Linha1,0,strlen(Linha1));
        }
        fseek(TFIDF2,0,SEEK_SET);


        //TFIDF3
        while(!feof(TFIDF3)){


            //TFIDF3
            int b=0;
            fgets(Linha0, 50, TFIDF3);


            //TFIDF3
            for (int y=0; y<30;y++ ){
                if(Linha0[y]== ' '){
                    b=y;
                    break;   
                }
                teste[y]=Linha0[y];
                
            }
            teste[b]='\n';
            

            
            if(strcmp(VOCA[i],teste)==0){
                //printf("AGORA sim\n");
                for (int x=39; x<47;x++){
                    //printf("%c",Linha1[x]);
                    Linha3[x-39]=Linha0[x];
                    
                }
                //printf("%s",Linha1);
                break;
            }
            memset(teste,0,strlen(teste));
            //memset(Linha1,0,strlen(Linha1));
        }
        fseek(TFIDF3,0,SEEK_SET);


        //TFIDF4
        while(!feof(TFIDF4)){


            //TFIDF3
            int b=0;
            fgets(Linha0, 50, TFIDF4);


            //TFIDF3
            for (int y=0; y<30;y++ ){
                if(Linha0[y]== ' '){
                    b=y;
                    break;   
                }
                teste[y]=Linha0[y];
                
            }
            teste[b]='\n';
            

            
            if(strcmp(VOCA[i],teste)==0){
                //printf("AGORA sim\n");
                for (int x=39; x<47;x++){
                    //printf("%c",Linha1[x]);
                    Linha4[x-39]=Linha0[x];
                    
                }
                //printf("%s",Linha1);
                break;
            }
            memset(teste,0,strlen(teste));
            //memset(Linha1,0,strlen(Linha1));
        }
        fseek(TFIDF4,0,SEEK_SET);

        //TFIDF5
        while(!feof(TFIDF5)){


            //TFIDF3
            int b=0;
            fgets(Linha0, 50, TFIDF5);


            //TFIDF3
            for (int y=0; y<30;y++ ){
                if(Linha0[y]== ' '){
                    b=y;
                    break;   
                }
                teste[y]=Linha0[y];
                
            }
            teste[b]='\n';
            

            
            if(strcmp(VOCA[i],teste)==0){
                //printf("AGORA sim\n");
                for (int x=39; x<47;x++){
                    //printf("%c",Linha1[x]);
                    Linha5[x-39]=Linha0[x];
                    
                }
                //printf("%s",Linha1);
                break;
            }
            memset(teste,0,strlen(teste));
            //memset(Linha1,0,strlen(Linha1));
        }
        fseek(TFIDF5,0,SEEK_SET);


        fprintf(AR, "%s : nota1:%s, nota2: %s, nota3: %s, nota4: %s, nota5: %s \n", VOCA[i], Linha1,Linha2,Linha3,Linha4,Linha5);//EDITANDO
        memset(Linha1,0,strlen(Linha1));
        memset(Linha2,0,strlen(Linha2));
        memset(Linha3,0,strlen(Linha3));
        memset(Linha4,0,strlen(Linha4));
        memset(Linha5,0,strlen(Linha5));

    }
    fclose(AR);
    fclose(VOCABULARIO);
    fclose(TFIDF1);
    fclose(TFIDF2);
    fclose(TFIDF3);
    fclose(TFIDF4);
    fclose(TFIDF5);

}





void finale(char *imprmir){

    FILE *imprimir= NULL;

        imprimir = fopen(imprmir,"r");
            if(imprimir == NULL){
                printf("Erro 2: Arquivo de Referência imprimir não pode ser aberto\n");
            }

char* imprmir5 =0;
long lengthimprimir;
if(imprimir)
{
    fseek(imprimir,0,SEEK_END);
    lengthimprimir = ftell(imprimir);
    fseek(imprimir,0,SEEK_SET);
    imprmir5 = malloc(lengthimprimir);
    if(imprmir5)
    {
        fread(imprmir5,1,lengthimprimir,imprimir);
    }
    fclose(imprimir);
}
printf("%s",imprmir5);
}
