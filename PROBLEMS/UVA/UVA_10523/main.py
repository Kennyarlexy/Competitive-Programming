import sys
for line in sys.stdin:
    N, A = map(int, line.split())
    tA = 1
    sum = 0
    for i in range(1, N+1):
        tA *= A
        sum += i*tA
    print(sum)