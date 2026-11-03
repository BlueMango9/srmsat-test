#include <stdio.h>
#include <stdlib.h>

// Helper function to allocate memory for a 2D matrix
int** allocateMatrix(int rows, int cols) {
int *matrix = (int *)malloc(rows sizeof(int ));
if (matrix == NULL) {
printf("Memory allocation failed!\n");
exit(1);
}
for (int i = 0; i < rows; i++) {
matrix[i] = (int )malloc(cols sizeof(int));
if (matrix[i] == NULL) {
printf("Memory allocation failed!\n");
exit(1);
}
}
return matrix;
}

// Helper function to free allocated memory for a 2D matrix
void freeMatrix(int **matrix, int rows) {
for (int i = 0; i < rows; i++) {
free(matrix[i]);
}
free(matrix);
}

int main() {
int r1, c1, r2, c2;

printf("Enter rows and columns for Matrix A: ");
scanf("%d %d", &r1, &c1);

printf("Enter rows and columns for Matrix B: ");
scanf("%d %d", &r2, &c2);

// Matrix multiplication constraint: Columns of A must equal Rows of B
if (c1 != r2) {
printf("Error: Matrix multiplication impossible! Columns of A (%d) must match Rows of B (%d).\n", c1, r2);
return 1;
}

// Allocate memory dynamically for matrices
int **A = allocateMatrix(r1, c1);
int **B = allocateMatrix(r2, c2);
int **C = allocateMatrix(r1, c2); // Result matrix size: r1 x c2

// Input elements for Matrix A
printf("\nEnter elements for Matrix A (%dx%d):\n", r1, c1);
for (int i = 0; i < r1; i++) {
for (int j = 0; j < c1; j++) {
scanf("%d", &A[i][j]);
}
}

// Input elements for Matrix B
printf("\nEnter elements for Matrix B (%dx%d):\n", r2, c2);
for (int i = 0; i < r2; i++) {
for (int j = 0; j < c2; j++) {
scanf("%d", &B[i][j]);
}
}

// Perform Matrix Multiplication: C[i][j] = sum(A[i][k] * B[k][j])
for (int i = 0; i < r1; i++) {
for (int j = 0; j < c2; j++) {
C[i][j] = 0;
for (int k = 0; k < c1; k++) {
C[i][j] += A[i][k] * B[k][j];
}
}
}

// Display the resulting matrix
printf("\nResultant Matrix C (%dx%d):\n", r1, c2);
for (int i = 0; i < r1; i++) {
for (int j = 0; j < c2; j++) {
printf("%d\t", C[i][j]);
}
printf("\n");
}

// Free memory in reverse order of allocation
freeMatrix(A, r1);
freeMatrix(B, r2);
freeMatrix(C, r1);

return 0;
}