/*----------------------------=- C O M A N D A -=-------------------------------------

 CRIAR UM SOFTWARE EM LINGUAGEM C, USANDO DEV C++ PARA GERENCIAMENTO DE UM PETSHOP

Neste software deve ser poss�vel cadastrar at� 100 animais. OK
Deve haver um menu (aprender a usar a funcao getch()) OK
Deve haver uma tela para cadastrar, editar e excluir animais 
Deve ter uma tela para cadastrar os banhos do animal (utilizar uma struct dentro da outra)
Deve haver a op��o de gerar uma relat�rio de todos os animais cadastrados e de seus banhos
Deve haver uma op��o para gerar o relat�rio dos banhos tomados por um animal espec�fico 
Deve haver uma op��o para gerar o relat�rio de animais que est�o a mais de 10 dias sem tomar banho. (usar biblioteca time.h)

CRIT�RIOS:
Todas as linhas devem ser comentadas
Deve ser apresentado no dia 28/11/2019 �s 13:50
A apresenta��o deve demonstrar as funcionalidades do sistema.
Deve ser entregue uma c�pia do arquivo de c�digo via GoogleClass

O cadastro dos animais deve conter:
Numero de identifica��o (ID)
Nome do dono
Telefone para contato
Especie do animal
Nome do animal
Raca
Sexo
idade do animal em Anos e Meses 
-------------------------------------------------------------------------------------*/



/* -----------------------=- DECLARA�AO DE BIBLIOTECAS -=--------------------------- */
#include <conio.h> // Para desenhar tela, manipular caracteres
#include <stdio.h> // Para usar printf scanf
#include <string.h> // Para utilizar strcpy
#include <locale.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------------- */



/* --------------------=- DECLARA�AO DE VARIAVEIS GLOBAIS -=------------------------ */
typedef struct {
	char dono[30];		// Nome do proprietaria
	char cell[20];		// Celular do Dono
	char nick[20];		// Nome do "TOTO"
	char esp [20];		// Especia animal
	char raca[20];		// Ra�a do animal
	char sexo[20];		// Sexo do animal
	int  idade;			// Idade do animal
	int  ID;			// Numero de Identifica��o
} Cadastro;

Cadastro pet[100] ={}; 

typedef struct {
	int IDbusca;
	int IDeditar;
	int Save_i;
}All;

All geral = {};
/* --------------------------------------------------------------------------------- */


// ----------------------- RELATORIO ---------------------------

void relatorio() { //Fun��es que n�o fornecem respostas

	
	printf ("\n----------=- RELATORIO DE ANIMAIS CADASTRADOS -=----------\n\n");
	
	for (int i = 0; i <= 99; i++ )
	 {
		if (pet[i].dono[0] != '\0')
		 {
			printf("------------------------------\n\n");
			printf(" Dono: %s\n", pet[i].dono);
			printf(" N�mero de Contato: %s\n", pet[i].cell);
			printf(" Nome do animal: %s\n", pet[i].nick);
			printf(" Esp�cie: %s\n", pet[i].esp);
			printf(" Ra�a: %s\n", pet[i].raca);
			printf(" Sexo: %s\n", pet[i].sexo);
			printf(" Idade do animal: %d Anos\n\n", pet[i].idade);
			printf(" ID do Cliente: %d\n\n", pet[i].ID);
			printf("-----------------------------\n\n");
		}
	} // i + 1
	
	getch();
	system("cls");
}

// -------------------------- BUSCA ---------------------------

/*int busca1() {
	for (int i = 0 ; i <= 99 ; i++)
	{
		if (pet[i].ID == geral.IDbusca)
		{
			return i;
	}
}
return 0;
}*/


void busca(){
	
	for (int i = 0 ; i <= 99 ; i++)
	{
		if (pet[i].ID == geral.IDbusca)
		{
			geral.Save_i = i;
			printf("\n            Cliente Cadastrado com esse ID");
			printf("\n------------------------------\n\n");
			printf(" Dono: %s\n", pet[i].dono);
			printf(" N�mero de Contato: %s\n", pet[i].cell);
			printf(" Nome do animal: %s\n", pet[i].nick);
			printf(" Esp�cie: %s\n", pet[i].esp);
			printf(" Ra�a: %s\n", pet[i].raca);
			printf(" Sexo: %s\n", pet[i].sexo);
			printf(" Idade do animal: %d Anos\n\n", pet[i].idade);
			printf(" ID do Cliente: %d\n\n", pet[i].ID);
			printf("-----------------------------\n\n");	
		}
	}
	
geral.IDbusca = 0; 	
getch();
system("cls");	
}

// ------------------------- EDI�ES ---------------------------
	
