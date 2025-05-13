N = int(input())
x = 0
string = str(input()).split(" ")
for i in range(N):
    x = x + int(string[i])

if x/N > 0:
    print(":)")
elif x/N < 0 :
    print(":(")
else:
    print(":|")