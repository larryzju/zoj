#!/usr/bin/env python2

triangular = lambda n: n*(n+1)/2
hexagonal  = lambda n: n*(2*n-1)
leap = lambda n: ((n % 4 == 0 and n % 100 != 0) or n % 400 == 0)

END = 990528

m,n = 63,32
M,N = 1407,704

assert( triangular(m) == 2016 )
assert( triangular(M) == END )
assert( hexagonal(n) == 2016 )
assert( hexagonal(N)  == END )

match = map( hexagonal, range(n,N+1) )
for x in xrange(m,M+1):
    t = triangular( x )
    if t in match and leap(t):
        print t 
