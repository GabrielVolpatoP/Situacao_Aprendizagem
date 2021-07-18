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
idade do animal em Anos e Meses 
-------------------------------------------------------------------------------------*/


/* -----------------------=- DECLARAÇAO DE BIBLIOTECAS -=--------------------------- */
#include <conio.h> // Para desenhar tela, manipular caracteres
#include <stdio.h> // Para usar printf scanf
#include <string.h> // Para utilizar strcpy
#include <locale.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------------- */


/* --------------------=- DECLARAÇAO DE VARIAVEIS GLOBAIS -=------------------------ */
typedef struct {
	char dono[30];		// Nome do proprietaria
	char cell[20];		// Celular do Dono
	char nick[20];		// Nome do "TOTO"
	char esp [20];		// Especia animal
	char raca[20];		// Raça do animal
	char sexo[20];		// Sexo do animal
	int  idade;			// Idade do animal
	int  ID;			// Numero de Identificação
} Cadastro;

Cadastro pet[100] ={}; 

typedef struct {
	int IDbusca;
	int IDeditar;

}ID;

ID geral = {};
/* --------------------------------------------------------------------------------- */



// -------------------------- BUSCA ---------------------------

void busca(){
	
	for (int i = 0 ; i <= 99 ; i++)
	{
		if (pet[i].ID == geral.IDbusca)
		{
			printf("Cliente Cadastrado com esse ID");
			printf("------------------------------\n\n");
			printf(" Dono: %s\n", pet[i].dono);
			printf(" Número de Contato: %s\n", pet[i].cell);
			printf(" Nome do animal: %s\n", pet[i].nick);
			printf(" Espécie: %s\n", pet[i].esp);
			printf(" Raça: %s\n", pet[i].raca);
			printf(" Sexo: %s\n", pet[i].sexo);
			printf(" Idade do animal: %d Anos\n\n", pet[i].idade);
			printf(" ID do Cliente: %d\n\n", pet[i].ID);
			printf("-----------------------------\n\n");	
		}
	}
	
geral.IDbusca = {}; 
getch();
system("cls");
	
}



// ------------------------- EDIÕES ---------------------------
	
void editar() { 
	
	char opcao = '1';
	int IDeditar;

	printf("\n-------------=- EDITAR CADASTRO DO CLIENTE -=-------------\n\n");
	
	while (opcaoII != '0')
	{	
		printf(" 1 - Por ID \n 2 - Emitir relatorio (caso n saiba o ID) \n 3 - Sair\n\n\n");
		
		opcaoII = getch();
		system("cls");
		
		switch(opcao)
		{	
		
			case '1':
				
				printf("\n Insira o ID do usuario: ");
				scanf("%d",geral.IDbusca);
				busca();
				
				
				
			case '2':
				relatorio();
				printf("\n Insira o ID do usuario: ");
				scanf("%d",IDeditar);
				
				
		}
	}


}	

// ----------------------- RELATORIO ---------------------------

void relatorio() { //Funções que não fornecem respostas

	
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
			printf(" Idade do animal: %d Anos\n\n", pet[i].idade);
			printf(" ID do Cliente: %d\n\n", pet[i].ID);
			printf("-----------------------------\n\n");
		}
	} // i + 1
	
	getch();
	system("cls");
}

// -------------------- CADASTROS -----------------------------

void cadastro() { //Funções que não fornecem respostas
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

			printf("Cliente Cadastrado com Sucesso\n ID (Numero de Identificação) do cliente/animal: %d",pet[i].ID);
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
	printf("\n          BEM VINDO A TOTOY & CIA\n\n");

	char opcao = '1';

	// Imprimir o menu Principal
	
	while(opcao != '0') 
	{ 
		printf("   Escolha uma opcao\n\n"); // Imprime o menu
		printf(" 1 - Cadastro de animais \n");
		printf(" 2 - Relatório de animais cadastrados\n");
		printf(" 3 - Busca de cadastros \n");
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
			
			default:
				break;
		}

}
	return 0;	
}

