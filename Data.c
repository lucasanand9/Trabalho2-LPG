#include "Data.h"
#include <stdio.h>

void le_data( Data *p ){
		printf("Digite o dia: ");
		scanf("%d", &p->dia);
	while( p->dia > 31 || p->dia < 1 ){
		printf("Digite um dia valido\n");
		scanf("%d", &p->dia);
	}
	
	printf("Digite o mes: ");
	scanf("%d", &p->mes);
	while (p->mes > 12 ||  p -> mes < 0){
		printf("Digite um mes valido\n");
		scanf("%d", &p->mes);
	}

	printf("Digite o ano: ");
	scanf("%d", &p->ano);
}

void mostra_data( Data *p ){
	printf("%.2d/%.2d/%.4d\n", p->dia, p->mes, p->ano );
}

int compara_data( Data *data1, Data *data2){
	if(data1->ano != data2->ano){
		return data1->ano - data2->ano;
	}
	if(data1 -> mes != data2 -> mes){
		return data1->mes - data2->mes;
	}
	return data1->dia - data2->dia;
}
