#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	FILE* fp;
	int studentscore[4][10] = { 0 };
	int ncount = 0;
	int scoresum = 0;
	double scoreaverage = 0.0;
	double subjectaverage[3] = { 0 };
	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 0;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d%d%d%d", &studentscore[0][ncount], &studentscore[1][ncount], &studentscore[2][ncount], &studentscore[3][ncount]);
		ncount++;
	}
	for (int i = 0; i < ncount; i++)
	{
		scoresum = studentscore[1][i] + studentscore[2][i] + studentscore[3][i];
		scoreaverage = scoresum / 3.0;
		printf("%d %d %d %d %d %f\n", studentscore[0][i], studentscore[1][i], studentscore[2][i], studentscore[3][i], scoresum, scoreaverage);
		subjectaverage[0] += studentscore[1][i];
		subjectaverage[1] += studentscore[2][i];
		subjectaverage[2] += studentscore[3][i];
	}
	printf("%f %f %f\n", subjectaverage[0] / (double)ncount, subjectaverage[1] / (double)ncount, subjectaverage[2] / (double)ncount);
	fclose(fp);
	return 0;
}