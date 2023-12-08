#include "Horario.h"
#include "Data.h"
#include <stdio.h>

typedef struct{
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
void busca_descricao(Evento v[],char *descricaobusca, int n){
