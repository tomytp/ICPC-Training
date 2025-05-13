N = int(input())
lista = ()
comandos = []
results = []
def function(x,y):
    if x == "1": 
        lista.__add__(y)
    elif x == "2":
        results.append(max(comandos[y-1][2]))
    elif x == "3":
        print(min(comandos[y-1][2]))
    elif x == "4":
        results.append(sum(comandos[y-1][2]))
for i in range(len(results)):
    print(results[i])
for i in range(N):
    inpt = input().split(" ")
    function(inpt[0],inpt[1])
    comandos.append([inpt[0],inpt[1],lista])