void editar() { 
	
	char opcao0 = 'A';

	printf("\n-------------=- EDITAR CADASTRO DO CLIENTE -=-------------\n\n");
	
	while (opcao0 != '0')
	{	
		printf(" 1 - Editar cadastro (por ID) \n 2 - Exluir cadastro (por ID) \n 3 - Emitir relatorio (se n�o souber o ID) \n 0 - Sair\n\n\n");
		
		opcao0 = getch();
		system("cls");
		
		switch(opcao0)
		{	

//----------- Sair --------------------------------------------------------------------------------------------------	
		
			case '0':
				
				opcao0 = '0';
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
				printf("\n Certeza desse a��o?\n");	
				scanf("%s", & dec);
				
				if (dec=='s')
				{
					pet[a].dono[0] = '\0';
					printf("\n A��o concluida \n",);	
					break;
				}
				else
				{
					printf("\n A��o cancelada\n");
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
				printf("\n Oque voc� desseja alterar?");
				
				char opcao1 = 'A';
				
				while(opcao1 != '0')
				{
					printf("\n\n------- Cadastro Atual --------\n\n 1 - Nome: %s \n 2 - Telefone: %s \n 3 - Nome do Animal: %s \n 4 - Esp�cie do animal: %s \n 5 - Ra�a do animal: %s \n 6 - Sexo do animal: %s \n 7 - Idade do animal \n\n 8 - Cancelar \n 9 - Concluido \n\n",pet[i].dono,pet[i].cell,pet[i].nick,pet[i].esp,pet[i].raca,pet[i].sexo,pet[i].idade);
					
					opcao1 = getch();
					system("cls");
					
					switch (opcao1)
					{
					
						case '1':
							printf("\n Insira a alter��o no nome: ");
							scanf("%s", & pet[i].dono);
							break;
								
						case '2':
							printf("\n Insira a alte��o no telefone: ");
							scanf("%s", & pet[i].cell);
							break;
						
						case '3':
							printf("\n Insira a alter��o no nome do animal: ");
							scanf("%s", & pet[i].nick);
							break;
						
						case '4':
							printf("\n Insira a alter��o na esp�cie: ");
							scanf("%s", & pet[i].esp);
							break;
						
						case '5':
							printf("\n Insira a altera��o na ra�a: ");
							scanf("%s", & pet[i].raca);
							break;
						
						case '6':
							printf("\n Insira a alter��o no sexo: ");
							scanf("%s", & pet[i].sexo);
							break;
						
						case '7':
							printf("\n Insira a altera��o na idade do animal: ");
							scanf("%s", & pet[i].idade);
							break;
						
						case '8':
							opcao1 = '0';
							break;
							
						case '9':
							printf("\n Altera�oes salvas com sucesso\n");
							opcao1 = '0';
							break;
					}
				}
				break;	
		}		
	}
}	



// -------------------- CADASTROS -----------------------------

void cadastro() { //Fun��es que n�o fornecem respostas
	system("cls");

	
	printf ("\n----------=- CADASTRO DE ANIMAIS -=----------\n\n");
	
	for (int i = 0; i <= 99; i++ )
	 {
		if (pet[i].dono[0] == '\0')
		 {
			printf("\n Dono: ");
			scanf("%s", pet[i].dono);
			printf("\n N�mero de Contato: ");
			scanf("%s",pet[i].cell);
			printf("\n Nome do animal: ");
			scanf("%s",pet[i].nick);
			printf("\n Esp�cie: ");
			scanf("%s",pet[i].esp);
			printf("\n Ra�a: ");
			scanf("%s",pet[i].raca);
			printf("\n Sexo: %s", pet[i].sexo);
			scanf("%s",pet[i].sexo);
			printf("\n Idade do animal: ");
			scanf("%d", & pet[i].idade);
			pet[i].ID = i + 10000;

			printf("Cliente Cadastrado com Sucesso\n ID (Numero de Identifica��o) do cliente/animal: %d",pet[i].ID);
			printf("----------------------------\n\n");
			system("cls");
			break;
		}
	} // i + 1
}

// ----------------------- MENU PRINCIPAL ---------------------

int main ()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char opcao = '1';

	// Imprimir o menu Principal
	
	while(opcao != '0') 
	{ 
		printf("\n          BEM VINDO A TOTOY & CIA\n\n");
		printf("   Escolha uma op��o\n\n"); // Imprime o menu
		printf(" 1 - Cadastro de animais \n");
		printf(" 2 - Relat�rio de animais cadastrados\n");
		printf(" 3 - Busca de cadastros \n");
		printf(" 4 - Editar/Excluir cadastros \n");
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
				printf(" ID do Cliente para cadastro: ");
				scanf("%d", & geral.IDbusca);
				busca(); // Busca de clientes/animais por ID cadastrados
				
			case '4':
				editar();
			
			default:
				break;
		}

}
	return 0;	
}
