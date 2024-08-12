import math

n, d = [int(item) for item in input().split()]
stor = [int(item) for item in input().split()]
x = 0

stor = sorted(stor, reverse=True)
print(stor)
# while len(stor) != 0:
#     cek = d / stor[0]
#     if cek % 1 == 0:
#         cek -= 1
#     stor.pop(0)
#     for i in range(math.trunc(cek)):
#         try:
#             stor.pop(-1)
#         except:
#             break
#     if stor[0] * len(stor) > d:
#         x += 1
#     else:
#         break
while True:
    if stor[0] <= d:
        try:
            stor.pop(-1)
        except:
            break
        stor[0] += stor[0]
    elif stor[0] > d:
        x += 1
    else:
        break
print(x)

# 6 180
# 90 80 70 60 50 100