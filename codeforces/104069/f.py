NT = input().split(" ")
N = int(NT[0])
T = int(NT[1])

mp = {
    'C' : [],
    'Q' : [],
    'F' : [],
    'P' : [],
}

for i in range(N):
    inpt = input().split(" ")
    mp[inpt[0]].append(int(inpt[1]))

p = 0
for key, vector in mp.items():
    vector.sort()
    k = T
    for x in vector:
        if (k-x >= 0):
            p = p+1
            k = k-x

print(p)