#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct tno {

	int ra;
	char nomeAluno[50];
	float nota;
	struct tno *prox;
};

typedef struct tno no;

no *cria_lista(void)
{
	return NULL;
}

void exibe(no *alunos);
no *insereOrdenado(no *lista, no *novaLista);
int verificaRepetido(no *cadastrados, int verifica);
no *insereAluno(int ra, char nomeAluno[50], float nota);
void buscaAluno(no *cadastrados, int opcao);

int main()
{
	int opcao;
	int ra;
	char nomeAluno[50], e;
	float nota;
	no *alunos, *aux;

	alunos = cria_lista();

	do
	{
		//menu
		//system("cls");
		system("clear");
		printf("\n -MENU- \n");
		printf("1. Inserir o cadastro de um aluno \n");
		printf("2. Buscar aluno por RA \n");
		printf("3. Buscar aluno por Nome \n");
		printf("4. Exibir dados de todos os alunos cadastrados \n");
		printf("5. Sair \n\n >");

		scanf("%d", &opcao);
		__fpurge(stdin);

		switch (opcao)//chamada para opção selecionada
		{
		case 1:
			//system("cls");
			system("clear");

			printf(" -Cadastro de Alunos- \n\n");

			printf(">Digite o RA do aluno: ");
			scanf("%d", &ra);
			__fpurge(stdin);

			printf(">Digite o nome do aluno: ");
			gets(nomeAluno);
			__fpurge(stdin);

			printf(">Digite a nota do aluno: ");
			scanf("%f", &nota);
			__fpurge(stdin);

			if (verificaRepetido(alunos,ra) == 0)//Verifica se o não existem alguém com o mesmo RA
			{
				aux = NULL;
				aux = insereAluno(ra, nomeAluno, nota);//Cria um novo segmento da lista com os dados inseridos
				
				if (aux != NULL)//Verifica se a lista retornada não é nula indicando falta de memoria
				{
					alunos = insereOrdenado(alunos, aux);//Insere de forma ordenada o segmento criado, na lista principal
				}
				else
				{
					printf("\nSem memoria\n");
				}

				printf("\n\n -Aluno cadastrado com sucesso-\n");
				//system("pause");
				getchar();
			}
			break;

		case 2:
			buscaAluno(alunos,1);//Busca aluno por RA
			break;

		case 3:
			buscaAluno(alunos, 2);//Busca aluno por nome
			break;

		case 4:
			exibe(alunos);//Exibe todos cadastrados
			break;


		case 5:
			//system("cls");
			system("clear");
			printf("\n Deseja mesmo sair? (s/n)\n\n >");//Comfirmação de saída do programa
			scanf("\n%c", &e);
			__fpurge(stdin);

			if (e != 's')
			{
				opcao = 0;
			}
			//system("cls");
			system("clear");

			break;
		}

	} while (opcao != 5);

	free(alunos);

	return 0;
}




void exibe(no *alunos)
{
	no *temp = alunos;
	int j;

	//system("cls");
	system("clear");
	if (temp == NULL)
	{
		printf("Nenhum aluno cadastrado\n\n");
		//system("pause");
		getchar();
	}
	else
	{
		printf("Nota  Aluno                                             RA\n\n");

		for (temp = alunos; temp != NULL; temp = temp->prox)
		{
			if (temp->nota < 10)//Alinha a nota
			{
				printf(" %.1f  ", temp->nota);
			}
			else
			{
				printf("%.1f  ", temp->nota);
			}

			printf("%s", temp->nomeAluno);//Imprime nome

			j = strlen(temp->nomeAluno);

			while (j < 50)
			{
				printf(".");//Alinha RA
				j++;
			}

			printf("%d\n", temp->ra);//Imprime RA
		}
		//system("pause");
		getchar();
	}
}

