#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define char_to_plaincode(c)\
    (c=='_'? 0:\
     c=='.'?27:\
     c-'a'+1)

#define plaincode_to_char(p)\
    (p== 0?'_':\
     p==27?'.':\
     p-1+'a')

int main()
{
    int i = 0;
    int key = 0;
    char string[71];
    int len = 0;

    while( scanf( "%d", &key ) != EOF )
    {
        if ( key == 0 )
        {
            break;
        }

        if ( scanf( "%s", string ) == EOF )
        {
            break;
        }

        len = strlen( string );
        char *plaintext = calloc( len+1, sizeof( char ) );

        for ( i = 0; i < len; i++ )
        {
            int raw_key = (key*i % len);

            int c = (char_to_plaincode(string[i]) + i) % 28;
            plaintext[ raw_key ] = plaincode_to_char( c );
        }

        plaintext[len] = '\0';
        printf(  "%s\n", plaintext );

        free( plaintext );
        memset( string, 0, sizeof( char ) * 71 );
    }

    return 0;
}
