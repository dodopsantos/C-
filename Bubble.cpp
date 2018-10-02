#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 5

void bubbleSort(int valores[], int n);
void printValores(int valores[], int n);

int valor=0;
int valores[MAX];

int main()
{
	for(int i = 0;i < MAX;i++){
		
		printf("*** Inserir valor: ***\n ->");
		scanf("%i",&valor);
	    valores[i] = valor;
	    system("cls");
	}

    bubbleSort(valores, MAX);
    printValores(valores, MAX);
    return 0;
}

void bubbleSort(int valores[], int n)
{
   int temp=0;
   int i, j;
   for (i = 0; i < n-1; i++) {
      
       for (j = 0; j < n-i-1; j++) 
           if (valores[j] > valores[j+1]){
           	temp = valores[j];
           	valores[j] = valores[j+1];
           	valores[j+1] = temp;
		   }
	}
}

void printValores(int valores[], int 	n)
{
    int i;
    printf("Valores ordenados: \n");
    for (i=0; i < n; i++){
        printf("%d ", valores[i]);
	}
	FILE *f;
    f = fopen("Blubble_Sort.txt","w");
	
	fprintf(f,"Valores ordenados:\n");
	for (int j=0; j<MAX; j++){
        	fprintf(f,"%dª valor: %d\n",j+1,valores[j]);
   		 }
   		 fclose(f);
}



