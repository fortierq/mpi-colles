#include <stdio.h>

int karatsuba(int x, int y, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return x == 1 && y == 1;
    int k = n >> 1;
    int p = 1 << k;
    int a = x >> k;
    int b = x - (a << k);
    int c = y >> k;
    int d = y - (c << k);
    int ac = karatsuba(a, c, k);
    int bd = karatsuba(b, d, k);
    int abcd = karatsuba(a - b, c - d, k);
    return (ac << n) - ((ac + bd - abcd) << k) + bd;
}

int main()
{
    printf("%d", karatsuba(6, 7, 4));
}