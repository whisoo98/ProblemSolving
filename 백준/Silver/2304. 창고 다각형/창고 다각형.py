import sys

input = sys.stdin.readline

n = int(input())
block = [0 for _ in range(1005)]

for i in range(n):
    idx, height = map(int,input().split())
    #block.append((idx,height))
    block[idx] = height
    
# block.sort()
# print(block)
# left = block[0][0]
# right = block[-1][0]
# left_height = block[0][1]
# right_height = block[-1][1]
left = 0
right = 1004
left_height = 0
right_height = 0
area= 0
while not left_height:
    left_height=block[left]
    left+=1
while not right_height:
    right_height=block[right]
    right-=1
right+=1
left -=1
while(left<right):
    if(left_height<right_height):
        # print("left height : ",left_height)
        area += left_height
        left += 1
        left_height = max(left_height, block[left])
    else:
        # print("right height : ",right_height)
        area += right_height
        right -= 1
        right_height = max(right_height, block[right])
area += max(left_height,right_height)
print(area)
