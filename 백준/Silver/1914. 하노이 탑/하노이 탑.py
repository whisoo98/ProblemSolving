
def Move(top, bottom, now, go_to, rest_of):
    if top < bottom:
        Move(top, bottom-1, now, rest_of, go_to)
        Move(bottom, bottom, now, go_to, rest_of)
        Move(top, bottom-1, rest_of, go_to, now)
    elif top == bottom:
        print(now, go_to)
        
def HanoiTop(n):
    Move(1,n,1,3,2)

def main():
    n = int(input())
    print(pow(2,n)-1)
    if n <= 20:
        HanoiTop(n)





if __name__ == "__main__":
    main()