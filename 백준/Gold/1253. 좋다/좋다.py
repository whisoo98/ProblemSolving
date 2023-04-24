import sys

input = sys.stdin.readline

n = int(input())
numbers = list(map(int,input().split()))
goodgood = []
numbers.sort()
for idx, number in enumerate(numbers):
    left = 0
    right = n-1
    if(idx == left):
        left+=1
    if(idx == right):
        right -= 1
    if number in goodgood:
        continue
    while(left<right):
        sum = numbers[left]+numbers[right]
        if sum == number:
            goodgood.append(number)
            break
        if sum < number:
            left+=1
            if(idx == left):
                left+=1
        else:
            right -= 1
            if(idx == right):
                right -= 1
         
ans = 0   
for good in goodgood:
    ans += numbers.count(good)
    
print(ans)