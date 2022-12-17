#include <stdio.h>
#include <stdlib.h>

//struct No
struct No{
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
};
//renomeando estrutura de dados
typedef struct No Arv;

int altura(Arv *r){
    if(r==NULL){
        return 0;
    }else{
        int ramoEsquerda = altura(r->pEsq);
        int ramoDireita = altura(r->pDir);
        
        if(ramoEsquerda < ramoDireita){
            return ramoDireita +1;
        }else{
            return ramoEsquerda +1;
        }
    }
}


/*
void rot_esq(Arv *r){
    Arv *a=*r;
    NO *b=a->pDir;
    a->pDir=b->pEsq;
    b->pEsq=a;
    a->FatBal=0;
    b->FatBal=0;
    *r=b;
}
*/
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

Arv *gerar(Arv *raiz, int valor){

    if(raiz == NULL){
        Arv *novo;
        novo = (Arv *)malloc(sizeof(Arv));
        novo->Chave = valor;
        //novo->FatBal = 0;
        novo->pDir=NULL;
        novo->pEsq=NULL;

        raiz = novo;    
        printf("recebeu\n");
        return raiz;
    }else{
        //esquerda
        if(valor < raiz->Chave){
            printf("Esquerda\n");
            raiz->pEsq = gerar(raiz->pEsq, valor);
            raiz->FatBal = altura(raiz);
            balanco(&raiz);
            raiz->FatBal = altura(raiz);
            return raiz;
        }else{
            printf("Direita\n");
            raiz->pDir = gerar(raiz->pDir, valor);
            raiz->FatBal = altura(raiz);
            //printf("%d\n",raiz->FatBal);
            balanco(&raiz);
            raiz->FatBal = altura(raiz);
            return raiz;
        }
    }
}

int main(){
    
    char linha[10];
    FILE *AR =NULL;
    AR = fopen("testeA.txt", "rt");
    int num=0;
    Arv *raiz=NULL;

    while(!feof(AR)){
        
        fgets(linha, 10, AR);
        num = atoi(linha);
        printf("\n%d %s\n",num, linha);
        raiz = gerar(raiz,num);
    }

    //printf("%d\n", raiz->Chave);
    
    //printf("%d\n", raiz->pDir->Chave);
    //printf("%d\n", raiz->pDir->pDir->Chave);
    //printf("%d\n", raiz->pDir->pDir->pEsq->Chave);
    //printf("%d\n", raiz->pEsq->Chave);
    //printf("%d\n", raiz->pEsq->pEsq->Chave);
    //printf("%p\n", *&raiz);
    //printf("%d\n", *&raiz->pDir->Chave);
    //printf("%d\n", *&raiz->pEsq->Chave);
    printf("%d", raiz->Chave);
    
    return 0;
}