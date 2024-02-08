#include <stdio.h>

void shape(char size[][21]);
char turn(int turn);
int check(int, char);

int main() {
    char size[11][21];
    int counter = 0, x;
    char y;
    shape(size);
    while (1) {
        printf("Turn: %c\n", turn(counter));
        printf("Enter position(a/b/c): ");
        scanf(" %c", &y); 
        printf("Enter position(1/2/3): ");
        scanf("%d", &x);
        int error = check(x, y);
        if (error != 0) {
            if (y == 'a' && x == 1)
                size[3][5] = turn(counter);
            else if (y == 'a' && x == 2)
                size[3][11] = turn(counter);
            else if (y == 'a' && x == 3)
                size[3][17] = turn(counter);
            else if (y == 'b' && x == 1)
                size[6][5] = turn(counter);
            else if (y == 'b' && x == 2)
                size[6][11] = turn(counter);
            else if (y == 'b' && x == 3)
                size[6][17] = turn(counter);
            else if (y == 'c' && x == 1)
                size[9][5] = turn(counter);
            else if (y == 'c' && x == 2)
                size[9][11] = turn(counter);
            else if (y == 'c' && x == 3)
                size[9][17] = turn(counter);
            counter++;
        }
        else {
            printf("Invalid position. Next Turn!!!\n");
        }
        shape(size);
    }
    return 0;
}

void shape(char size[][21]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 21; j++) {
            if (i == 1 && j == 1 || i == 1 && j == 20 || i == 10 && j == 1 || i == 10 && j == 20) {
                size[i][j] = '.';
            } else if (size[i][j] != 'x' && size[i][j] != 'o') {
                size[i][j] = ' ';
            }
        }
    }
    for (int i = 1; i < 21; i++) {
        size[1][i] = '_';
        size[4][i] = '_';
        size[7][i] = '_';
        size[10][i] = '_';
    }
    for (int i = 1; i < 11; i++) {
        size[i][2] = '|';
        size[i][8] = '|';
        size[i][14] = '|';
        size[i][20] = '|';
    }
    
    size[1][5] = '1';
    size[1][11] = '2';
    size[1][17] = '3';
    size[3][1] = 'a';
    size[6][1] = 'b';
    size[9][1] = 'c';

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 21; j++) {
            printf("%c", size[i][j]);
        }
        printf("\n");
    }
}

char turn(int turn){
    if (turn % 2 == 0) {
        return 'x';
    } else {
        return 'o';
    }
}

int check(int x,char y){
    if (x < 1 || x > 3 || (y != 'a' && y != 'b' && y != 'c')) {
        return 0;
    }
    return 1;
}
