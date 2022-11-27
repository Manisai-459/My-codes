l = input().split()
b = []
q = []
q.append(0)
while len(q):
    n = len(q)
    x = []
    while n:
        i = q[0]
        x.append(int(l[i]))
        if 2*i + 1 < len(l) and l[2*i + 1] != "null":
            q.append(2*i + 1)
        if 2*i + 2 < len(l) and l[2*i + 2] != "null":
            q.append(2*i + 2)
        q.pop(0)
        n -= 1
    b.append(x)
print(b)
