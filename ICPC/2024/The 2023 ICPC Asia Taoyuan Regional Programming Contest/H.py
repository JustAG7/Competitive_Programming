import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()

C = int(input())
v = list(map(int,input().split()))
w = list(map(int,input().split()))
n = len(v)
dp = [0] * (1005)
for i in range(n):
	for j in range(1000, w[i] - 1, -1):
		dp[j] = max(dp[j], dp[j - w[i]] + v[i])
print(dp[C])
