#include <stdio.h>

int main()
{
    int T;
    int n;
    scanf( "%d", &T );
    while( T-- > 0 )
    {
        scanf( "%d", &n );

        if ( n / 10 % 10 == 1 )
        {
            printf( "%dth\n", n );
        }
        else
        {
            if ( n % 10 == 1 )
            {
                printf( "%dst\n", n );
            }
            else if ( n % 10 == 2 )
            {
                printf( "%dnd\n", n );
            }
            else if ( n % 10 == 3 )
            {
                printf( "%drd\n", n );
            }
            else 
            {
                printf( "%dth\n", n );
            }
        }
    }

    return 0;
}
