from pprint import pprint
from copy import deepcopy

y,x = map(int, input().split())
arr = []
arr.append([])
virus = []
dx = [0,0,-1,1]
dy = [1,-1,0,0]
cnt = 0
ans = -1

for i in range(y):
    temp = [-1]
    temp += list(map(int,input().split()))
    for idx,j in enumerate(temp):
        if j==2:
            virus.append((i+1,idx))
        elif j==0:
            cnt+=1
    arr.append(temp)

labs = [[[-1 for _ in range(80)] for _ in range(80)] for _ in range(80)]


def ok(ty, tx,temp):
    if ty<1 or ty > y or tx<1 or tx>x or temp[ty][tx]==1 or temp[ty][tx]==2:
        return False
    return True

def zero(ty,tx):
    if arr[ty][tx]==1 or arr[ty][tx]==2:
        return False
    return True

def bfs(i,j,k):
    temp = deepcopy(arr)
    #temp=arr.copy()
    temp[i[0]][i[1]]=1
    temp[j[0]][j[1]]=1
    temp[k[0]][k[1]]=1
    q = deepcopy(virus)
    ii = i[0]*x+i[1]
    jj = j[0]*x+j[1]
    kk = k[0]*x+k[1]
    
    labs[ii][jj][kk]=0
    labs[ii][kk][jj]=0
    
    labs[jj][ii][kk]=0
    labs[jj][kk][ii]=0
    
    labs[kk][jj][ii]=0
    labs[kk][ii][jj]=0
    count = cnt-3
    while len(q):
        
        
        tup = q.pop(0)
        yy = tup[0]
        xx = tup[1]
        for h in range(4):
            ty = yy + dy[h]
            tx = xx + dx[h]
            if(ok(ty,tx,temp)):
                count-=1
                q.append((ty,tx))
                temp[ty][tx]=2
            


    labs[ii][jj][kk]=count
    labs[ii][kk][jj]=count
    
    labs[jj][ii][kk]=count
    labs[jj][kk][ii]=count
    
    labs[kk][jj][ii]=count
    labs[kk][ii][jj]=count


def Solution(i,j,k):
    ii = i[0]*x+i[1]
    jj = j[0]*x+j[1]
    kk = k[0]*x+k[1]
    if labs[ii][jj][kk]!= -1:
        return labs[ii][jj][kk]
    bfs(i,j,k)
    return labs[ii][jj][kk]

for i in range(1, (y)*x+1):
    for j in range(1, (y)*x+1):
        for k in range(1, (y)*x+1):
            if i==j or j==k or k==i:
                continue
            ti = list(divmod(i,x))
            if ti[1]==0:
                ti[1]=x
                ti[0]-=1;
            tj = list(divmod(j,x))
            if tj[1]==0:
                tj[1]=x
                tj[0]-=1;
            tk = list(divmod(k,x))
            if tk[1]==0:
                tk[1]=x
                tk[0]-=1;
            ti[0]+=1
            tj[0]+=1
            tk[0]+=1
            if zero(ti[0],ti[1]) and zero(tj[0],tj[1]) and zero(tk[0],tk[1]):
                ret = Solution(ti,tj,tk)
                ans = max(ans,ret)
            
                
print(ans)






