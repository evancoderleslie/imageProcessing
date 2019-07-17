#include <stdio.h>
#include <conio.h>
#include <math.h>

int input[512][512];
int output[512][512];
int c = 512;

void main()
{
	int i,j,d;
	
	FILE *fp, *fp1;
	fp = fopen("original.txt", "r");
	
	
	for(i=1;i<=512;i++)
	{
		for(j=1;j<=512;j++)
		{
			fscanf(fp, "%d",&d);
			input[i][j] = d;
		}
	}
	
	for(i=1;i<=512;i++){
		
		for(j=1;j<=512;j++){
			d = input[i][j];
			//output[i][j]=255 - input[i][j];
			//output[i][j] = (d<=100)?d:(d<=150?100:(d<=200?200:255));
			output[i][j] = (int)(c*log(1+d));
		}
	}
	
	fp1 = fopen("output.pgm", "w");
	
	fprintf(fp1,"P2 512 512 255 ");
	
	for(i=1;i<=512;i++){
		
		for(j=1;j<=512;j++)
			fprintf(fp1,"%d ",output[i][j]);
			
		fprintf(fp1,"\n ");
	}
}
