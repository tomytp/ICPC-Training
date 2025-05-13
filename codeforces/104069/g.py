N = int(input())
lista = []
for i in range(N):
    inpt = str(input())
    lista.append(inpt)
startingpoints = str(input()).split(" ")
c = lista.index(startingpoints[0])
m = lista.index(startingpoints[1])

def function(x,y):
    if x>y:
        d = x-y
    else: 
        d = y-x
    if d%2==0:
        return d//2
    else:
        return((d//2)+1)
print(int(function(c,m)))