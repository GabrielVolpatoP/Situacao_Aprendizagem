#include <conio.h> // Para desenhar tela, manipular caracteres
#include <stdio.h> // Para usar printf scanf
#include <string.h> // Para utilizar strcpy
#include <locale.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
	char dono[30];		// Nome do proprietaria
	char cell[20];		// Celular do Dono
	char nick[20];		// Nome do "TOTO"
	char esp [20];		// Especia animal
	char raca[20];		// Raça do animal
	char sexo[20];		// Sexo do animal
	int  idade;			// Idade do animal
	int  ID;			// Numero de Identificação
	char banhoS[3];
	char seca[100];
	
} Cadastro;

Cadastro pet[100] ={}; 

typedef struct 
{
	int IDbusca;
	int IDeditar;
	int Save_i;
} All;

All geral = {};

void banhoInf()
{
	
	char opcao2;
	opcao2 = 'A';
				
	while (opcao2 != '0')
	{
		printf("\n\n Como o banho deve ser? \n\n 1 - Banho Simple:\n - Banho\n - Secagem\n - Limp. olhos  \n 2 - Banho Completo:\n - Banho\n - Secagem\n - Limp. olhos\n - Corte d' unhas\n - Limp. ouvidos\n\n");
				
		opcao2 = getch();
		system("cls");
				
		switch(opcao2)
		{
			case '1':
				
				int opcao2_1;
				
				for(opcao2_1 = 1; opcao2_1 <= 5; opcao2_1++)
				{
				system("cls");
				printf("\n Banho simples selecionado! \n\n Etapas para ser concluido %d/4\n",opcao2_1);
				
				switch(opcao2_1)
				{
					case 1:
						printf("\n Pre Banho - Escovar os pelos p/ desembaranhar (pente de nós)\n 1 - Sim \n 2 - Não");
					
						geral.banhoS[0] = getch();
						break;
					
					case 2:
						printf("\n Secagem \n 1 - Afofar o pelo, c/ secador de alta velocidade \n 2 - cães de pelos curtos, secagem em canil ou gaiola \n 3 - raças pequenas e de pelo duro uso de toalha");
					
						geral.banhoS[1] = getch();
						break;
						
					case 3:
						printf("\n LIMP. OLHOS - limp. em volta da área dos olhos \n 1 - Sim \n 2 - Não");
						
						pet.banhoS[2] = getch();
						break;
						
					case 4:
						printf("\n Pos Banho - creme para pelugem (para animais com pelos longos)\n 1 - Sim \n 2 - Não ");

						geral.banhoS[3] = getch();
						break;
						
					case 5:
						system("cls");
						opcao2 = '0';
						break;
				}
				}
				
				
		}
	}

}				
				

// -------------------- INTERFACE BANHOS -------------------------

void banhos() {
	
	char opcao1 = 'A';

	printf("\n---------------=- CADASTRO De BANHOS -=----------------\n\n");
	
	while (opcao1 != '1')
	{
		printf("\n 1 - Banho para hoje \n 2 - Marcar data para banho \n 3 - Excluir banho marcado \n\n 4 - Cancelar \n 5 - Concluido\n\n");
		
		opcao1 = getch();
		system("cls");
		
		switch(opcao1)
		{
			case '1':
				const time_t timer = time(NULL);
				printf("\n Banho marcado para hoje: %s", ctime(&timer));
				banhoInf();
				opcao1='1';
				break;
				
				
		}	
	}
	
}

int main(){
	setlocale(LC_ALL, "Portuguese"); 
	banhos();
	for (int i=0;i<4;i++){
		printf("\n %c",pet.banhoS[i]);
	}
	for (int ii=0;ii<4;ii++){
		
		if(i!=1)
		{
			if(pet.banhoS[i]='1')
			{
				pet.banhoS[i] = 'S';
			}
			else
			{
				pet.banhoS[i] = 'N';
			}
			
		}
		else
		{
			if(pet.banhoS[i]==1)
			{
				pet.seca = "Secador";	
			}
			if(pet.banhoS[i]==2)
			{
				pet.seca = "Secamento Canil";
			}
			if(pet.banhoS[i]==3)
			{
				pet.seca = "Secamento Canil";
			}
		}
	}
}
