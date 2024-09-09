import sys
from math import sqrt
from collections import defaultdict

def rustica(n, l, k):
    lk = k * l
    freq_marca = [0] * (lk + 1)
    freq_freq = [0] * (lk + 1)

    for i in range(lk):
        freq_marca[vec[i]] += 1
    
    for i in range(lk):
        freq_freq[freq_marca[i]] += 1
    
    if freq_freq[freq_marca[0]] == k:
        return lk

    for i in range(1, n - lk + 1):
        freq_freq[freq_marca[vec[i-1]]] -= 1
        freq_marca[vec[i-1]] -= 1
        freq_freq[freq_marca[vec[i-1]]] += 1
        freq_freq[freq_marca[vec[i+lk-1]]] -= 1
        freq_marca[vec[i+lk-1]] += 1
        freq_freq[freq_marca[vec[i+lk-1]]] += 1
        if freq_freq[freq_marca[vec[i+lk-1]]] == k:
            return lk
    
    return 0

def solve_burro(n, k):
    l = n // k
    while l >= 1:
        p = rustica(n, l, k)
        if p:
            print(p)
            return
        l -= 1
    print(0)

def solve_smart(n, k):
    tab = [0] * k
    mp = defaultdict(set)
    for i in range(n):
        tab[vec[i]] += 1
        if tab[vec[i]] == 1:
            menor = min((x for x in tab if x > 0), default=float('inf'))
            if menor != float('inf'):
                tab = [x - menor for x in tab]
        mp[tuple(tab)].add(i)
    
    diff = max(max(s) - min(s) for s in mp.values()) if mp else 0
    print(diff)

def main():
    n, k = map(int, input().split())
    global vec
    vec = [int(x) - 1 for x in input().split()]
    raiz = int(sqrt(n))
    
    if k > raiz:
        solve_burro(n, k)
    else:
        solve_smart(n, k)

if __name__ == "__main__":
    main()