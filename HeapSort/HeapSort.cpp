// HeapSort

#include<iostream> 

using namespace std; 

void Max_Heapify(int aray[], int raiz, int tamanho)
{    //"tornar heap"

	int FilhoEsq = 2*raiz+1;
	int FilhoDir = 2*raiz+2;
	int maior = raiz;

	if(FilhoEsq < tamanho && aray[FilhoEsq] > aray[maior])
		maior = FilhoEsq;   // Verifica se o filho esquerdo existe e se ele for maior que a raiz ocorre a troca..
	
	if(FilhoDir < tamanho && aray[FilhoDir] > aray[maior])
		maior = FilhoDir;   // Verifica se o filho direito existe e se ele for maior que a raiz ocorre a troca..

	// Se houve troca do valor de "maior" durane os ifs, significa que a raiz não era o maior elemento, então temos que achar heapify para arrumar o resto...
    if (maior != raiz)
    {
        swap(aray[raiz], aray[maior]); // troca os elementos da raiz inicial com o maior elemento apos o 1 heapify.

        Max_Heapify(aray, maior, tamanho); // chama denovo o heapify para arrumar o resto do heap.
    }
}

void HeapSort(int aray[], int tamanho)
{
    // O primeiro passo é criar um heap maximo, para isso vamos utilizar o metodo heapify, nao vamos chamar nas folhas pois ja estao "ordenadas"...
    for (int i = ((tamanho / 2) - 1); i >= 0; i--)// do meio pra esquerda
        Max_Heapify(aray, i, tamanho);//Cria Heap a partir dos dados 

    for (int i=(tamanho-1); i>=0; i--)
    {
        // Troca a raiz com o ultimo elemento do heap...
        swap(aray[0], aray[i]);

        // Chama o Max_heapify para tornar o heap novamente num MAX_HEAP...
        Max_Heapify(aray, 0, i);
    }
}

int main()
{
    int aray[] = {5,1,5,8,9,3,1,8,58,582,84,85,1,0,14,5,888};
    int tamanho = sizeof(aray)/sizeof(aray[0]);

   cout << "Antes de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    HeapSort(aray, tamanho);

    cout << "Depois de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    return 0;
}
	


