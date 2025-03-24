a = list(input().split())
n = int(input())
forbidden = list(input().split())

mp = {}
for x in forbidden:
    s = x.lower()
    if s not in mp:
        mp[s] = 1
for x in a:
    if x.lower() in mp:
        print('*' * (len(x)), end=' ')
    else:
        print(x, end=' ')
    