#include <stdio.h>
#define ROW1 3
#define COL1 2
#define ROW2 2
#define COL2 3

int main()
{
    int a[ROW1][COL1] = {{1,2},{3,4},{5,6}};
    int b[ROW2][COL2] = {{2,3,0},{8,9,1}};
    int c[ROW1][COL2] = {0};

    for(int i=0;i<ROW1;i++)
    {
        for(int j=0;j<COL1;j++)
        {
            for(int k=0;k<COL2;k++)
            {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    for(int i=0;i<ROW1;i++)
    {
        for(int j=0;j<COL2;j++){

             printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
       
}