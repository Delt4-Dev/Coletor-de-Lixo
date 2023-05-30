/*Trab de LP 30/05/23 feito por:Claudio rodrigues nunes e Fábio Borges da Silva Gonçalves

O trabalho tem por fim simular um coletor de lixo por referência está é a biblioteca onde está definido a struct refcount. */

#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct refcount{
    struct refcount *proximo;
    void *endereco;
    int cont;
}refcount;

void contfix(void *end1, int m);

refcount *removelixo(refcount *l);

void dump();

void *atrib2(void *end1, void *end2);

void *malloc2(int tam);

void endprogram();

#endif
