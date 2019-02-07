#include <iostream>

using namespace std;

void Merge(int arr[], int esq, int med, int dir)
{
    int i, j, k;

    int n1 = med - esq + 1;
    int n2 = dir - med;

    // CRIA OS ARRAYS TEMPORARIOS..
    int TempL[n1], TempR[n2];

    // COPIAS AS INFORMACOES PARA OS ARRAYS TEMPORARIOS
    for (i = 0; i < n1; i++)
        TempL[i] = arr[esq + i];
    for (j = 0; j < n2; j++)
        TempR[j] = arr[med + 1 + j];



    // UNE OS ARRAYS TEMPORARIOS DE VOLTA EM UM ARRAY UNICO, ORDENADO.
    i = 0; // INDICE INICIAL DO ARRAY TEMPORARIO DA ESQUERDA (TempL)
    j = 0; // INDICE INICIAL DO ARRAY TEMPORARIO DA DIREITA (TempR)
    k = esq; // INDICE INICIAL DO ARRAY APOS A UNIAO

    while (i < n1 && j < n2)
    {
        if (TempL[i] <= TempR[j])
        {
            arr[k] = TempL[i];
            i++;
        }
        else
        {
            arr[k] = TempR[j];
            j++;
        }
        k++;
    }

    // COPIA OS DADOS RESTANTES NO ARRAY TempL[], SE AINDA SOBRARAM
    while (i < n1)
    {
        arr[k] = TempL[i];
        i++;
        k++;
    }

    // COPIA OS DADOS RESTANTES NO ARRAY TempR[]
    while (j < n2)
    {
        arr[k] = TempR[j];
        j++;
        k++;
    }
}

void MergeSort(int aray[], int esq, int dir)
{
    if (esq < dir)
    {
        // med É O VALOR MÉDIO
        int med = ((esq+dir)/2);

        // CHAMADA RECURSIVA, ORDENDA AS DUAS METADES...
        MergeSort(aray, 0, med);
        MergeSort(aray, med+1, dir);

        Merge(aray, esq, med, dir);
    }
}

int main()
{
    int aray[] = {12, 11, 13, 5, 6, 7,5,1,0,10,80,45,4,45,13,15,16};
    int tamanhoDoArray = sizeof(aray)/sizeof(aray[0]);
    int i;
    cout << "Array antes de ser ordenado:" << endl;
    for (i=0; i < tamanhoDoArray; i++)
    {
        cout << aray[i] << " ";
    }

    MergeSort(aray, 0, tamanhoDoArray - 1);

    cout << endl << "Array depois de ser ordenado:" << endl;
    for (i=0; i < tamanhoDoArray; i++)
    {
        cout << aray[i] << " ";
    }

}

