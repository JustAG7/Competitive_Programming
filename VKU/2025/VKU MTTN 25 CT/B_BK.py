import re

def get_list(s):

    range_check = re.match(r"\[?(\d+)\.\.(\d+)\]?", s) # idk what i'm doing, but at least it worked
    if range_check:
        start, end = map(int, range_check.groups())
        return list(range(start, end + 1))
    
    list_check = re.match(r"\[(..*?)\]", s) # same thing
    if list_check:
        return list(map(int, list_check.group(1).split(',')))


a = list(input().split())
s = ""
t = ""
for c in a[0]:
    if c == ',':
        break
    if c != '[' and c != '(':
        s += c
        
for c in a[1]:
    if c == ')':
        break
    t += c

ans = []
x_array = get_list(a[5])
y_array = get_list(a[8])
for i in x_array:
    new_s = s.replace('i', str(i))
    for j in y_array:
        new_t = t.replace('j', str(j))
        
        ans.append(f"({eval(new_s)},{eval(new_t)})")
print('[', end='')
str_ans = ", ".join(ans)
print(str_ans, end=']')