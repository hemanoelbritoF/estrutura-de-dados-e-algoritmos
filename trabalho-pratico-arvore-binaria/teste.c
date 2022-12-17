#include <stdlib.h>
#include <stdio.h>

struct NO{
    int Chave;
    struct NO *pDir, *pEsq;
    int FatBal;
};
typedef struct NO Arv;

int altura(Arv *r){
    if(r==NULL){
        return 0;
    }
    return r->FatBal;
}

int getBal(Arv *N){
    if(N==NULL){
        return 0;
    }
    return altura(N->pEsq) - altura(N->pDir);
}

int max(int a, int b){
    return (a>b) ? a: b;
}
int min(int a, int b){
    return (a<b) ? b: a;
}

void roda_dir(Arv ** p)
{
    if((*p)->pEsq==NULL) return;
    Arv * q = (*p) -> pEsq;

    (*p) -> pEsq = q -> pDir;
    q -> pDir = (*p);

    (*p)->FatBal=altura(*p);
    q->FatBal=altura(q);

    *p=q;
}

void roda_esq(Arv ** p)
{
    if((*p)->pDir==NULL) return;

    Arv * q = (*p) -> pDir;

    (*p) -> pDir = q -> pEsq;
    q -> pEsq = (*p);

    (*p)->FatBal=altura(*p);
    q->FatBal=altura(q);

    *p=q;
}

int getaltura(Arv* p)
{
    return p!=NULL ? p -> FatBal : 0;
}

void balanco(Arv ** p)
{
    Arv * aux;
    int fb=getaltura((*p) -> pEsq ) - getaltura((*p) -> pDir);

    if  (fb>= 2 )
    {
        aux=(*p) -> pEsq;
        fb=getaltura(aux -> pEsq)-getaltura(aux -> pDir);
        if (fb<0)
            roda_esq(&((*p) -> pEsq));

        roda_dir(p);

    }
    else if (fb <= -2 )
    {
        aux=(*p) -> pDir;
        fb=getaltura(aux -> pEsq)-getaltura(aux -> pDir);
        if (fb>0)
            roda_dir(&((*p) -> pDir));

        roda_esq(p);
    }
}

int calculaAltura(Arv *raiz){
    int a,b;
    if (raiz==NULL){
        return 0;
    }else{
        a = calculaAltura(raiz->pDir)+1;
        b = calculaAltura(raiz->pEsq)+1;
    }
    return max(a,b);
}

Arv *gerar(Arv *raiz, int valor){

    if(raiz == NULL){
        Arv *novo;
        novo = (Arv *)malloc(sizeof(Arv));
        novo->Chave = valor;
        novo->FatBal = 0;
        novo->pDir=NULL;
        novo->pEsq=NULL;

        raiz = novo;    
        printf("recebeu\n");
        return raiz;
    }

    //esquerda
    if(valor < raiz->Chave){
        printf("Esquerda\n");
        raiz->pEsq = gerar(raiz->pEsq, valor);
        
    }else if(valor > raiz->Chave){
        printf("Direita\n");
        raiz->pDir = gerar(raiz->pDir, valor);

    } else{
        return raiz;
    }
    //CALCULA FATBAL
    raiz->FatBal = calculaAltura(raiz->pEsq)-calculaAltura(raiz->pDir);
    
    //realizar rotações 
    
    return raiz;
}

int  main(){

    Arv *raiz=NULL;
    raiz = gerar(raiz,40);
    raiz = gerar(raiz,45);
    raiz = gerar(raiz,44);
    raiz = gerar(raiz,50);
    raiz = gerar(raiz,55);

    printf("\n");
    printf("%d\n", raiz->Chave);
    printf("%d\n", raiz->FatBal);
    printf("%d\n", raiz->pDir->Chave);
    printf("%d\n", raiz->pDir->FatBal);
    printf("%d\n", raiz->pDir->pDir->Chave);
    printf("%d\n", raiz->pDir->pDir->FatBal);
    printf("%d\n", raiz->pDir->pEsq->Chave);
    printf("%d\n", raiz->pDir->pEsq->FatBal);
    

    return 0;
}