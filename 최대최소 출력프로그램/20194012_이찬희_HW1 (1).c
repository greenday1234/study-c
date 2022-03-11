
#include <stdio.h>
#define SIZE 10000
int main()
{
	FILE* fp;
	int num[SIZE] = { 0 };
	int a = 0;
	int b = 0;
	int c = 1;
	int max, min;
	int i, s;
	int k = 1;
	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		return 0;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d", &num[b]);
		b++;
		a++;
	}
	printf("%d만큼씩 숫자를 출력합니다.\n\n", num[0]);
	max = num[1];
	min = num[1];
	for (i = 1; i < a; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
		else if (min > num[i])
		{
			min = num[i];
		}
	}
	for (i = 1; i <= num[0]; i++)	
	{
		printf("\t%d", i);
	}
	printf("\n");
	for (i = 0; i <= num[0]; i++)	
	{
		printf("========");
	}
	printf("\n");
	for (i = 0; i < b / num[0] + 1; i++)	
	{
		for (int j = 0; j < num[0]; j++)
		{
			if (k == a)	
			{
				break;
			}
			printf("\t%d", num[k]);
			k++;	
		}
		printf("\n");
		for (s = 0; s < num[0]; s++) 
		{
			if (num[c] == max)
			{
				printf("\t최댓값");
			}
			else if (num[c] == min)
			{
				printf("\t최솟값");
			}
			else
			{
				printf("\t");
			}
			c++;
		}
		printf("\n");
		for (int x = 0; x <= num[0]; x++)	
		{
			if (k == a)	
			{
				break;
			}
			printf("--------");
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}