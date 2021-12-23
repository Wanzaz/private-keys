#include <stdio.h>
#include <stdlib.h>

/*I discoverd that was not possible put all the 4 790 016 combinations in one array and test it after that
It brokes if there is the 12 numbers and 7 numbers on one line.
It can only print the combinations with 12, 6 and that is 924 combinations and after that it goes down 
*/

long long int combinations(int n, int r)
{
    if (r < 0)
    {
        return 0;
    }
    long  res = 1LL;
    if (r > n - r)
    {
        r = n - r;
    }
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    int n, r;
    printf("Zadej kolik cisel: ");
    scanf("%d", &n);
    printf("Zadej kolik paru: ");
    scanf("%d", &r);
    printf("%lld", combinations(n, r));
    return 0;
}

