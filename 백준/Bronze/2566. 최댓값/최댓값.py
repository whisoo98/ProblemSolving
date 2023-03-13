arr = [0 for _ in range(9)]
M=-1

for i in range(9):
    arr[i] = list(map(int,input().split()))

for i in range(9):
    for j in range(9):
        if M < arr[i][j]:
            y = i+1
            x = j+1
            M=arr[i][j]
            
print(M)
print(y,x)