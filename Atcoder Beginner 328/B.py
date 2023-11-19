n = int(input())
a = list(map(int,input().split()))
ans = 0
def check(x):
    tmp = x % 10
    while(x > 0):
        if tmp != (x % 10):
            return False
        x //= 10
    return True
for i in range(n):
    j = i + 1
    if(not check(j)): continue
    s = str(j % 10)
    while(int(s) <= a[i]):
        ans += 1
        s += str(j % 10)
    
print(ans)