no *insereOrdenado(no *lista, no *novaLista)
{
	no *temp = NULL, *temp1 = lista;

	if (temp1 == NULL)
	{
		lista = novaLista;//Se a lista está vazia, os novos dados são a lista
	}
	else
	{
		while (temp1 != NULL && novaLista->ra > temp1->ra)//Encontra a posição correta na lista
		{
			temp = temp1;
			temp1 = temp1->prox;
		}

		if (temp == NULL)//Insere na posição correta
		{
			novaLista->prox = lista;
			lista = novaLista;
		}
		else
		{
			novaLista->prox = temp1;
			temp->prox = novaLista;
		}
	}

	return lista;//Retorna a lista ordenada
}

int verificaRepetido(no *cadastrados, int verifica)//Verifica se o RA já exite
{
	no *temp = cadastrados;
	int verificador = 0;

	if (temp != NULL)
	{
		if (temp->ra == verifica)
		{
			printf("\n ERRO!!!: -RA ja cadastrado- \n");
			//system("pause");
			getchar();
			verificador = 1;
			return verificador;//Retorna 1 sinalizando para que não seja alocado espaço para este segmento 
		}
		else
		{
			verificaRepetido(temp->prox, verifica);//Chamada recursiva percorrendo a lista
		}
	}
}



no *insereAluno(int ra, char nomeAluno[50], float nota)//Aloca espaço e cria um novo segmento para ser inserido na lista
{
	no *aluno = (no*)malloc(sizeof(no));

	aluno->ra = ra;
	aluno->nota = nota;
	strcpy(aluno->nomeAluno, nomeAluno);
	aluno->prox = NULL;

	return aluno;//Retorna esse segmento

}


void buscaAluno(no *cadastrados, int opcao)//Encontra e imprime o aluno de desejado
{
	char aluno[50];
	int ra, j;
	no *aux = cadastrados;

	switch (opcao)
	{
	case 1: //Busca por RA

		if (cadastrados != NULL)
		{
			//system("cls");
			system("clear");
			printf(" -Digite o RA do aluno desejado\n\n >");
			scanf("%d", &ra);
			__fpurge(stdin);

			j = 0;
			for (aux = cadastrados; aux != NULL; aux = aux->prox)
			{
				if (aux->ra == ra)
				{
					printf("\nNota  Aluno                                             RA\n");

					if (aux->nota < 10)
					{
						printf(" %.1f  ", aux->nota);
					}
					else
					{
						printf("%.1f  ", aux->nota);
					}

					printf("%s", aux->nomeAluno);

					j = strlen(aux->nomeAluno);

					while (j < 50)
					{
						printf(".");
						j++;
					}

					printf("%d\n\n", aux->ra);
					//system("pause");
					getchar();
				}
			}

			if (j == 0 && cadastrados != NULL)
			{
				printf("\n Aluno nao encontrado\n\n");
				//system("pause");
				getchar();
			}
		}
		else
		{
			//system("cls");
			system("clear");
			printf("Nenhum aluno cadastrado\n\n");
			//system("pause");
			getchar();
		}
		break;


	case 2: //Busca por nome

		if (cadastrados != NULL)
		{
			//system("cls");
			system("clear");
			printf(" -Digite o NOME do aluno desejado\n\n >");
			gets(aluno);
			__fpurge(stdin);

			j = 0;
			for (aux = cadastrados; aux != NULL; aux = aux->prox)
			{
				if (strcmp(aux->nomeAluno, aluno) == 0)
				{
					printf("\nNota  Aluno                                             RA\n");

					if (aux->nota < 10)
					{
						printf(" %.1f  ", aux->nota);
					}
					else
					{
						printf("%.1f  ", aux->nota);
					}

					printf("%s", aux->nomeAluno);

					j = strlen(aux->nomeAluno);

					while (j < 50)
					{
						printf(".");
						j++;
					}

					printf("%d\n\n", aux->ra);
					//system("pause");
					getchar();
				}
			}

			if (j == 0 && cadastrados != NULL)
			{
				printf("\n Aluno nao encontrado\n\n");
				//system("pause");
				getchar();
			}
		}
		else
		{
			//system("cls");
			system("clear");
			printf("Nenhum aluno cadastrado\n\n");
			//system("pause");
			getchar();
		}

		break;
	}
}

