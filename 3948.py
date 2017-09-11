def calculate( x, y, a, b ):
    ans = 0

    while a >= x or b >= y:
        c = a / x + b / y
        a = a % x + c
        b = b % y + c
        ans += c

        if ans > 1000:
            return 'INF'

    return ans


T = int(raw_input())
for _ in xrange(T):
    x,y,a,b = [int(v) for v in raw_input().split()]
    print calculate(x,y,a,b)
