#include "stdio.h"
#include "agenda.h"
#include "stdlib.h"



int main(int argc, char* argv[]) {

    //cria lista
    lista_eventos_t* lista = NULL;
    
    printf("Inserindo no início da lista...\n");
    lista_eventos_adicionar_inicio(criar_evento(1.5, 1, 1), &lista);
    lista_eventos_adicionar_inicio(criar_evento(2.5, 2, 2), &lista);
    lista_eventos_listar(lista);
    printf("---------FIM---------\n");
    
    return 0; 

}