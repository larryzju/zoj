#include <stdio.h>
#define SIZE (10)

int main()
{
    int fib[SIZE] = {0};
    int i, n;

    fib[0] = 1;
    for ( i = 1 ; i < SIZE; i++ )
    {
	fib[i] = fib[i-1]*i;
    }

    /*
    for ( i = 1; i < SIZE; i++ )
    {
	printf( "fib[%d] = %d\n", i, fib[i] );
    }
    */

    while( 1 )
    {
	scanf( "%d", &n );
	if ( n < 0 )
	{
	    break;
	}

	if ( n == 0 )
	{
	    printf( "NO\n" );
	}
	else
	{
	    for ( i = SIZE-1; i>=0; i-- )
	    {
		if ( n >= fib[i] )
		{
		    n-= fib[i];
		}

		if ( n == 0 )
		{
		    break;
		}
	    }

	    printf( "%s\n", n==0 ? "YES": "NO" );
	}
    }
    return 0;
}
