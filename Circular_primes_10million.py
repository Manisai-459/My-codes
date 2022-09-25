def is_prime(n):
    if n <= 1:
        return 0
    elif n <= 3:
        return 1
    elif (n % 2 == 0 or n % 3 == 0):
        return 0
    else:
        i = 5
        while ((i*i) <= n):
            if n % i == 0 or n % (i+2) == 0:
                return 0
            i += 6
        return 1


def circular_prime(n):
    if is_prime(n):
        x = n
        count = 0
        while x != 0:
            count += 1
            x = x//10
        x = n
        for i in range(1, count):
            q = x//pow(10, count-1)
            r = x % pow(10, count-1)
            x = r*10 + q
            if is_prime(x) == 0:
                return 0
        return 1
    return 0


count = 0
for i in range(2, 1000000):
    count += circular_prime(i)
print(count)
