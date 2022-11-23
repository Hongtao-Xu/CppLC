#include <stdio.h>

void fun(int array[3][3]) {
    int i, j;
    int *p = NULL;
    int *q = NULL;
    int temp;
    for (i = 0; i < 3; i++) {
        for (j = i; j < 3; j++) {
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}

int main() {
    int i, j;
    int array[3][3] = {{100, 200, 300},
                       {400, 500, 600},
                       {700, 800, 900}};

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%7d", array[i][j]);
        printf("\n");
    }
    fun(array);
    printf("Converted array:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%7d", array[i][j]);
        printf("\n");
    }
    getchar();
}


