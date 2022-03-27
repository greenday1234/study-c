#include <Stdio.h>

int main()
{
	FILE* fp;
	fp = fopen("test.txt", "r");
	int year[12][8] = { 0 };
	int count=0;
	int yearsum=0;
	double av=0;
	int monthsum=0;
	int y=2000;
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 0;
	}
	while (!feof(fp))
	{
		fscanf(fp,"%d%d%d%d%d%d%d%d%d%d%d%d\n", &year[0][count], &year[1][count],&year[2][count],&year[3][count],&year[4][count],
		&year[5][count],&year[6][count],&year[7][count],&year[8][count],&year[9][count],&year[10][count],&year[11][count]);
		count++;
	}
	printf("|==================================================================================|\n");
	printf("| 년도   | 1월| 2월| 3월| 4월 | 5월 | 6월 | 7월 | 8월 | 9월 | 10월|11월|12월|년별총합|\n");
	for(int i=0;i<count;i++)
	{
		printf("| %d년 ", y);
		y++;
		for(int j=0;j<12;j++)
		{
		yearsum+=year[j][i];
		printf("| %d ", year[j][i]);
		}
		printf("| %d |", yearsum);
		printf("\n");
		yearsum=0;
	}
	printf("|==================================================================================|\n");
	printf("|월별평  |");
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<count;j++)
		{
			monthsum+=year[i][j];
		}
		av=(double) monthsum/8; 
		printf(" %0.lf |", av);
			av=0;
			monthsum=0;
	}
	printf("\n|===========================================================================|");
	return 0;
}