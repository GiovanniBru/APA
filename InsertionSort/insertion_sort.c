
#include <stdio.h>

int main()
{
	int i, j, num_atual,
		num_vet[5] = {5, 3, 10, 1, 6}; 

	for(i = 1; i < 5; i++)
	{
		num_atual = num_vet[i];  

		j = i - 1; 

		while((j >= 0) && (num_atual < num_vet[j]))
		{
			num_vet[j+1] = num_vet[j]; 

			j--; 
		}

		num_vet[j+1] = num_atual; // num_vet[3] = num_atual
	}

	for(i = 0; i < 5; i++)
		printf("%d ", num_vet[i]);

	system("PAUSE>>NULL");


return 0;
}