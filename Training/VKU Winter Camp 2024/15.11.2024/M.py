import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()

n, M = map(int, input().split())
ans = 2 * n * (n + 1) + n + 1
ans += (4 * n * (n + 1) * (2 * n + 1)) // 6
print(ans % M)