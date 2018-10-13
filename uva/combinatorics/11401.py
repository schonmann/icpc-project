def _input():
    return int(input())

mem = dict()
def pre_compute():
    mem[0] = mem[1] = mem[2] = mem[3] = 0
    for i in range (4,1_000_001):
        if i%2 == 0:
            mem[i] = mem[i-1] + (-1 + int(i/2)) ** 2
        else:
            mem[i] = mem[i-1] + (-1 + int(i/2)) * (-1 + int(i/2) + 1)

pre_compute()
n = _input()
while n >= 3:
    print(mem[n])
    n = _input()
