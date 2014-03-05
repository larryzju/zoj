#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int size;

int place_max_castle( char map[] )
{
    int count = 0;
    int max = -1;

    int i;
    int place = 0;

    int x, y;
    
    char *map_mirror = calloc(size*size, sizeof(char));
    memcpy ( map_mirror, map, size*size*sizeof(char) );
    
    for ( i = 0; i < size*size; i++ )
    {
        memcpy ( map, map_mirror, size*size*sizeof(char) );
        if ( map[i] == '.' )
        {
            map[i] = 'O';
            place = 1;

            x = i%size;
            y = i/size;

            x--;
            while ( x >= 0 && map[ y*size + x] != 'X' )
                map[ y*size + x-- ] = 'N';

            x = i%size;
            y = i/size;

            y--;
            while ( y >= 0 && map[ y*size + x] != 'X' )
                map[ (y--)*size + x ] = 'N';

            x = i%size;
            y = i/size;

            x++;
            while ( x < size && map[ y*size + x] != 'X' )
                map[ y*size + x++ ] = 'N';

            x = i%size;
            y = i/size;

            y++;
            while ( y < size && map[ y*size + x] != 'X' )
                map[ (y++)*size + x] = 'N';

            count = 1 + place_max_castle( map );
            if ( max < count )
            {
                max = count;
            }
        }
    }
    if ( !place )
    {
        max = 0;
    }
    return max;
}

int main()
{
    char *map = NULL;
    int i;
    int tmp;
    
    while (1)
    {
        i = 0;
        scanf ("%d", &size );
        if ( size == 0 )
        {
            break;
        }

        map = calloc( size*size, sizeof(char) );
        while ( i < size*size )
        {
            tmp = getchar();
            if ( tmp == '.' || tmp == 'X' )
            {
                map[i++] = (char) tmp;
            }
        }

        printf( "%d\n", place_max_castle( map ) );
        free(map);        
    }
    return 0;
}
