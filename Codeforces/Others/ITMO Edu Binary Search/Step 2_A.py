w, h, n = map(int,input().split())
l = 1
r = int(1e18)
ans = int(1e18)
while(l <= r):
    m = (l + r) // 2
    s = (m // w) * (m // h)
    if(s >= n):
        ans = m
        r = m - 1
    else:
        l = m + 1
print(ans)