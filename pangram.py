str = input()
s = set()
for i in str:
    if i>='a' and i<='z':
        s.add(i)
    elif i>='A' and i<= 'Z':
        s.add(i.lower())
print(len(s))
if len(s) == 26:
    print("YES")
else:
    print("NO")