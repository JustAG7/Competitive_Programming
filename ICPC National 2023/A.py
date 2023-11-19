for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if c == 0: print("NO CURVE")
    elif c > 0: print("CURVE UP")
    else: print("CURVE DOWN")
