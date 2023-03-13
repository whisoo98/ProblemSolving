n = int(input())

l = []
count = [0 for _ in range(4)]
M=0
for _ in range(6):
    direction, size = map(int,input().split())
    count[direction-1]+=1
    l.append((size, direction))
    M = max(M,size)
    
while True:
    if l[0][0]==M:
        break
    l.append(l.pop(0))
    
sub1 = count.index(2) +1
sub2 = count[sub1:].index(2)+sub1+1
if l[1][1]!=sub1 and l[1][1]!=sub2:
    l.append(l.pop(0))    

sub = l[2][0]*l[3][0]
dimension = l[0][0]*l[-1][0]
print((dimension-sub)*n)