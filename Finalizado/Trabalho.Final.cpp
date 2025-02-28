/*----------------------------=- C O M A N D A -=-------------------------------------

 CRIAR UM SOFTWARE EM LINGUAGEM C, USANDO DEV C++ PARA GERENCIAMENTO DE UM PETSHOP

Neste software deve ser poss�vel cadastrar at� 100 animais.  OK
Deve haver um menu (aprender a usar a funcao getch())  OK
Deve haver uma tela para cadastrar, editar e excluir animais  OK
Deve ter uma tela para cadastrar os banhos do animal (utilizar uma struct dentro da outra) OK
Deve haver a op��o de gerar uma relat�rio de todos os animais cadastrados e de seus banhos OK
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
idade do animal em Anos e Meses !!!

-------------------------------------------------------------------------------------*/



/* -----------------------=- DECLARA�AO DE BIBLIOTECAS -=--------------------------- */
#include <conio.h> // Para desenhar tela, manipular caracteres
#include <stdio.h> // Para usar printf scanf
#include <string.h> // Para utilizar strcpy
#include <locale.h> // Para acentua��o
#include <stdlib.h> //Emulador so prompt do sistema operacional
#include <time.h> //Para a data
#include <unistd.h> //Biblioteca para a fun��o Sleep
/* ------------------------------------------------------ */



/* ----------=- DECLARA�AO DE VARIAVEIS GLOBAIS -=------- */

typedef struct {  // Declarar uma estrutura
	
	int dia; //Dias
	int mes; //M�s
	int ano; //Ano

}Databanho;  // Cria��o de um novo tipo

typedef struct // Declarar uma estrutura
{
	char dono[30];			// Nome do proprietaria
	char cell[20];			// Celular do Dono
	char nick[20];			// Nome do "TOTO"
	char esp [20];			// Especia animal
	char raca[20];			// Ra�a do animal
	char sexo[20];			// Sexo do animal
	int  idade;				// Idade do animal
	int  ID;				// Numero de Identifica��o
	Databanho banho[8];	//Data do Banho
		
	
} Cadastro; //Cria��o de um novo tipo

Cadastro pet[100] = {};  //Cria��o de uma vari�vel do tipo cadastro

typedef struct  //Declarar uma vari�vel para o c�digo todo
{
	int IDbusca;   //Vari�vel Global para buscar
	int IDeditar;  //Vari�vel Global para editar
	int Save_i;    //Vari�vel Global para salvar
	int dia,mes,ano; //Varu�vel Global da data
	
}All; // Cria��o de um novo tipo

All geral = {}; //Cria��o de uma nova vari�vel do tipo geral

//------------------------------------------------------------- 

// ! ! ! ! ! ! ! ! ! ! ! ! !  ! ! ! NAO FOI RALIZADO O ATIVIDADE PROPOSTA ! ! ! ! ! ! ! ! ! ! ! !  ! ! ! ! ! ! ! ! ! ! ! ! ! ! 

// "Deve haver uma op��o para gerar o relat�rio de animais que est�o a mais de 10 dias sem tomar banho. (usar biblioteca time.h)"

// ! ! ! ! ! ! ! ! ! ! ! !  ! ! ! ! ! ! ! ! ! ! ! ! ! ! !  ! ! ! ! ! ! ! ! ! ! ! ! ! ! !  ! ! ! ! ! ! ! ! ! ! ! ! ! ! !  ! ! !

// ------------------- MENU PRINCIPAL -----------------------


