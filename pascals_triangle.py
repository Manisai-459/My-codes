n = int(input("Enter rows : "))
for i in range(1, n+1):
    c = 1
    print(' '*(n - i), end="")
    for j in range(1, i+1):
        print(c, end=" ")
        c = c * (i - j)//j
    print()
