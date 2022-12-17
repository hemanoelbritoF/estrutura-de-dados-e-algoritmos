//
//  BibArquivos.h
//  Arquivos
//
//  Created by Nilton Correia da Silva on 27/02/21.
//

#ifndef BibArquivos_h
#define BibArquivos_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Aberturas/criação de arquivos:
FILE *Arquivo_AbreLeitura(char *PNomeArquivo);
FILE *Arquivo_Novo(char *PNomeArquivo);


//Exibições de conteúdos de arquivos
void unique_ocurrence(char *parqentrada,FILE *parqsaida, int size_words, int size_c);
void tf_idf(char *parqentrada_nota,char *parqsaida, int size_c,int size_words_nota);
/*
void tf_idf2(char *parqentrada_nota,FILE *parqsaida, int size_c,int size_words_nota);
void tf_idf3(char *parqentrada_nota,FILE *parqsaida, int size_c,int size_words_nota);
void tf_idf4(char *parqentrada_nota,FILE *parqsaida, int size_c,int size_words_nota);
void tf_idf5(char *parqentrada_nota,FILE *parqsaida, int size_c,int size_words_nota);
*/
int Arquivo_retorna_word(char *parq);
int Arquivo_retorna_characters(char *parq);
void gera_vocabulario(FILE *AR,FILE *SAIDA);
void separarArquivosPorNota(char *NomeArq);
void BubbleSort(double *A, double n, double (*compare)(double,double));
double compare ( double a, double b);
//void aglomerar (char *vocabulario, char *tfidf_1, char *tfidf_2, char *tfidf_3, char *tfidf_4, char *tfidf_5);
void aglomerar (char *vocabulario, int nVocabulario, char *tfidf_1, char *tfidf_2, char *tfidf_3, char *tfidf_4, char *tfidf_5);
void finale(char *imprmir);
#endif /* BibArquivos_h */
