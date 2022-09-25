d = {1: 3, 2: 3, 3: 5, 4: 4, 5: 4, 6: 3, 7: 5, 8: 5, 9: 4, 11: 6,
     12: 6, 13: 8, 14: 8, 15: 7, 16: 7, 17: 9, 18: 8, 19: 8}
d2 = {1: 3, 2: 6, 3: 6, 4: 5, 5: 5, 6: 5, 7: 7, 8: 6, 9: 6}
count = 0
for i in range(1, 1000):
    x, i = i % 10, i//10
    y, i = i % 10, i//10
    if i == 0:
        if y == 0:  # single digit
            count += d[x]
        elif y == 1 and x != 0:  # 11 - 19
            count += d[y*10 + x]
        elif y != 0 and x == 0:  # 10,20,30---90
            count += d2[y]
        else:  # numbers missed in above
            count += d2[y]+d[x]
    else:
        if y == 0 and x == 0:
            count += 7 + d[i]
        elif y == 1 and x != 0:
            count += 10 + d[i] + d[y*10+x]
        elif y == 0:
            count += d[i]+10+d[x]
        elif x == 0:
            count += d[i]+10+d2[y]
        else:
            count += d[i]+10+d2[y]+d[x]

print(count+11)
