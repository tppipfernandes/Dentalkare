/**
* \file
* \brief Projeto Modulo Tematico LTIC 2014/2015 "menuGestao.h"
* \details "menuGestao.h" implementa o menu Gestao
* \date 9 dez 2014
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define N 50
/**
* \brief Funcao para pesquisar por idades dos PACIENTES
* \param p : listaPaciente
*/
int pesquisaIdade(listaPaciente p)
{
	int ida, i;
	system("cls");
	printf("\n------------------- PESQUISA POR IDADES -------------------\n"); 
	printf("\nQual a idade do Paciente?  [0]-SAIR: "); scanf("%d%*c", &ida);
	//if(ida==0)
		//break;
	printf("\n------------------- DADOS ENCONTRADOS --------------------------\n");
	for (i=0; i<N; i++)
	{
    	if(p[i].idade==ida && p[i].estado==1)  // verifica se p.telemove e igual a tele ou nao
     	{
			printf("\nId Paciente: %d", p[i].idP);
			printf("\nNome do Paciente: %s %s", p[i].nome, p[i].apelido);
			printf("\nMorada: %s", p[i].morada);
			printf("\nE-mail: %s", p[i].email);
			printf("\nTelemovel: %9d", p[i].telemovel);
			printf("\nData Nascimento: %d-%d-%d", p[i].dNascimento.dia, p[i].dNascimento.mes, p[i].dNascimento.ano);
			printf("\nIdade: %d\n", p[i].idade);
     	}
	}
	printf("\n------------------------------------------------------------\n");
	getch();
}
/**
* \brief Funcao para pesquisar pelo telemovel dos PACIENTES
* \param p : listaPaciente
*/
int pesquisaTelemovel(listaPaciente p)
{
	int tele=0, i;
	system("cls");
	printf("\n----------------- PESQUISA PELO TELEMOVEL ------------------\n"); 
	printf("\nQual o telemovel do Paciente?  [0]-SAIR: "); scanf("%d%*c", &tele);
	//if(tele==0)
		//break;
	printf("\n---------------- DADOS ENCONTRADOS -------------------------\n");
	for (i=0; i<N; i++)
	{
		if(p[i].telemovel==tele && p[i].estado==1)  // verifica se p.telemoveL e igual a tele ou nao
     	{
			printf("\nId Paciente: %d", p[i].idP);
			printf("\nNome do Paciente: %s %s", p[i].nome, p[i].apelido);
			printf("\nMorada: %s", p[i].morada);
			printf("\nE-mail: %s", p[i].email);
			printf("\nTelemovel: %9d", p[i].telemovel);
			printf("\nData Nascimento: %d-%d-%d", p[i].dNascimento.dia, p[i].dNascimento.mes, p[i].dNascimento.ano);
			printf("\nIdade: %d\n", p[i].idade);
		}
	}
	printf("\n------------------------------------------------------------\n");
	getch();
}
/**
* \brief Funcao para pesquisar por nome dos PACIENTES
* \param p : listaPaciente
*/
int pesquisaNome(listaPaciente p)
{
	int i, op;
	char n[N], a[N];
	system("cls");
	do
	{
		system("cls");
		printf("\n---------------------- PESQUISA POR NOME ----------------------\n"); 
		printf("\n	[1] - Pesquisar por nome");
		printf("\n	[2] - Pesquisar por apelido");
		printf("\n	[0] - Sair");
		printf("\n----------------------------------------------------------------\n");
		printf("\nQual a sua opcao: "); scanf("%d%*c", &op);
		
		switch(op)
		{
			case 1: printf("\n\nIntroduza o nome: "); scanf("%s%*c", &n);
					printf("\n------------------- DADOS ENCONTRADOS --------------------------\n");
					for (i=0; i<N; i++)
					{
						if(p[i].nome==n && p[i].estado==1) 	 // verifica se p.nome e igual a n ou nao
				     	{
							printf("\nId Paciente: %d", p[i].idP);
							printf("\nNome do Paciente: %s %s", p[i].nome, p[i].apelido);
							printf("\nMorada: %s", p[i].morada);
							printf("\nE-mail: %s", p[i].email);
							printf("\nTelemovel: %9d", p[i].telemovel);
							printf("\nData Nascimento: %d-%d-%d", p[i].dNascimento.dia, p[i].dNascimento.mes, p[i].dNascimento.ano);
							printf("\nIdade: %d\n", p[i].idade);
				     	}
					}
					getch();
					break;
			case 2: printf("\n\nIntroduza o apelido: "); scanf("%s%*c", &a);
					printf("\n------------------- DADOS ENCONTRADOS --------------------------\n");
					for (i=0; i<N; i++)
					{
						if(p[i].apelido==a && p[i].estado==1) 	 // verifica se p.nome e igual a n ou nao
				     	{
							printf("\nId Paciente: %d", p[i].idP);
							printf("\nNome do Paciente: %s %s", p[i].nome, p[i].apelido);
							printf("\nMorada: %s", p[i].morada);
							printf("\nE-mail: %s", p[i].email);
							printf("\nTelemovel: %9d", p[i].telemovel);
							printf("\nData Nascimento: %d-%d-%d", p[i].dNascimento.dia, p[i].dNascimento.mes, p[i].dNascimento.ano);
							printf("\nIdade: %d\n", p[i].idade);
				     	}
					}
					break;
					getch();
			case 0: return(0); getch(); break;
			default: printf("\nOpcao Invalida"); getch(); break;
		}
		printf("\n---------------------------------------------------------------\n");
	}while(op!=0);
}
/**
* \brief Funcao para calcular a media de idades dos PACIENTES
* \param p : listaPaciente
*/
int mediaIdades(listaPaciente p)
{
	int i, idades=0, pac=0, minimo, maximo=0;
	float mediaIdades;
	system("cls");
	printf("\n------------------ MEDIA DE IDADES -------------------\n"); 
	for (i=0; i<=N; i++) 			//percorre pacientes
    {
    	if(p[i].estado==1)
    	{
         	idades=idades+p[i].idade; 	//soma idades dos pacientes
         	pac++; 						//incrementa numero de pacientes
    	}
    	if (p[i].idade==0)   
			break;
    	if (p[i].idade>maximo && p[i].estado==1) 
			maximo=p[i].idade;
		if (p[i].idade<minimo && p[i].estado==1) 
			minimo=p[i].idade;
    }
    mediaIdades=idades/pac; 			//calcula a media
    printf("\n\nA idade maxima dos pacientes e de: %d anos.", maximo);
    printf("\n\nA idade minima dos pacientes e de: %d anos.", minimo);
	printf("\n\nA Media de idades dos pacientes e de: %.2f anos.", mediaIdades);
	printf("\n------------------------------------------------------\n");
	getch();
}
/**
* \brief Funcao para pesquisar pelo tipo de TRATAMENTO
* \param t : listaTratamento
*/
int pesquisaTipo(listaTratamento t)
{
	int i;
	char tip[50];
	system("cls");
	printf("\n--------------- PESQUISA POR TIPO TRATAMENTO ------------------\n"); 
	printf("\nQual o tipo de tratamento? [0]-SAIR: "); scanf("%c%*c", &tip);
	//if(tip=='0')
		//break;
	printf("\n------------------- DADOS ENCONTRADOS --------------------------\n");
	for (i=0; i<N; i++)
	{
    	if(t[i].tipo==tip && t[i].estado==1)
     		printf("\nId Tratamento: %d\nTipo de Tratamento: %s\nPreco: %d EUROS\n\n", t[i].idT, t[i].tipo, t[i].preco);
	}
	printf("\n---------------------------------------------------------------\n");
	getch();
}
/**
* \brief Funcao para calcular a media de precos dos TRATAMENTOS
* \param t : listaTratamento
*/
void mediaPrecos(listaTratamento t)
{
	int i, precos=0, trata=0, min, max=0;
	float mediaPrecos;
	system("cls");
	printf("\n--------------- MEDIA DE PRECOS DOS TRATAMENTOS ---------------\n"); 
	for (i=0; i<N; i++) 			//percorre pacientes
    {
    	if(t[i].estado==1)
    	{
	        precos=precos+t[i].preco; 	//soma idades dos pacientes
    	    trata++; 						//incrementa numero de pacientes
    	}
    	if (t[i].preco>max && t[i].estado==1) 
			max=t[i].preco;
		if (t[i].preco<min && t[i].estado==1) 
			min=t[i].preco;
    }
    mediaPrecos=precos/trata; 			//calcula a media
    printf("\n\nO preco maximo de tratamentos e de: %d EUROS.", max);
    printf("\n\nO preco minimo de tratamentos e de: %d EUROS.", min);
	printf("\n\nA Media de precos dos Tratamentos e de: %.2f EUROS.", mediaPrecos);
	printf("\n---------------------------------------------------------------\n");
	getch();
}
/**
* \brief Funcao que gravar a estrutura de dados no ficheiro "tratamentos.txt"
* \param c : listaConsulta
*/
void pesquisaData(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int a, d, m, i;
	char op;
	do
	{
		system("cls");
		printf("\n--------------- PESQUISA POR DATA DE CONSULTA ----------------\n"); 
		printf("\n	[1] - Pesquisar por ano"); 
		printf("\n	[2] - Pesquisar por mes"); 
		printf("\n	[3] - Pesquisar por dia"); 
		printf("\n	[0] - Sair"); 
		printf("\n----------------------------------------------------------");
		printf("\nQual a sua opcao: ");	scanf("%s%*c", &op);
		switch(op)
		{
			case '1': 	printf("\nAno <aaaa>: "); scanf("%d%*c", &a);
						printf("\n------------ LISTA POR ANO [%d] -----------\n", a);
						for (i=0; i<N; i++)
						{
					    	if (c[i].dConsulta.ano==a && c[i].estado==1)
							{
								printf("\nId Consulta: %d", c[i].idC);
								printf("\nId Paciente: %d", c[i].idP);
								c[i].idP=p[i].idP;
								//printf("\nNome do Paciente: %s", p[i].nome);
								printf("\nId Tratamento: %d", c[i].idT);
								c[i].idT=t[i].idT;
								//printf("\nTipo de Tratamento: %s", t[i].tipo);
								printf("\nData Consulta: %d-%d-%d", c[i].dConsulta.dia, c[i].dConsulta.mes, c[i].dConsulta.ano);
								printf("\nHora Inicial da Consulta: %d:%d", c[i].hInicial.h, c[i].hInicial.m);
								printf("\nHora Final da Consulta: %d:%d", c[i].hFinal.h, c[i].hFinal.m);
								printf("\nDuracao da Consulta: %s", c[i].duracao);
								printf("\nPreco da Consulta: %d EUROS\n\n", c[i].preco);
							}
					     	//else
					     		//printf("\nNao existe consultas neste ano.");
						}	
						printf("\n--------------------------------------------\n");
						getch();
						break;
			case '2': 	printf("\nMes <mm>: "); scanf("%d%*c", &m); 
						printf("\n------------ LISTA POR MES [%d] -----------\n", m);
						for (i=0; i<N; i++)
						{
					    	if (c[i].dConsulta.mes==m && c[i].estado==1)
							{
								printf("\nId Consulta: %d", c[i].idC);
								printf("\nId Paciente: %d", c[i].idP);
								c[i].idP=p[i].idP;
								//printf("\nNome do Paciente: %s", p[i].nome);
								printf("\nId Tratamento: %d", c[i].idT);
								c[i].idT=t[i].idT;
								//printf("\nTipo de Tratamento: %s", t[i].tipo);
								printf("\nData Consulta: %d-%d-%d", c[i].dConsulta.dia, c[i].dConsulta.mes, c[i].dConsulta.ano);
								printf("\nHora Inicial da Consulta: %d:%d", c[i].hInicial.h, c[i].hInicial.m);
								printf("\nHora Final da Consulta: %d:%d", c[i].hFinal.h, c[i].hFinal.m);
								printf("\nDuracao da Consulta: %s", c[i].duracao);
								printf("\nPreco da Consulta: %d EUROS\n\n", c[i].preco);
							}
					     	//else
								//printf("\nNao existe consultas neste mes.");
						}
						printf("\n--------------------------------------------\n");
						getch();
						break;
			case '3': 	printf("\nDia <dd>: "); scanf("%d%*c", &d);
						printf("\n------------ LISTA POR DIA [%d] -----------\n", d);
						for (i=0; i<N; i++)
						{
					    	if (c[i].dConsulta.dia==d && c[i].estado==1)
					    	{
								printf("\nId Consulta: %d", c[i].idC);
								printf("\nId Paciente: %d", c[i].idP);
								c[i].idP=p[i].idP;
								//printf("\nNome do Paciente: %s", p[i].nome);
								printf("\nId Tratamento: %d", c[i].idT);
								c[i].idT=t[i].idT;
								//printf("\nTipo de Tratamento: %s", t[i].tipo);
								printf("\nData Consulta: %d-%d-%d", c[i].dConsulta.dia, c[i].dConsulta.mes, c[i].dConsulta.ano);
								printf("\nHora Inicial da Consulta: %d:%d", c[i].hInicial.h, c[i].hInicial.m);
								printf("\nHora Final da Consulta: %d:%d", c[i].hFinal.h, c[i].hFinal.m);
								printf("\nDuracao da Consulta: %s", c[i].duracao);
								printf("\nPreco da Consulta: %d EUROS\n\n", c[i].preco);
					    	}
					     	//else
					     		//printf("\nNao existe consultas neste dia.");
						}
						printf("\n--------------------------------------------\n");
						getch();
						break;
			case '0': return; getch(); break;
			default: printf("\nOpcao invalida!"); getch(); break;
		}
	}while(op!='0');
	getch();
}
/**
* \brief Funcao para mostrar menu de GESTAO
* \param void
*/
void menuGestao(void)
{
	listaConsulta c;
	listaPaciente p;
	listaTratamento t;
	
	lerPaciente(p);
	lerTratamento(t);
	lerConsulta(c);
	
	char op;
	do
	{
		system("cls");
		printf("\n------------------- MENU GESTAO CLINICA -------------------");
		printf("\n\n	[1] - Pesquisa de Paciente por Idade");
		printf("\n\n	[2] - Pesquisa de Paciente por Telemovel");
		printf("\n\n	[3] - Pesquisa de Paciente por Nome");
		printf("\n\n	[4] - Media de Idades dos Pacientes");
		printf("\n\n	[5] - Pesquisa de Tratamento por tipo");
		printf("\n\n	[6] - Media de Precos dos Tratamentos");
		printf("\n\n	[7] - Pesquisa de Consulta por Data");
		printf("\n\n	[0] - Voltar Menu Principal");
		printf("\n-----------------------------------------------------------");
		printf("\n\nQual a opcao: ");	scanf("%s%*c", &op);
		switch(op)
		{
			case '1': pesquisaIdade(p); break;
			case '2': pesquisaTelemovel(p); break;
			case '3': pesquisaNome(p); break;
			case '4': mediaIdades(p); break;
			case '5': pesquisaTipo(t); break;
			case '6': mediaPrecos(t); break;
			case '7': pesquisaData(c,p,t); break;
			case '0': return; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while(op!='0' || op=='a' || op=='A');
	getch();
}

