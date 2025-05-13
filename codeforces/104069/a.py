T = int(input())
lista = []
for i in range(T):
    inpt = str(input()).split(" ")
    lista.append([int(inpt[0]),int(inpt[1]),int(inpt[2])])
def function(setpoints,tpoints,npoints):
    changed = ((tpoints+npoints)//setpoints)
    #print(changed)
    if changed == 0:
        print("Thiago")
    elif changed%2==0:
        print("Thiago")
    else:
        print("Nathan")
    
for index in range(T):
    #print(lista[index])
    function(lista[index][0],lista[index][1],lista[index][2])
#print(lista)