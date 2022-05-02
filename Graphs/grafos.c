#include "grafos.h"
PONT criarGrafo(){
    PONT grafo = malloc(sizeof(TipoGrafo));

    return grafo;
}

void InicializaGrafoVazio(PONT grafo, int nv){
    int i, j;
    if (nv > 101){
        printf("bruh1\n");
    }
    if (nv <= 0){
        printf("bruh2\n");
    }
    else{
            grafo->numVertices = nv;
            for(i = 0; i < grafo->numVertices; i++){//linha
                for(j = 0; j < grafo->numVertices; j++){ //coluna
                    grafo->mat[j][i] = -1;     
                }
            }
        printf("ok \n");    
    }
}

bool ExisteAresta(PONT grafo,  int v1, int v2){
    if(grafo->mat[v1][v2] != -1){
        return true;
    }
    return false;
}

bool InsereAresta(PONT grafo, int v1, int v2, int Peso){
    if(ExisteAresta(grafo, v1, v2) == true){
        return false;
    }
    if(Peso <= -1){
        return false;
    }
    else {
        grafo->mat[v1][v2] = Peso;

  }


    return true;
}

bool RetiraAresta(PONT grafo, int v1, int v2){
    int i, j;
    if(ExisteAresta == false){
        return false;
    }     
    if(grafo->mat[i][j] <= -1){
        return false;
    }
    else{
        grafo->mat[v1][v2] = -1;
    }
    return false;
}

bool ListaVerticesAdjVazia(int v, PONT grafo){
    for(int i = 0; i < grafo->numVertices; i++){
        if(grafo->mat[i][v] != -1){
            printf("line not empty.\n");
            return false;
        }
    }
    printf("line empty.\n");
    return true;
}

void ImprimeGrafo(PONT grafo){
    int i;
    int j;
   // printf("%d \n", grafo->numVertices);
     
            for(i = 0; i < grafo->numVertices; i++){
                for(j = 0; j < grafo->numVertices-1; j++){ 
                    if(grafo->mat[j][i] == -1){
                        if(j == grafo->numVertices-1){
                            printf("%d", grafo->mat[j][i]);
                        }
                        else{
                            printf(" %d", grafo->mat[j][i]);
                        }
                    }

                    else{
                        printf("  %d", grafo->mat[j][i]); //estetica
                    }
                }
                printf(" %d\n", grafo->mat[j][i]);
            }
}
