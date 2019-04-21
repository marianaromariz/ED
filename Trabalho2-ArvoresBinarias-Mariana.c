#include<stdlib.h>
#include<stdio.h>

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;


Arv* arv_criavazia (void){
	return NULL;
}

int arv_vazia (Arv* a){
    return a==NULL;
}

Arv* arv_libera (Arv* a){
	if (!arv_vazia(a)){
		arv_libera(a->esq); /* libera sae */
		arv_libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

//FUNÇÕES CRIADAS
Arv* abb_insere (Arv* a, int v){
	if (a==NULL){
		a=(Arv*)malloc(sizeof(Arv));
		a->info=v;
		a->esq = a->dir=NULL;
	}
	else if (v < a->info)
		a-> esq = abb_insere(a->esq,v);
	else
		a-> dir = abb_insere(a->dir,v);
	return a;
}

void imprime_crescente(Arv *a){
    if(!arv_vazia(a)) {
        imprime_crescente(a->esq);
        printf("%d ",a->info);
        imprime_crescente(a->dir);
   }
}

Arv* abb_busca (Arv* r, int v){
	if (r == NULL) return NULL;
	else if (r->info > v) return abb_busca (r->esq, v);
	else if (r->info < v) return abb_busca (r->dir, v);
	else return r;
}

void showmenor(Arv* a, int x){
	if (a==NULL) return;
	showmenor(a->esq, x);
	if (a->info < x) {
		printf ("%d ", a->info);
		showmenor(a->dir, x);
	}
}
 
Arv* menor (Arv* a){
	if (a==NULL) return NULL;
	while(a->esq!=NULL)
		a=a->esq;
	return a;
}

Arv* busca_no (Arv* a){
	if (a==NULL) return NULL;
	Arv* b = a->esq;
	if(b==NULL) return NULL;
	while (b->dir != NULL) 
		b = b->dir;
	return b;
 } 
 
int main(){
    
    Arv*a;
    a = arv_criavazia();

    /*Vai inserir, recursivamente, valores na árvore - implementar "Arv* abb_insere (Arv* a, int v)" */
    a = abb_insere (a,6);
    a = abb_insere (a,2);
    a = abb_insere (a,8);
    a = abb_insere (a,1);
    a = abb_insere (a,4);
    a = abb_insere (a,3);
	printf("\n\n==========| ARVORE BINARIA DE BUSCA |===========\n");
    
	/* Vai imprimir, recursivamente, todos os elementos em ordem crescente - implementar "void imprime_crescente(Arv *a)"*/
    printf("\n Impressao em ordem crescente = ");
	imprime_crescente(a); 
	
    /*Vai buscar, recursivamente, um valor na árvore - implementar "Arv* abb_busca (Arv* r, int v)"*/
    Arv*k = abb_busca(a,1);
    if (k!=NULL) printf("\n Info da busca = %d", k->info);

    /*imprime, recursivamente, todos os valores nos nós da árvore que sejam menores que x, em ordem
	crescente - implementar "void showmenor(Arv* a, int x)".*/
    printf("\n Valores menores que 5 = ");
	showmenor(a,5);
    
	/* Encontra, iterativamente, um ponteiro para o menor valor da árvore - implementar "Arv* menor (Arv* a)"*/
	k = menor(a);
    if (k!=NULL) printf("\n Menor valor da arvore = %d\n", k->info);

   /* Encontra, iterativamente, o valor que antecede a raiz - implementar "Arv* busca_no (Arv* a)"*/
    k = busca_no(a);
    if (k!=NULL) printf(" Valor que antecede a raiz = %d\n", k->info);
	else printf("Não ha valor!");
	printf("\n====================| FIM |======================\n\n");
    arv_libera(a);
    system("pause");
    return 0;
}
