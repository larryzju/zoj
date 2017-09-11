def fare( flag_down, level1, level2, wait_fare_per_minute ):
    def cal( d, t ):
        f = flag_down
        if d > 3:
            f += (min(d,10) - 3) * level1
        if d >= 10:
            f += (d-10) * level2
        return round(f+t*wait_fare_per_minute)
    return cal


fare1 = fare( 11, 2, 3, 2.0/5 )
fare2 = fare( 11, 2.5, 3.75, 2.5/4 )

for _ in xrange(int(raw_input())):
    ds, ts = raw_input().split()
    d, t = int(ds), int(ts)
    f2 = fare2(d,t)
    f1 = fare1(d,t)
    print int(f2-f1)
