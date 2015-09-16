#!/usr/bin/env python

try:
    while True:
        r = int(raw_input())
        if r == 0:
            print "fail"
        else:
            print "win"
except EOFError:
    pass
