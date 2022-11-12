def permutate(s, l, r):
    if l == r:  # ! base case : if single element is there to arrange , print the string ---
        for i in s:
            print(i, end="")
        print()
    for i in range(l, r+1):
        s[l], s[i] = s[i], s[l]
        # ! part from 0-l is fixed ,so we can re arrange l+1 to r , to find different ways to arrange
        permutate(s, l+1, r)
        # ! retain back to original position (backtrack) , we can again swap and find any combination
        s[l], s[i] = s[i], s[l]


n = input("Enter string : ")
s = []
for i in n:
    s.append(i)
permutate(s, 0, len(n)-1)  # ! 2^n typed of arrangements
