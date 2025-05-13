def fatorial(x):
    if x == 0 :
        return 1 
    elif x == 1 :
        return 1
    else:
        return x*fatorial(x-1)
N = int(input())
print(int((N-2)*(N-3)/2))