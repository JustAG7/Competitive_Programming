import sys
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
n=1005
dp=[0]*n;
dp[0]=0
dp[1]=1
for i in range(2,n):
    dp[i]=dp[i-1]+dp[i-2]
for t in sys.stdin:
    print(dp[int(t)])