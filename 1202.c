#include <stdio.h>
#include <string.h>

int A( int n )
{
    int i;
    int res = 1;
    for ( i = 1; i <= n; i++ )
    {
	res *= i;
    }
    return res;
}

int C( int m, int n )
{
    int i;
    int res = 1;

    for ( i = 0; i < m; i++ )
    {
	res *= (n-i);
    }

    for ( i = 0; i < m; i++ )
    {
	res /= (i+1);
    }
    return res;
}

int main()
{
    int n,i;
    int boxes[12];
    int cnts[12];
    int sum;
    double res;

    while( scanf( "%d", &n ) != EOF )
    {
	if ( n == 0 )
	{
	    break;
	}

	memset( cnts, 0, sizeof(int)*12 );
	res = 1;
	sum = 0;
	for ( i = 0; i < n; i++ )
	{
	    scanf( "%d", boxes + i );
	    cnts[ boxes[i] ]++;
	    sum += boxes[i];
	}

	for ( i = 0; i < n; i++ )
	{
	    res *= C( boxes[i], sum );
	    sum -= boxes[i];
	}

	for ( i = 0; i < 12; i++ )
	{
	    if ( cnts[i] > 0 )
	    {
		res /= A(cnts[i]);
	    }
	}

	printf( "%d\n", (int)res );
    }

    return 0;
}
