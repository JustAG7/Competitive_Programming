import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()
M = int(1e9 + 7)
n, m = map(int,input().split())
'''
	1x1 : n . m
	2x2 : (n - 1) . (m - 1)
	3x3 : (n - 2) . (m - 2)
	m x m : 1 . (m - n + 1)

	=> sigma {{i = 1 -> m} {i * (n - m + i)}
'''
if n > m:
	n, m = m, n
ans = n * (n + 1) * (3 * m - n + 1) // 6;
print(ans % M)