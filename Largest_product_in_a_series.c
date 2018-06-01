#include<stdio.h>
#define MAX 100

int main()
{
	int T=0, K[MAX]={0}, N[MAX]={0}, maxp, prod, aux, i, j, k;
	char D[MAX][MAX];
	
	do{
		fflush(stdin);
		scanf("%i", &T);
		if(T < 1 || T > 100)
		{
			printf("\n\nIntentalo de nuevo.\n\n");
			printf("T debe ser mayor que 0 y menor que 101\n\n");
			system("pause");
			system("cls");
		}
	}while(T < 1 || T > 100);
	
	for(i = 0; i < T; i++)
	{
		do{
			fflush(stdin);
			scanf("%i %i", &N[i], &K[i]);
			if(K[i] < 1 || K[i] > 7 || N[i] < K[i] || N[i] > 1000)
			{
				printf("\n\nIntentalo de nuevo.\n\n");
				printf("Se debe cumplir lo siguiente para el primer\n   y el segundo valor respectivamente:\n");
				printf("\t K <= N <= 1000\n");
				printf("\t 1 <= K <= 7 \n");
				system("pause");
				system("cls");
				printf("%i\n", T);
				for(j = 0; j < i; j++)
				{
					printf("%i %i\n", N[j], K[j]);
				}
			}
		}while(K[i] < 1 || K[i] > 7 || N[i] < K[i] || N[i] > 1000);
		fflush(stdin);
		fgets(D[i], N[i]+1, stdin);
	}
	
	for(i = 0; i < T; i++)
	{
		maxp = 0;
		for(j = 0; j < N[i] - K[i] + 1; j++)
		{
			prod = 1;
			for(k = j; k < j + K[i]; k++)
			{
				aux = (int)(D[i][k] - 48);
				prod *= aux;
			}
			if(prod > maxp)
			{
				maxp = prod;
			}
		}
		printf("\n%i\n", maxp);
	}
	
	return 0;
}
