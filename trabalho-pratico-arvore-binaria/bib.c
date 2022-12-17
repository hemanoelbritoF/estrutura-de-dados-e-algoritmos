#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "bib.h"

//struct No
struct No{
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
};
//renomeando estrutura de dados
typedef struct No celula;

FILE *Arquivo_AbreLeitura(char *PNomeArquivo) {
    return fopen(PNomeArquivo,"r");
}
