#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// constantes
#define MAT_SIZE_X 5
#define MAT_SIZE_Y 5

// prototipos
void printMatrix(int mat[MAT_SIZE_X][MAT_SIZE_Y]);


// main
int main(void){
    setlocale(LC_ALL,"");

	// variaveis
	int mat[MAT_SIZE_X][MAT_SIZE_Y] = {0},
        continuar,
        lin,
        col,
        num;


	while(1){
        printMatrix(mat);

        printf("\tLinha: ");
        scanf("%d", &lin);

        printf("\tColuna: ");
        scanf("%d", &col);

        printf("\tNumero: ");
        scanf("%d", &num);

        mat[lin][col] = num;

        system("cls");
        printMatrix(mat);

        printf("\t     Continuar?\n\t(1) sim | (0) não\n\t>> ");
        scanf("%d", &continuar);
        if(!continuar) break;
        system("cls");
	}

	putchar('\n');
	system("pause");
	return 0;
}

//funções
void printMatrix(int mat[MAT_SIZE_X][MAT_SIZE_Y]){
	int i,j;

	for(i=0; i<MAT_SIZE_X;i++){


		    //printf("\n------------------------------------------\n");
		for(j=0; j<MAT_SIZE_Y;j++){
			printf("|(%d,%d) %d ",i,j,mat[i][j]);
			//printf("|\t%d ",mat[i][j]);
		}
		    //if(i==MAT_SIZE_X-1) printf("\n------------------------------------------\n");
		    putchar('\n');
	}
}
