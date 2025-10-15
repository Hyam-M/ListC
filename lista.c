#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
/* coloque demais includes aqui */

/* ------------------- Nao altere estas structs ------------------------- */
struct nodo {
    int chave;
    struct nodo *prox;
};

struct lista {
    struct nodo *ini;
    struct nodo *ptr; /* ponteiro para algum nodo da lista (iterador) */
    int tamanho;

};
/* ---------------------------------------------------------------------- */

struct lista *lista_cria (){
	struct lista *list = malloc(sizeof(struct lista));
	if (list) {
		/*se foi alocado corretamente.*/
		list->ini = NULL;
		list->ptr = NULL;
		list->tamanho = 0;
		return list;
	} 
	/*se não foi alocado corretamente.*/
	return NULL;
}


/* Elimina o nodo inicial através da função
 * "lista_remove_inicio" até o ponteiro inicial "Lista->ini" 
 * apontar para "NULL";
 * Libera a Lista.
 * */
void lista_destroi (struct lista **lista) {
	int chave;
	while((*lista)->ini != NULL) {
		lista_remove_inicio(*lista, &chave);
	}
	free(*lista);
	*lista = NULL;
}

/* Se for alocado memória corretamente, o novo elemento
 * aponta para o primeiro elemento da lista, e o ponteiro
 * inicial "lista->ini" aponta para o novo elemento.  
 * */
int lista_insere_inicio (struct lista *lista, int chave){
	struct nodo *NovoNodo = malloc(sizeof(struct nodo));

	if (NovoNodo){
		NovoNodo->chave = chave;
		NovoNodo->prox = lista->ini;
		
		lista->ini = NovoNodo;
		lista->tamanho++;

		return 1;
	}
	return 0;
}

/* Se a memória for alocada corretamente,
 * o último elemento aponta para o novo elemento e
 * o novo elemento aponta para "NULL".
 * */
int lista_insere_fim (struct lista *lista, int chave){
	struct nodo *aux;
	aux = lista->ini;

	struct nodo *novonodo = malloc(sizeof(struct nodo));

	if (novonodo) {
		novonodo->prox = NULL;
		novonodo->chave = chave;

		lista->tamanho++;

		/*Caso a lista esteja vazia.*/
		if (lista->ini == NULL){
			lista->ini = novonodo;
			return 1;
		}
		/*Enquanto não chegar ao último elemento.*/
		while (aux->prox != NULL) {
			aux = aux -> prox;
		}
		aux->prox = novonodo;
		return 1;
	}
	/*Memória não foi alocada corretamente.*/
	return 0;
}
/*dar uma mexida*/
int lista_insere_ordenado (struct lista *lista, int chave) {
	if (lista->ini == NULL){
		lista_insere_fim(lista, chave);
		return 1;
	}
	if (lista->tamanho == 1){
		if (lista->ini->chave < chave){
			lista_insere_fim(lista, chave);
			return 1;
		lista_insere_inicio(lista, chave);
		return 1;	
		}
	}
	if (lista->ini->chave >= chave){
		lista_insere_inicio(lista, chave);
		return 1;
	}
	
	struct nodo *NovoNodo = malloc(sizeof(struct nodo));
	NovoNodo->prox = NULL;
	NovoNodo->chave = chave;

	struct nodo *aux = lista->ini;
	
	if(NovoNodo) {
		while(aux->prox->chave < chave && aux->prox != NULL) {
			aux = aux->prox;
		}
		NovoNodo->prox = aux->prox;
		aux->prox = NovoNodo;
		lista->tamanho++;
		return 1;
	}
	
	return 0;
}

/* A memória do primeiro elemento é liberado;
 * O primeiro ponteiro "lista->ini" aponta para
 * O segundo elemento;
 * O tamanho da lista é decrementado.
 * */
int lista_remove_inicio (struct lista *lista, int *chave){
	/*Caso a lista esteja vazia.*/
	if(lista->ini == NULL)
		return 0;

	struct nodo *aux = lista->ini->prox;
	*chave = lista->ini->chave;
	free(lista->ini);

	lista->ini = aux;
	lista->tamanho--;
	return 1;
}

/* A memória do último ponteiro é liberada;
 * O penúltimo ponteiro aponta para "NULL";
 * O tamanho é decrementado;
 * */
int lista_remove_fim (struct lista *lista, int *chave) {
	/*Caso a lista esteja vazia*/
	if(lista->ini == NULL)
                return 0;

	/*Caso a lista tenha apenas um elemento*/
	if(lista->tamanho == 1){
		*chave = lista->ini->chave;
		free(lista->ini);

		lista->ini = NULL;
		lista->tamanho--;
		return 1;
	}
	struct nodo *aux;
	aux = lista->ini;
	
	/*Verifica o ponteiro dá frente para não perder
	 *  a referencia do ponteiro que precisará ser modificado*/
	while (aux->prox->prox != NULL) {
		aux = aux->prox;
	}
	*chave = aux->prox->chave;
	free(aux->prox);

	aux->prox = NULL;
	lista->tamanho--;
	return 1;
} 
/*mexer ta fei*/
int lista_remove_ordenado (struct lista *lista, int chave) {
	if(lista->ini == NULL)
		return 0;

	if(lista->tamanho == 1) {
		free(lista->ini);
		lista->ini = NULL;
		lista->tamanho--;
		return 1;
	}

	if(lista->ini->chave == chave) {
		lista_remove_inicio(lista, &chave);
		return 1;
	}

	struct nodo *aux;
	aux = lista->ini;
	
	while(aux->prox->chave != chave) {
		aux = aux->prox;
	}
	struct nodo *aux1 = aux->prox;
	aux->prox = aux1->prox;
	lista->tamanho--;
	free(aux1);
	return 1;	
}

/* Verifica se o primeiro elemento é nulo;
 * Se for, a lista está vazia;
 * Caso contrário, não está. 
 * */
int lista_vazia (struct lista *lista){
	if(lista -> ini == NULL)
		return 1;
	return 0;
}

int lista_tamanho (struct lista *lista) {
	return lista->tamanho;
}

/* Percorre toda a lista até o "aux" encontrar
 * a chave ou chegar ao último elemento;
 * */
int lista_pertence (struct lista *lista, int chave) {
	struct nodo *aux;
	aux = lista->ini;
	
	while(aux->chave != chave && aux->prox != NULL) {
		aux = aux->prox;
	}

	if (aux->chave == chave) {
		return 1;
	}

	return 0;
}

void lista_inicia_iterador (struct lista *lista) {
	lista->ptr = lista->ini;
}

int lista_incrementa_iterador (struct lista *lista, int *chave) {
	if (lista->ptr != NULL) {
		*chave = lista->ptr->chave;
		lista->ptr = lista->ptr->prox;
		return 1;
	}
	return 0;
}
