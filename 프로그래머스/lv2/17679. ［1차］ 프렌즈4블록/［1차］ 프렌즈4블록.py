def isOk(ty,tx,y,x):
    if ty<0 or ty>=y or tx<0 or tx>=x:
        return False
    return True

def goDown(y,x,board):
    for i in range(y-1,-1,-1):
        for j in range(x-1,-1,-1):
            if board[i][j]==0:
                continue
            else:
                nowy = i
                downy = i+1
                tx = j
                while True:
                    if isOk(downy,tx,y,x) and board[downy][tx]==0:
                        temp = board[downy][tx]
                        board[downy][tx] = board[nowy][tx]
                        board[nowy][tx]=temp
                        nowy=downy
                        downy+=1
                    else:
                        break
            
    
def boom(y,x,board):
    saved = [[0 for _ in range(x)] for _ in range(y)]
    
    for i in range(y):
        for j in range(x):
            ty = i
            tx = j
            if board[ty][tx]==0:
                continue
            cnt = 0
            target = board[ty][tx]
            

            if isOk(ty,tx,y,x) and board[ty][tx]==target:
                cnt+=1
            if isOk(ty+1,tx,y,x) and board[ty+1][tx]==target:
                cnt+=1
            if isOk(ty,tx+1,y,x) and board[ty][tx+1]==target:
                cnt+=1
            if isOk(ty+1,tx+1,y,x) and board[ty+1][tx+1]==target:
                cnt+=1
                
            if cnt == 4:
                saved[ty][tx]=1
                saved[ty+1][tx]=1
                saved[ty][tx+1]=1
                saved[ty+1][tx+1]=1
    bomb = 0
    for i in range(y):
        for j in range(x):
            if saved[i][j]:
                board[i][j]=0
                bomb +=1
    return bomb
def solution(y, x, board):
    answer = 0
    Board = []
    for i in range(y):
        l = [] 
        for j in board[i]:
            l.append(ord(j)-ord('A')+1)
        Board.append(l)
    # for i in range(y):
    #     for j in range(x):
    #         print(chr(Board[i][j]+64), end = ' ')
    #     print()
    while True:
        bomb = boom(y,x,Board)
        if bomb==0:
            break
        goDown(y,x,Board)
            
        # for i in range(y):
        #     for j in range(x):
        #         print(chr(Board[i][j]+64), end = ' ')
        #     print()
        
    for i in range(y):
        for j in range(x):
            if Board[i][j]==0:
                answer+=1
    return answer