int main () //Fun��o principal
{

 void cadastro(void),relatorio(void),busca(void),editar(void),banhos(void),relatB(void); //Declarar as fun��es sem retorno utilizadas
// ----------------------- TESTES ---------------------------

strcpy(pet[0].dono, "Fulano de Tal"); //Cadastro para TESTE
strcpy(pet[0].cell, "(44)99935-1725"); //Cadastro para TESTE
strcpy(pet[0].nick, "Bertin"); //Cadastro para TESTE
strcpy( pet[0].esp, "Egipicio"); //Cadastro para TESTE
strcpy(pet[0].raca, "Egipicio"); //Cadastro para TESTE
strcpy(pet[0].sexo, "M"); //Cadastro para TESTE
pet[0].idade = 1; //Cadastro para TESTE
pet[0].ID = (10000); //Cadastro para TESTE

strcpy(pet[1].dono, "Fulana de Tal"); //Cadastro para TESTE
strcpy(pet[1].cell, "(44)98755-1455"); //Cadastro para TESTE
strcpy(pet[1].nick, "Bob"); //Cadastro para TESTE
strcpy( pet[1].esp, "Jacare"); //Cadastro para TESTE
strcpy(pet[1].raca, "Chines"); //Cadastro para TESTE
strcpy(pet[1].sexo, "F"); //Cadastro para TESTE
pet[1].idade = 6; //Cadastro para TESTE
pet[1].ID = (10001); //Cadastro para TESTE
pet[1].banho[0].dia = 10; //Cadastro para TESTE
pet[1].banho[0].mes = 12; //Cadastro para TESTE
pet[1].banho[0].ano = 2019; //Cadastro para TESTE
pet[1].banho[1].dia = 20; //Cadastro para TESTE
pet[1].banho[1].mes = 1; //Cadastro para TESTE
pet[1].banho[1].ano = 2020; //Cadastro para TESTE

strcpy(pet[2].dono, "Ciclano"); //Cadastro para TESTE
strcpy(pet[2].cell, "(45)89978-89258"); //Cadastro para TESTE
strcpy(pet[2].nick, "Ken"); //Cadastro para TESTE
strcpy( pet[2].esp, "Rato"); //Cadastro para TESTE
strcpy(pet[2].raca, "Laptupip"); //Cadastro para TESTE
strcpy(pet[2].sexo, "M"); //Cadastro para TESTE
pet[2].idade = 2; //Cadastro para TESTE
pet[2].ID = (10002); //Cadastro para TESTE
pet[2].banho[0].dia = 18; //Cadastro para TESTE
pet[2].banho[0].mes = 3; //Cadastro para TESTE
pet[2].banho[0].ano = 2020; //Cadastro para TESTE

strcpy(pet[3].dono, "Ciclana"); //Cadastro para TESTE
strcpy(pet[3].cell, "(44)34535-1675"); //Cadastro para TESTE
strcpy(pet[3].nick, "Litle Big"); //Cadastro para TESTE
strcpy( pet[3].esp, "Porquinho"); //Cadastro para TESTE
strcpy(pet[3].raca, "Indiano"); //Cadastro para TESTE
strcpy(pet[3].sexo, "F"); //Cadastro para TESTE
pet[3].idade = 14; //Cadastro para TESTE
pet[3].ID = (10003); //Cadastro para TESTE
//-------------------------------------------------------------

	setlocale(LC_ALL, "Portuguese");  //Declarar a Linguagem Portugu�s, para a Utiliza��o de Acentos
	
	char opcao = '1';  //Dar o valor de 1 para a vari�vel "opcao"
	
	usleep(400000); //Pausa pequena
		
	printf("            ___   ___   __  __    __   __  ___   _  _   ___     ___    \n");           //Imprime o "Bem Vindo"
	printf("           | _ ) | __| |  \\/  |   \\ \\ / / |_ _| | \\| | |   \\   / _ \\   \n");     //Imprime o "Bem Vindo"
	printf("           | _ \\ | _|  | |\\/| |    \\ V /   | |  | .` | | |) | | (_) |  \n");        //Imprime o "Bem Vindo"
	printf("           |___/ |___| |_|  |_|     \\_/   |___| |_|\\_| |___/   \\___/ \n");          //Imprime o "Bem Vindo"
	 
	usleep(400000); //Pausa pequena
   
	printf("\n                                    _  \n");       //Imprime o "A"
	printf("                                   /_\\  \n");       //Imprime o "A"
	printf("                                  / _ \\  \n");      //Imprime o "A"
	printf("                                 /_/ \\_\\  \n");    //Imprime o "A"
	
	usleep(400000); //Pausa pequena
	
	printf("                                              ___            ");
	printf("\n  _____    ___    _____    ___   __   __     ( _ )        ___   ___     _       \n");              //Imprime o "Totoy & Cia"
	printf(" |_   _|  / _ \\  |_   _|  / _ \\  \\ \\ / /     / _ \\/\\     / __| |_ _|   /_\\      \n");         //Imprime o "Totoy & Cia"
	printf("   | |   | (_) |   | |   | (_) |  \\ V /     | (_>  <    | (__   | |   / _ \\     \n");              //Imprime o "Totoy & Cia"
	printf("   |_|    \\___/    |_|    \\___/    |_|       \\___/\\/     \\___| |___| /_/ \\_\\    \n");         //Imprime o "Totoy & Cia"
	 
	usleep(400000); //Pausa pequena
	
	printf("                                                                                 |\\_/|                  \n");        //Imprime um Cachorro
	printf("                                                                           Au!   |o o|   Au! Au!          \n");       //Imprime um Cachorro
	printf("                                                                                 |   <>              _    \n");       //Imprime um Cachorro
	printf("                                                                        Au!      |  _/\\------____ ((| |))  \n");     //Imprime um Cachorro
	printf("                                                                                 |               `--' |      \n");    //Imprime um Cachorro
	printf("                                                                             ____|_       ___|   |___.'      \n");    //Imprime um Cachorro
	printf("                                                                            /_/_____/____/_______|           \n");    //Imprime um Cachorro
	
	sleep(3); //Pausa pequena de 3 segundos
	system("cls"); //Limpa a tela para imprimir o Menu
	
	// Imprimir o menu Principal
	
	while(opcao != '0') // Permite sempre voltar no menu principal 
	{ 	
		printf("\n        TOTOY & CIA  \n\n"); //Imprime o t�tulo
		printf("\n  - Escolha uma op��o - \n\n"); // Imprime o menu
		printf(" 1 - Cadastro de animais \n"); //Op��o 1 para o usu�rio escolher
		printf(" 2 - Relat�rio de cadastros \n"); //Op��o 2 para o usu�rio escolher
		printf(" 3 - Busca de cadastros \n"); //Op��o 3 para o usu�rio escolher
		printf(" 4 - Editar/Excluir cadastros \n\n"); //Op��o 4 para o usu�rio escolher
		printf(" 5 - Banhos\n"); //Op��o 5 para o usu�rio escolher
		printf(" 6 - Relat�rio banhos\n\n"); //Op��o 6 para o usu�rio escolher
		printf(" 0 - Sair\n\n\n");//�ltima op��o para o usu�rio escolher, na qual finaliza o programa 
		
		opcao = getch();//Permite que as escolhas do usu�rios n�o apare�am na tela
		system("cls"); // Limpa tela

		switch(opcao) //Verifica tecla digitada
		 { 
			case '1': // Se a tecla foi 1
				cadastro(); // Cadastrara um animal
				break;//Fim da escolha 1
			
			case '2': // Se a tecla foi 2
				relatorio();// Imprime o relatorio de animais
				break;//Fim da escolha 1
				
			case '3': // Se a tecla foi 3
				printf("\n ID do Cliente para buscar: "); //Pergunta qual o ID desejado para a busca
				scanf("%d", & geral.IDbusca);//L� o ID desejado
				busca(); // Busca de clientes/animais por ID cadastrados
				break;//Fim da escolha 1
				
			case '4':// Se a tecla foi 4
				editar();//Edita o cadastro
				break;//Fim da escolha 1
				
			case '5':// Se a tecla foi 5
				banhos();//Entra na fun��o banhos
				break;//Fim da escolha 1
			
			case '6':// Se a tecla foi 6
				relatB();//Entra na fun��o relat
				break;//Fim da escolha 1
			
			default://Define o padr�o
				break;//Fim da escolha 1
		}

}
    	//Caso o usu�rio escolha sair do programa
	
		printf("     ___     ___     ___     ___     ___     ___     ___     ___     ___     ___     ___  \n");                          //Imprime um agradecimento
		printf(" ___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___  \n");           //Imprime um agradecimento
		printf("/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\   \n");        //Imprime um agradecimento
		printf("\\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/  \n");         //Imprime um agradecimento
		printf("/   \\___/                                                                           \\___/   \\   \n");	             //Imprime um agradecimento 
		printf("\\___/                    ___    _            _                    _                     \\___/    \n");                 //Imprime um agradecimento
		printf("/   \\                   / _ \\  | |__   _ _  (_)  __ _   __ _   __| |  ___               /   \\  \n");                  //Imprime um agradecimento
		printf("\\___/                  | (_) | | '_ \\ | '_| | | / _` | / _` | / _` | / _ \\              \\___/   \n");                //Imprime um agradecimento
		printf("/   \\                   \\___/  |_.__/ |_|   |_| \\__, | \\__,_| \\__,_| \\___/              /   \\     \n");           //Imprime um agradecimento
		printf("\\___/                                           |___/                                   \\___/    \n");                 //Imprime um agradecimento                         
		printf("/   \\                                ___         _                                      /   \\    \n");                 //Imprime um agradecimento
		printf("\\___/                               | _ \\  ___  | |  __ _                               \\___/      \n");              //Imprime um agradecimento
		printf("/   \\                               |  _/ / -_) | | / _` |                              /   \\  \n");                   //Imprime um agradecimento
		printf("\\___/                               |_|   \\___| |_| \\__,_|                              \\___/   \n");                //Imprime um agradecimento
		printf("/   \\              ___                __                                 _              /   \\  \n");                   //Imprime um agradecimento
		printf("\\___/             | _ \\  _ _   ___   / _|  ___   _ _   ___   _ _    __  (_)  __ _       \\___/     \n");               //Imprime um agradecimento
		printf("/   \\             |  _/ | '_| / -_) |  _| / -_) | '_| / -_) | ' \\  / _| | | / _` |      /   \\   \n");                 //Imprime um agradecimento
		printf("\\___/             |_|   |_|   \\___| |_|   \\___| |_|   \\___| |_||_| \\__| |_| \\__,_|      \\___/      \n");          //Imprime um agradecimento
		printf("/   \\___                                                                             ___/   \\    \n");                 //Imprime um agradecimento
		printf("\\___/   \\___     ___     ___     ___     ___     ___     ___     ___     ___     ___/   \\\___/   \n");                //Imprime um agradecimento
		printf("/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\  \n");         //Imprime um agradecimento
		printf("\\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \n");        //Imprime um agradecimento
		printf("    \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \\___/   \n");             //Imprime um agradecimento

		return 0; //Volta a 0 e sai do programa	
}

