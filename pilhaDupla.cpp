#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alergico[5];
char qualquer[5];

int ponto =0;
int ponto2= 0; 


int push(int pus);
int push2(int pus2);
void pop();
void pop2();
void exibir();
void exibir2();


struct alimento {
		int cod;
		char nome[20];
	};
struct alimento2 {
		int cod;
		char nome[20];
	};

struct alimento e[2];
struct alimento2 a[2];
main(){
	//struct mercadoria e[2];
	char ali[20];
	int op=0, x=0, y=0, z=0;
	
	for(int i=0;i<99;i++){
		system("cls");
		printf("\n******PILHA******\n");
		printf("Escolha uma opcao: \n");
		printf("1 - PUSH\n2 - POP\n3 - Exibir\n4 - Sair");
		scanf("%i",&x);
		
		if(x == 1){
			printf("\nQual alimentos gostaria de inserir na pilha: \n");
			scanf("%s",&ali);
		 
		 	printf("\nO alimento: %s contem ingredientes alergicos?",ali);
		 	printf("\n1 - Sim\n2 - Nao\n");
		 	scanf("%i",&op);
		 	if(op == 1){
		 		strcpy(e[ponto].nome,ali);
		 		push(i);
			 }else{
			 	strcpy(a[ponto2].nome,ali);
			 	push2(i);
			 }
		}else if(x == 2){
			printf("\nGostaria de retirar um alimento de qual pilha: \n");
			printf("\n1 - Comuns\n2 - Alergicos\n");
			scanf("%i",&y);
			if(y == 1){
				pop();
			}else if(y == 2){
				pop2();
			}
		}else if(x == 3){
			printf("\nGostaria de listar qual lista:\n");
			printf("1 - Comuns\n2 - Alergicos\n");
			scanf("%i",&z);
			if(z == 1){
				exibir();
				system("pause");
			}else if(z == 2){
				exibir2();
				system("pause");
			}
		}else{
			break;
		}
	}
}


int push(int pus){
	e[ponto].cod = pus;
	ponto ++;
}

int push2(int pus2){
	a[ponto2].cod = pus2;
	ponto2 ++;
}

void pop(){
	e[ponto].cod = -1;
	ponto --;
	printf("-");
}

void pop2(){
	alergico[ponto2] = NULL;
	ponto2 --;
	printf("-");
}

void exibir()
{
	int j;
	
	for(j=0;j<=ponto;j++)
	{
		if (ponto == 0)
		{
			printf("Pilha vazia!");
		}else{
			if(e[j].cod < 1){
				printf("");
			}
			printf("%s\n",e[j].nome);
		}
	}
}

void exibir2()
{
	int j;
	
	for(j=0;j<=ponto2;j++)
	{
		if (ponto2 == 0)
		{
			printf("Pilha vazia!");
		}else{
			if(a[j].cod < 0){
				printf("");
			}else{
				printf("%s\n",a[j].nome);
			}
			
		}
	}
}
