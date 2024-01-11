import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()
n = int(input())
res = set()
l = [int('1' * (i + 1)) for i in range(12)]
for i in range(12):
	for j in range(12):
		for k in range(12):
			res.add(l[i] + l[j] + l[k])
print(sorted(res)[n - 1])