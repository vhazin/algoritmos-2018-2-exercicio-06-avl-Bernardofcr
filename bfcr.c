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
    raiz->tamanho=1;
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
    updatealt(arv);
    return arv;
}

struct Arvore *findarv(struct Arvore *arv, int id){
    if (arv!=NULL){
        if (id==arv->id)
            return (findarv(arv->esq,id));
        else if (id>arv->id)
            return (findarv(arv->dir,id));
        else
            return (findarv(arv->esq,id));
    }else
        return arv;
}

int main() {
    int t,count=0,n,add,altdir,altesq;
    scanf("%d",&t);
    struct Arvore *arv[t];
    int nmax[t],nmin[t];
    while (count<t){
        nmax[count]=0;
        nmin[count]=10000;
        scanf("%d",&n);
        while (n--){
            scanf("%d",&add);
            addarvore(arv[count],add);
            if (add>nmax[count])
                nmax[count]=add;
            else if (add<nmin[count])
                nmin[count]=add;
        }
        count++;
    }
    count=0;
    while (count<t){
        altdir=altura(findarv(arv[count],nmax[count]));
        altesq=altura(findarv(arv[count],nmin[count]));
        if (((altdir-altesq)>-2)||((altdir-altesq)<2))
            printf("T\n");
        else
            printf("F\n");
        count++;
    }
    return 0;
}
