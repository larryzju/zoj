#include <stdio.h>

int main()
{
    int T = 0;
    int n, c;
    scanf( "%d", &T );

    while( T-- > 0 )
    {
        scanf( "%d", &n );
        for ( c = 0; n >= 1; n /= 2 )
        {
            c++;
        }
        printf( "%d\n", c );
    }

    return 0;
}
