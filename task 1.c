#include <stdio.h>
#include <stdlib.h>

int main() {
int *num1, *num2, *num3;

num1 = (int*)malloc(sizeof(int));
num2 = (int*)malloc(sizeof(int));
num3 = (int*)malloc(sizeof(int));

printf("Enter the number :");
scanf("%d", num1); // Removed &

printf("Enter the number :");
scanf("%d", num2); // Removed &

*num3 = *num1 + *num2;
printf("sum is %d\n", *num3);

free(num1);
free(num2);
free(num3);

return 0;
}