import sys
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
while True:
    n = int(input())
    if n == 0:
        break
    a = int(input())
    b = int(input())    
    c = int(input())

    #print(a+b)
    if a + b == c:
        print(0)
    else:
        k = 0
        count = 0
        while a > 0:
            tp = (a % 10 + b % 10)
            if tp % 10 + k != c % 10:
                count += 1
            else:
                if tp > 9:
                    k = 1
                else:
                    k = 0\
            a //= 10
            b //= 10
            c //= 10
        print(count)