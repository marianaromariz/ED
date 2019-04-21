#include<stdio.h>
#include<stdlib.h>

struct arvbin{
	char info;
	struct arvbin *esq;
	struct arvbin *dir;
};
typedef struct arvbin arv;


arv* cria(char c, arv* sae, arv* sad){
    arv* p = (arv*)malloc(sizeof(arv));
    p->info = c ;
    p->esq = sae;
    p->dir = sad;
    return p;
}

arv* criavazia(){
	return NULL;
}

int vazia (arv* a){
    return a==NULL;
}

arv* libera (arv* a){
     if (!vazia(a)){
        libera(a->esq);
        libera(a->dir);
        free(a); 
     }
     return NULL;
}

void preordem(arv *a){
    if(a != NULL){
        printf("\n|| \t\t\t * %c \t\t\t ||", a->info);
        preordem(a->esq);
        preordem(a->dir);
    }
}

void posordem(arv *a){
    if(a != NULL){
        posordem(a->esq);
        posordem(a->dir);
        printf("\n|| \t\t\t * %c \t\t\t ||", a->info);
    }
}

void ordem(arv *a){
    if(a != NULL){
        ordem(a->esq);
        printf("\n|| \t\t\t * %c \t\t\t ||", a->info);
        ordem(a->dir);
    }
}

int main(){

    arv* a1= cria('J',criavazia(),criavazia());
	arv* a2= cria('I',criavazia(),a1);
	arv* a3= cria('M',criavazia(),criavazia());
	arv* a4= cria('H',a3,a2);
	arv* a5= cria('D',a4,criavazia());
	arv* a6= cria('G',criavazia(),criavazia());
	arv* a7= cria('C',a6,a5);
	arv* a8= cria('L',criavazia(),criavazia());
	arv* a9= cria('K',criavazia(),a8);
	arv* a10=cria('F',criavazia(),criavazia());
	arv* a11=cria('E',a9,a10);
	arv* a12=cria('B',a11,a7);
	arv* a = cria('A',a12,criavazia());
	
	printf("\n-------------------ARVORES BINARIAS-----------------\n");
	printf("\n \t----------------ORDEM----------------\n");
    ordem(a);
    printf("\n\n \t--------------PRE-ORDEM------------\n");
    preordem(a);
    printf("\n\n \t--------------POS-ORDEM------------\n");
    posordem(a);
    printf("\n\n");

    libera(a);
    system("pause");
    return 0;
}
