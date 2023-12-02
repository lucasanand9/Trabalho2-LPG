typedef struct{
	int hora, minuto;
} Horario;

void le_horario( Horario *p );
void mostra_hora( Horario *p );
int conflito_hora(Horario inicio1, Horario final1, Horario inicio2, Horario final2); //verifica se o intervalo de 1 e 2 estao em conflito