// ------------------------ RELATORIO --------------------------

void relatorio() {  //Fun��es que n�o fornecem respostas
	
	
	printf ("\n----------=- RELATORIO DE ANIMAIS CADASTRADOS -=----------\n\n"); //Printar o t�tulo
	
	for (int i = 0; i <= 99; i++ ) //Contador para a quantidade de relat�rios que ser�o printados
	 {
		if (pet[i].dono[0] != '\0') //Condi��o para printar um relat�rio (Se a informa��o n�o existir, ela n�o ser� mostrada)
		 {
			printf("------------------------------\n\n");                           //Printar um espa�o
			printf(" Dono: %s\n", pet[i].dono);                                     //Printar o Nome do Dono
			printf(" N�mero de Contato: %s\n", pet[i].cell);                        //Printar o N�mero para contato
			printf(" Nome do animal: %s\n", pet[i].nick);                           //Printar o Nome do Animal
			printf(" Esp�cie: %s\n", pet[i].esp);                                   //Printar a Esp�cie do Animal
			printf(" Ra�a: %s\n", pet[i].raca);                                     //Printar a Ra�a
			printf(" Sexo: %s\n", pet[i].sexo);                                     //Printar o Sexo
			printf(" Idade do animal: %d Anos\n", pet[i].idade);                    //Printar a Idade
			printf(" ID do Cliente: %d\n\n", pet[i].ID);                            //Printar o Id do Cliente
			printf("-----------------------------\n\n");                            //Printar um espa�o
		}
	} // i + 1
	
	getch();          //Ler sem mostrar 
	system("cls");	  //Limpar a tela
}

