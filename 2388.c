#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int s,d;
    int a, b;

    scanf( "%d", &n );
    while( n-- > 0 )
    {
	scanf( "%d %d", &s, &d );
	a = 0.5*(s+d);
	b = 0.5*(s-d);

	if ( a < 0 || b < 0 )
	{
	    printf( "impossible\n" );
	}
	else if ( a+b != s || abs(a-b) != d )
	{
	    printf( "impossible\n" );
	}
	else
	{
	    if ( a > b )
	    {
		printf( "%d %d\n", a, b );
	    }
	    else
	    {
		printf( "%d %d\n", b, a );
	    }
	}
    }
    return 0;
}
