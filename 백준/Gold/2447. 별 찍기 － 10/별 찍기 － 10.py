def DAC(n, k, y, x):
    if n>=3:
        m = n//3
        dy = [y, y, y, y + m, y + m, y + m, y + 2 * m, y + 2 * m, y+ 2 * m]
        dx = [x, x + m, x + 2 * m, x, x + m, x + 2 * m, x, x + m, x + 2 * m]
        for i in range(9):
            DAC(m, k - 1, dy[i], dx[i])
        #dy[4], dx[4]
        for i in range(y+m,y+2*m):
            for j in range(x+m,x+2*m) :
                l[i][j]=' '



n = int(input())

l =  [[ '*' for _ in range(n+1)] for _ in range(n+1)]

DAC(n,1,1,1)
for i in range(1,n+1):
    for j in range(1,n+1):
        print(l[i][j],end='')
    print()