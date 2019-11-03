#include <stdio.h>

char matriz[3][3] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};


void ImprimeJogo() {
    int i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            printf("%c  ", matriz [i][j]);
        }

        printf("\n");
    }
}


int AtualizaMatriz(int lin, int col, char tipo) {

    if (lin > 2 || col > 2) {
        printf("Posicao invalida\n");
    }

    else if (matriz[lin][col] == '-') {
        matriz[lin][col] = tipo;
    }

    else {
        printf("Posicao invalida\n");
    }

    return 0;
}


int ImprimeStatus(int status) {
    return status;
}


int JogoTerminou() {
    return 0;
}

int main()
{
    const char tipo[2] = {'X','O'};
    int lin, col, count = 0;

    while (1)
    {
        ImprimeJogo();
        if (ImprimeStatus(JogoTerminou()))
            break;
        scanf("%d %d", &lin, &col);
        if (!ImprimeStatus(AtualizaMatriz(lin, col, tipo[count])))
            count = (count + 1) % 2;
    }

    return 0;
}