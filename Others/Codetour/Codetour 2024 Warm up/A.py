t = int(input())
a = []
mp = {}
for _ in range(t):
    s = input()
    a.append(s)
cnt = 0
for i in range(t):
    s = input()
    RR1 = int(str(s[1] + s[2]),16)
    RR2 = int(str(a[i][1] + a[i][2]), 16)
    
    GG1 = int(str(s[3] + s[4]),16)
    GG2 = int(str(a[i][3] + a[i][4]), 16)
    
    BB1 = int(str(s[5] + s[6]),16)
    BB2 = int(str(a[i][5] + a[i][6]), 16)
    
    RR = ((RR1 - RR2) ) % 256
    GG = ((GG1 - GG2) ) % 256
    BB = ((BB1 - BB2) ) % 256
    if((RR, GG, BB) not in mp):
        mp[(RR, GG, BB)] = 1
        cnt = max(cnt, 1)
    else:
        mp[(RR, GG, BB)] += 1
        cnt = max(cnt, mp[(RR, GG, BB)])
print("%.2f" % round((cnt / t) * 100, 2),end = '')
print('%')