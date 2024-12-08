ip = map(int, input().split('.'))
number = ''.join(map(lambda x: bin(x)[2:].zfill(8), ip))
print(number)