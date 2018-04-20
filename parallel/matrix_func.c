#include <stdio.h>


__global__
void transpose(int n, float *a, float *b)
{
	// a is transpose of b of size nxn
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	int j = i/n;
	int k = i%n;
	a[i][j] = b[j][i];
}


__global__
void multiply(int n, float *a, float *b, float *c)
{
	// c = a*b of size nxn
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	int j = i/n;
	int k = i%n;
	c[j][k] = 0;
	for(v=0; v<n; v++)
	{
		c[j][k] = c[j][k] + a[j][v]*b[v][k];
	}
}


__global__
void getSumRows(int n, float *a, float *b)
{
	// a is a n dimentional array containing sum of each row of matrix b of size nxn
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if(i<n)
	{
		a[i] = 0;
		for(j=0;j<n;j++)
		{
			a[i] = a[i] + a[i][j];
		}
	}
}


__global__
void getSumColumns(int n, float *a, float *b)
{
	// a is a n dimentional array containing sum of each column of matrix b of size nxn
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if(i<n)
	{
		a[i] = 0;
		for(j=0;j<n;j++)
		{
			a[i] = a[i] + a[j][i];
		}
	}
}


__global__
void constMatrixDevide(int n, float a, float *b, float *c)
{
	// c = b/a where b is an nxn matrix and a is a constant
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	int j = i/n;
	int k = i%n;
	c[j][k] = b[j][k]/a;
}


__global__
void constMatrixDevide(int n, float a, float *b, float *c)
{
	// c = b/a where b is an nxn matrix and a is a constant
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	int j = i/n;
	int k = i%n;
	c[j][k] = b[j][k]*a;
}
