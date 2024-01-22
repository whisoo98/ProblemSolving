import sys

input = sys.stdin.readline

def main():
    T = int(input())

    while (T):
        T-=1
        n = int(input())
        arr = list(map(int,input().split()))
        print(min(arr),max(arr))
    
    
if __name__ == "__main__":
    main()