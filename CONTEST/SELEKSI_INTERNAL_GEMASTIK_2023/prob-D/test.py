power = list(map(int, input().split()))
speed = list(map(int, input().split()))
boss_hp = int(input())

time = 0

while boss_hp > 0:
    time += 1
    for i in range(4):
        if time % speed[i] == 0:
            boss_hp -= power[i]

print(time)
