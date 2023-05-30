/*Trab de LP 30/05/23 feito por:Claudio rodrigues nunes e Fábio Borges da Silva Gonçalves

O trabalho tem por fim simular um coletor de lixo por referência está é a biblioteca onde estão definidas as funções onde será feito a alocação de
memória, contagem de referencias, limpezas e etc. Está tudo mais bem comentado abaixo.*/

#include"biblioteca.h"

refcount *refcount_list = NULL;

refcount *clear(refcount *l){
    if(l != NULL){
        if(l->cont == 0){
            l->proximo = clear(l->proximo);
            refcount *aux = l->proximo;
            free(l);
            return aux;
        }
        else{
            l->proximo = clear(l->proximo);
            return l;
        }
    }
    return NULL;
}

void *malloc2(int tam){ //recebe o tamanho da varável inteiro.
    refcount *aux = refcount_list; //faz a copia do endereço do refcount_list para o aux.
    refcount_list = malloc(sizeof(refcount)); //cria uma "celula" da estrutura,alocando um espaço para ela.
    refcount_list->proximo = aux; //a emenda.  insere a "celula" no inicio da lista.
    refcount_list->endereco = malloc(tam); // aqui recebe o endereço reservado.
    refcount_list->cont = 1; //contagem de referencia.
    return refcount_list->endereco;
}

void dump(){
    refcount *aux = refcount_list; //faz a copia do endereço do refcount_list para o aux.
    printf("iniciando o Impressão\n");
    while(aux != NULL){
        printf("[Endereco: %p, Referencias: %d]\n", aux->endereco, aux->cont);
        aux = aux->proximo;
    }
    printf("\n\n");
}

void *atrib2(void *end1, void *end2){ //recebe dois valores
    contfix(end1, -1); // chama a função contfix
    contfix(end2, 1); // chama a função contfix
    refcount_list = clear(refcount_list);
    return end2;
}

void contfix(void *end1, int m){ // vai ajustar as referencias de acordo com as variaveis.
    refcount *aux = refcount_list;
    while(aux != NULL){
        if(aux->endereco == end1){
            aux->cont = aux->cont + m;
            break;
        }
        aux = aux->proximo;
    }
} 

void endprogram(){
    while(refcount_list != NULL){
        refcount *aux = refcount_list->proximo;
        free(refcount_list->endereco);
        free(refcount_list);
        refcount_list = aux;
    }
}
