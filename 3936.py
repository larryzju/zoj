#!/usr/bin/env python2

import sys

for _ in range( int(sys.stdin.readline()) ):
    A,B,C,D = map( int, sys.stdin.readline().strip().split() )
    print C, B+D
    print A, B+D
