#include "Horario.h"
#include <stdio.h>

void le_horario( Horario *p ){
	printf("Digite a hora: ");
	scanf("%d", &p->hora);
	while( p->hora > 23 || p->hora < 0 ){
    printf("Digite uma hora valida:\n");
	scanf("%d", &p->hora);    
    }
	
	printf("Digite os minutos: ");
	scanf("%d", &p->minuto);
    while( p->minuto > 59 || p->minuto < 0 ){
        printf("Digite um minuto valido:\n");
        scanf("%d", &p->minuto);    
    }   
}

void mostra_hora( Horario *p ){
	printf("%.2d:%.2d\n", p->hora, p->minuto);
}

int compara_hora(Horario *hora1, Horario *hora2) {
    return (hora1->hora * 60 + hora1->minuto) - (hora2->hora * 60 + hora2->minuto);
}
/*int compara_hora(Horario *hora1, Horario *hora2){
	if(hora1->hora != hora2->hora){
		return hora1->hora - hora2->hora;
	}
	return hora1->minuto - hora2->minuto;
	//compara_hora < 0 -> hora1 vem primeiro
	//compara_hora = 0 -> hora1 e hora2 são iguais
	//compara_hora > 0 -> hora2 vem primeiro
	}*/


int valida_hora(Horario *inicio, Horario *final){
	if (inicio->hora > final->hora || (inicio->hora == final->hora && inicio->minuto >= final->minuto)){
        return 0;
    }
    return 1;

	/*if (inicio->hora >= final->hora){
        if (inicio->minuto > final->minuto){
            return 0;
        }
        return 1;
    }
	*/
}