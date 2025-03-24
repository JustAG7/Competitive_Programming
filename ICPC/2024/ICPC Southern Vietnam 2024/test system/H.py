import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()

def calc(n, M):
    return (n * (n + 1) * (2 * n + 1) // 6) % M 
a, b, M = map(int,input().split())
print((calc(b, M) - calc(a - 1, M) % M + M) % M) 


