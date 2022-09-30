#include "Pilha.hpp"


pilha* pilha_criar(void){

    Pilha* p = (Pilha*) malloc(sizeof (Pilha));
    p-> topo = NULL;
    return p;
}

bool pilha_Vazia(pilha *pilha){
    
    if(pilha->numeroElementos == 0){
        return true;
    }else
        return false;

}

void pilha_Push (Pilha* pilha, int valor){

    NoPilha* aux = (NoPilha*)malloc(sizeof(NoPilha));

    aux->valor = valor;
    aux->proximo = pilha->topo;
    pilha->topo = aux;

    pilha->numeroElementos++;  

}

int pilha_Pop (Pilha* pilha){

    if(pilha_Vazia(pilha) == true){
        return -1;
    }else{
        NoPilha* No = pilha->topo;
        int auxValor = No-> valor;
        pilha->topo = No->proximo;
        pilha->numeroElementos--;
        free(No);
        return auxValor;
    }

}

int pilha_Top(pilha *pilha){

    if(pilha_Vazia(pilha)){
        return -1;
    }else{
        NoPilha* aux = pilha->topo;
        return aux->valor;
    }

}

int pilha_Tamanho(pilha *pilha){

    return pilha->numeroElementos;
}


void exibir_Pilha(pilha *pilha){
    cout << "--------------PILHA--------------" << endl;
    NoPilha* aux = pilha->topo;

    for ( int i = 0; i < pilha->numeroElementos; i++){
        cout << "|" << aux->valor << "|" << endl;
        aux = (aux->proximo);
    }
    cout << "---------------------------------" << endl;
    
}