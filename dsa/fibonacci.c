#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    printf("Enter n to print n items of fibonacci series: ");
    scanf("%d", &n);
    for (int i = 1; i<=n; ++i)
    {
        printf(" %d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
