#include <stdio.h>

int factorial(int n)
{
    if (n <= 1)
        return n;
    else
        return n * factorial(n-1);
}

int main()
{
    int n;
    printf("Enter the number to find the factorial of: ");
    scanf("%d", &n);
    printf("The factorial of %d (%d!) = %d\n", n, n, factorial(n));
    return 0;
}
