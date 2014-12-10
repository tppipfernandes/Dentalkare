/* !
* \ file
* \ brief Projeto Modulo Tematico LTIC 2014/2015 "menuTratamento.h"
* \ details "menuTratamento.h" implementa o menu Tratamento
* \ author Susana Estevao (a48584)
* \ date 9 dez 2014
* \ bug sem erros detetados
* \ version 0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 50 	//Numero maximo de Registos
#define tratamentoName "tratamentos.txt"
/**
* estrututa para armazenar os dados de um TRATAMENTO
*/
typedef struct
{
	int id; /**< id - inteiro com o numero de identificacao do TRATAMENTO */
	char tipo[N]; /**< tipo - string com o tipo do TRATAMENTO */
	float preco; /**< preco - inteiro com o preco do TRATAMENTO */
	int estado; /**< estado - inteiro com o estado do TRATAMENTO */
}tratamento;
/** define um tipo como sendo um lista de TRATAEMENTOS */
typedef tratamento listaTratamento[N];
listaTratamento t;
/**
* \brief Funcao que inicializa a estrutura de dados TRATAMENTOS
* \ param void
*/
void initTratamento(listaTratamento t) // funcao para inicializar a estrutura de dados
{
    int i;
    for (i=0; i<N; i++)
    {
         t[i].id=0;
         t[i].estado=0;
    }
    return;
}
/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "tratamentos.txt"
* \param t : listaTratamento
* \return void
*/
void lerTratamento(listaTratamento t)
{
	FILE *fileTratamento=fopen(tratamentoName, "r+");
	int i;
	if(fileTratamento==NULL)
	{
		printf("\nErro ao abrir ficheiro!");
		getch(); return;
	}
	for(i=0; i<N; i++)
	{
		fscanf(fileTratamento,"%d", &t[i].id);
		fscanf(fileTratamento," %[^\n]s%*c", t[i].tipo);
		fscanf(fileTratamento,"%f", &t[i].preco); 
		fscanf(fileTratamento,"%d", &t[i].estado);
		
	}
	//fread(t, sizeof(tratamento), N, fileTratamento);
	fclose(fileTratamento);
	printf("\nFicheiro Carregado com Sucesso! <enter para sair>"); getch();
}
/**
* \brief Funcao que gravar a estrutura de dados no ficheiro "tratamentos.txt"
* \param t : listaTratamento
* \return void
*/
void gravarTratamento(listaTratamento t)
{
	FILE *fileTratamento=fopen(tratamentoName, "w+");
	int i;
	if(fileTratamento==NULL)
	{
		printf("\nErro ao gravar ficheiro! <enter para sair>");
		getch(); return;
	}
	for(i=0; i<N; i++)
	{
		if(t[i].estado==1)
		{
			fprintf(fileTratamento,"%d\n%s\n%.2f\n%d\n\n",
					t[i].id, t[i].tipo, t[i].preco, t[i].estado);
		}

	}
	//fwrite(t, sizeof(tratamento), N, fileTratamento);
	fclose(fileTratamento);
	printf("\nFicheiro Gravado com Sucesso! <enter para sair>"); 
	getch();
}
/**
* \brief Funcao para mostrar todos os TRATAMENTOS gravados em "tratamentos.txt"
* \param void
* \return void
*/
void mostrarTratamento(listaTratamento t)
{
	int i;
	system("cls");
	for(i=0; i<N; i++)
	{
		if(t[i].estado==1)
		{
			printf("Id Tratamento: %d\nTipo de Tratamento: %s\nPreco de Tratamento: %.2f EUROS\nEstado:%d\n\n",
					t[i].id, t[i].tipo, t[i].preco, t[i].estado);
		}
	}
	printf("\n\nListagem Concluida! <Enter para Continuar>");
	getch();
}
/**
* \brief Funcao para adicionar um novo TRATAMENTO
* \param t : listaTratamento
*/
void inserirTratamento(listaTratamento t)
{
	int i=0, op;
	system("cls");
	do //corre ate o ultimo registo(vai para o primeiro indice onde t[i].estado=0)
	{
		i++;
	}while(t[i].estado>0 && t[i].estado<2);
	do
	{
		printf("\nID Tratamento: %d\n", i);
		t[i].id=i;
		printf("Tipo de Tratamento: "); gets(t[i].tipo);
		printf("Preco de Tratamento: "); scanf("%f%*c", &t[i].preco);
		t[i].estado=1;
		i++;
		while(t[i].estado>0 && t[i].estado<2)
			i++;
		printf("\n\nQuer inserir outro tratamento? [1]-SIM [0]-NAO: "); scanf("%d%*c", &op);
	}while(op==1);
}
/**
* \brief Funcao para alterar um determinado TRATAMENTO
* \param t : listaTratamento
*/
int alterarTratamento(listaTratamento t)
{
	int i, alt, op, op2, confere;
	do
	{
		system("cls");
		printf("\nQual o Id do Tratamento para alterar? [0]-SAIR: "); scanf("%d%*c", &alt);
		if(alt==0) 
			break;
		t[alt].id=alt;
		if(alt==t[alt].id)
		{
			printf("\n----------------------------------------------");
			printf("\nId Tratamento: %d", alt);
			printf("\nTipo de Tratamento: %s", t[alt].tipo);
			printf("\nPreco de Tratamento: %.2f EUROS", t[alt].preco);
			printf("\nEstado: %d", t[alt].estado);
			printf("\n----------------------------------------------");
		}
		else
			printf("\nERRO! Id do Tratamento nao existe.");	
		printf("\n\nQuer mesmo editar este Tratamento? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
		if(confere==1)
		{
			printf("\n\nEditar Tratamento ID: [%d]", alt);
			do
			{
				printf("\n\nPretende alterar que campos: ");
				printf("\n[1] - Tipo de Tratamento");
				printf("\n[2] - Preco do Tratamento");
				printf("\n[0] - Nenhum");
				printf("\n\nQual a sua opcao: "); scanf("%d%*c", &op);
				if(op==1)	
				{	
					printf("Tipo de Tratamento: "); gets(t[alt].tipo); 
				}
				else
					if(op==2)	
					{	
						printf("Preco do Tratamento: "); scanf("%f", &t[alt].preco); 
					}
					else
						if(op==0) 
							return 0; 									
						else
							printf("\nOpcao Invalida\n");
			}while(op==0 && op>0 || op<2);
			t[alt].estado=1;
			printf("\n\nTratamento alterado com Sucesso!");
		}
		else
			break;
		printf("\n\nQuer editar outro Tratamento? [1]-SIM [0]-NAO:  ");	scanf("%d%*c", &op2);
	}while(op2==1);
}
/**
* \brief Funcao para eliminar um determinado TRATAMENTO
* \param t : listaTratamento
*/
void eliminarTratamento(listaTratamento t)
{
	int i, eli, confere, op;
	do
	{
		system("cls");
		printf("\nQual o Id do Tratamento para eliminar? [0]-Sair: "); scanf("%d",&eli);
		if(eli==0) 
			break;
		t[eli].id=eli;
		if(eli==t[eli].id)
		{
			printf("\n----------------------------------------------");
			printf("\nId Tratamento: %d", eli);
			printf("\nTipo de Tratamento: %s", t[eli].tipo);
			printf("\nPreco de Tratamento: %.2f EUROS", t[eli].preco);
			printf("\nEstado: %d", t[eli].estado);
			printf("\n----------------------------------------------");
		}
		printf("\n\nQuer mesmo eliminar este Tratamento? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
		if(confere==1)
		{
			t[eli].estado=0;
			printf("\n\nTratamento Eliminado com Sucesso!");
		}
		printf("\n\nQuer eliminar outro Tratamento? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &op);
	}while(op==1);
}
/**
* \brief Funcao para mostrar menu TRATAMENTO
* \param void
* \return void
*/
void menuTratamento(void)
{
	listaTratamento t;
	int op;
	initTratamento(t);
	do
	{
		system("cls");
		printf("\n----- MENU GESTAO TRATAMENTO -------");
		printf("\n\n[1] - Ler Ficheiro");
		printf("\n\n[2] - Gravar Ficheiro");
		printf("\n\n[3] - Inserir Novo Registo");
		printf("\n\n[4] - Alterar Registo");
		printf("\n\n[5] - Eliminar Registo");
		printf("\n\n[6] - Mostrar Todos Registos");
		printf("\n\n[0] - Voltar Menu Principal");
		printf("\n-------------------------------------");
		printf("\n\nQual Opcao: ");	scanf("%d%*c", &op);
		switch(op)
		{
			case 1: lerTratamento(t); break;
			case 2: gravarTratamento(t); break;
			case 3: inserirTratamento(t); break;
			case 4: alterarTratamento(t); break;
			case 5: eliminarTratamento(t); break;
			case 6: mostrarTratamento(t); break;
			case 0: return; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while (op!=0);
	getch();
}
