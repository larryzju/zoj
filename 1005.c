#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

static int Ca, Cb, N;

enum flag{
    VIRGIN,
    MARRIED
};

typedef struct _Node{
    struct _Node *prev;
    struct _Node *next;
    int x;
    int y;
    unsigned char flag:4,
                  op:4;
}Node;

enum op_enum{
    FILL_A,
    FILL_B,
    EMPTY_A,
    EMPTY_B,
    A_TO_B,
    B_TO_A,
    ORIGIN
};

Node* fill_a( Node *org, int op );
Node* fill_b( Node *org, int op );
Node* empty_a( Node *org, int op );
Node* empty_b( Node *org, int op );
Node* a_to_b( Node *org, int op );
Node* b_to_a( Node *org, int op );

struct _Op{
    int op;
    char *op_desc;
    Node*(*func)(Node*, int);
}op_lists[] = {
    {FILL_A, "fill A", fill_a},
    {FILL_B, "fill B", fill_b},
    {EMPTY_A, "empty A", empty_a},
    {EMPTY_B, "empty B", empty_b},
    {A_TO_B,  "pour A B", a_to_b},
    {B_TO_A,  "pour B A", b_to_a},
    {ORIGIN,  NULL,  NULL}
};

/* ugly */
#define NODE_COPY\
    Node *tt  = malloc( sizeof( Node ) );\
    assert( tt );\
    memcpy( tt, org, sizeof( Node ) );\
    tt->op = op;\
    tt->flag = VIRGIN;\
    tt->prev = org;\
    tt->next = NULL

Node* fill_a( Node *org, int op )
{
    NODE_COPY;
    tt->x = Ca;
    return tt;
}

Node* fill_b( Node *org, int op )
{
    NODE_COPY;
    tt->y = Cb;
    return tt;
}

Node* empty_a( Node *org, int op )
{
    NODE_COPY;
    tt->x = 0;
    return tt;
}

Node* empty_b( Node *org, int op )
{
    NODE_COPY;
    tt->y = 0;
    return tt;
}

Node* a_to_b( Node *org, int op  )
{
    NODE_COPY;
    int total = tt->x + tt->y;
    if ( total > Cb )
    {
        tt->x = total-Cb;
        tt->y = Cb;
    }
    else
    {
        tt->x = 0;
        tt->y = total;
    }
    return tt;
}

Node *b_to_a ( Node *org, int op )
{
    NODE_COPY;
    int total = tt->x + tt->y;
    if ( total > Ca )
    {
        tt->x = Ca;
        tt->y = total - Ca;
    }
    else
    {
        tt->x = total;
        tt->y = 0;
    }
    return tt;
}


void reverse_print_path( Node *n )
{
    if ( n->op == ORIGIN )
    {
        /* printf( "start\n" ); */
        return;
    }
    else
    {
        reverse_print_path( n->prev );
        printf( "%s\n", op_lists[n->op].op_desc );
        return;
    }
}

int main()
{
    Node *map = NULL;
    Node origin = {NULL, NULL, 0, 0, VIRGIN, ORIGIN};
    int any_more = 0;
    int i = 0;

    while( scanf( "%d %d %d", &Ca, &Cb, &N ) != EOF )
    {
        origin.prev = NULL;
        origin.next = NULL;
        origin.x = 0;
        origin.y = 0;
        origin.flag = VIRGIN;
        origin.op = ORIGIN;
        map = (Node*)&origin;


        while(1)
        {
            any_more = 0;
            Node *l = map;
            while( l )
            {
                if ( l->flag == VIRGIN )
                {
                    for ( i = 0; op_lists[i].func != NULL; i++ )
                    {
                        Node *n = op_lists[i].func( l, op_lists[i].op );
                        assert( n );

                        Node *t = map;
                        while( t )
                        {
                            if ( n->x == t->x &&
                                 n->y == t->y )
                            {
                                break;
                            }
                            t = t->next;
                        }
                        if ( t )
                        {
                            /* has been married */
                        }
                        else
                        {
                            n->next = map;
                            map = n;
                            any_more = 1;

                            if ( n->y == N )
                            {
                                /* got it */
                                reverse_print_path( n );
                                printf( "success\n" );

                                while( map != &origin )
                                {
                                    Node *tmp = map;
                                    map = map->next;
                                    free( tmp );
                                }
                                goto FOUND;
                            }
                        }
                    }
                    l->flag = MARRIED;
                }
                l = l->next;
            }
            if ( any_more )
            {
                /* continue */
            }
            else
            {
                fprintf( stderr, "no answer\n" );

                while( map != &origin )
                {
                    Node *tmp = map;
                    map = map->next;
                    free( tmp );
                }

                goto NOTFOUND;
            }
        }
NOTFOUND:
FOUND:
        ;  /* make gcc happy */
    }
    return 0;
}
