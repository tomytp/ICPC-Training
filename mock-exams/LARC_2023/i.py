mod = 1000000007
bit = [0 for _ in range(30)]

def add(p, v):
    while (p < 30):
        bit[p] = (bit[p] + v) % mod
        p += (p&-p)

def query(p):
    r = 0
    while p:
        r = (r + bit[p]) % mod
        p -= (p&-p)
    return r

def count_inv(s):
    resp = 0
    i = len(s) - 1
    while i >= 0:
        v = (ord(s[i]) - ord('a')) + 1
        add(v, 1)
        resp = (resp + query(v-1)) % mod
        i -= 1

    return resp

s = input()
n = int(input())
a = count_inv(s)
bit = [0 for _ in range(30)]
b = (count_inv(s+s) - (2 * a)) % mod

print((a*n + (b * n * (n-1)) // 2 ) % mod)
