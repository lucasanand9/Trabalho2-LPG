typedef struct{
	int dia, mes, ano;
} Data;

void le_data( Data *p );
void mostra_data( Data *p );
int compara_data( Data *data1, Data *data2);
