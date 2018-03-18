#include <stdlib.h>
#include <stdio.h>


typedef tno no;

struct tno{

	int ra;
	char nomeAluno[50];
	float nota;
	struct no *prox;
}




void insereAluno(int ra, char nomeAluno[50], float nota){


	
}

void exibeDados(){

}



int main(){


int opcao=0;
int ra;
char nomeAluno[50];
float nota;




	while(opcao != -1)
	{

		printf("\n MENU \n");
		printf("1. Inserir o cadastro de um aluno \n");
		printf("2. Buscar aluno por RA \n");
		printf("3. Buscar aluno por Nome \n");
		printf("4. Exibir dados de todos os alunos cadastrados \n");
		printf("5. Sair \n")
		scanf("&d",opcao);


		
		if(opcao == 1)
		{

			printf("Digite o RA do aluno:");
			scanf("%d",ra);

			printf("Digite o nome do aluno:");
			gets(nomeAluno);

			printf("Digite a nota do aluno:");
			gets("%f", nota);
			
			//Insere Aluno
			insereAluno(ra,nomeAluno,nota);
		}

		if(opcao == 2)
		{

			printf("Digite o RA do aluno:");
		}
		
		if(opcao == 3)
		{
			printf("Digite o nome do aluno:");
		}

		if(opcao == 4)
		{
			
		}

		if(opcao == 5)
		{
			opcao = -1;
		}

		else
		{
			printf("Opcao Invalida!\n");
		}

	}





}

