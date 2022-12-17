#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct No
struct No{
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
};
//renomeando estrutura de dados
typedef struct No celula;

FILE *Arquivo_AbreLeitura(char *PNomeArquivo);
celula *GeraABP(celula *pRaiz, int valor);