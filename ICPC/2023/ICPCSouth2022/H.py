
import sys
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

def multi(n):
    ans=1
    while(n>0):
        ans*=(n%10)
        n//=10
        if(ans==0): return ans
    return ans
l=input()
r=input()

a=b=ans=0
M=int(1e9+7)
if(len(l)<len(r)):
    l=""
    tmp=r[0]
    tmp=ord(tmp)-1
    l+=chr(tmp) 
    for i in range(1,len(r)):
        l+='9'
else: 
    if(ord(l[0])<ord(r[0])):
        l=""
        tmp=r[0]
        tmp=ord(tmp)-1
        l+=chr(tmp)
        for i in range(1,len(r)):
            l+='9'
a=int(l)
b=int(r)
print(l,r)
for i in range(a,b+1):
    ans=max(ans,multi(i))
print(ans%M)
