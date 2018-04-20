#include <stdio.h>


void transpose(int n, float *a, float *b)
{
	// a is transpose of b of size nxn
	int i, j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j] = b[j][i]

}


void multiply(int n, float *a, float *b, float *c)
{
	// c = a*b of size nxn
	int i, j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			c[j][k] = 0;
			for(v=0; v<n; v++)
			{
				c[i][j] = c[i][j] + a[i][v]*b[v][j];
			}
		}
}


float getHighestSumRow(int n, float *b)
{
	// max contains sum of max sum row of matrix b of size nxn
	int i, j, max = -10000000, temp=0;
	for(i=0; i<n; i++)
	{
		temp = 0;
		for(j=0; j<n; j++)
		{
			temp = temp + b[i][j];
		}
		if(temp>max)
			max = temp;
	}
	return max;
}


float getHighestSumRow(int n, float *b)
{
	// max contains sum of max sum column of matrix b of size nxn
	int i, j, max = -10000000, temp=0;
	for(i=0; i<n; i++)
	{
		temp = 0;
		for(j=0; j<n; j++)
		{
			temp = temp + b[j][i];
		}
		if(temp>max)
			max = temp;
	}
	return max;
}
