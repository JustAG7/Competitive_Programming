tt = int(input())

for _ in range(tt):
	a, b = map(int,input().split())
	print("increasing" if a > 0 else ("decreasing" if a < 0 else "horizontal"))