#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//incluir a biblioteca mutex, semaforo e testar os dois com monitores
//


typedef struct{
    int lin;
    int col;
    int **matriz;
}matrizes;

DWORD WINAPI preencherMatriz(LPVOID param){
    matrizes* m = (matrizes *) param;
    for(int i = 0; i < m->lin; i++){
        for(int j = 0; j < m->col; j++){
            scanf("%d", &m->matriz[i][j]);
        }
    }
    return 0;
}

int main(){
    HANDLE t1;
    DWORD t1Id;
    matrizes m;

    printf("Digite a quantidade de linhas:\n");
    scanf("%d", &m.lin);

    printf("Digite a quantidade de colunas:\n");
    scanf("%d", &m.col);
    
    m.matriz = (int**) malloc(m.lin * sizeof(int*));
    for(int i = 0; i < m.lin; i++){
        m.matriz[i] = (int*) malloc(m.col * sizeof(int));
    }

    t1 = CreateThread(NULL, 0, preencherMatriz, &m, 0, &t1Id);

    if (t1 == NULL) {
        printf("Erro ao criar thread 1.\n");
        return 1;
    }
    WaitForSingleObject(t1, INFINITE);
    CloseHandle(t1);

    for(int i = 0; i < m.lin; i++){
        free(m.matriz[i]);
    }
    free (m.matriz);

    printf("Thread finalizada.\n");
    return 0;
}