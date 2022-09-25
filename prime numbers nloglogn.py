import numpy as np
import time as t
s = t.time()
n = int(input("Enter n : "))
a = np.ones((n+1), dtype=int)
# for i in range(2, n+1):
#     if a[i] and i*i <= n:
#         for j in range(i*i, n+1, i):
#             a[j] = 0
# for i in range(2, n+1):
#     if a[i]:
#         print(i)
# e = t.time()
# print("time taken : "+str(e-s)+" sec")
i = 2
while i*i <= n:
    if a[i]:
        for j in range(i*i, n, i):
            a[j] = 0
    i += 1
for i in range(2, n+1):
    if a[i]:
        print(i)
e = t.time()
print("time taken : "+str(e-s)+" sec")
