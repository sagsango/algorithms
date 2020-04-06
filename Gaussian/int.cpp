// source  https://www.geeksforgeeks.org/gaussian-elimination/
#include<bits/stdc++.h>
using namespace std; 

#define N 3	 // Number of unknowns 


int forwardElim(int mat[N][N+1]); 
void backSub(int mat[N][N+1]); 
void gaussianElimination(int mat[N][N+1]) 
{ 
	int singular_flag = forwardElim(mat); 
	if (singular_flag != -1) 
	{ 
		printf("Singular Matrix.\n"); 
		if (mat[singular_flag][N]) 
			printf("Inconsistent System."); 
		else
			printf("May have infinitely many "
				"solutions."); 
		return; 
	} 
	backSub(mat); 
} 
void swap_row(int mat[N][N+1], int i, int j) 
{ 
	for (int k=0; k<=N; k++) 
	{ 
		int temp = mat[i][k]; 
		mat[i][k] = mat[j][k]; 
		mat[j][k] = temp; 
	} 
} 
int forwardElim(int mat[N][N+1]) 
{ 
	for (int k=0; k<N; k++) 
	{ 
		int i_max = k; 
		int v_max = mat[i_max][k]; 
		for (int i = k+1; i < N; i++) 
			if (abs(mat[i][k]) > v_max) 
				v_max = mat[i][k], i_max = i;
		if (!mat[k][i_max]) 
			return k;
		if (i_max != k) 
			swap_row(mat, k, i_max); 
		for (int i=k+1; i<N; i++) 
		{ 
			int f = mat[i][k]/mat[k][k]; 
			for (int j=k+1; j<=N; j++) 
				mat[i][j] -= mat[k][j]*f; 
			mat[i][k] = 0; 
		} 
	}
	return -1; 
} 
void backSub(int mat[N][N+1]) 
{ 
	int x[N];
	for (int i = N-1; i >= 0; i--) 
	{ 
		x[i] = mat[i][N]; 
		for (int j=i+1; j<N; j++) 
		{ 
			x[i] -= mat[i][j]*x[j]; 
		} 
		x[i] = x[i]/mat[i][i]; 
	} 

    /* Here you got your solution */
    
	printf("\nSolution for the system:\n"); 
	for (int i=0; i<N; i++) 
		printf("%d\n", x[i]); 
} 

int main() 
{ 
	/* input matrix */
	int mat[N][N+1] = {{3, 2,-4, 3},     // 3*x + 2*y - 4*z = 3
						{2, 3, 3, 15},   // 2*x + 3*y + 3*z = 15
						{5, -3, 1, 14}   // 5*x - 3*y + 14*z= 14
					   }; 

	gaussianElimination(mat); 

	return 0; 
}
