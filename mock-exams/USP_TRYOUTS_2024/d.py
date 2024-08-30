a, b, c = (int(x) * 1000000000 for x in input().split())
ox, oy, oz = (int(float(x) * 1000000000) for x in input().split())
rdado = int(float(input()) * 1000000000)

rsup = max([a, b, c])
rinf = 0

def teste(r):
    x = max(abs(ox - r), abs(ox - (a - r)))
    y = max(abs(oy - r), abs(oy - (b - r)))
    z = max(abs(oz - r), abs(oz - (c - r)))
    dist = x*x+y*y+z*z
    if (dist < (r+rdado)*(r+rdado)):
        return False
    return True

while rsup-rinf > 2:
    delta =  (rsup - rinf)/ 2
    r = rinf + delta
    print(delta, r-rinf)
    if (teste(r)):
        rinf = r
    else:
        rsup = r

print("%.15f" % r)