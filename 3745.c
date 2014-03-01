#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX (1000010)

int main()
{
    int N,Q;
    int j,m,t;
    int l,r,c;
    long long pay;
    long long salay[MAX];

    while( scanf( "%d %d", &N, &Q ) != EOF )
    {
	pay = 0;
	memset( salay, 0, sizeof(long long)*MAX );
	for ( j = 0; j < N; j++ )
	{
	    scanf( "%d", &t );
	    salay[t]++;
	}

	for ( j = 0; j < Q; j++ )
	{
	    scanf( "%d %d %d", &l, &r, &c );
	    for ( m = r; m >= l; m-- )
	    {
		if ( salay[m] > 0 )
		{
		    salay[m+c] += salay[m];
		    salay[m] = 0;
		}
	    }
	}


	pay = 0;
	for ( m = 0; m < MAX; m++ )
	{
	    if ( salay[m] > 0 )
	    {
		pay += salay[m]*m;
	    }
	}

	printf( "%.lld\n", pay );
    }

    return 0;
}
