import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()

par = [0] * (205)
edge = []
def find_root(u):
	if(u == par[u]):
		return u
	par[u] = find_root(par[u])
	return par[u]

def merge_set(u, v):
	u = find_root(u)
	v = find_root(v)
	if(u == v):
		return False
	par[v] = u
	return True
n, m = map(int,input().split())
for i in range(m):
	par[i + 1] = i + 1  
	u, v, w = map(int,input().split())
	edge.append([w, u, v])
edge.sort()
ans = 0
res = 0
for x in edge:
	w, u, v = x
	if(merge_set(u, v)):
		ans += 1
		res += w
print(ans, res)
