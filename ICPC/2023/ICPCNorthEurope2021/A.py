def time(res):
    x = res.split(" ")
    if (len(x) == 2):
        return 
    return int(x[-2][1:])

def ttime(t):
    if (t == -1): return -1
    return (t-14)//9

cur = 0
s = "a"
while True:
    print(s)
    cur = time(input())
    if (cur == -1): exit()
    s += "a"

n = len(s)-1

chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

s = list(s[:-1])
for i in range(n-1):
    for c in chars:
        s[i] = c
        print(''.join(s))
        x = ttime(time(input()))
        if (x == -1):
            exit()
        if x >= i+1:
            break

def getGranted(res):
    return res.split(" ")[-1] == "GRANTED"

for c in chars:
    s[n-1] = c
    print(''.join(s))
    if getGranted(input()):
        exit()