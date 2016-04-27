#!/usr/bin/env python2

import sys

T = int( sys.stdin.readline() )
for _ in range(T):
    p = int( sys.stdin.readline() )
    q = [int(t) for t in sys.stdin.readline().strip().split()]
    print p + sum(q)
