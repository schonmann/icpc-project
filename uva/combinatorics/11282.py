def fat(n, floor):
    if n == floor: return 1
    if n == 0: return 1
    return n*fat(n-1, floor)

def comb(n, m):
    if n - m  <= n/2:
        return int(fat(n,n-m)/fat(m, 0))
    return int(fat(n,m)/fat(n-m, 0))

def dearr(n):
    if n == 1: return 0
    if n == 0: return 1
    if n == 2: return 1
    return (n-1)*(dearr(n-1)+dearr(n-2))

while True:
    try:
        n, m = map(int, input().split())
        s = 0
        for i in range(n-m, n+1):
            s += dearr(i) * comb(n,i)
        print(s)
    except:
        break
