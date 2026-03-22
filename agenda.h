#ifndef AGENDA_H
#define AGENDA_H
#include <stdbool.h>
#include "agenda.c"

typedef struct lista_eventos_t lista_eventos_t;
evento_t* criar_evento(double tempo, int alvo, int tipo);
bool lista_eventos_adicionar_inicio(evento_t *evento, lista_eventos_t **lista);


#endif