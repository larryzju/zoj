#include <stdio.h>
#include <string.h>

#define MAX (25)

typedef struct{
    int top;
    int bottom;
    int left;
    int right;
    int amount;
} Square;

static int  SIZE;
static Square s[MAX];
static int  kind;

static int  curmap[MAX];
static int  curpos;
static int  res;

void solve( int remain )
{
    int i = 0;

    if ( remain == 0 )
    {
        res = 1;
        return;
    }

    for( i = 0; i < kind; i++ )
    {
        if( s[i].amount == 0 )
            continue;

        if ( curpos % SIZE > 0 )
            if ( s[i].left != s[curmap[curpos-1]].right )
                continue;

        if ( curpos / SIZE > 0 )
            if ( s[i].top != s[curmap[curpos-SIZE]].bottom )
                continue;

        s[i].amount--;
        curmap[curpos++] = i;
        solve( remain - 1 );
        if ( res == 1 ) return;
        s[i].amount++;
        curmap[curpos--] = -1;
    }
}

int main()
{
    int i, j;
    int idx = 1;
    int top, bottom, left, right;

    while(1)
    {
        memset( curmap, -1, sizeof(int)*MAX );
        curpos = 0;
        kind   = 0;
        res    = 0;

        scanf( "%d", &SIZE );
        if ( SIZE == 0 ) break;

        for ( i = 0; i < SIZE*SIZE; i++ )
        {
            scanf( "%d %d %d %d", &top, &right, &bottom, &left );
            for ( j = 0; j < kind; j++ )
            {
                if ( top == s[j].top && right == s[j].right && bottom == s[j].bottom && left == s[j].left )
                {
                    s[j].amount++;
                    break;
                }
            }
            if ( j == kind )
            {
                s[j].top = top;
                s[j].bottom = bottom;
                s[j].left = left;
                s[j].right = right;
                s[j].amount = 1;
                kind++;
            }
        }

        solve( SIZE * SIZE );
        if ( idx > 1 )
        {
            printf( "\n" );
        }

        printf( "Game %d: %s\n", idx++, (res==1)?"Possible":"Impossible" );
    }
    return 0;
}
