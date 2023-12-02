#include "Horario.h"
#include <stdio.h>

void le_horario( Horario *p ){
	
	printf("Digite a hora: ");
	scanf("%d", &p->hora);
	while( p->hora > 23 || p->hora < 0 ){
    printf("Digite uma hora valida:\n");
	scanf("%d", &p->hora);    
    }
	
	printf("Digite os minutos: \n");
	scanf("%d", &p->minuto);
    while( p->minuto > 0 || p->minuto < 59 ){
        printf("Digite um minuto valido:\n");
        scanf("%d", &p->minuto);    
    }   
}

void mostra_hora( Horario *p ){
	printf("%d:%d\n", p->hora, p->minuto);
}

// int conflito_hora(Horario inicio1, Horario final1, Horario inicio2, Horario final2){
//     if (inicio1.hora == inicio2.hora){
//         if (){
//         }
//     }
// }