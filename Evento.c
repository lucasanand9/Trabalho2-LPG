#include "Evento.h"
#include "Horario.h"
#include "Data.h"
#include <stdio.h>

void le_evento(Evento *p){
    printf("Digite a data do evento:\n");
    le_data(&p->data);
    printf("O horario final vem primeiro que o horario inicial, coloque um horario valido:\n");
    printf("Digite o horario de inicio:\n");
    le_horario(&p->inicio);
    printf("Digite o horario do final:\n");
    le_horario(&p->fim);
        while (valida_hora(&p->inicio, &p->fim)){
            printf("O horario final vem primeiro que o horario inicial, coloque um horario valido:\n");
            printf("Digite o horario de inicio:\n");
            le_horario(&p->inicio);
            printf("Digite o horario do final:\n");
            le_horario(&p->fim);
        } 

    printf("Digite uma descricao:\n");
    scanf(" %s", p->descricao);
    printf("Digite um local:\n");
    scanf(" %s", p->local);
}

void mostra_evento(Evento *p){  
    printf("Data do evento: ");
    mostra_data(&p->data);
    printf("Inicio: ");
    mostra_hora(&p->inicio);
    printf("Final: ");
    mostra_hora(&p->fim);
    printf("Descricao: %s", p->descricao);
    printf("Local %s", p->local);
}

void busca_evento_data(Evento p[], int tam, Data a){
    for (int i = 0; i < tam; i++){
        if (a.ano == (p[i]).data.ano && a.mes == (p[i]).data.mes && a.dia == (p[i]).data.dia ){
            mostra_evento(&p[i]);
        }
    }
}

void busca_descricao(Evento v[],char *descricaobusca, int n){
    for(int i = 0 ; i < n ; i++ ){
        if(strcmp(v[i],descricaobusca) == 0){
            printf("Evento encontrado:\n");
            printf("Descrição: %s\n", v[i].descricao);
        }
    }
}
int busca_sequencial(Evento v[], int n, Data a, Horario inicial){
    for(int i = 0; i < n; i ++){
        if (a.ano == v[i].data.ano && a.mes == v[i].data.mes && a.dia == v[i].data.dia && inicial.hora == v[i].inicio.hora && inicial.minuto == v[i].inicio.minuto){
            return i;
        }
        return -1;
    }
}

int verifica_data_hora(Evento *evento1, Evento *evento2){
    if (compara_data(&(evento1)->data, &(evento2)->data) == 0){
        if (conflito_hora(&(evento1)->fim, &(evento2)->inicio)){
            
        }
        
    }
//printf("Não é possível inserir esse evento nesse horário.");
}

void sortEventos(Evento listaEventos[], int tam){
    Evento aux;
    for (int i = 0; i < tam; i++){
        int indiceMenor = i;
    
        for (int j = i+1; j < tam; j++){
            if (compara_data(&(listaEventos[indiceMenor]).data, &(listaEventos[j]).data ) > 0){
                indiceMenor = j;
            }else if (compara_data(&(listaEventos[indiceMenor]).data, &(listaEventos[j]).data ) == 0){
                if (compara_hora(&(listaEventos[indiceMenor]).inicio, &(listaEventos[j]).inicio)){
                    indiceMenor = j;
                }
            }
        }

        aux = listaEventos[i];
        listaEventos[i] = listaEventos[indiceMenor];
        listaEventos[indiceMenor] = aux;
    }
}
