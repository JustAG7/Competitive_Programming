import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()
n,m,p=map(int,input().split())
po=[]
huong=[[]for i in range(m+1)]
for i in range(m):
	u,v,d=map(int,input().split())
	po.append([u,v])
	huong[i]=d
def movea(j,i,k):
	global po
	global huong
	if i==1:
		po[j][0]=(po[j][0]-k%n+n)%n
	elif i==4:
		po[j][0]=(po[j][0]+k%n)%n
	elif i==2:
		po[j][1]=(po[j][1]+k%n)%n
	else:
		po[j][1]=(po[j][1]-k%n+n)%n
def mover(i,k):
	global p 
	global huong
	huong[i]+=(k%n)
	huong[i] %= n
def movez(i,k):
	po[i][0]=k//n 
	po[i][1]=k%n

for i in range(p):
	lenh=input()
	if lenh[0]=="A":
		for j in range(m):
			movea(j,huong[j],int(lenh[2]))
	elif lenh[0]=="R":
		for j in range(m):
			mover(j,int(lenh[2]))
	else:
		for j in range(m):
			movez(i,int(lenh[2]))
	print(po)
for i in range(m):
	print(po[i][0],po[i][1])