//--------------------------- BUSCA ---------------------------

void busca(){//Declarar uma fun��o sem retorno chamada busca
	int i; //Declara uma vari�vel para o contador
	system("cls");//Limpa a tela
	char opcaoB = 'A';//Atribui um valor para a op��o B
	
	if (geral.IDbusca<=9999||geral.IDbusca>=11000) //Verifica se o usu�rio inseriu um n�mero que n�o possui no sistema
	{
		
		printf("\n ERRO 404 :/ \n\n Desculpe, esse cadastro n�o existe");	//Printa um erro
		getch(); //Permite digitar um valor e n�o aparecer no sistema
		system("cls");	//Limpa a tela
		opcaoB = '2'; //Atribui o valor de 2 para a op��oB	
	}
	
	for (i = 0 ; i <= 100 ; i++) //Declara um contador at� 100 (Quantidade de animais que podem ser cadastrados)
	{
		if (pet[i].ID == geral.IDbusca)
		{
			geral.Save_i = i;                                         //Atribui o valor do contador na vari�vel geral
			printf("\n       Cliente Cadastrado com esse ID");        //Printar o T�tulo
			printf("\n------------------------------\n\n");           //Printar um espa�o
			printf(" Dono: %s\n", pet[i].dono);                       //Printar o Dono
			printf(" N�mero de Contato: %s\n", pet[i].cell);          //Printar o N�mero para Contato
			printf(" Nome do animal: %s\n", pet[i].nick);             //Printar o Nome do Animal
			printf(" Esp�cie: %s\n", pet[i].esp);                     //Printar a Esp�cie
			printf(" Ra�a: %s\n", pet[i].raca);                       //Printar a Ra�a
			printf(" Sexo: %s\n", pet[i].sexo);                       //Printar o Sexo 
			printf(" Idade do animal: %d Anos\n\n", pet[i].idade);    //Printar a Idade
			printf("-----------------------------\n\n");              //Printar um espa�o
			break;	//Quebra
		}

	}
			if (i>100) //Caso o usu�rio insira um Id errado
		{
			printf("\n Desculpe, n�o foi possivel achar esse cadastro... :/ \n\n Insira um novo ID para buscar novamente: "); //Mensagem de erro
			scanf("%d",& geral.IDbusca); //L� o novo Id
			system("cls"); //Limpa a tela
			busca(); //Chama a fun��o busca
		}
		
	printf("\n Cadastro correto? \n\n 1 - Sim \n 2 - N�o \n"); //Verifica se o Id encontrado � o procurado
	
	if (opcaoB != '2') //Caso n�o
	{
	opcaoB = getch(); //Permite ler a escolha sem que apare�a na tela
	}
	
	switch(opcaoB) //Permite escolher entre as 2 op��es
	{
		case '1': //Primeira escolha
			break; //Fim
			
		case '2': //Segunda escolha
			system("cls"); //Limpa a tela
			printf("\n Insira o ID correto: "); //Printa um novo comando
			scanf("%d",& geral.IDbusca); //L� o novo Id para ser encontrado
			system("cls"); //Limpa a tela
			busca(); //Chama a fun��o busca
			break; //Fim
	}
	
	
	geral.IDbusca = 0;	//Atribui o valor 0 para a busca
	system("cls");	//Limpa a tela
}
				
