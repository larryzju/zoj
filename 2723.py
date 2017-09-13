# see https://rosettacode.org/wiki/Semiprime#C

def semi_prime(n):
    p = 2
    dc = 0

    while dc < 2 and p*p <= n:
        while n % p == 0:
            n /= p
            dc += 1
        p += 1

    if n == 1 and dc == 2:
        return True
    elif n > 1 and dc == 1:
        return True
    else:
        return False

while True:
    try:
        v = int(raw_input())
        if semi_prime(v):
            print 'Yes'
        else:
            print 'No'
    except EOFError, e:
        break

