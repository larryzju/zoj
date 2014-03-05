#include <stdio.h>

int small_valid = 0;
int large_valid = 0;

void possible( int M, int m, int cnt )
{
    if ( m == 1 && M == 1 ) 
    {
        large_valid = 1;
    }
    else 
    {
        if ( m == 1 )
        {
            small_valid = 1;
        }

        while( cnt > 0 )
        {
            if ( M % cnt == 0 ) possible( M/cnt, m, cnt-1 );
            if ( m % cnt == 0 ) possible( M, m/cnt, cnt-1 );
            cnt --;
        }
    }
}

int main()
{
    int M, m;
    while( scanf( "%d %d", &M, &m ) != EOF )
    {
        small_valid = 0;
        large_valid = 0;
        if ( M < m )
        {
            M ^= m; m ^= M; M ^= m;
        }

        if ( m < 1 ) 
        {
            printf( "%d\n", M );
        }
        possible( M, m, 100 );
        if ( small_valid && !large_valid )
        {
            printf( "%d\n", m );
        }
        else
        {
            printf( "%d\n", M );
        }
    }
    return 0;
}
