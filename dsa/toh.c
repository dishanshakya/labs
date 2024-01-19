#include <stdio.h>

int toh(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("Move the disc %d from %c to %c\n", n, a, c);
        return 0;
    }
    else{
        toh(n-1, a, c, b);
        printf("Move the disc %d from %c to %c\n", n, a, c);
        toh(n-1, b, a, c);
    }
}

int main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}
