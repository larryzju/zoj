#include <stdio.h>

#define IS_LEAP_YEAR(y) ((y%4==0 && y%100 !=0) || (y%400==0))

const int leap_day_of_month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
const int nonleap_day_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int leap_nine_of_month[] = {3,3,3,3,3,3,3,3,33,3,3,3};
const int nonleap_nine_of_month[] = {3,2,3,3,3,3,3,3,33,3,3,3};

const int leap_days = 366;
const int nonleap_days = 365;
const int leap_nines = 66;
const int nonleap_nines = 65;

static int _n9[10000] = {0};

#define nines(c) _n9[c];

int count( int by, int bm, int bd, int ey, int em, int ed )
{
    int cnt = 0;
    int m = 0, d = 0, y = 0;
    if ( by == ey && bm == em ) {
	int y9 = nines( by );
	for ( d = bd; d <= ed; d++ ) {
	    if ( d % 10 == 9 ) cnt++;
	}
	cnt += (ed-bd+1)*y9;
	if ( bm == 9 ) {
	    cnt += (ed-bd+1);
	}
    } else if ( by == ey ) {
	int y9 = nines( by );
	int leap = IS_LEAP_YEAR(by);
	int *n9 = (int*)(leap?leap_nine_of_month:nonleap_nine_of_month);
	int *days = (int*)(leap?leap_day_of_month:nonleap_day_of_month);

	cnt += count( by, bm, bd, by, bm, days[bm-1] );
	cnt += count( ey, em,  1, ey, em,         ed );

	for ( m = bm+1; m < em; m++ ) {
	    cnt += n9[m-1];
	    cnt += y9*days[m-1];
	}
    } else {
        cnt += count( by,bm,bd, by,12,31 );
        cnt += count( ey, 1, 1, ey,em,ed );

	for ( y = by+1; y < ey; y++ ) {
	    int y9 = nines(y);
	    if (IS_LEAP_YEAR(y)) {
		cnt += leap_nines;
		cnt += y9*leap_days;
	    } else {
		cnt += nonleap_nines;
		cnt += y9*nonleap_days;
	    }
	}
    }
    return cnt;
}

int main()
{
    int m = 0;
    for ( m = 2000; m <= 9999; m++ ) {
	int x = m;
	int v = 0;
	while( x != 0 ) {
	    if ( x % 10 == 9 ) {
		v++;
	    }
	    x /= 10;
	}
	_n9[m] = v;
    }


    int t = 0;
    int by,bm,bd,ey,em,ed;
    scanf( "%d", &t );
    while( t-- > 0 ) {
	scanf( "%d %d %d %d %d %d", &by, &bm, &bd, &ey, &em, &ed );
	printf( "%d\n", count(by,bm,bd,ey,em,ed) );
    }
    return 0;
}
