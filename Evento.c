#include "Evento.h"
#include "Horario.h"
#include "Data.h"
#include <stdio.h>
#include <string.h>

void le_evento(Evento *p){
    printf("--Digite a data do evento--\n");
    le_data(&p->data);
    printf("--Digite o horario de inicio--\n");
    le_horario(&p->inicio);
    printf("--Digite o horario final--\n");
    le_horario(&p->fim);
        while (compara_hora(&p->inicio,&p->fim) >= 0){
            printf("--O horario final vem primeiro que o horario inicial, coloque um horario valido--\n");
            printf("--Digite o horario de inicio--\n");
            le_horario(&p->inicio);
            printf("--Digite o horario do final--\n");
            le_horario(&p->fim);
        } 

    printf("--Digite uma descricao: \n");
    getchar();
    fgets(p->descricao, 150, stdin);
    p->descricao[strcspn(p->descricao, "\n")] = '\0';
    printf("Digite um local: \n");
    fgets(p->local, 100, stdin);
    p->local[strcspn(p->local, "\n")] = '\0';
}

void mostra_evento(Evento *p){  
    printf("--Data do evento-- \n");
    mostra_data(&p->data);
    printf("Inicio: ");
    mostra_hora(&p->inicio);
    printf("Final: ");
    mostra_hora(&p->fim);
    printf("Descricao: %s", p->descricao);
    printf("\n");
    printf("Local: %s", p->local);
    printf("\n");
}

void busca_evento_data(Evento p[], int tam, Data a){
    int existe = 0;
    for (int i = 0; i < tam; i++){
        if (a.ano == (p[i]).data.ano && a.mes == (p[i]).data.mes && a.dia == (p[i]).data.dia ){
            mostra_evento(&p[i]);
            existe = 1;
        }
    }
    if (existe == 0){
        printf("Não existe nenhum evento nessa data\n");
    }
    
}

void busca_descricao(Evento v[],char *descricaobusca, int n){
    int existe = 1;
    for(int i = 0 ; i < n ; i++ ){
        {
            printf("Evento encontrado!\n");
            mostra_evento(&v[i]);
            existe = 0;
        }
    }
    if (existe == 1){
        printf("Não existe evento com essa mesma descrição\n");
    }
    
    
}
int busca_sequencial(Evento v[], int n, Data a, Horario inicial){
    for(int i = 0; i < n; i ++){
        if (a.ano == v[i].data.ano && a.mes == v[i].data.mes && a.dia == v[i].data.dia && inicial.hora == v[i].inicio.hora && inicial.minuto == v[i].inicio.minuto){
            return i;
        }
    }
    return -1;
}
int verifica_data_hora(Evento *evento1, Evento *evento2) {
    if (compara_data(&(evento1)->data, &(evento2)->data) == 0) {
        if (compara_hora(&(evento1)->fim, &(evento2)->inicio) > 0 || compara_hora(&(evento1)->inicio, &(evento2)->fim) < 0) {
            // Há sobreposição de horários
            printf("Conflito de horário!\n");
            return 1;
        }
    }
    return 0; // Sem conflitos
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

int compEvento(Evento *a, Evento *b) {
    if (compara_data(&(a)->data, &(b)->data) == 0) {
        // As condições abaixo verificam se há sobreposição de horários
        if (compara_hora(&(a)->inicio, &(b)->fim) < 0 && compara_hora(&(a)->fim, &(b)->inicio) > 0) {
            return 1; // há conflito
        } else {
            return 0; // não há conflito
        }
    } else {
        return 0; // as datas são diferentes, não há conflito
    }
}
/*int compEvento(Evento *a, Evento *b){
    if (compara_data(&(a)->data, &(b)->data) == 0){
        if (compara_hora(&(a)->inicio, &(b)->fim)<0){
            if (compara_hora(&(a)->fim, &(b)->inicio)<0){
                return 0; //é valido
            }else{
                return 1;//n é valido
            }
            }else{
                return 0;// é valido
            } 
    }else{
        return 0;//é valido
    }
    
}*/

//vê se há conflito
int comparaTodosEventos(Evento v[],int tam ,Evento *a){
    for (int i = 0; i < tam; i++){
        if (compEvento(&(v[i]), a)){
            return 1;
        }
    }
    return 0;
}

int busca_evento(Evento p[], int tam, Data *data, Horario *horaInicial){
    for (int i = 0; i < tam; i++){
        if (compara_data(&(p[i]).data, data) == 0){
            if(compara_hora(&p[i].inicio, horaInicial) == 0){
                return i;
            }
        }
    }
    return -1;
}

void removerEvento(Evento v[], int n, Data *data, Horario *hora, int *verifica){
    int indice = busca_evento(v, n, data, hora);
    if (indice == -1){
        printf("Não existe um evento com esses dados.\n");
        *verifica = -1;
    }else{
        for (int i = indice; i < n-1; i++){
            v[i] = v[i+1];
        }
        *verifica = 1;
    }
}
