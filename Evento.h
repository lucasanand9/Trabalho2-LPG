#ifndef EVENTO_H
#define EVENTO_H

#include "Horario.h"
#include "Data.h"
#include <stdio.h>

typedef struct Evento{
    Data data;
    Horario inicio; 
    Horario fim;
    char descricao[150];
    char local[100];  
} Evento;

void le_evento(Evento *p);
void mostra_evento(Evento *p);
void busca_evento_data(Evento p[], int tam, Data a);
int verifica_data_hora(Evento *evento1, Evento *evento2);
void sortEventos(Evento listaEventos[], int tam);
int compEvento(Evento *a, Evento *b);
int comparaTodosEventos(Evento v[], int tam ,Evento *a);
void busca_descricao(Evento v[],char *descricaobusca, int n);
int busca_evento(Evento p[], int tam, Data *data, Horario *horaInicial);
void removerEvento(Evento v[], int n, Data *data, Horario *hora, int *verifica);

#endif
