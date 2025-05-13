NQ = str(input()).split(" ")
N = int(NQ[0])
Q = int(NQ[1])
inpt = str(input()).split(" ")
l = []
for i in range(N):
    l.append(int(inpt[i]))
l.sort()
result = []
def function(num):
    if l==[]:
        result.append(-1)
    else:
        for index in range(len(l)):
            if l[index] >= num :
                result.append(l[index])
                l.pop(index)
                break
            else:
                if index == (len(l)-1) and l[index] < num :
                    result.append(-1)

for i in range(Q):
    q = int(input())
    function(q)
for o in range(Q):
    print(result[o])