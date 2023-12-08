//gcc main.c Data.c Evento.c Horario.c && ./a.out
#ifdef WIN32
#define PAUSE 1
#else
#define PAUSE 0
#endif
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
    if (v== NULL){
        printf("Erro na alocação de memória\n");
    }
        for( i = 0 ; i < n ; i++ ){
             fscanf( f, "%d %d %d", &v[i].data.dia, &v[i].data.mes, &v[i].data.ano );
             fscanf( f, "%d %d", &v[i].inicio.hora, &v[i].inicio.minuto);
             fscanf( f, "%d %d", &v[i].fim.hora, &v[i].fim.minuto);
             fscanf( f, " %[^\n]", v[i].descricao );
             fscanf( f, " %[^\n]", v[i].local );
	 	}
	 	fclose( f );
	 	printf("%d eventos foram carregados!\n", n);
	 	 if(PAUSE==1)
            system("pause");
         else
            system("read -p \"\nPressione enter para continuar\" ");
	}
	
    do{
        
        system("cls||clear");
        printf("1-Cadastrar\n2-Mostrar todos os eventos da agenda\n3-Mostrar todos os eventos dessa data\n4-Mostrar todos os eventos que tenham essa descrição\n5-Remover Evento\n6-Sair\n");
        scanf("%d", &opcao);
        switch( opcao ){
            case 1://Cadastro
                Evento novoEvento;
                le_evento(&novoEvento);
                if (comparaTodosEventos(v,n,&novoEvento) == 1 && n != 0){
                    printf("Evento esta entrando em conflito com outros eventos\n");
                    if(PAUSE==1)
                        system("pause");
                    else
                        system("read -p \"\nPressione enter para continuar\" ");
                    break;
                }
                n++;
                v = realloc( v, sizeof(Evento) * n );
                v[n-1] = novoEvento;
                printf("Evento adicionado com sucesso\n");
        		if(PAUSE==1)
                    system("pause");
                else
                    system("read -p \"\nPressione enter para continuar\" ");
                break;
                
            case 2://Mostrar todos os eventos da agenda
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{
                    printf("Eventos Cadastrados:\n");
                    for( i = 0 ; i < n ; i++ ){
                        printf("\nEvento %d:\n", i+1 );
                        mostra_evento( &v[i] );
                    }
                }
                if(PAUSE==1)
                    system("pause");
                else
                    system("read -p \"\nPressione enter para continuar\" ");
                break;
            case 3://Mostrar todos os eventos dessa data
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{ //ARRUMAR
                    Data novaData;
                    le_data(&novaData);
                    busca_evento_data(v, n, novaData);
                }

                if(PAUSE==1)
                    system("pause");
                else
                    system("read -p \"\nPressione enter para continuar\" ");
                break;

            case 4: //Mostrar todos os eventos que tenham essa descrição
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{
                    char descricaobusca[150];
                    printf("Digite uma descrição:\n");
                    getchar();
                    fgets(descricaobusca, 150, stdin);
                    busca_descricao(v, descricaobusca, n);
                }
                if(PAUSE==1)
                    system("pause");
                else
                    system("read -p \"\nPressione enter para continuar\" ");
                break;

            case 5: //Remover Evento falta fazer
            int verifica;
                if( n == 0 )
                    printf("Cadastro vazio!\n");
                else{
                    Data removeData;
                    Horario removeHorario;
                    printf("--Digite a data--\n");
                    le_data( &removeData );
                    printf("--Digite um horario--\n");
                    le_horario( &removeHorario );
                    removerEvento(v, n, &removeData, &removeHorario, &verifica);
                    if (verifica == 1){
                        n = n-1;
                        v = realloc(v, sizeof(Evento)*n);
                        printf("Seu evento foi removido\n");
                    }
                }

                if(PAUSE==1)
                    system("pause");
                else
                    system("read -p \"\nPressione enter para continuar\" ");
                break;
        }
    sortEventos(v, n);
    }while( (opcao < 6) & (opcao > 0) );

	 //Salva vetor v no arquivo.
	 f = fopen( "eventos.txt", "wt" );
	 if( f == NULL ){
	 	printf("Erro no arquivo da saida!\n");
	 	return 1;
	 }
	fprintf( f, "%d\n", n );
	for( i = 0 ; i < n ; i++ ){
        fprintf( f, "%.2d %.2d %.4d\n", v[i].data.dia, v[i].data.mes, v[i].data.ano );
        fprintf( f, "%.2d %.2d\n", v[i].inicio.hora, v[i].inicio.minuto);
        fprintf( f, "%.2d %.2d\n", v[i].fim.hora, v[i].fim.minuto);
	 	fprintf( f, "%s\n", v[i].descricao);
        fprintf( f, "%s\n", v[i].local);
	}
	fclose(f);
	
	free(v);

    return 0;
}