/*----------------------------=- C O M A N D A -=-------------------------------------

 CRIAR UM SOFTWARE EM LINGUAGEM C, USANDO DEV C++ PARA GERENCIAMENTO DE UM PETSHOP

Neste software deve ser possível cadastrar até 100 animais. OK
Deve haver um menu (aprender a usar a funcao getch()) OK
Deve haver uma tela para cadastrar, editar e excluir animais 
Deve ter uma tela para cadastrar os banhos do animal (utilizar uma struct dentro da outra)
Deve haver a opção de gerar uma relatório de todos os animais cadastrados e de seus banhos
Deve haver uma opção para gerar o relatório dos banhos tomados por um animal específico 
Deve haver uma opção para gerar o relatório de animais que estão a mais de 10 dias sem tomar banho. (usar biblioteca time.h)

CRITÉRIOS:
Todas as linhas devem ser comentadas
Deve ser apresentado no dia 28/11/2019 às 13:50
A apresentação deve demonstrar as funcionalidades do sistema.
Deve ser entregue uma cópia do arquivo de código via GoogleClass

O cadastro dos animais deve conter:
Numero de identificação (ID)
Nome do dono
Telefone para contato
Especie do animal
Nome do animal
Raca
Sexo
idade do animal em Anos e Meses !!!

-------------------------------------------------------------------------------------*/



/* -----------------------=- DECLARAÇAO DE BIBLIOTECAS -=--------------------------- */

#include <conio.h> // Para desenhar tela, manipular caracteres
#include <stdio.h> // Para usar printf scanf
#include <string.h> // Para utilizar strcpy
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/* ------------------------------------------------------ */



/* ----------=- DECLARAÇAO DE VARIAVEIS GLOBAIS -=------- */

typedef struct {
	
	int dia;
	int mes;
	int ano;

}Databanho;

typedef struct 
{
	char dono[30];			// Nome do proprietaria
	char cell[20];			// Celular do Dono
	char nick[20];			// Nome do "TOTO"
	char esp [20];			// Especia animal
	char raca[20];			// Raça do animal
	char sexo[20];			// Sexo do animal
	int  idade;				// Idade do animal
	int  ID;				// Numero de Identificação
	Databanho banho[8];	//
		
	
} Cadastro;

Cadastro pet[100] = {}; 

typedef struct 
{
	int IDbusca;
	int IDeditar;
	int Save_i;
	int dia,mes,ano;
	
} All;

All geral = {};


//------------------------------------------------------------- 

// ----------------------- MENU PRINCIPAL ---------------------

int main ()
{
 void cadastro(void),relatorio(void),busca(void),editar(void),banhos(void);
// ----------------------- TESTES ---------------------------

strcpy(pet[0].dono, "Fulano de Tal");
strcpy(pet[0].cell, "(44)99935-1725");
strcpy(pet[0].nick, "Bertin");
strcpy( pet[0].esp, "Egipicio");
strcpy(pet[0].raca, "Egipicio");
strcpy(pet[0].sexo, "M");
pet[0].idade = 1;
pet[0].ID = (10000);

strcpy(pet[1].dono, "Fulana de Tal");
strcpy(pet[1].cell, "(44)98755-1455");
strcpy(pet[1].nick, "Bob");
strcpy( pet[1].esp, "Jacare");
strcpy(pet[1].raca, "Chines");
strcpy(pet[1].sexo, "F");
pet[1].idade = 6;
pet[1].ID = 10001;

//-------------------------------------------------------------

	setlocale(LC_ALL, "Portuguese"); 
	
	char opcao = '1';

	// Imprimir o menu Principal
	
	while(opcao != '0') 
	{ 	
		printf("\n          TOY TOY & CIA  \n\n");
		printf("\n  - Escolha uma opção - \n\n"); // Imprime o menu
		printf(" 1 - Cadastro de animais \n");
		printf(" 2 - Relatório de cadastros \n");
		printf(" 3 - Busca de cadastros \n");
		printf(" 4 - Editar/Excluir cadastros \n\n");
		printf(" 5 - Banhos\n");
		printf(" 6 - Relatório banhos\n\n");
		printf(" 0 - Sair\n\n\n");
		
		opcao = getch();
		system("cls"); // Limpa tela

		switch(opcao) //Verifica tecla digitada
		 { 
			case '1': // Se a tecla foi 1
				cadastro(); // Cadastrara um animal
				break;
			
			case '2': // Se a tecla foi 2
				relatorio();// Imprime o relatorio de animais
				break;
				
			case '3': // Se a tecla foi 3
				printf("\n ID do Cliente para cadastro: ");
				scanf("%d", & geral.IDbusca);
				busca(); // Busca de clientes/animais por ID cadastrados
				break;
				
			case '4':
				editar();
				break;
				
			case '5':
				banhos();
				break;
			
			default:
				break;
		}

}
	return 0;	
}


