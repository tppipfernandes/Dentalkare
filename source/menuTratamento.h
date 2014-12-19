/**
* \file
* \brief Projeto Modulo Tematico LTIC 2014/2015 "menuTratamento.h"
* \details "menuTratamento.h" implementa o menu dos TRATAMENTOS
* \date 9 dez 2014
*/
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <string.h>

#define N 50
#define tratamentoName "tratamento.txt"

/** Estrutura para Armazenar os dados dos TRATAMENTOS */
typedef struct
{	int idT; /**< id - inteiro com o numero de identificacao do TRATAMENTO */
	char tipo[N]; /**< tipo - string com o tipo do TRATAMENTO */
	int preco; /**< preco - inteiro com o preco do TRATAMENTO */
	int estado; /**< estado - inteiro com o estado do TRATAMENTO */
}tratamento;

/** Define um tipo como sendo uma listaTratamento */
typedef tratamento listaTratamento[N];

/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "tratamento.txt"
* \param t : listaTratamento
*/
void lerTratamento(listaTratamento t)
{
	FILE *fTratamento=fopen(tratamentoName, "r+");
	int i;
	if(fTratamento==NULL)
	{
		printf("\nErro ao abrir ficheiro! <enter para sair>");
		getch();
	}
	for(i=0; i<N; i++)
	{
		fscanf(fTratamento,"%d", &t[i].idT);
		fscanf(fTratamento," %[^\n]s%*c", t[i].tipo);
		fscanf(fTratamento,"%d", &t[i].preco); 
		fscanf(fTratamento,"%d", &t[i].estado);
		
	}
	fclose(fTratamento);
	//printf("\nFicheiro Carregado com Sucesso! <enter para continuar>"); 
}
/**
* \brief Funcao que gravar a estrutura de dados no ficheiro "tratamento.txt"
* \param t : listaTratamento
*/
void gravarTratamento(listaTratamento t)
{
	FILE *fTratamento=fopen(tratamentoName, "w+");
	int i;
	if(fTratamento==NULL)
	{
		printf("\nErro ao gravar ficheiro! <enter para sair>");
		getch();
	}
	for(i=0; i<N; i++)
	{
		if(t[i].estado==1)
		{
			fprintf(fTratamento, "%d\n%s\n%d\n%d\n\n", t[i].idT, t[i].tipo, t[i].preco, t[i].estado);
		}
	}
	fclose(fTratamento);
	//printf("\nFicheiro Gravado com Sucesso! <enter para sair>"); 
}
/**
* \brief Funcao para mostrar todos os TRATAMENTOS gravados em "tratamento.txt"
* \param void
*/
void listarTratamento(listaTratamento t)
{
	int i;
	system("cls");
	printf("\n-------------------------- LISTAR TRATAMENTOS -------------------------\n");
	for(i=0; i<N; i++)
	{
		if(t[i].estado==1)
		{
			printf("\nId Tratamento: [%d]\nTipo de Tratamento: %s\nPreco de Tratamento: %d EUROS\nEstado:%d\n\n",	t[i].idT, t[i].tipo, t[i].preco, t[i].estado);
		}
	}
	printf("\n------------------------------------------------------------------------\n");
	printf("\n\nListagem Concluida! <Enter para Continuar>");
	getch();
}
/**
* \brief Funcao para adicionar um novo TRATAMENTO
* \param t : listaTratamento
*/
void inserirTratamento(listaTratamento t)
{
	int i=0, op, op2;
	
	do //corre ate o ultimo registo(vai para o primeiro indice onde t[i].estado=0)
	{
		i++;
	}while(t[i].estado>0 && t[i].estado<2);
	do
	{
		system("cls");
		printf("\n[1]-Inserir Tratamento ou [0]-Sair? "); scanf("%d%*c", &op2);
		if(op2==0)
			break;
		printf("\n----------------------------------------------------\n");
		printf("\nID Tratamento: [%d]\n", i);
		t[i].idT=i;
		printf("Tipo de Tratamento: "); gets(t[i].tipo);
		printf("Preco de Tratamento: "); scanf("%d%*c", &t[i].preco);
		t[i].estado=1;
		i++;
		while(t[i].estado>0 && t[i].estado<2)
			i++;
		printf("\n\nQuer inserir outro tratamento? [1]-SIM [0]-NAO: "); scanf("%d%*c", &op);
	}while(op==1);
	getch();
}
/**
* \brief Funcao para alterar um determinado TRATAMENTO
* \param t : listaTratamento
*/
int alterarTratamento(listaTratamento t)
{
	int alt, op, op2, confere;
	do
	{
		system("cls");
		printf("\nQual o Id do Tratamento para alterar? [0]-SAIR: "); scanf("%d%*c", &alt);
		if(alt==0) 
			break;
		t[alt].idT=alt;
		if(alt==t[alt].idT)
		{
			printf("\n----------------------------------------------");
			printf("\nId Tratamento: [%d]", alt);
			printf("\nTipo de Tratamento: %s", t[alt].tipo);
			printf("\nPreco de Tratamento: %d EUROS", t[alt].preco);
			printf("\nEstado: %d", t[alt].estado);
			printf("\n----------------------------------------------");
		}
		else
			printf("\nERRO! Id do Tratamento nao existe.");	
		printf("\n\nQuer editar este Tratamento? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
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
				switch(op)
				{
					case 1: printf("Tipo de Tratamento: "); gets(t[alt].tipo); break;
					case 2: printf("Preco do Tratamento: "); scanf("%d%*c", &t[alt].preco); break;
					case 0: return 0; break;
					default: printf("\nOpcao Invalida\n"); break;
				}
			}while(op>0 || op<2);
			t[alt].estado=1;
			printf("\n\nTratamento alterado com Sucesso!");
		}
		else
			break;
		printf("\n\nQuer editar outro Tratamento? [1]-SIM [0]-NAO:  ");	scanf("%d%*c", &op2);
	}while(op2==1);
	getch();
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
		t[eli].idT=eli;
		if(eli==t[eli].idT)
		{
			printf("\n----------------------------------------------");
			printf("\nId Tratamento: [%d]", eli);
			printf("\nTipo de Tratamento: %s", t[eli].tipo);
			printf("\nPreco de Tratamento: %d EUROS", t[eli].preco);
			printf("\nEstado: %d", t[eli].estado);
			printf("\n----------------------------------------------");
		}
		printf("\n\nQuer eliminar este Tratamento? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
		if(confere==1)
		{
			t[eli].estado=0;
			printf("\n\nTratamento Eliminado com Sucesso!");
		}
		printf("\n\nQuer eliminar outro Tratamento? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &op);
	}while(op==1);
	getch();
}
/**
* \brief Funcao para mostrar menu TRATAMENTO
* \param void
*/
void menuTratamento(void)
{
	listaTratamento t;
	char op;
	int i;
	//Inicializar estrutura TRATAMENTO
	for (i=0; i<N; i++)
    {
		//t[i].idT=0;
    	t[i].estado=0;
    }
    lerTratamento(t);
	do
	{
		system("cls");
		printf("\n--------------------- MENU GESTAO TRATAMENTO ---------------------");
		printf("\n\n	[1] - Inserir Novo Registo");
		printf("\n\n	[2] - Alterar Registo");
		printf("\n\n	[3] - Eliminar Registo");
		printf("\n\n	[4] - Mostrar Todos Registos");
		printf("\n\n	[0] - Voltar Menu Principal");
		printf("\n------------------------------------------------------------------");
		printf("\n\nQual Opcao: ");	scanf("%s%*c", &op);
		switch(op)
		{
			case '1': inserirTratamento(t); break;
			case '2': alterarTratamento(t); break;
			case '3': eliminarTratamento(t); break;
			case '4': listarTratamento(t); break;
			case '0': gravarTratamento(t); return; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while (op!='0' || op=='a' || op=='A');
	getch();
}
