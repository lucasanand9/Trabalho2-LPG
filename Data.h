#ifndef DATA_H
#define DATA_H

typedef struct Data{
	int dia, mes, ano;
} Data;

void le_data( Data *p );
void mostra_data( Data *p );
int compara_data( Data *data1, Data *data2);

#endif