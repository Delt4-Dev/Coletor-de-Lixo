/*Trab de LP 30/05/23 feito por:Claudio rodrigues nunes e Fábio Borges da Silva Gonçalves

O trabalho tem por fim simular um coletor de lixo por referência está é a biblioteca onde estão definidas as funções onde será feito a alocação de
memória, contagem de referencias, limpezas e etc. Está tudo mais bem comentado abaixo.*/

#include"biblioteca.h"

int main(){
    int *v = malloc2(sizeof(int)); /*retorna o endereço reservado.  Lembrando que é uma estrutura, onde estará o contador de referencia.*/
    dump(); //imprime  a única celula com seu endereço e a quantidade de referencia.
    *v = 10;
    int *w = malloc2(sizeof(int)); /*retorna já com duas celulas (v e w). Nos comentarios da função está mais explicado.*/
    dump(); //imprime  duas celulas com seus endereços e a quantidade de referencia.
    *w = 20;
    v = atrib2(v, w);
    dump();
    char *c = malloc2(sizeof(char));
    *c = 'Z';
    dump();
    w = atrib2(w, NULL);
    dump();
    int *k = malloc2(sizeof(int));
    dump();
    *k = 30;
    k = atrib2(v,k);
    dump();
    w = atrib2(w,k);
    dump();
    w=k;
    dump();
    return 0;

}
