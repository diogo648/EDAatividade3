#include <stdlib.h>
#include <stdio.h>


typedef tno no;

struct tno{

	int ra;
	char nomeAluno[50];
	float nota;
	struct no *prox;
}


int insereAluno(int ra, char nomeAluno[50], float nota, no **proxAluno){

	
	
}



int main(){


int opcao;
int ra;
char nomeAluno[50];
float nota;



while(opcao)
printf("\n MENU \n");
printf("1. Inserir o cadastro de um aluno \n");
printf("2. Buscar aluno por RA \n");
printf("3. Buscar aluno por Nome \n");
printf("4. Exibir dados de todos os alunos cadastrados \n");
printf("5. Sair \n")
scanf("&d",opcao);



if(opcao == 1){

	printf("Digite o RA do aluno:");
	scanf("%d",ra);

	printf("Digite o nome do aluno:");
	gets(nomeAluno);

	printf("Digite a nota do aluno:");
	gets("%f", nota);

	insereAluno(ra,nomeAluno,nota);
}



}

