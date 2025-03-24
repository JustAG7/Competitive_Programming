from math import gcd
l,r,a,k=map(int,input().split())
bcnn = (a*k) // gcd(a,k)
print(r//(bcnn//a) - (l - 1)//(bcnn//a))
