import os, sys

def indef():
    JA = "input"
    if os.path.exists(JA + ".inp"):
        sys.stdin = open(JA + ".inp", "r")
        sys.stdout = open(JA + ".out", "w")


class ChallengeClass:
    
    def Calculate(selft, s):
        
        a = list(s[:len(s)-1].split('], '))
        m = 0
        g = [[] for _ in range(101)]
        for x in a:
            x = x.replace('->[','').split("  ")
            g[int(x[0])].append(list(map(int, x[1].split(', '))))
            m = max(m, int(x[0]))
        v = [-1]*(m + 1)
        print(g)


indef()
ChallengeClass().Calculate("0 ->[ 5, 6, 7], 1 ->[ 12, 14], 2 ->[ 3, 8], 3 ->[ 2, 4, 8, 10], 4 ->[ 3, 5], 5 ->[ 0, 4], 6 ->[ 0, 7], 7 ->[ 0, 6], 8 ->[ 2, 3], 9 ->[ 16], 10 ->[ 3, 11], 11 ->[ 10], 12 ->[ 1, 13], 13 ->[ 12], 14 ->[ 1, 15], 15 ->[ 14], 16 ->[ 9]")

