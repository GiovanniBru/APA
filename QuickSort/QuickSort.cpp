#include <iostream>

using namespace std;

int Partition(int aray[], int esq, int dir){  // Neste caso vamos pegar sempre o ultimo elemento como o pivo.
    int pivo, leftWall;
    pivo = aray[dir];
    leftWall = esq-1; // Índice da barreira de menor elemento

    for(int i=esq;i<=(dir-1);i++){

        if(aray[i] <= pivo){ // Verifica se o elemento atual é menor ou igual o pivo.
            leftWall++;
            swap(aray[i],aray[leftWall]); // Se for menor, joga ele pro lado esquerdo da barreira (elementos menores que o pivo)
        }
    } // Quando o for termina é pq o pivô não achou ninguém menor que ele, agora é só trocar o pivo pelo elemento logo após a leftWall.
    swap(aray[leftWall+1],aray[dir]);

    return (leftWall+1);
}

void QuickSort(int aray[],int esq, int dir){
    int localizacaoPivo;


    if(esq<dir){
        localizacaoPivo = Partition(aray,esq,dir); // Recebe o valor do pivo previo, que já está no lugar correto.
        QuickSort(aray,esq,localizacaoPivo-1);
        QuickSort(aray,localizacaoPivo+1,dir);
    }
}

int main()
{
    int aray[] = {12, 11, 13, 5, 6, 7,15,14,0,50,20,28,80,50,2,6,4,0,1,2,3,5,4,8,9,1,1,15,14,1,58,546,644,21455,108,5};
    int tamanhoDoArray = sizeof(aray)/sizeof(aray[0]);
    int i;
    cout << "Array antes de ser ordenado:" << endl;
    for (i=0; i < tamanhoDoArray; i++)
    {
        cout << aray[i] << " ";
    }

    QuickSort(aray, 0, tamanhoDoArray - 1);

    cout << endl << "Array depois de ser ordenado:" << endl;
    for (i=0; i < tamanhoDoArray; i++)
    {
        cout << aray[i] << " ";
    }

}
