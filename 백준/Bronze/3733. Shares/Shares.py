while True:
    try:
        A, B= map(int,input().split())
        A+=1
        print(B//A)
    except:
        break
