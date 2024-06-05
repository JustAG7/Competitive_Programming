import sys
import itertools
from decimal import Decimal, getcontext

getcontext().prec = 100

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
    if vol - (length * width * height) * ans > 0:
        ans += 1
    return ans, vol

def solve():
    r1, r2, h = map(Decimal, input().split())
    a = list(map(Decimal, input().split()))
    
    ans = Decimal('inf')
    volume = Decimal('inf')
    
    for perm in itertools.permutations(a):
        cnt, vol = calc(perm[0], perm[1], perm[2], r1, r2, h)
        ans = min(ans, cnt)
        volume = min(volume, vol)
    
    print(ans, end=' ')
    print(f"{volume:.2f}")

if __name__ == "__main__":
    indef()
    tt = 1
    # tt = int(input())
    for _ in range(tt):
        solve()