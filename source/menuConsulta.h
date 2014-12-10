/* !
* \ file
* \ brief Projeto Modulo Tematico LTIC 2014/2015 "menuConsulta.h"
* \ details "menuConsulta.h" implementa o menu Consulta
* \ author Susana Estevao (a48584)
* \ date 9 dez 2014
* \ bug sem erros detetados
* \ version 0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 50	//Numero de Registos
#define consultaName "consultas.txt"
/**
* estrututa para trabalhar a data da Consulta
*/
typedef struct
{
	int ano;
	int mes;
	int dia;
}dataC;
/**
* estrututa para trabalhar a hora da Consulta
*/
typedef struct
{
	int h;
	int m;
}horaC;
/**
* estrututa para armazenar os dados de uma CONSULTA
*/
typedef struct
{
	int id; /**< idC - inteiro com o numero de identificacao da CONSULTA */
	int idPaciente; /**< idP - inteiro com o numero de identificacao do PACIENTE */
	//char nome[N]; /**< nomeP - string com o nome do PACIENTE */
	int idTratamento; /**< idT - inteiro com o numero de identificacao do TRATAMENTO */
	//char tipo[N]; /**< tipoT - string com o tipo de TRATAMENTO */
	dataC dataConsulta; /**< data - string com a data da CONSULTA */ 
	horaC horaI; /**< hora - string com a hora da CONSULTA */
	horaC horaF; /**< hora - string com a hora da CONSULTA */
	horaC duracao; /**< duracao - float com a duracao da CONSULTA */
	float preco; /**< preco - float com o preco da CONSULTA */
	int estado; /**< estado - int para o estado da CONSULTA */
}consulta;
/** define um tipo como sendo um lista de CONSULTA */
typedef consulta listaConsulta[N];
listaConsulta c;
/**
* \brief Funcao que inicializa a estrutura de dados CONSULTA
* \ param c : listaConsulta
* \return int
*/
int initConsulta(listaConsulta c) // funcao para inicializar a estrutura de dados
{
    int i;
    for (i=0; i<N; i++)
    {
         c[i].id=0;
         c[i].estado=0;
    }
    return 0;
}
/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "consultas.txt"
* \param c : listaConsulta
* \return void 
*/
void lerConsulta(listaConsulta c)
{
	FILE *fileConsulta=fopen(consultaName,"r+");
	int i;
	if(fileConsulta==NULL)
	{
		printf("\nErro ao abrir ficheiro! <Enter para Sair>");
		getch(); return;
	}
	for(i=0; i<N; i++)
	{
		fscanf(fileConsulta,"%d\n", &c[i].id);
		fscanf(fileConsulta,"%d\n", &c[i].idPaciente);
		fscanf(fileConsulta,"%d\n", &c[i].idTratamento);
		fscanf(fileConsulta,"%d-%d-%d\n", &c[i].dataConsulta.ano, &c[i].dataConsulta.mes, &c[i].dataConsulta.dia);
		fscanf(fileConsulta,"%2d:%2d\n", &c[i].horaI.h, &c[i].horaI.m);
		fscanf(fileConsulta,"%2d:%2d\n", &c[i].horaF.h, &c[i].horaF.m);
		fscanf(fileConsulta,"%2d:%2d\n", &c[i].duracao.h, &c[i].duracao.m);
		fscanf(fileConsulta,"%f\n", &c[i].preco); 
		fscanf(fileConsulta,"%d\n", &c[i].estado);
	}
	//fread(c, sizeof(consulta), N, fileConsulta);
	fclose(fileConsulta);
	printf("\nFicheiro Carregado com Sucesso! <Enter para Continuar>"); getch();
}
/**
* \brief Funcao que gravar a estrutura de dados no ficheiro "consulta.txt"
* \param c : listaConsulta
* \return void
*/
void gravarConsulta(listaConsulta c)
{
	FILE *fileConsulta=fopen(consultaName,"w+");
	int i;
	if(fileConsulta==NULL)
	{
		printf("\nErro ao gravar ficheiro! <enter para continuar>");
		getch(); return;
	}
	for(i=0; i<N; i++)
	{
		if(c[i].estado==1)
		{
			fprintf(fileConsulta,"%d\n%d\n%d\n%d-%d-%d\n%2d:%2d\n%2d:%2d\n%2d:%2d\n%d\n%d\n\n",
			c[i].id, c[i].idPaciente, c[i].idTratamento, c[i].dataConsulta.ano, c[i].dataConsulta.mes, c[i].dataConsulta.dia, c[i].horaI.h, c[i].horaI.m, c[i].horaF.h, c[i].horaF.m, c[i].duracao.h, c[i].duracao.m, c[i].preco, c[i].estado);
		}
	}
	//fwrite(c, sizeof(consulta), N, fileConsulta);
	fclose(fileConsulta);
	printf("\nFicheiro Gravado com Sucesso! <enter para continuar>"); getch();
}
/**
* \brief Funcao que mostra todas as CONSULTAS gravadas em "consultas.txt"
* \param c : listaConsulta
* \return void
*/
void mostrarConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int i;
	system("cls");
	for(i=0; i<N; i++)
	{
		if(c[i].estado==1)
		{
			//printf("Id Consulta: %d\nId Paciente: %d\nNome do Paciente: %s\nId Tratamento: %d\nTipo de Tratamento: %s\nData Consulta: %d-%d-%d\nHora Inicial da Consulta: %2d:%2d\nHora Final da Consulta: %2d:%2d\nDuracao Consulta: %2d:%2d\nPreco Consulta: %.2f EUROS\nEstado:%d\n",
					//c[i].id, c[i].idPaciente, p[i].nome, c[i].idTratamento, t[i].tipo, c[i].dataConsulta.ano, c[i].dataConsulta.mes, c[i].dataConsulta.dia, c[i].horaI.h, c[i].horaI.m, c[i].horaF.h, c[i].horaF.m, c[i].duracao.h, c[i].duracao.m, t[i].preco, c[i].estado);
					
			printf("Id Consulta: %d\nId Paciente: %d\nId Tratamento: %d\nData Consulta: %d-%d-%d\nHora Inicial da Consulta: %2d:%2d\nHora Final da Consulta: %2d:%2d\nDuracao Consulta: %2d:%2d\nPreco Consulta: %.2f EUROS\nEstado:%d\n",
			c[i].id, c[i].idPaciente, c[i].idTratamento, c[i].dataConsulta.ano, c[i].dataConsulta.mes, c[i].dataConsulta.dia, c[i].horaI.h, c[i].horaI.m, c[i].horaF.h, c[i].horaF.m, c[i].duracao.h, c[i].duracao.m, c[i].preco, c[i].estado);
		}
	}
	printf("\n\nListagem Concluida! <Enter para Continuar>");getch();
}
/**
* \brief Funcao que converte as horas em minutos
* \param horaI - hora inicial da consulta
* \param minI - minuto inicial da consulta
* \param horaF - hora final da consulta
* \param minF - minuto final da consulta
* \return int
*/
int duracaoConsulta(int horaI, int minI, int horaF, int minF)
{ 
	int d;
	if(horaI > horaF)
	{
		d =  1440 - (horaI * 60 + minI);
		d += horaF*60 + minF;
	}
	else
		d = (horaF*60 + minF) - (horaI*60 + minI);
	return (d);
}
/**
* \brief adicionar uma nova CONSULTA
* \param c : listaConsulta
* \return void
*/
void inserirConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int dura, i, op1, op2, op, idPac, idTrata;
	system("cls");
	do//corre ate o ultimo registo(vai para o primeiro indice onde c[i].estado=0)
	{
		i++;
	}while(c[i].estado>0 && c[i].estado<2);
	do
	{
		printf("\nID Consulta: %d\n", i);
		c[i].id=i;
		
		printf("\nInsira o Id do Paciente [0]-SAIR: "); scanf("%d%*c", &idPac);
		c[i].idPaciente=idPac;
		do
		{
			printf("\nId Paciente: %d", idPac);
			printf("\nNome do Paciente: %s", p[idPac].nome);

			printf("\nQuer este paciente? [1]-SIM [2]-NAO:  ");	scanf("%d%*c", op1);
		}while(op1==2);
		printf("\nInsira o Id de Tratamento: [0]-SAIR: "); scanf("%d%*c", &idTrata);
		c[i].idTratamento=idTrata;
		do
		{
			printf("\nId Tratamento: %d", idTrata);
			printf("\nTipo de Tratamento: %s", t[idTrata].tipo);
			printf("\nPreco do Tratamento: %.2f", t[idTrata].preco);
			
			printf("\nQuer este Tratamento? [1]-SIM [2]-NAO:  "); scanf("%d%*c", &op2);
		}while(op2==2);
		
		c[i].preco=t[idTrata].preco;
		
		printf("\nData Consulta: \n"); 
        printf("Ano <aaaa>: "); scanf("%d%*c", &c[i].dataConsulta.ano);
        printf("Mes <mm>: "); scanf("%d%*c", &c[i].dataConsulta.mes);
        printf("Dia <dd>: "); scanf("%d%*c", &c[i].dataConsulta.dia);
        printf("\nHora Inicial da Consulta: \n");
        printf("Hora <hh>: "); scanf("%d", &c[i].horaI.h);
        printf("Minuto <mm>: "); scanf("%d", &c[i].horaI.m);
        printf("\nHora Final da Consulta: \n");
        printf("Hora <hh>: "); scanf("%d", &c[i].horaF.h);
        printf("Minuto <mm>: "); scanf("%d", &c[i].horaF.m);
        dura=duracaoConsulta(c[i].horaI.h, c[i].horaI.m, c[i].horaF.h, c[i].horaF.m);
		//c[i].duracao=dura;
		//printf("\nDuracao da Consulta: %d:%d.", c[i].duracao.h/60, c[i].duracao.m%60);
		printf("\nDuracao da Consulta: %d:%d.", dura/60, dura%60);
		
		printf("\nPreco da consulta: %.2f", c[i].preco);
        c[i].estado=1;
        printf("\n\nConsulta Inserida com sucesso!");
        
        i++;
		while(c[i].estado>0 && c[i].estado<2)
			i++;
		printf("\n\nQuer inserir outra consulta? [1]-SIM [0]-NAO: "); scanf("%d%*c", &op);
	}while(op==1);
}
/**
* \brief Funcao que altera uma determinada CONSULTA
* \param c : listaConsulta
* \return int
*/
int alterarConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int alt, op, confere, op2, op1, idPac, idTrata;
	system("cls");
	do
	{
		printf("\nQual o Id da Consulta para alterar? [0]-SAIR: "); scanf("%d%*c",&alt);
		if(alt==0)
			break;
		c[alt].id=alt;
		if(alt==c[alt].id)
		{
			printf("\n----------------------------------------------");
			printf("\nId Consulta: %d", alt);
			printf("\nId Paciente: %d", c[alt].idPaciente);
			//printf("\nNome do Paciente: %s", p[alt].nome);
			printf("\nId Tratamento: %d", c[alt].idTratamento);
			//printf("\nTipo de Tratamento: %s", t[alt].tipo);
			printf("\nData Consulta: %d-%d-%d", c[alt].dataConsulta.ano, c[alt].dataConsulta.mes, c[alt].dataConsulta.dia);
			printf("\nHora Inicial da Consulta: %d:%d", c[alt].horaI.h, c[alt].horaI.m);
			printf("\nHora Final da Consulta: %d:%d", c[alt].horaF.h, c[alt].horaF.m);
			printf("\nDuracao da Consulta: %d:%d", c[alt].duracao.h, c[alt].duracao.m);
			printf("\nPreco da Consulta: %.2f EUROS", c[alt].preco);
			printf("\nEstado: %d", c[alt].estado);
			printf("\n----------------------------------------------");
		}
		else
			printf("\nERRO! Id da Consulta nao existe.");	
		printf("\n\nQuer mesmo editar esta Consulta? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
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
				printf("\n\nQual a sua opcao: "); scanf("%d%*c", &op);
				if(op==1)	
				{	
					printf("\nInsira o Id do Paciente [0]-SAIR: "); scanf("%d%*c", &idPac);
					c[alt].idPaciente=idPac;
					do
					{
						printf("\nId Paciente: %d", idPac);
						printf("\nNome do Paciente: %s", p[idPac].nome);
			
						printf("\nQuer este paciente? [1]-SIM [2]-NAO:  ");	scanf("%d%*c", op1);
					}while(op1==2);
				}
				else
					if(op==2)	
					{	
						printf("\nInsira o Id de Tratamento: [0]-SAIR: "); scanf("%d%*c", &idTrata);
						c[alt].idTratamento=idTrata;
						do
						{
							printf("\nId Tratamento: %d", idTrata);
							printf("\nTipo de Tratamento: %s", t[idTrata].tipo);
							printf("\nPreco do Tratamento: %.2f", t[idTrata].preco);
							
							printf("\nQuer este Tratamento? [1]-SIM [2]-NAO:  "); scanf("%d%*c", &op2);
						}while(op2==2);
						c[alt].preco=t[idTrata].preco;
					}
					else
						if(op==3)	
						{	
							printf("\nData Consulta: \n"); 
			        		printf("Ano <aaaa>: ");	scanf("%d%*c", c[alt].dataConsulta.ano);
			        		printf("Mes <mm>: "); scanf("%d%*c", c[alt].dataConsulta.mes);
			        		printf("Dia <dd>: "); scanf("%d%*c", c[alt].dataConsulta.dia);
						}
						else
							if(op==4)	
							{	
								printf("\nHora Inicial da Consulta: \n");
			        			printf("Hora <hh>: "); scanf("%d", c[alt].horaI.h);
			        			printf("Minuto <mm>: "); scanf("%d", c[alt].horaI.m); 
							}
							else
								if(op==5)	
								{	
									printf("\nHora Final da Consulta: \n");
				        			printf("Hora <hh>: "); scanf("%d", c[alt].horaF.h);
				        			printf("Minuto <mm>: "); scanf("%d", c[alt].horaF.m); 
								}
								else
									if(op==6)	
									{	
										printf("\nDuracao Consulta: \n");
				        				printf("Hora <hh>: "); scanf("%d%*c", c[alt].duracao.h);
				        				printf("Minuto <mm>: "); scanf("%d%*c", c[alt].duracao.m); 
									}
									else
										if(op==7)	
										{	
											printf("\nPreco de Tratamento: %.2f EUROS", c[alt].preco);
										}
										else
											if(op==0)	
											{	
												return 0;
											}
											else
												printf("\nOpcao Invalida!");
			}while(op==0 && op>0 || op<8);
			c[alt].estado=1;
			printf("\n\nConsulta alterada com Sucesso!");
		}
		else
			break;
		printf("\n\nQuer editar outra Consulta? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &op2);
	}while(op2==1);
}

