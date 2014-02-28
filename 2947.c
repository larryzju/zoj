#include <stdio.h>
#include <string.h>

#define LEN (20)

int main()
{
    int T = 0;
    char word[LEN], buf1[LEN], buf2[LEN];
    int n,m,i;

    scanf( "%d", &T );
    while( T-- > 0 )
    {
        scanf( "%d", &n );
        for ( i = 0; i < n; i++ )
        {
            scanf( "%s", word );
            buf1[i] = word[0];
        }
        buf1[i] = '\0';

        scanf( "%d", &m );
        for ( i = 0; i < m; i++ )
        {
            scanf( "%s", word );
            buf2[i] = word[0];
        }
        buf2[i] = '\0';

        if ( strcmp( buf1, buf2 ) == 0 )
        {
            printf( "SAME\n" );
        }
        else
        {
            printf( "DIFFERENT\n" );
        }
    }
    return 0;
}
