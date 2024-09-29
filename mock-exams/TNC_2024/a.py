n = int(input())

resp = 0

for i in range(n,2,-2):
    resp += 1 + ((i-2)*(i-1))//2

print(resp)