/**
* \brief Funcao para eliminar uma determinada CONSULTA
* \param c: listaConsulta 
*/
void eliminarConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	int i, eli, confere, op;
	system("cls");
	do
	{
		printf("\nQual o Id da Consulta para eliminar [0]-SAIR: "); scanf("%d%*c",&eli);
		if(eli==0)
			break;
		c[eli].id=eli;
		if(c[eli].id==eli)
		{
			printf("\n----------------------------------------------");
			printf("\nId Consulta: %d", eli);
			printf("\nId Paciente: %d", c[eli].idPaciente);
			//printf("\nNome do Paciente: %s", p[eli].nome);
			printf("\nId Tratamento: %d", c[eli].idTratamento);
			//printf("\nTipo de Tratamento: %s", t[eli].tipo);
			printf("\nData Consulta: %d-%d-%d", c[eli].dataConsulta.ano, c[eli].dataConsulta.mes, c[eli].dataConsulta.dia);
			printf("\nHora Inicial da Consulta: %d:%d", c[eli].horaI.h, c[eli].horaI.m);
			printf("\nHora Final da Consulta: %d:%d", c[eli].horaF.h, c[eli].horaF.m);
			printf("\nDuracao da Consulta: %d:%d", c[eli].duracao.h, c[eli].duracao.m);
			printf("\nPreco da Consulta: %.2f EUROS", c[eli].preco);
			printf("\nEstado: %d", c[eli].estado);
			printf("\n----------------------------------------------");
		}
		else
			printf("\nERRO! Id da Consulta nao existe.");
		printf("\n\nQuer mesmo eliminar esta Consulta? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
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
int menuConsulta(listaConsulta c, listaPaciente p, listaTratamento t)
{
	p;
	c;
	t;
	
	int op;
	initConsulta(c);
	do
	{
		system("cls");
		printf("\n-------- MENU GESTAO CONSULTA ------------");
		printf("\n\n[1] - Ler Ficheiro");
		printf("\n\n[2] - Gravar Ficheiro");
		printf("\n\n[3] - Marcacao de Consulta");
		printf("\n\n[4] - Eliminar Consulta");
		printf("\n\n[5] - Alterar Consulta");
		printf("\n\n[6] - Mostrar todas as Consultas");
		printf("\n\n[0] - Voltar Menu Principal");
		printf("\n------------------------------------------");
		printf("\n\nQual a opcao: ");	scanf("%d%*c", &op);
		switch(op)
		{
			case 1: lerConsulta(c); break;
			case 2: gravarConsulta(c); break;
			case 3: inserirConsulta(c, p, t); break;
			case 4: eliminarConsulta(c, p, t); break;
			case 5: alterarConsulta(c, p, t); break;
			case 6: mostrarConsulta(c, p, t); break;
			case 0: return 0; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while(op!=0);
	getch();
}
