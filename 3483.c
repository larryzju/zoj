#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX (40100)
#define DEBUG(fmt,args...) \
    /* printf( "[%d] " fmt "\n", __LINE__, ##args ) */

int gcd ( int a, int b )
{
    int t;
    while ( b > 0 )
    {
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{
    char prime_table[MAX];
    int i,j;
    int T;
    int x1,x2,y1,y2,count, size, g;

    memset( prime_table, 1, MAX );
    prime_table[0] = 0;
    prime_table[1] = 0;
    for ( i = 2; i < MAX/2+1; i++ )
    {
        for ( j = 2; i*j <= MAX; j++ )
        {
            prime_table[i*j] = 0;
        }
    }


    scanf( "%d", &T );
    while( T-- > 0 )
    {
        scanf( "%d %d %d %d", &x1, &x2, &y1, &y2 );
        size = (x2-x1+1)*(y2-y1+1);
        count = 0;

        for ( i = x1; i <= x2; i++ )
        {
            for ( j = y1; j <= y2; j++ )
            {
                if ( i == 0 ) 
                {
                    if ( prime_table[abs(j)] && (abs(j)-3)%4 == 0 )
                    {
                        DEBUG( "case1 [%d %d]\n", i, j );
                        count++;
                    }
                }
                else if ( j == 0 ) 
                {
                    if ( prime_table[abs(i)] && (abs(i)-3)%4 == 0 )
                    {
                        DEBUG( "case2 [%d %d]\n", i, j );
                        count++;
                    }
                }
                else
                {
                    if ( prime_table[ i*i + j*j ] &&
                         ( ( i*i + j*j ) - 3 ) % 4 != 0 )
                    {
                        DEBUG( "case3 [%d %d]\n", i, j );
                        count++;
                    }
                }
            }
        }

        g = gcd( count, size );
        printf( "%d/%d\n", count/g, size/g );

    }

    return 0;
}
