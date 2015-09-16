#!/usr/bin/env python

def who_is_the_smartest_man( caocao, peoples ):
    peoples = sorted( peoples )
    skipped = 0
    for i in range( len(peoples) ):
        if caocao < peoples[i]:
            caocao += 2
        else:
            skipped += 1
    caocao += skipped
    print caocao


try:
    while True:
        _n, caocao = map( int, raw_input().split() )
        peoples   = map( int, raw_input().split() )
        who_is_the_smartest_man( caocao, peoples )

except EOFError:
    pass
