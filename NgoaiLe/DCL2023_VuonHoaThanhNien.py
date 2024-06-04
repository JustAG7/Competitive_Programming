import sys
import itertools
import math

def indef():
    try:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    except FileNotFoundError:
        pass

def calc(length, width, height, r1, r2, h):
    gap = ((r1 - r2) * height) / h
    leng = (r1 * 4) + (r2 + gap) * 2 + width

    vol = leng * width * height * 4
    ans = int(vol / (length * width * height))
    if(vol - ans * (length * width * height) > 0):
        ans += 1
    return ans, vol

def solve():
    r1, r2, h = map(float, input().split())
    a = list(map(float, input().split()))
    
    ans = float('inf')
    volume = float('inf')
    
    for perm in itertools.permutations(a):
        cnt, vol = calc(perm[0], perm[1], perm[2], r1, r2, h)
        if cnt < ans:
            ans = cnt
            volume = vol
        elif cnt == ans:
            volume = min(volume, vol)
    
    print(ans, end=' ')
    print("%.2f" % volume)

if __name__ == "__main__":
    indef()
    tt = 1
    # tt = int(input())
    for _ in range(tt):
        solve()