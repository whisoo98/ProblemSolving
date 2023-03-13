n,k  = map(int,input().split())
room = 0
grades = [[0 for _ in range(2)] for _ in range(7)]
for _ in range(n):
    sex, grade = map(int,input().split())
    grades[grade][sex]+=1
    
for grade in range(1,7):
    for sex in range(2):
        mok, rest = divmod(grades[grade][sex],k)
        if rest != 0:
            mok+=1
        room+=mok
print(room)