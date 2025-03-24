import os, sys
import math

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")
indef()

num_test = int(input())
for test in range(0, num_test):
	len_a, len_b = map(int, input().split())
	aa = int(input())
	ba = int(input())

	ab = 10**len_a
	bb = int('9'*len_b)

	bb *= ab

	pa = aa*bb + ab*ba
	pb = ab*bb

	g = math.gcd(pa, pb)
	pa //= g
	pb //= g
	print(pa, pb)