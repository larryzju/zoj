#include <stdio.h>
#include <string.h>

static int cache[21][21][21];

int w(int a,int b,int c)
{
    if ( a <= 0 || b <= 0 || c <= 0 ) {
	return 1;
    } else if ( a > 20 || b > 20 || c > 20 ) {
	return w(20,20,20);
    } else if ( cache[a][b][c] != -1 ) {
	return cache[a][b][c];
    } 

    int v = 0;
    if ( a < b && b < c ) {
	v = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
	v = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }

    cache[a][b][c] = v;
    return v;
}

int main()
{
    memset( cache, -1, sizeof( cache ) );
    int a, b, c;
    while( scanf( "%d %d %d", &a, &b, &c ) == 3 && !(a==-1&&b==-1&&c==-1) ) {
	printf( "w(%d, %d, %d) = %d\n", a,b,c,w(a,b,c) );
    }
    return 0;
}