// ------------------------- EDI��ES ---------------------------
	
void editar() { //Declarar uma fun��o sem retorno chamada editar 
	
	char opcaoE = 'A'; //Atribuir o valor de A para a vari�vel op��oE
	
	while (opcaoE != '0') //Enquanto a op��o do usu�rio for diferente que 0, executa o c�digo abaixo
	{	
		printf("\n-------------=- EDITAR CADASTRO DO CLIENTE -=-------------\n\n"); //Printa o T�tulo
		printf(" 1 - Editar cadastro (por ID) \n 2 - Exluir cadastro (por ID) \n 3 - Emitir relatorio (se n�o souber o ID) \n\n 0 - Sair\n \n\n");  //Printa as op��es de editar
		
		opcaoE = getch(); //Permite que o usu�rio escolha, sem que a op��o apare�a na tela
		system("cls");    //Limpa a te
		
		switch(opcaoE) //Permite que o usu�rio escolha algo
		{	

//----------- Default -----------------------------------------------------------------------------------------------
		
			default: //Define o padr�o
				printf("\n Op��o invalida..."); //Printa um erro
				getch(); //Permite o usu�rio fazer alguma a��o sem que apare�a na tela
				system("cls"); //Limpa a tela
				break; //Fim


//----------- Sair --------------------------------------------------------------------------------------------------	
		
			case '0': //Caso escolha 0
				
				opcaoE = '0'; //Caso o valor da op��o seja 0
				break; //Quebra o c�digo
				
//----------- Emitir relatorio ---------------------------------------------------------------------------------------		
		
			case '3': //Caso escolha 3
				
				relatorio(); //Chama a fun��o relat�rio
				printf("\n-------------=- EDITAR CADASTRO DO CLIENTE -=-------------\n\n"); //Printa um t�tulo
				break; //Quebra o c�digo

//----------- Exluir cadastro ----------------------------------------------------------------------------------------		
				
			case '2':                                                           //Caso escolha 2
				int a;                                                          //Cria uma vari�vel do tipo inteiro
				char dec;                                                       //Cria uma vari�vel do tipo caract�r
				printf("\n Insira o ID do cadastro que sera excluido: ");       //Printa uma informa��o
				scanf("%d", & geral.IDbusca);                                   //L� o Id desejado
				busca();                                                        //Chama a fun��o busca
				a = geral.Save_i;                                               //Atribui um valor para (a)
				printf("\n Certeza desse a��o?\n");	                            //Printa uma pergunta
				scanf("%s", & dec);                                             //L� a escolha do usu�rio
				  
				if (dec=='s')                                                   //Condi��o de verdadeiro ou falso
				{                                                               //Caso sim
					pet[a].dono[0] = '\0';                                      //Atribui o valor do Dono para 0
					pet[a].ID = 0;                                              //Atribui o valor do ID para 0
					printf("\n A��o comcluida %c\n\n",a);	                    //Printa uma confirma��o
					break;                                                      //Fim
				}
				else                                                            //Caso n�o
				{
					printf("\n A��o cancelada\n");                              //Printa o cancelamento
					break;                                                      //Fim
				}
				break;                                                          //Quebra o c�digo
				
//----------- Editar cadastro -----------------------------------------------------------------------------------------			
				
			case '1':                                                               //Caso escolha 1
				int i;                                                              //Atribui uma nova vari�vel
				printf("\n Insira o ID do cadastro: ");                             //Printa uma pergunta
				scanf("%d", & geral.IDbusca);                                       //L� o ID
				                                                                    //Int i = busca();
				busca();                                                            //Chama a vari�vel busca
				i = geral.Save_i;                                                   //Atribui um valor para i
				printf("\n Oque voc� deseja alterar?");                             //Printa uma pergunta
				 
				char opcao1 = 'A';                                                  //Atribui uma nova v�riavel do tipo caracter
				
				while(opcao1 != '0')                                                //Permite ficar no menu enquanto o usu�rio n�o sair
				{
					printf("\n\n------- Cadastro Atual --------\n\n 1 - Nome: %s \n 2 - Telefone: %s \n 3 - Nome do Animal: %s \n 4 - Esp�cie do animal: %s \n 5 - Ra�a do animal: %s \n 6 - Sexo do animal: %s \n 7 - Idade do animal \n\n 8 - Cancelar \n 9 - Concluido \n\n",pet[i].dono,pet[i].cell,pet[i].nick,pet[i].esp,pet[i].raca,pet[i].sexo,pet[i].idade); //Printa as informa��es sobre aquele cadastro
					
					opcao1 = getch();                                               //Permite a escolha da op��o 1 n�o aparecer na tela
					system("cls");                                                  //Limpa a tela
					 
					switch (opcao1)                                                 //Permite o usu�rio escolher uma op��o
					{
					 
						case '1':                                                   //Primeira escolha
							printf("\n Insira a alter��o no nome: ");               //Printa o que ser� modificado
							scanf("%s", & pet[i].dono);                             //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo 
								
						case '2':                                                   //Segunda escolha
							printf("\n Insira a alte��o no telefone: ");            //Printa o que ser� modificado
							scanf("%s", & pet[i].cell);                             //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo
						
						case '3':                                                   //Terceira escolha
							printf("\n Insira a alter��o no nome do animal: ");     //Printa o que ser� modificado  
							scanf("%s", & pet[i].nick);                             //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo
						
						case '4':                                                   //Quarta escolha
							printf("\n Insira a alter��o na esp�cie: ");            //Printa o que ser� modificado
							scanf("%s", & pet[i].esp);                              //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo
						
						case '5':                                                   //Quinta escolha
							printf("\n Insira a altera��o na ra�a: ");              //Printa o que ser� modificado
							scanf("%s", & pet[i].raca);                             //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo
						
						case '6':                                                   //Sexta escolha
							printf("\n Insira a alter��o no sexo: ");               //Printa o que ser� modificado
							scanf("%s", & pet[i].sexo);                             //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo
						 
						case '7':                                                   //S�tima escolha
							printf("\n Insira a altera��o na idade do animal: ");   //Printa o que ser� modificado
							scanf("%s", & pet[i].idade);                            //L� a nova modifica��o feita pelo usu�rio
							break;                                                  //Quebra o c�digo
						
						case '8':                                                   //Oitava escolha
							opcao1 = '0';                                           //Atribui o valor 0 para a op��o e cancela a altera��o
							geral.Save_i=0;                                         //Atribui o valor 0 para a vari�vel geral
							break;                                                  //Quebra o c�digo
							
						case '9':                                                   //Nona escolha
							printf("\n Altera�oes salvas com sucesso");             //Printa uma confirma��o
							geral.Save_i=0;                                         //Atribui o valor 0 para a vari�vel geral
							opcao1 = '0';                                           //Atribui o valor 0 para a op��o
							break;                                                  //Quebra o c�digo
					}
				}
			break;	                                                                //Quebra o c�digo
		}		
	}
}	

