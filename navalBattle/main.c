#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// constants ------------------
#define MAT_D 8

// prototypes -----------------
void print_matrix(char mat[MAT_D][MAT_D], int show);
void newseed();
void fill_table(char mat[MAT_D][MAT_D]);
int map_col(char lin);

// global var
int ships = 0;

// main -----------------------
int main()
{
    setlocale(LC_ALL, "Portuguese");

    char mat[MAT_D][MAT_D]= {0};

    int sort  = 1,
        err   = 0,
        hit   = 0,
        lin   = 0;

    char choice='y',
         col;

    do
    {

        if(sort)
        {
            system("cls");
            fill_table(mat);
            print_matrix(mat, 1);
        }
        else
        {
            printf("opção invalida! ");
            sort = 1;
        }

        printf("(S)Sort again (P)Play\n>>");
        scanf(" %c", &choice);

        if(choice!='s' && choice!='S') sort=0;

    }
    while(choice!='p' && choice!='P');

    // game
    while(1){
        system("cls");
        print_matrix(mat, 0);

        printf("HITS: %d || ERRORS: %d\n", hit, err);


        if(err == 5){
            printf("WE WERE DEFEATED!\n");
            system("pause");
            exit(0);
        }
        else if(hit == ships){
            printf("YOU WIN!!!!!\n");
            system("pause");
            exit(0);
        }

        printf("Set the coordinates for the attack:\n>>> ");
        scanf(" %c%d", &col, &lin);

        if(mat[--lin][map_col(col)]=='@'){
            hit++;
            mat[lin][map_col(col)] = '#';
        } else {
            err++;
            mat[lin][map_col(col)] = 'O';
        }


    }
    system("pause");
    return 0;
}// end main ------------------

// functions ------------------
void print_matrix(char mat[MAT_D][MAT_D], int show)
{
    int i, j;
    char label = 0x20;

    printf("       A   B   C   D   E   F   G   H\n");

    for(i=0; i<MAT_D; i++)
    {
        printf("     ---------------------------------\n");
        printf("  %d  ", i+1);

        for(j=0; j<MAT_D; j++)
        {

            if(mat[i][j] == '@') label = show?'@':0x20;
            else if(mat[i][j] == '#') label = '#';
            else if(mat[i][j] == 'O') label = 'O';

            printf("| %c ", label);

            label=0x20;
        }// for linhas

        putchar('|');
        putchar('\n');

        if(i==MAT_D-1) printf("     ---------------------------------\n");
    }// for colunas

} // end print matrix

void newseed()
{
    //unsigned long capture;
    //time(&capture);
    srand((unsigned)time(0));

} // end new seed

void fill_table(char mat[MAT_D][MAT_D])
{
    int i,j;
    newseed();
    for(i=0; i<MAT_D; i++)
    {

        for(j=0; j<MAT_D; j++)
        {

            int num = rand()%100+1;
            if(num%2){mat[i][j] = '@'; ships++;}
            else      mat[i][j] = 0x20;

        } // for j

    } // for i
} // end fill table

int map_col(char lin){
    switch(lin){
    case 'a':
    case 'A': return 0; break;

    case 'b':
    case 'B': return 1; break;

    case 'c':
    case 'C': return 2; break;

    case 'd':
    case 'D': return 3; break;

    case 'e':
    case 'E': return 4; break;

    case 'f':
    case 'F': return 5; break;

    case 'g':
    case 'G': return 6; break;

    case 'h':
    case 'H': return 7; break;
    }

}

