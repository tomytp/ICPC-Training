inpt = input().split(" ")
t = [ int(inpt[0]),int(inpt[1])]
c = [ int(inpt[2]),int(inpt[3])]
trackt = input()
trackc = input()
def function(l,d):
    k = [l[0],l[1]]
    if d == "U":
        k[1] = k[1]+1
        return k
    elif d == "D":
        k[1] = k[1]-1
        return k 
    elif d == "R" :
        k[0] = k[0]+1
        return k
    elif d == "L":
        k[0] = k[0]-1
        return k
B = False 
for i in range(len(trackc)):
    t = function(t,trackt[i])
    c = function(c,trackc[i])
    if t == c:
        print("Rodou!")
        B = True
        break
if B == False : 
    print("Quase!")
