#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// #define MAXNUMBERVERTICES 100;
// #define AN -1;
// #define VERTICE_INVALIDO -1;


//typedef int TipoPeso;
typedef struct {
    int numVertices;
    int numArestas;
    int mat[101][101];
} TipoGrafo, * PONT;
