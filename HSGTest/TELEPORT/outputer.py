import sys
sys.stdin=open('TELEPORT.INP','r')
sys.stdout=open('TELEPORT.OUT','w')
n,c=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n):
    a[i]+=i+1
a.sort()
ans=0
for i in range(n):
    if c>=a[i]:
        ans+=1
        c-=a[i]
    else: break
print(ans)