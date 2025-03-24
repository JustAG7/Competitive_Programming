x,n=map(float,input().split())
n = int(n)

sinx = x
cosx = 1

num = x
fact = 1

for i in range(2,min(n,20)+1):
    fact *= i
    num *= x
    tmp = i % 4
    
    if(tmp == 0):
        cosx += num / fact
    elif(tmp == 1):
        sinx += num / fact
    elif(tmp == 2):
        cosx -= num / fact
    else:
        sinx -= num / fact

print('{:.15f}'.format(sinx),'{:.15f}'.format(cosx))