// ------------------------- BANHOS ---------------------------

void banhos() {//Declarar uma fun��o sem retorno chamada banhos
	
	void cadastroB(void);//Chama a fun��o
	char opcao1 = 'A'; //Cria uma vari�vel do tipo caracter, e atribui o valor de 'A' para ela
	int i;//Cria uma vari�vel do tipo inteiro
	
	while (opcao1 != '0')//Permite o usu�rio fazer escolhas at� ele sair
	{	
		printf("\n ------------=- CADASTRO DE BANHOS -=--------------\n\n");//Printa um t�tulo
		printf("\n 1 - Banho para hoje \n 2 - Marcar data para banho \n\n 3 - Cancelar \n 4 - Concluido\n\n");//Printa as op��es do usu�rio
		
		opcao1 = getch();  //Permite o usu�rio escolher sem que apare�a na tela
		system("cls");     //Limpa a tela
		
		switch(opcao1)     //Permite o usu�rio escolher o que fazer
		{	
		
		default: //Define o padr�o
				printf("\n Op��o invalida..."); //Printa um erro
				opcao1 = getch(); //Permite o usu�rio escolher sem que a escolha dele apare�a
				system("cls"); //Limpa a tela
				break; //Fim
		
		case '4': //Quarta escolha
				printf("\n As a��es foram salvas! \n :D"); //Printa uma confirma��o
				opcao1 = '0'; //Atribui 0 para op��o1
				system("cls");//Limpa a tela
				break;//Fim
			
		case '3'://Terceira escolha
				opcao1 = '0';//Atribui 0 para op��o1
				system("cls");//Limpa a tela
				break;//Fim
				
		case '2'://Segunda escolha
				printf("\n Insira a data do banho: \n Dia: "); //Printa um comando
				scanf("%d",& geral.dia); //L� o dia
				printf(" M�s: "); //Printa um comando
				scanf("%d",& geral.mes);//L� o m�s
				printf(" Ano: ");//Printa um comando
				scanf("%d",& geral.ano);//L� o ano
				system("cls");//Limpa a tela
				cadastroB();//Chama a fun��o CadastroB
				break;//Fim
				
			case '1'://Primeira escolha
				
				time_t mytime; //Declara um struct de "meu tempo"
   				mytime = time(NULL);
   				struct tm tm = *localtime(&mytime);
   				geral.dia = tm.tm_mday; // Da valor do dia a varivel global
   				geral.mes = tm.tm_mon + 1; // Da valor do mes mais 1 ao varivel global
   				geral.ano = tm.tm_year + 1900; // Da valor do mes mais 1900 (so se salva 0-200) ao varivel global
   				
				printf("\n Banho cadastrado para hoje \n - Data: %d/%d/%d \n", geral.dia, geral.mes, geral.ano);//Printa a data do banho cadastrado
				cadastroB();//Chama a fun��o CadastroB
				break;//Fim
				
		}	
	}
	
}