// --------------------=--- RELATORIO ---------------------------

void relatorio() { 
	
	
	printf ("\n----------=- RELATORIO DE ANIMAIS CADASTRADOS -=----------\n\n");
	
	for (int i = 0; i <= 99; i++ )
	 {
		if (pet[i].dono[0] != '\0') 
		 {
			printf("------------------------------\n\n");
			printf(" Dono: %s\n", pet[i].dono);
			printf(" Número de Contato: %s\n", pet[i].cell);
			printf(" Nome do animal: %s\n", pet[i].nick);
			printf(" Espécie: %s\n", pet[i].esp);
			printf(" Raça: %s\n", pet[i].raca);
			printf(" Sexo: %s\n", pet[i].sexo);
			printf(" Idade do animal: %d Anos\n", pet[i].idade);
			printf(" ID do Cliente: %d\n\n", pet[i].ID);
			printf("-----------------------------\n\n");
		}
	} // i + 1
	
	getch();
	system("cls");	
}

//-----------------------=--- BUSCA ---------------------------

void busca(){
	
	if (geral.IDbusca<=9999||geral.IDbusca>=11000)
	{
		
		printf("\n ERRO 404 :/ \n Esse cadastro nao existe");
		geral.IDbusca = 0;	
		getch();
		system("cls");	
		
	}
	
	for (int i = 0 ; i <= 100 ; i++)
	{
		if (pet[i].ID == geral.IDbusca)
		{
			geral.Save_i = i;
			printf("\n       Cliente Cadastrado com esse ID");
			printf("\n------------------------------\n\n");
			printf(" Dono: %s\n", pet[i].dono);
			printf(" Número de Contato: %s\n", pet[i].cell);
			printf(" Nome do animal: %s\n", pet[i].nick);
			printf(" Espécie: %s\n", pet[i].esp);
			printf(" Raça: %s\n", pet[i].raca);
			printf(" Sexo: %s\n", pet[i].sexo);
			printf(" Idade do animal: %d Anos\n\n", pet[i].idade);
			printf("-----------------------------\n\n");
			break;	
		}
	}

	
	geral.IDbusca = 0;	
	getch();
	system("cls");	
}
				
// ------------------------- EDIÕES ---------------------------
	
void editar() { 
	
	char opcaoE = 'A';

	printf("\n-------------=- EDITAR CADASTRO DO CLIENTE -=-------------\n\n");
	
	while (opcaoE != '0')
	{	
		printf(" 1 - Editar cadastro (por ID) \n 2 - Exluir cadastro (por ID) \n 3 - Emitir relatorio (se não souber o ID) \n 0 - Sair\n\n\n");
		
		opcaoE = getch();
		system("cls");
		
		switch(opcaoE)
		{	

//----------- Sair --------------------------------------------------------------------------------------------------	
		
			case '0':
				
				opcaoE = '0';
				break;
				
//----------- Emitir relatorio ---------------------------------------------------------------------------------------		
		
			case '3':
				
				relatorio();
				printf("\n-------------=- EDITAR CADASTRO DO CLIENTE -=-------------\n\n");
				break;

//----------- Exluir cadastro ----------------------------------------------------------------------------------------		
				
			case '2':
				int a;
				char dec;
				printf("\n Insira o ID do cadastro que sera excluido: ");
				scanf("%d", & geral.IDbusca);
				busca();
				a = geral.Save_i;
				printf("\n Certeza desse ação?\n");	
				scanf("%s", & dec);
				
				if (dec=='s')
				{
					pet[a].dono[0] = '\0';
					pet[a].ID = 0;
					printf("\n Ação comcluida %c\n\n",a);	
					break;
				}
				else
				{
					printf("\n Ação cancelada\n");
					break;
				}
				break;
				
//----------- Editar cadastro -----------------------------------------------------------------------------------------			
				
			case '1':
				int i;
				printf("\n Insira o ID do cadastro: ");
				scanf("%d", & geral.IDbusca);
				//int i = busca();
				busca();
				i = geral.Save_i;
				printf("\n Oque você deseja alterar?");
				
				char opcao1 = 'A';
				
				while(opcao1 != '0')
				{
					printf("\n\n------- Cadastro Atual --------\n\n 1 - Nome: %s \n 2 - Telefone: %s \n 3 - Nome do Animal: %s \n 4 - Espécie do animal: %s \n 5 - Raça do animal: %s \n 6 - Sexo do animal: %s \n 7 - Idade do animal \n\n 8 - Cancelar \n 9 - Concluido \n\n",pet[i].dono,pet[i].cell,pet[i].nick,pet[i].esp,pet[i].raca,pet[i].sexo,pet[i].idade);
					
					opcao1 = getch();
					system("cls");
					
					switch (opcao1)
					{
					
						case '1':
							printf("\n Insira a alterção no nome: ");
							scanf("%s", & pet[i].dono);
							break;
								
						case '2':
							printf("\n Insira a alteção no telefone: ");
							scanf("%s", & pet[i].cell);
							break;
						
						case '3':
							printf("\n Insira a alterção no nome do animal: ");
							scanf("%s", & pet[i].nick);
							break;
						
						case '4':
							printf("\n Insira a alterção na espécie: ");
							scanf("%s", & pet[i].esp);
							break;
						
						case '5':
							printf("\n Insira a alteração na raça: ");
							scanf("%s", & pet[i].raca);
							break;
						
						case '6':
							printf("\n Insira a alterção no sexo: ");
							scanf("%s", & pet[i].sexo);
							break;
						
						case '7':
							printf("\n Insira a alteração na idade do animal: ");
							scanf("%s", & pet[i].idade);
							break;
						
						case '8':
							opcao1 = '0';
							geral.Save_i=0;
							break;
							
						case '9':
							printf("\n Alteraçoes salvas com sucesso");
							geral.Save_i=0;
							opcao1 = '0';
							break;
					}
				}
			break;	
		}		
	}
}	

