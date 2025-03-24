import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()

a, b = map(int,input().split())
x, y = map(int,input().split())
if(a > b): a, b = b, a
if(x > y): x, y = y, x
if(x * b == y * a):
    print("YES")
else:
    print("NO")