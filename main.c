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
        return 1;
    }

    else if (matriz[lin][col] == '-') {
        matriz[lin][col] = tipo;
    }

    else {
        printf("Posicao invalida\n");
        return 1;
    }

    return 0;
}


char JogoTerminou() {

    int i, j;
    char current;


    for (i = 0; i < 3; i++) {
        current = matriz[i][0];
        for (j = 0; j < 3; j++) {
            if(current != matriz[i][j])
                break;
        }
        if(j == 3) {
            if (current != '-')
                return current;
        }
    }

    for (i = 0; i < 3; i++) {
        current = matriz[0][i];
        for (j = 0; j < 3; j++) {
            if(current != matriz[j][i])
                break;
        }
        if(j == 3) {
            if (current != '-')
                return current;
        }
    }

    current = matriz[0][0];
    for (i = 0; i < 3; i++) {
        if(current != matriz[i][i])
            break;

    }
    if(i == 3){
        if (current != '-')
            return current;
    }

    current = matriz[2][2];
    for (i = 2; i >= 0; i--) {
        if(current != matriz[i][i])
            break;
    }
    if(i == -1){
        if (current != '-')
            return current;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if(matriz[i][j] == '-')
                break;
        }
        if(j != 3)
            return 1;
    }

    return 0;
}

int main()
{
    const char tipo[2] = {'X','O'};
    int lin, col, count = -1;
    char res;

    while (1)
    {
        ImprimeJogo();

        count = (count + 1) % 2;

        res = JogoTerminou();
        if (res) {
            if(res != 1) {
                printf("O jogador com %c ganhou\n", res);
                break;
            }
        }
        else {
            printf("Deu velha");
        }

        do {
            scanf("%d %d", &lin, &col);
        } while(AtualizaMatriz(lin, col, tipo[count]));
    }


    return 0;
}