// ------------------------- BANHOS ----------------------------

void banhos() {
	
	void cadastroB(void);
	char opcao1 = 'A';
	int i;
	
	printf("\n---------------=- CADASTRO DE BANHOS -=----------------\n\n");
	

	
	while (opcao1 != '0')
	{
		printf("\n 1 - Banho para hoje \n 2 - Marcar data para banho \n 3 - Excluir banho marcado \n\n 4 - Cancelar \n 5 - Concluido\n\n");
		
		opcao1 = getch();
		system("cls");
		
		switch(opcao1)
		{	
		
		default:
				printf("\n Opção invalida...");
				opcao1 = getch();
				break;
		
		case '5':
				printf("\n As acções foram salvas");
				opcao1 = '0';
				break;
			
		case '4':
				opcao1 = '0';
				break;
				
		case '2':
				printf("\n Insira a data do banho: ");
				scanf("%d",& geral.dia);
				printf(" / ");
				scanf("%d",geral.mes);
				printf(" / ");
				scanf("%d",geral.ano);
				system("cls");
				cadastroB();
				break;
				
			case '1':
				time_t mytime;
   				mytime = time(NULL);
   				struct tm tm = *localtime(&mytime);
   				geral.dia = tm.tm_yday;
   				geral.mes = tm.tm_mon + 1;
   				geral.ano = tm.tm_year + 1900;
   				
				printf("\n Banho cadastrado para hoje \n Data: %d/%d/%d \n", tm.tm_yday, tm.tm_mon + 1, tm.tm_year + 1900);
				cadastroB();
				break;
				
		}	
	}
	
}

void cadastroB(){ 
	
	int save;	
	printf("\n Insira o ID do cadastro o qual marcara o banho: ");
	scanf("%d", & geral.IDbusca);
	busca();
	save = geral.Save_i;
	
	for (int i = 0 ; i <= 8 ; i++)
	{

		if (pet[save].banho[i].dia == 0 )
		{
			pet[save].banho[i].dia = geral.dia;
			geral.dia = 0;
			pet[save].banho[i].mes = geral.mes;
			geral.mes = 0;
			pet[save].banho[i].ano = geral.ano;
			geral.ano = 0;
			printf("\n Banho marcado com sucesso \n Lhe aguardamos em: %d / %d / %d ",pet[save].banho[i].dia,  pet[save].banho[i].mes,  pet[save].banho[i].ano);
			break;	
		}
	}

	}
	


// -------------------- CADASTROS -----------------------------

void cadastro() { 
	system("cls");

	
	printf ("\n----------=- CADASTRO DE ANIMAIS -=----------\n\n");
	
	for (int i = 0; i <= 99; i++ )
	 {
		if (pet[i].dono[0] == '\0')
		 {
			printf("\n Dono: ");
			scanf("%s", pet[i].dono);
			printf("\n Número de Contato: ");
			scanf("%s",pet[i].cell);
			printf("\n Nome do animal: ");
			scanf("%s",pet[i].nick);
			printf("\n Espécie: ");
			scanf("%s",pet[i].esp);
			printf("\n Raça: ");
			scanf("%s",pet[i].raca);
			printf("\n Sexo: %s", pet[i].sexo);
			scanf("%s",pet[i].sexo);
			printf("\n Idade do animal: ");
			scanf("%d", & pet[i].idade);
			pet[i].ID = i + 10000;

			printf("Cliente Cadastrado com Sucesso\n ID (Numero de Identificação): %d",pet[i].ID);
			printf("----------------------------\n\n");
			system("cls");
			break;
		}
	} // i + 1
}




