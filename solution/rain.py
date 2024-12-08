n = int(input())
rain = list(map(int, input().split()))

level = [0] * (10 ** 6 + 1)
for i in rain:
    level[i] += 1

days = 0
for i in range(len(level) - 1, 0, -1):
    days += level[i]
    if days >= i:
        print(i)
        break