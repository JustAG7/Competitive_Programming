n = int(input())
print(((n*(n - 3)//2) + (n*(n - 1)*(n - 2)*(n - 3)//24) + 1) % 987654321)
# or print(((n - 1)*(n - 2)*(n**2 - 3*n + 12)//24) % 987654321)
# this is from Google when i research for this formula