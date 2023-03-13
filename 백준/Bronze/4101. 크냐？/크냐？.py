while True:
    try:
        a,b = map(int,(input().split()))
        if a+b==0:
            break
        ans = a>b
        if ans:
            print("Yes")
        else:
            print("No") 
    except EOFError:
        break