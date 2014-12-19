/** 
* \file
* \brief Projeto Modulo Tematico LTIC 2014/2015 "menuConsulta.h"
* \details "menuConsulta.h" implementa o menu das CONSULTAS
* \date 9 dez 2014
*/
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <string.h>

#define N 50
#define consultaName "consulta.txt"

/** Estrutura para trabalhar as DATAS */
typedef struct
{	int dia; /**< dia - inteiro com o dia */
	int mes; /**< mes - inteiro com o mes */
	int ano; /**< ano - inteiro com o ano */
}d;

/** Estrutura para trabalhar as HORAS */
typedef struct
{	int h; /**< h - inteiro com a hora */
	int m; /**< m - inteiro com os minutos */
}hora;

/** Estrutura para Armazenar os dados das CONSULTAS */
typedef struct
{	int idC; /**< idC - inteiro com o numero de identificacao da CONSULTA */
	int idP; /**< idPac - inteiro com o numero de identificacao do PACIENTE */
	int idT; /**< idTrata - inteiro com o numero de identificacao do TRATAMENTO */
	d dConsulta; /**< data - data da CONSULTA */ 
	hora hInicial; /**< hInicial - hora da CONSULTA */
	hora hFinal; /**< hFinal - hora da CONSULTA */
	char duracao[5]; /**< duracao - duracao da CONSULTA */
	int preco; /**< preco - inteiro com o preco da CONSULTA */
	int estado; /**< estado - int para o estado da CONSULTA */
}consulta;

/** Define um tipo como sendo uma listaConsulta */
typedef consulta listaConsulta[N];

/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "consulta.txt"
* \param c : listaConsulta
*/
void lerConsulta(listaConsulta c)
{
	FILE *fConsulta=fopen(consultaName,"r+");
	int i;
	if(fConsulta==NULL)
	{
		printf("\nErro ao abrir ficheiro! <Enter para Sair>");
		getch();
	}
	for(i=0; i<N; i++)
	{
		fscanf(fConsulta,"%d\n", &c[i].idC);
		fscanf(fConsulta,"%d\n", &c[i].idP);
		fscanf(fConsulta,"%d\n", &c[i].idT);
		fscanf(fConsulta,"%d-%d-%d\n", &c[i].dConsulta.dia, &c[i].dConsulta.mes, &c[i].dConsulta.ano);
		fscanf(fConsulta,"%2d:%2d\n", &c[i].hInicial.h, &c[i].hInicial.m);
		fscanf(fConsulta,"%2d:%2d\n", &c[i].hFinal.h, &c[i].hFinal.m);
		fscanf(fConsulta," %[^\n]s%*c", c[i].duracao);
		fscanf(fConsulta,"%d\n", &c[i].preco); 
		fscanf(fConsulta,"%d\n", &c[i].estado);
	}
	fclose(fConsulta);
	//printf("\nFicheiro Carregado com Sucesso! <Enter para Continuar>"); 
}
/**
* \brief Funcao que gravar a estrutura de dados no ficheiro "consulta.txt"
* \param c : listaConsulta
*/
void gravarConsulta(listaConsulta c)
{
	FILE *fConsulta=fopen(consultaName,"w+");
	int i;
	if(fConsulta==NULL)
	{
		printf("\nErro ao gravar ficheiro! <enter para continuar>");
		getch();
	}
	for(i=0; i<N; i++)
	{
		if(c[i].estado==1)
		{
			fprintf(fConsulta,"%d\n%d\n%d\n%d-%d-%d\n%2d:%2d\n%2d:%2d\n%s\n%d\n%d\n\n",
			c[i].idC, c[i].idP, c[i].idT, c[i].dConsulta.dia, c[i].dConsulta.mes, c[i].dConsulta.ano, c[i].hInicial.h, c[i].hInicial.m, c[i].hFinal.h, c[i].hFinal.m, c[i].duracao, c[i].preco, c[i].estado);
		}
	}
	fclose(fConsulta);
	//printf("\nFicheiro Gravado com Sucesso! <enter para continuar>"); 
}
/**
* \brief Funcao que mostra todas as CONSULTAS gravadas em "consulta.txt"
* \param c : listaConsulta
*/
void listarConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int i;
	system("cls");
	printf("\n------------------- LISTAR CONSULTAS ----------------------\n");
	for(i=0; i<N; i++)
	{
		if(c[i].estado==1)
		{	
			printf("\nId Consulta: [%d]\nId Paciente: %d\nId Tratamento: %d\nData Consulta: %d-%d-%d\nHora Inicial da Consulta: %2d:%2d\nHora Final da Consulta: %2d:%2d\nDuracao Consulta: %s\nPreco Consulta: %d EUROS\nEstado:%d\n\n",
			c[i].idC, c[i].idP, c[i].idT, c[i].dConsulta.dia, c[i].dConsulta.mes, c[i].dConsulta.ano, c[i].hInicial.h, c[i].hInicial.m, c[i].hFinal.h, c[i].hFinal.m, c[i].duracao, c[i].preco, c[i].estado);
		}
	}
	printf("\n-----------------------------------------------------------\n");
	printf("\n\nListagem Concluida! <Enter para Continuar>");getch();
}

