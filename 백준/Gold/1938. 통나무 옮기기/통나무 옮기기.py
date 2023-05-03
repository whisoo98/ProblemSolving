import sys
import pprint

input = sys.stdin.readline

n = int(input())
_map = []
visit = [[[987654321 for _ in range(n)] for _ in range(n)] for _ in range(2)]
# pprint.pprint(visit)
log = []
hole = []
dy = [0,0,1,-1]
dx = [1,-1,0,0]
turnx = [[-1,0,1],
         [1,0,-1]]
turny = [[1,0,-1],
         [-1,0,1]]
def isOk(ty,tx):
    global n
    if ty<0 or ty>=n or tx<0 or tx>=n or _map[ty][tx]==1:
        return False
    return True

for i in range(n):
    l = input()
    temp = []
    for j in range(n):
        if l[j] == 'B':
            temp.append(3)
            log.append((i,j))
        elif l[j] == 'E':
            temp.append(4)
            hole.append((i,j))
        elif l[j] == '0':
            temp.append(0)
        elif l[j] =='1':
            temp.append(1)
    _map.append(temp)
log.sort()
hole.sort()
Q = []
# visit[log[0]]= -1
# visit[log[2]]= -1

if log[0][1] == log[1][1]:
    direction = 1
else:
    direction = 0
visit[direction][log[1][0]][log[1][1]]= 0    
# print(direction)
Q.append((log,0,direction))
while Q:
    log, moved, direction= Q.pop(0)
    # print(log)
    # print(moved)
    # print(direction)
    if log[1] == hole[1]:
        # print("?")
        break
    if direction == 0:
        turn =1
    else:
        turn =0
    for i in range(4): # dy,dx
        cnt =0 
        tlog = []
        for j in range(3):
            ty = log[j][0] + dy[i]
            tx = log[j][1] + dx[i]
            tlog.append((ty,tx))
            if isOk(ty,tx):
                cnt+=1
        if cnt==3:
            if visit[direction][tlog[1][0]][tlog[1][1]] > moved+1:
                visit[direction][tlog[1][0]][tlog[1][1]] = moved+1
                Q.append((tlog, moved+1, direction))
    # turn
    cnt =0 
    tlog = []
    # print()
    # print(log)
    for j in range(3):
        ty = log[j][0] + turny[turn][j]
        tx = log[j][1] + turnx[turn][j]
        tlog.append((ty,tx))
        # print("ty = {0}, tx = {1}".format(ty,tx))
        if isOk(ty,tx):
            cnt+=1
    if cnt==3:
        cnt =0
        for i in [-1,0,1]:
            for j in [-1,0,1]:
                ty = log[1][0] + i
                tx = log[1][1] + j
                if isOk(ty,tx):
                    cnt+=1
        # print(turn)
        if cnt == 9:
            if visit[turn][tlog[1][0]][tlog[1][1]] > moved+1:
                visit[turn][tlog[1][0]][tlog[1][1]] = moved+1
                Q.append((tlog, moved+1, turn))
ans = min(visit[0][hole[1][0]][hole[1][1]],visit[1][hole[1][0]][hole[1][1]])
if ans == 987654321:
    ans = 0
print(ans)