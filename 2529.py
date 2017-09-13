prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113]

def plus( x, y ):
    # padding zero
    size = max(len(x), len(y))

    x[:0] = [0]*(size-len(x)) 
    y[:0] = [0]*(size-len(y)) 
    
    res = []
    carry = 0

    # for each bit of second number
    for i in range(len(y)):
        idx = -i - 1
        base = prime[i]
        t = x[idx] + y[idx] + carry
        res.insert( 0, t % base )
        carry = t / base

    # last carry
    if carry:
        res.insert( 0, carry )

    return res

def parse(ss):
    return map(int,ss.split(','))

while True:
    try:
        a, b = raw_input().split()
        res = plus( parse(a), parse(b) )
        print ','.join( map( str, res ) )
    except EOFError, e:
        break
