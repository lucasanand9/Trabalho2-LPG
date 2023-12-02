#include <stdio.h>
#include <stdlib.h>
#include "Horario.h"
#include "Data.h"
#include "Evento.h"

int main(int argc, char *argv[]) {
	Evento *v = NULL;
	int n = 0;
	int opcao, i;
	
	FILE *f = fopen( "eventos.txt", "rt" );
	if( f == NULL ){
		printf("Arquivo nao encontrado!\n");
	}
	else{
		fscanf( f, "%d", &n );
		v = malloc( sizeof(Evento) * n );
		for( i = 0 ; i < n ; i++ ){
            fscanf( f, "%d %d %d\n", v[i].data.dia, v[i].data.mes, v[i].data.ano );
            fscanf( f, "%d %d\n", v[i].inicio.hora, v[i].inicio.minuto);
            fscanf( f, "%d %d\n", v[i].fim.hora, v[i].fim.minuto);
            fscanf( f, "%s\n", v[i].descricao );
            fscanf( f, "%s\n", v[i].local );
		}
		fclose( f );
		printf("%d eventos foram carregados!\n", n);
		system("pause");
	}
	
    do{
        system("cls||clear");
        printf("1-Cadastrar\n2-Mostrar todos os eventos da agenda\n3-Mostrar todos os eventos dessa data\n4-Mostrar todos os eventos que tenham essa descrição\n5-Remover Evento\n6-Sair\n");
        scanf("%d", &opcao);
        switch( opcao ){
            case 1://Cadastro
                n++;
                v = realloc( v, sizeof(Evento) * n );
                le_produto( &v[n-1] );
                break;
                
            case 2://Mostrar todos os eventos da agenda
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{
                    printf("Eventos Cadastrados:\n");
                    for( i = 0 ; i < n ; i++ ){
                        printf("Evento %d:\n", i+1 );
                        mostra_evento( &v[i] );
                    }
                }
                system("pause");
                break;
            case 3://Mostrar todos os eventos dessa data
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{ //ARRUMAR
                    int dia,mes,ano;
                    printf("Digite um dia:\n");
                    printf("Digite um mês:\n");
                    printf("Digite um ano:\n");
                    scanf("%s",descricaobusca);
                    busca_evento_data(Evento &p[], tam, Data a);
                }
                system("pause");
                break;

            case 4: //Mostrar todos os eventos que tenham essa descrição
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{
                    char descricaobusca[200];
                    printf("Digite uma descrição:\n");
                    scanf("%s",descricaobusca);
                    busca_descricao(Evento &v[],*descricaobusca,n);
                }
                system("pause");
                break;

            case 5: //Remover Evento
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{
                    int dia_remover,mes_remover,ano_remover,hora_remover,minutos_remover;
                    printf("Digite a data:\n");
                    void le_data( Data *p );
                    scanf("%d",&dia_remover);
                    printf("Digite o horário:\n");
                    scanf("%d",&mes_remover);

                    n = n-1;
                }
                system("pause");
                break;
        }
            
    }while( (opcao < 6) & (opcao > 0) );

	// Salva vetor v no arquivo.
	f = fopen( "eventos.txt", "wt" );
	if( f == NULL ){
		printf("Erro no arquivo da saida!\n");
		return 1;
	}
	fprintf( f, "%d\n", n );
	for( i = 0 ; i < n ; i++ ){
        fprintf( f, "%d %d %d\n", v[i].data.dia, v[i].data.mes, v[i].data.ano );
        fprintf( f, "%d %d\n", v[i].horario.hora, v[i].horario.minuto);
        fprintf( f, "%d %d\n", v[i].horario.hora, v[i].horario.minuto);
		fprintf( f, "%s\n", v[i].descricao);
        fprintf( f, "%s\n", v[i].local);
	}
	fclose(f);
	
	free(v);

    return 0;
}