#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const static char *default_port = "<default>";
const static char *default_path = "<default>";

void parse( int id, char *line )
{
    char *protocol = line;
    char *host = strstr( line, "://" );
    *host = '\0';
    host += 3;

    char *path = strchr( host, '/' );
    if ( path ) {
	*path++ = '\0';
    } else {
	path = (char*)default_path;
    }

    char *port = strchr( host, ':' );
    if ( port ) {
	*port++ = '\0';
    } else {
	port = (char*)default_port;
    }

    printf( "URL #%d\n"
	    "Protocol = %s\n"
	    "Host     = %s\n"
	    "Port     = %s\n"
	    "Path     = %s\n",
	    id,
	    protocol,
	    host,
	    port,
	    path);
}

int main()
{
    int n = 0;
    int i = 0;
    char line[70];
    scanf( "%d\n", &n );

    for ( i = 1; i <= n; i++ ) {
	fgets( line, 70, stdin );
	char *nl = strchr(line,'\n');
	if ( nl ) { *nl = '\0'; }
	parse( i, line );
	printf( "\n" );
    };

    return 0;
}
