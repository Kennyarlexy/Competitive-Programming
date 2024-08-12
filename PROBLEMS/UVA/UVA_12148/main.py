from datetime import date, timedelta

while True:
    N = int(input())
    if N == 0:
        break
    
    prev = date(1, 1, 1)
    prevC = 0
    cnt = 0
    total = 0
    for i in range(N):
        D, M, Y, C = [int(n) for n in input().split()]
        cur = date(Y, M, D)
        if i > 0 and prev + timedelta(days=1) == cur:
            cnt += 1
            total += (C - prevC)

        prev = cur
        prevC = C

    print(cnt, total)