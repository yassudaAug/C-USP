#include "grafos.c"

int main(){   
    PONT g = criarGrafo();
    
    InicializaGrafoVazio(g, 2);
    InsereAresta(g, 1, 1 , 6);
    InsereAresta(g, 0, 1 , 6);
    InsereAresta(g, 1, 0 , 6);
    InsereAresta(g, 0, 0 , 6);
    // InsereAresta(g, 1, 1 , 5);
  
    // InsereAresta(g, 5, 1 , 9);
    // InsereAresta(g, 1, 5 , 4);
    // InsereAresta(g, 2, 1 , 7);
    // InsereAresta(g, 10, 15 , 9);
    // InsereAresta(g, 4, 8 , 3);
    ListaVerticesAdjVazia(7, g);
    ImprimeGrafo(g);
    //LiberaGrafo(g);
    
    return 0;
}