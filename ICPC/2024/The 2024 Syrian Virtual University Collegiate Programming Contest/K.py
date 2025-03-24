import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()
N = 2*10**(701)
M = 998244353
a = []
n = int(input())
a.append(N)
for i in range(n):
	x = int(input())
	a.append(x)
pre = [N] * (n + 2)
pre[n] = a[n]

mx = N
ans = 0
for i in range(n - 1, 0, -1):
	pre[i] = min(pre[i + 1], a[i])

for i in range(1, n + 1):
	tmp = min(pre[i + 1], mx)
	ans = (ans + tmp) % M
	mx = min(mx, pre[i + 1])
print(ans)

