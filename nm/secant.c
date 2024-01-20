#include <stdio.h>
#include <math.h>

#define f(x) (4*sin(x)-exp(x))

int main()
{
	int n = 1;
	float e = 0.00001, x0, x1, x2;
	printf("Enter the initial guesses: ");
	scanf("%f %f", &x0, &x1);
	printf("________________________________________________________________________________________________\n");
	printf("%15s %15s %15s %15s %15s\n", "Iteration", "x0", "x1", "x2", "f(x2)");
	printf("________________________________________________________________________________________________\n");
	do {
		x2 = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
		printf("%15d %15f %15f %15f %15f\n",n, x0, x1, x2, f(x2));
		x0=x1, x1=x2;
		n++;
	} while(fabs(f(x2))>e);
	printf("________________________________________________________________________________________________\n");
	printf("The approximate root is %f\n", x2);
	return 0;
}

		
