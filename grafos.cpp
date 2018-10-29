#include <stdio.h>
#include <stdlib.h>

struct grafos{
	int id;
	int cor;
};
struct grafos g[8];

void preencher();
int colorir(int local);

int i=0, j, flag = 0, qtCor = 0;
int adj[8][8];
int vet[8];
int cores[10]={1,2,3,4,5,6,7,8,9,10};

main(){
	int local;
	int op;
	
	preencher();
		
	for(;;){
		printf("\n\n\nDigite a opcao desejada\n");
		printf("1 - colorir Grafo\n");
		printf("2 - Busca em Profundidade\n");
		printf("3 - Sair\n");
		scanf("%i", &op);
		
		if(op==3){
			break;
		}else if(op==1){
			local=0;
			while(local<=7){
				colorir(local);
				local++;
			}
			printf("Foram necessarios %i cores para o grafo\n",qtCor+1);
			system("pause");
		}else if(op==2){
			printf("Digite o numero para fazer a busca em profundidade\n");
			scanf("%i",&local);
			
			printf("Ligacao com:\n");
			for(j = 0;j < 8; j++){
				if(adj[local][j] == 1 && local != j && local >= j){
					printf("%i\t",j);
				}
			}
			printf("X\n");					
			system("pause");
					
		}else{
			printf("Opcao inexistente");
		}
		system("cls");
	}
	
}

void preencher(){
	
	for(i=0;i<8;i++){
		g[i].id=i;
		g[i].cor=NULL;
		for(;;){
			printf("O grafo %i tem ligacao com quais outros grafos?  -->  (Negativo para finalizar)\n-->",i);
			scanf("%i",&flag);
			
			if(flag < 0){
				break;
			}else{
				adj[i][flag]=1;
				adj[flag][i]=1;
			}	
		}	
	}
	system("cls");
}

int colorir(int local){
	if(g[local].cor!=NULL){
		return 0;
	}else{	
		i=0;
		g[local].cor=cores[0];
		flag=0;
		for(j=0; j<5;j++){
			
			if(adj[local][j] == 1 && local!=j){
				vet[i]=j;
				i++;
			}
		}
		for(j=0;j<i;j++){
			if(g[local].cor == g[(vet[j])].cor){
				flag++;
				g[local].cor = cores[flag];
				
			}
		}
		if(flag > qtCor){
			qtCor = flag;
		}
	}
	return 0;
}



