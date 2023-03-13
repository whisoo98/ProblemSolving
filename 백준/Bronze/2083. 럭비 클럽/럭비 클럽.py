while True:
    name,age,weight = map(str,input().split())
    age = int(age)
    weight = int(weight)
    if name == '#' and (age+weight)==0:
        break
    
    if age > 17 or weight >= 80:
        print(name,"Senior")
    else:
        print(name,"Junior")