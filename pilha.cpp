#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int *pilha;

int ponto = 0;

int push(int pus);
void pop();
void exibir();

int main(){
	
	pilha = (int *)malloc (5 * sizeof(int));
	int i=0,resp=0,x=0;
	
	for	(;;){
		system("cls");
		printf("#  menu  #\n");
		printf("\n1. PUSH\n2. POP\n3. Exibir\n4. Exit\n");scanf("%i", &resp);
		switch(resp){
			
		case 1 :
			printf("\nQual o valor deseja inserir: ");scanf("%i", &x);
			push(x);
			break;
		
		case 2 :
			pop();
			break;
			
		case 3 :
			exibir();
			break;
				
		case 4 :
			exit(1);
			break;
		}
	}
}

int push(int pus){

		pilha[ponto] = pus;
		ponto ++;
		printf("Valor inserido: %i\n",pus);
		Sleep(1000);
		
	}

void pop()
{
	if(ponto <= 0){
		printf("Pilha vazia!\n");
	}else{
		ponto --;
		printf("\nValor removido: %i\n",pilha[ponto]);
		pilha [ponto] = NULL;
	}

	Sleep(1000);
	
}
void exibir()
{
	int j;
	
	for(j=0;j<ponto;j++)
	{
		if (ponto == 0)
		{
			printf("Pilha vazia!");
		}else
		{
			printf("%i\n",pilha[j]);
		}
		
	}
	system("pause");
}

