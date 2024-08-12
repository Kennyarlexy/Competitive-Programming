t = 0
while True:
    t += 1
    N, F = [int(a) for a in input().split()]
    if N == 0 and F == 0:
        break

    total = 0
    for i in range(N):
        a = int(input())
        total += a
    
    print(f"Bill #{t} costs {total}: each friend should pay {total//F}\n")

