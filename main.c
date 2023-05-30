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
