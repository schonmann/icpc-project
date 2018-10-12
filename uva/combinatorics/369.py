
mem = dict()

def fat(n, floor):
    if n == floor: return 1
    if n == 0: return 1
    return n*fat(n-1, floor)

n, m = map(int, input().split())
while not (m == 0 and n == 0):
    res = 0
    if n - m  <= n/2:
        res = int(fat(n,n-m)/fat(m, 0))
    else:
        res = int(fat(n,m)/fat(n-m, 0))
    print(f"{n} things taken {m} at a time is {res} exactly.")
    n, m = map(int, input().split())
