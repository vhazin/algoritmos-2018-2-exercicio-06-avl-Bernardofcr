//
//  main.c
//  Hazin 20 - 09
//
//  Created by Bernardo Russo on 20/09/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Arvore{
    int id;
    struct Arvore *esq;
    struct Arvore *dir;
    struct Arvore *pai;
    int tamanho;
}arvore;

int altura(struct Arvore *arv){
    if (arv==NULL)
        return 0;
    else
        return arv->tamanho;
}

void updatealt(struct Arvore *arv){
    int altdir,altesq;
    if (arv!=NULL){
        altdir=altura(arv->dir);
        altesq=altura(arv->esq);
        if (altdir>altesq)
            arv->tamanho=altdir+1;
        else
            arv->tamanho=altesq+1;
    }
}

struct Arvore *criararv (int id, struct Arvore *esq, struct Arvore *dir){
    struct Arvore *raiz;
    raiz=malloc(sizeof(arvore));
    raiz->id=id;
    raiz->esq=esq;
    raiz->dir=dir;
    raiz->tamanho=altura(raiz);
    return raiz;
}
struct Arvore *addarvore(struct Arvore *arv, int add){
    if (arv==NULL){
        arv=criararv(add,NULL,NULL);
    }else if (add<arv->id){
        arv->esq=addarvore(arv->esq,add);
        arv->esq->pai=arv;
    }else{
        arv->dir=addarvore(arv->dir,add);
        arv->dir->pai=arv;
    }
    return arv;
}


int main() {
    int t,count=0,n,add;
    scanf("%d",&t);
    struct Arvore *arv[t];
    while (count<t){
        scanf("%d",&n);
        while (n--){
            scanf("%d",&add);
            addarvore(arv[count],add);
        }
        count++;
    }
    count=0;
    while (count<t){
        if (arv[count]->dir->tamanho==arv[count]->esq->tamanho)
            printf("T\n");
        else
            printf("F\n");
        count++;
    }
    return 0;
}
