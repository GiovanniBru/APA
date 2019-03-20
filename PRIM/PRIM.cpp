//Giovanni Bruno - APA - PRIM
//O Algoritmo de PRIM propõe encontrar a árvore geradora mínima de um grafo.
//Isto significa que ele encontra um subgrafo que forme uma árvore que inclua todos os vértices do grafo original,
//onde a soma dos pesos das arestas das árvores, será o mínimo possível

#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

#define V 4

void PRIM(int G[V][V]){
  int a=0;//aresta
  int s[V];

  memset(s, 0, sizeof(s)); //define um bloco especificado de memória para um caractere especificado, sobrescrevendo os dados origiais
  s[0] = 1;

  int x;//linha
  int y;//coluna

  cout << "Aresta" << " - " << "Peso"<<endl;

  while(a < V - 1){
    int min =10000;
      x = 0;
      y = 0;
      int i,j;

      for (i = 0; i < V; i++){
        if (s[i]){
            for (j = 0; j < V; j++){
              if (!s[j] && G[i][j]){
                  if (min > G[i][j]){
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
              }
          }
        }
      }
      cout << x <<  " - " << y << "  = " << G[x][y];
      cout << endl;
      s[y] = 1;
      a++;
    }
}

int main () {

    int G[V][V] = {
            {0, 25, 14, 29},
            {18, 0, 20, 26},
            {12, 20, 0, 15},
            {29, 20, 24, 0}
    };

    PRIM(G);

  return 0;
}
