#include <stdio.h>

char matriz[3][3] = {{'-', '-', '-'},
                     {'-', '-', '-'},
                     {'-', '-', '-'}};


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

    if(((lin<0 || lin>2) || (col<0 || col>2)) || matriz[lin][col] != '-'){
        return 3;
    }

    else{
        matriz[lin][col] = tipo;
    }

    return 0;

}


int ImprimeStatus(int status) {

    if (status == 2) {
        printf("Ganhou\n");
    }

    else if (status == 1) {
        printf("Empatou\n");
    }

    else if (status == 3){
        printf("Posicao invalida\n");
    }

    return status;
}


int JogoTerminou() {
    int i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            if (matriz[i][j] == '-') {
                return 0;
            }
            else {

                if ((matriz[0][0] == 'X') && (matriz[0][1] == 'X') && (matriz[0][2] == 'X')) { /*verifica linha 1 X */
                    return 2;
                }

                if ((matriz[0][0] == 'O') && (matriz[0][1] == 'O') && (matriz[0][2] == 'O')) { /*verifica linha 1 O*/
                    return 2;
                }

                if ((matriz[1][0] == 'X') && (matriz[1][1] == 'X') && (matriz[1][2] == 'X')) { /*verifica linha 2 X */
                    return 2;
                }

                if ((matriz[1][0] == 'O') && (matriz[1][1] == 'O') && (matriz[1][2] == 'O')) { /*verifica linha 2 O */
                    return 2;
                }

                if ((matriz[2][0] == 'X') && (matriz[2][1] == 'X') && (matriz[2][2] == 'X')) { /*verifica linha 3 X */
                    return 2;
                }

                if ((matriz[2][0] == 'O') && (matriz[2][1] == 'O') && ('O' == matriz[2][2])) { /*verifica linha 3 O */
                    return 2;
                }

                if ((matriz[0][0] == 'X') && (matriz[1][0] == 'X') && ('X' == matriz[2][0])) { /*verifica  coluna 1 X*/
                    return 2;
                }

                if ((matriz[0][0] == 'O') && (matriz[1][0] == 'O') && ('O' == matriz[2][0])) { /*verifica  coluna 1 O*/
                    return 2;
                }

                if ((matriz[0][1] == 'X') && (matriz[1][1] == 'X') && ('X' == matriz[2][1])) { /*verifica  coluna 2 X*/
                    return 2;
                }

                if ((matriz[0][1] == 'O') && (matriz[1][1] == 'O') && ('O' == matriz[2][1])) { /*verifica  coluna 2 O*/
                    return 2;
                }

                if ((matriz[0][2] == 'X') && (matriz[1][2] == 'X') && ('X' == matriz[2][2])) { /*verifica coluna 3 X*/
                    return 2;
                }

                if ((matriz[0][2] == 'O') && (matriz[1][2] == 'O') && ('O' == matriz[2][2])) { /*verifica coluna 3 O*/
                    return 2;
                }

                if ((matriz[0][0] == 'X') && (matriz[1][1] == 'X') && ('X' == matriz[2][2])) { /*verifica diagonal 1 X*/
                    return 2;
                }

                if ((matriz[0][0] == 'O') && (matriz[1][1] == 'O') && ('O' == matriz[2][2])) { /*verifica diagonal 1 O*/
                    return 2;
                }

                if ((matriz[0][2] == 'X') && (matriz[1][1] == 'X') && ('X' == matriz[2][0])) { /*verifica diagonal 2 X*/
                    return 2;
                }

                if ((matriz[0][2] == 'O') && (matriz[1][1] == 'O') && ('O' == matriz[2][0])) { /*verifica diagonal 2 O*/
                    return 2;
                }
            }

            /*if (matriz[i][j] == '-'){
                return 0;
            } */
        }
    }

    return 1;
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