// -------------------- CADASTROS BANHO -----------------------

void cadastroB(){ //Nova fun��o sem retorno
	
	int save; //Nova vari�vel	
	
	printf("\n Insira o ID do cadastro o qual marcara o banho: "); //Printa um comando
	scanf("%d", & geral.IDbusca);//L� o ID
	system("cls");//Limpa a tela
	busca();//Chama a fun��o busca
	save = geral.Save_i;//Atribui o valor encontrado para a vari�vel save
	
	for (int i = 0 ; i <= 7 ; i++)
	{
		if (pet[save].banho[i].dia == 0 )
		{
			pet[save].banho[i].dia = geral.dia;
			geral.dia = 0; //Atribui o valor 0
			pet[save].banho[i].mes = geral.mes;		
			geral.mes = 0; //Atribui o valor 0
	 		pet[save].banho[i].ano = geral.ano;
			geral.ano = 0; //Atribui o valor 0
			printf("\n Banho marcado com sucesso \n\n Aguardamos voc� %s e seu pet %s em: %d/%d/%d \n                                                                       - TOTOY & Cia",pet[save].dono,pet[save].nick,pet[save].banho[i].dia,  pet[save].banho[i].mes,  pet[save].banho[i].ano);//Printa a data marcada para o banho
			getch();//Sem retorno
			system("cls");//Limpa tela
			break;	//Fim
		}	
	}
	}

