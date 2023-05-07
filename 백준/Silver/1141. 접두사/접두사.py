import sys

input = sys.stdin.readline

n = int(input())
words =[]
for i in range(n):
    s = input().split()[0]
    words.append(s)
words.sort()
# print(words)
dictionary = words[:]
for i in range(n):
    for j in range(i+1,n):
        deleted = 0
        cnt = 0 
        for k in range(len(words[i])):
            if words[i][k] == words[j][k]:
                cnt+=1
            else:
                break
        if cnt == len(words[i]):
            dictionary.remove(words[i])
            deleted=1
            break
        if deleted:
            break
    
print(len(dictionary))