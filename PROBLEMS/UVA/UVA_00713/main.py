N = int(input())
for i in range(N):
    a, b = input().split()
    a, b = a[::-1], b[::-1]

    a, b = int(a), int(b)
    res = a + b
    while res % 10 == 0:
        res //= 10

    res = str(res)[::-1]
    print(res)