// -------------------- RELATORIO BANHO -----------------------

void relatB(){ //Nova fun��o sem retorno
	
	void sujinho(void); //Chama a fun��o
	int cont=0,ii; //Cria uma nova vari�vel e atribui o valor 0 � ela
	
	printf ("\n--------=- RELATORIO DOS BANHOS DOS ANIMAIS  -=--------\n"); //Printa um t�tulo
	
	for (int i = 0; i <= 99; i++ ) //Contador
	 {
		if (pet[i].dono[0] != '\0') //Verificar se existe algum registro sobre o pet
		{
			printf("\n\n------------------------------------------------------\n"); //Printa um espa�o
			printf("\n O(A) %s ",pet[i].dono); //Printa o nome do dono
			
			for (ii = 0 ; ii <= 7; ii ++) //Percorrer
			{
				if(pet[i].banho[ii].dia != 0) //Caso h� banhos registrados
				{
					cont++;//+1 para cont
					if (cont != 1)//Se cont for diferente de 1
					{
					printf("\n Data do Banho: %d/%d/%d ",pet[i].banho[ii].dia, pet[i].banho[ii].mes, pet[i].banho[ii].ano);//Printa a data do banho marcado	
					}
					else //Se cont for igual a 1
					{
					printf("tem registro de banho marcado em seu pet %s! \n",pet[i].nick);
					printf("\n Data do Banho: %d/%d/%d ",pet[i].banho[ii].dia, pet[i].banho[ii].mes, pet[i].banho[ii].ano);//Printa a data do banho marcado	
					}
				}
				if(ii == 7 && cont == 0) //Caso n�o h� banhos registrados
				{
	 				printf("\n N�o se tem resgistro de banhos \n\n 'Poh dono me de um banho!' \n                                       - %s ",pet[i].nick); //Printa um pedido
				}
				
			}
			printf("\n\n------------------------------------------------------\n"); //Printa um espa�o
	   	}
	cont=0;//zera o contador
	} 
	printf("\n\n------------------------------------------------------\n");//Printa um espa�o
	 
	getch();//Sem retorno
	system("cls");//Limpa a tela
}
	
// ----------------------- CADASTROS --------------------------

void cadastro() { //Declarar uma fun��o sem retorno para o cadastro
	system("cls"); //Limpar a tela

	
	printf ("\n----------=- CADASTRO DE ANIMAIS -=----------\n\n"); //Printar o t�tulo
	
	for (int i = 0; i <= 99; i++ )                    //Contador para cadastrar um animal
	 {
		if (pet[i].dono[0] == '\0')                   //Condi��o para cadastrar um animal
		 {
			printf("\n Dono: ");                      //Printar "Dono"
			scanf("%s", pet[i].dono);                 //Ler o Nome do Dono
			printf("\n N�mero de Contato: ");         //Printar "N�mero de Contato"
			scanf("%s",pet[i].cell);                  //Ler o N�mero para Contato
			printf("\n Nome do animal: ");            //Printar "Nome do Animal"
			scanf("%s",pet[i].nick);                  //Ler o Nome do Animal
			printf("\n Esp�cie: ");                   //Printar "Esp�cie"
			scanf("%s",pet[i].esp);                   //Ler a esp�cie
			printf("\n Ra�a: ");                      //Printar "Ra�a"
			scanf("%s",pet[i].raca);                  //Ler a Ra�a
			printf("\n Sexo: %s", pet[i].sexo);       //Printar "Sexo"
			scanf("%s",pet[i].sexo);                  //Ler o Sexo do Animal
			printf("\n Idade do animal: ");           //Printar "Idade do Animal"
			scanf("%d", & pet[i].idade);              //Ler a Idade do Animal
			pet[i].ID = i + 10000;                    //Declarar o N�mero de Identifica��o do Dono, sendo Equivalente ao N�mero que est� no Contador, Somado com 10.000 

			printf("Cliente Cadastrado com Sucesso\n ID (Numero de Identifica��o) do cliente/animal: %d",pet[i].ID); //Printar a Confirma��o do Cadastro do Cliente
			printf("----------------------------\n\n"); //Printar um Espa�o
			system("cls"); //Limpar a tela
			break; //Quebrar o comando
		}
	} // i + 1
}

// Fim espero que tenh�o gostado :D
