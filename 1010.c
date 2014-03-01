#include <stdio.h>
#include <math.h>

#define MIN(_a,_b) ((_a)>(_b)?(_b):(_a))
#define MAX(_a,_b) ((_a)>(_b)?(_a):(_b))
#define ZERO(x) (fabs(x)<1E-8)
#define BETWEEN(x,a,b) (((x)>=(a)&&(x)<=(b))||((x)>=(b)&&(x)<=(a)))

typedef struct{
    double x;
    double y;
} Point;

double cross_multiply( Point a, Point b, Point o )
{
    return (o.x-a.x)*(o.y-b.y) - (o.y-a.y)*(o.x-b.x);
}

double area( int n, Point *veh )
{
    const Point o = {0,0};
    double area = 0.0;
    int i;

    for ( i = 0; i < n; i++ )
    {
	area += 0.5*cross_multiply( veh[i], veh[(i+1)%n], o );
    }
    return fabs(area);
}


int on_segment( Point a1, Point a2, Point m )
{
    if ( BETWEEN( m.x, a1.x, a2.x ) &&
	 BETWEEN( m.y, a1.y, a2.y ) )
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

int line_insect( Point a1, Point a2, Point b1, Point b2 )
{
    double d1 = cross_multiply( a1, a2, b1 );
    double d2 = cross_multiply( a1, a2, b2 );
    double d3 = cross_multiply( b1, b2, a1 );
    double d4 = cross_multiply( b1, b2, a2 );

    if (  ( ( d1 < 0 && d2 > 0 ) || ( d1 > 0 && d2 < 0 ) )
	    &&
	  ( ( d3 < 0 && d4 > 0 ) || ( d3 > 0 && d4 < 0 ) ) )
    {
	return 1;
    }
    else if ( d1 == 0 )
    {
	return on_segment( a1, a2, b1 );
    }
    else if ( d2 == 0 )
    {
	return on_segment( a1, a2, b2 );
    }
    else if ( d3 == 0 )
    {
	return on_segment( b1, b2, a1 );
    }
    else if ( d4 == 0 )
    {
	return on_segment( b1, b2, a2 );
    }
    else
    {
	return 0;
    }
}

int verify_polygon( int n, Point *veh )
{
    int i, j;
    for ( i = 0; i < n; i++ )
    {
	for ( j = i+1; j < n; j++ )
	{
	    if ( i == j || i == j - 1 || i == (j+1) % n )
	    {
		continue;
	    }
	    else
	    {
		if ( line_insect( veh[i], veh[(i+1)%n], veh[j], veh[(j+1)%n] ) )
		{
		    return 0;
		}
	    }
	}
    }

    return 1;
}

int main()
{
    int idx = 1;
    int i = 0;
    int n = 0;
    Point veh[1000];

    while(1)
    {
	scanf( "%d", &n );
	if ( n == 0 )
	{
	    break;
	}

	for ( i = 0; i < n; i++ )
	{
	    scanf( "%lf %lf", &veh[i].x, &veh[i].y );
	}


	if ( idx > 1 )
	{
	    printf( "\n" );
	}

	if ( n <= 2 || ! verify_polygon(n,veh) )
	{
	    printf( "Figure %d: Impossible\n", idx++ );
	}
	else
	{
	    printf( "Figure %d: %.2lf\n", idx++, area(n,veh) );
	}
    }

    return 0;
}