/**
* \brief adicionar uma nova CONSULTA
* \param c : listaConsulta
*/
void inserirConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int i, idPac=0, idTrata=0, dura, j;
	char op1, op2, op, op3;
	do//corre ate o ultimo registo(vai para o primeiro indice onde c[i].estado=0)
	{
		i++;
	}while(c[i].estado>0 && c[i].estado<2);
	do
	{
		system("cls");
		printf("\n[1]-Inserir Consulta ou [0]-Sair? "); scanf("%d%*c", &op3);
		if(op3==0)
			break;
		printf("\n------------------------------------------------------\n");
		printf("\nID Consulta: [%d]\n", i);
		c[i].idC=i;
		do		
		{
			printf("\n---------------------------------\n");
			printf("\nInsira o Id do Paciente: "); scanf("%d%*c", &idPac);
			for (j=0; j<N; j++)
			{
				if(p[j].idP==idPac && p[j].estado==1)  // verifica se p.telemoveL e igual a tele ou nao
		     	{
					printf("\nId Paciente: %d", idPac);
					c[i].idP=idPac;
					printf("\nNome do Paciente: %s %s", p[j].nome, p[j].apelido);
					printf("\nTelemovel do Paciente: %d", p[j].telemovel);
				}
			}
			printf("\n---------------------------------\n");
			printf("\nQuer este paciente? [1]-SIM [0]-NAO:  ");	scanf("%s%*c", &op1);
		}while(op1=='0' || op1=='a' || op1=='A');
		do
		{
			printf("\n---------------------------------\n");
			printf("\nInsira o Id de Tratamento: "); scanf("%d%*c", &idTrata);
			for (j=0; j<N; j++)
			{
				if(t[j].idT==idTrata && t[j].estado==1)  // verifica se p.telemoveL e igual a tele ou nao
		     	{
					printf("\nId Tratamento: %d", idTrata);
					c[i].idT=idTrata;
					printf("\nTipo de Tratamento: %s", t[j].tipo);
					printf("\nPreco do Tratamento: %d EUROS", t[j].preco);
					c[i].preco=t[j].preco;
				}
			}
			printf("\n---------------------------------\n");
			printf("\nQuer este Tratamento? [1]-SIM [0]-NAO:  "); scanf("%s%*c", &op2);
		}while(op2=='0' || op1=='a' || op1=='A');		
		printf("\nData Consulta: \n"); 
        printf("Ano <aaaa>: "); scanf("%d%*c", &c[i].dConsulta.ano);
        printf("Mes <mm>: "); scanf("%d%*c", &c[i].dConsulta.mes);
        printf("Dia <dd>: "); scanf("%d%*c", &c[i].dConsulta.dia);
        printf("\nHora Inicial da Consulta: \n");
        printf("Hora <hh>: "); scanf("%d", &c[i].hInicial.h);
        printf("Minuto <mm>: "); scanf("%d", &c[i].hInicial.m);
        printf("\nHora Final da Consulta: \n");
        printf("Hora <hh>: "); scanf("%d", &c[i].hFinal.h);
        printf("Minuto <mm>: "); scanf("%d", &c[i].hFinal.m);
        /*dura=duracaoConsulta(c[i].hInicial.h, c[i].hInicial.m, c[i].hFinal.h, c[i].hFinal.m);
		printf("\nDuracao da Consulta: %d:%d.", dura/60, dura%60);
		c[i].duracao=dura;*/
		printf("\nDuracao da Consulta <hh>:<mm>: "); scanf("%s%*c", &c[i].duracao);
		printf("\nPreco da consulta: %d EUROS", c[i].preco); //scanf("%d", &c[i].preco);
        c[i].estado=1;
        printf("\n\nConsulta Inserida com sucesso!");
        
        i++;
		while(c[i].estado>0 && c[i].estado<2)
			i++;
		printf("\n\nQuer inserir outra consulta? [1]-SIM [0]-NAO: "); scanf("%s%*c", &op);
	}while(op=='1' && op1=='a' || op1=='A');
}
/**
* \brief Funcao para alterar uma determinada CONSULTA
* \param c : listaConsulta
*/
int alterarConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int alt=0, confere;
	char op, op1, op2, idPac, idTrata, dura;
	do
	{
		system("cls");
		printf("\nQual o Id da Consulta para alterar? [0]-SAIR: "); scanf("%d%*c",&alt);
		if(alt==0)
			break;
		c[alt].idC=alt;
		if(alt==c[alt].idC)
		{
			printf("\n----------------------------------------------");
			printf("\nId Consulta: %d", alt);
			printf("\nId Paciente: %d", c[alt].idP);
			printf("\nId Tratamento: %d", c[alt].idT);
			printf("\nData Consulta: %d-%d-%d", c[alt].dConsulta.dia, c[alt].dConsulta.mes, c[alt].dConsulta.ano);
			printf("\nHora Inicial da Consulta: %2d:%2d", c[alt].hInicial.h, c[alt].hInicial.m);
			printf("\nHora Final da Consulta: %2d:%2d", c[alt].hFinal.h, c[alt].hFinal.m);
			printf("\nDuracao Consulta: %s", c[alt].duracao);
			printf("\nPreco Consulta: %d EUROS", c[alt].preco);
			printf("\nEstado:%d", c[alt].estado);
			printf("\n----------------------------------------------");
		}
		else
			printf("\nERRO! Id da Consulta nao existe.");	
		printf("\n\nQuer editar esta Consulta? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
		if(confere==1)
		{
			printf("\n\nEditar Consulta ID: [%d]", alt);
			do
			{
				printf("\n\nPretende alterar que campos: ");
				printf("\n[1] - Id Paciente");
				printf("\n[2] - Id Tratamento");
				printf("\n[3] - Data Consulta");
				printf("\n[4] - Hora Inicial da Consulta");
				printf("\n[5] - Hora Final da Consulta");
				printf("\n[6] - Duracao da Consulta");
				printf("\n[7] - Preco do Tratamento");
				printf("\n[0] - Nenhum");
				printf("\n\nQual a sua opcao: "); scanf("%s%*c", &op);
				switch(op)
				{
					case 1: do
							{
								printf("\nInsira o Id do Paciente: "); scanf("%d%*c", &idPac);
								c[alt].idP=idPac;
								printf("\nId Paciente: %d", idPac);
								printf("\nNome do Paciente: %s", p[idPac].nome);
								printf("\nQuer este Paciente? [1]-SIM [2]-NAO:  ");	scanf("%d%*c", &op1);
							}while(op1==2);
							break;
					case 2: do
							{
								printf("\nInsira o Id do Tratamento: "); scanf("%d%*c", &idTrata);
								c[alt].idT=idTrata;
								printf("\nId Tratamento: %d", idTrata);
								printf("\nTipo do Tratamento: %s", t[idTrata].tipo);
								printf("\nPreco de Tratamento: %d", t[idTrata].preco);
								printf("\nQuer este Tratamento? [1]-SIM [2]-NAO:  ");	scanf("%d%*c", &op2);
							}while(op2==2);
							c[alt].preco=t[idTrata].preco;
							break;
					case 3: printf("\nData Consulta: \n"); 
			        		printf("Ano <aaaa>: ");	scanf("%d%*c", c[alt].dConsulta.ano);
			        		printf("Mes <mm>: "); scanf("%d%*c", c[alt].dConsulta.mes);
			        		printf("Dia <dd>: "); scanf("%d%*c", c[alt].dConsulta.dia);
			        		break;
					case 4: printf("\nHora Inicial da Consulta: \n");
		        			printf("Hora <hh>: "); scanf("%d", c[alt].hInicial.h);
		        			printf("Minuto <mm>: "); scanf("%d", c[alt].hInicial.m); 
		        			break;
					case 5: printf("\nHora Final da Consulta: \n");
		        			printf("Hora <hh>: "); scanf("%d", c[alt].hFinal.h);
		        			printf("Minuto <mm>: "); scanf("%d", c[alt].hFinal.m); 
		        			break;
					case 6: printf("\nDuracao Consulta <hh>:<mm>: "); scanf("%s%*c", c[alt].duracao);
	        				break;
					case 7: printf("\nPreco da Consulta"); scanf("%d*c", &c[alt].preco); break;
					case 0: return 0;
					default: printf("\nOpcao Invalida!");
				}
			}while(op=='0' && op>'0' || op<'8');
			c[alt].estado=1;
			printf("\n\nConsulta alterada com Sucesso!");
		}
		else
			break;
		printf("\n\nQuer editar outra Consulta? [1]-SIM [0]-NAO:  "); scanf("%s%*c", &op2);
	}while(op2=='1');
}
/**
* \brief Funcao para eliminar uma determinada CONSULTA
* \param c: listaConsulta 
*/
void eliminarConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int eli=0, confere, op;
	do
	{
		system("cls");
		printf("\nQual o Id da Consulta para eliminar [0]-SAIR: "); scanf("%d%*c",&eli);
		if(eli==0)
			break;
		c[eli].idC=eli;
		if(c[eli].idC==eli)
		{
			printf("\n----------------------------------------------");
			printf("\nId Consulta: %d", eli);
			printf("\nId Paciente: %d", c[eli].idP);
			c[eli].idP=p[eli].idP;
			//printf("\nNome do Paciente: %s", p[eli].nome);
			printf("\nId Tratamento: %d", c[eli].idT);
			c[eli].idT=t[eli].idT;
			//printf("\nTipo de Tratamento: %s", t[eli].tipo);
			printf("\nData Consulta: %d-%d-%d", c[eli].dConsulta.dia, c[eli].dConsulta.mes, c[eli].dConsulta.ano);
			printf("\nHora Inicial da Consulta: %d:%d", c[eli].hInicial.h, c[eli].hInicial.m);
			printf("\nHora Final da Consulta: %d:%d", c[eli].hFinal.h, c[eli].hFinal.m);
			printf("\nDuracao da Consulta: %s", c[eli].duracao);
			printf("\nPreco da Consulta: %d EUROS", c[eli].preco);
			printf("\nEstado: %d", c[eli].estado);
			printf("\n----------------------------------------------");
		}
		else
			printf("\nERRO! Id da Consulta nao existe.");
		printf("\n\nQuer eliminar esta Consulta? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
		if(confere==1)
		{
			c[eli].estado=0;
			printf("\n\nConsulta Eliminada com Sucesso!");
		}
		printf("\n\nQuer eliminar outra Consulta? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &op);
	}while(op==1);
}
/**
* \brief Funcao para mostrar o menu da CONSULTA
* \param void 
*/
void menuConsulta(void)
{	
	char op;
	int i;
	listaConsulta c;
	listaPaciente p; 
	listaTratamento t;
	//Inicializar estrutura CONSULTA
	for (i=0; i<N; i++)
    {
         //c[i].idC=0;
         c[i].estado=0;
    }
    lerConsulta(c);
    lerPaciente(p);
    lerTratamento(t);
	do
	{
		system("cls");
		printf("\n--------------- MENU GESTAO CONSULTA ---------------");
		printf("\n\n	[1] - Marcacao de Consulta");
		printf("\n\n	[2] - Eliminar Consulta");
		printf("\n\n	[3] - Alterar Consulta");
		printf("\n\n	[4] - Mostrar todas as Consultas");
		printf("\n\n	[0] - Voltar Menu Principal");
		printf("\n----------------------------------------------------");
		printf("\n\nQual a opcao: ");	scanf("%s%*c", &op);
		switch(op)
		{
			case '1': inserirConsulta(c, p, t); break;
			case '2': eliminarConsulta(c, p, t); break;
			case '3': alterarConsulta(c, p, t); break;
			case '4': listarConsulta(c, p, t); break;
			case '0': gravarConsulta(c); return; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while(op!='0' || op=='a' || op=='A');
	getch();
}
