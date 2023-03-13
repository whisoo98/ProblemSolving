n = int(input())
for i in range(n):
    if i == 0:
        print(' '*(n-1),end='')
        print('*')
        continue
    print(' '*(n-1-i),end='')
    print('*',end='')
    print(' '*(i*2-1), end='')
    print('*')
