n,m=map(int,input().split())
a=list(map(int,input().split()))
ans = 0
while(m>0):
	ok=True
	cnt=0
	sum=0
	for i in a:
		if sum+i<=m:
			cnt+=1
			sum+=a[i]
			ok=True
	if ok==False: break
	else:
		ans+=cnt*(m/sum);
		m%=sum
print(ans) 