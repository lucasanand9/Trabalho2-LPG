typedef struct{
	int hora, minuto;
} Horario;

void le_horario( Horario *p );
void mostra_hora( Horario *p );
int compara_hora(Horario *hora1, Horario *hora2);
int valida_hora(Horario *inicio, Horario *final);