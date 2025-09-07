#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função recursiva para verificar se existe caminho
bool dfs(int lab[4][4], int n, int r, int c) {
    // Se estiver fora dos limites
    if (r < 0 || r >= n || c < 0 || c >= n || lab[r][c] == 2)
        return false;

    // Se for parede
    if (lab[r][c] == 1)
        return false;

    // Se chegou ao destino
    if (r == n - 1 && c == n - 1)
        return true;

    //marca como visitado
    lab[r][c] = 2;

    // Movimentos: cima, baixo, esquerda, direita
    if (dfs(lab, n, r - 1, c)) return true;
    if (dfs(lab, n, r + 1, c)) return true;
    if (dfs(lab, n, r, c - 1)) return true;
    if (dfs(lab, n, r, c + 1)) return true;


    return false;
}

int main(void) {

    int lab[4][4] = {
    {0, 1, 0, 0},
    {0, 0, 0, 1},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
    };

    if (lab[0][0] == 1 || lab[3][3] == 1) {
        printf("Não\n");
    } else if (dfs(lab, 4, 0, 0)) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }

    return 0;
}
