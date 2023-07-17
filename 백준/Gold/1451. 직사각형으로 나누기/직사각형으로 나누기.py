import sys

input = sys.stdin.readline

def horizontalSum(x1,y1,x2,y2, square):
    ret = 0
    for i in range(y1,y2+1):
        ret += sum(square[i][x1:x2+1])
    return ret

def verticalSum(x1,y1,x2,y2, square):
    ret = 0
    for i in range(y1,y2+1):
        ret += sum(square[i][x1:x2+1])
    return ret

# square x : 0 ~ x-1
# square y : 0 ~ y-1
def divideSquare(y, x, square):
    # horizontally
    # case 1 : all horizotal
    multiplication = 1
    ret = -987654321
    for i in range(y-2): 
        for j in range(i+1, y-1):
            multiplication = 1
            multiplication *= horizontalSum(0, 0, x-1, i, square)
            multiplication *= horizontalSum(0, i+1, x-1, j, square)
            multiplication *= horizontalSum(0, j+1, x-1, y-1, square)
            # print("multiplication :", multiplication)
            ret = max(multiplication, ret)
    # case 2 : left vertical + two horizontal
    for x_split in range(x-1):
        for y_split in range(y-1):
            multiplication = 1
            multiplication *= verticalSum(0, 0, x_split, y-1, square)
            multiplication *= horizontalSum(x_split+1, 0, x-1, y_split, square)
            multiplication *= horizontalSum(x_split+1, y_split+1, x-1, y-1, square)
            # print("multiplication :", multiplication)
            ret = max(multiplication, ret)
    
    # case 3 : two horizontal + right vertical
    for x_split in range(x-1):
        for y_split in range(y-1):
            multiplication = 1
            multiplication *= horizontalSum(0, 0, x_split, y_split, square)
            multiplication *= horizontalSum(0, y_split+1, x_split, y-1, square)
            multiplication *= verticalSum(x_split+1, 0, x-1, y-1, square)
            # print("multiplication :", multiplication)
            ret = max(multiplication, ret)
            
    # vertically
    # case 4 : all vertical
    for i in range(x-2): 
        for j in range(i+1, x-1):
            multiplication = 1
            multiplication *= verticalSum(0, 0, i, y-1, square)
            multiplication *= verticalSum(i+1, 0, j, y-1, square)
            multiplication *= verticalSum(j+1, 0, x-1, y-1, square)
            # print("multiplication :", multiplication)
            ret = max(multiplication, ret)        
               
    # case 5 : upper horizontal + two vertical
    for y_split in range(y-1):
        for x_split in range(x-1):
            multiplication = 1
            multiplication *= horizontalSum(0, 0, x-1, y_split, square)
            multiplication *= verticalSum(0, y_split+1, x_split, y-1, square)
            multiplication *= verticalSum(x_split+1, y_split+1, x-1, y-1, square)
            # print("multiplication :", multiplication)
            ret = max(multiplication, ret)
    
    # case 6 : two vertical + lower horizontal
    for y_split in range(y-1):
        for x_split in range(x-1):
            multiplication = 1
            multiplication *= verticalSum(0, 0, x_split, y_split, square)
            multiplication *= verticalSum(x_split+1, 0, x-1, y_split, square)
            multiplication *= horizontalSum(0, y_split+1, x-1, y-1, square)
            # print("multiplication :", multiplication)
            ret = max(multiplication, ret)
            
    return ret

def main():
    y,x = map(int,input().split())
    square = []
    for _ in range(y):
        #l = list(map(int,input().split()))
        numbers = input()
        l= []
        for number in numbers[:-1]:
            l.append(int(number))
        square.append(l)
    # print(square)
    ans = divideSquare(y,x, square)
    print(ans)

if __name__ == "__main__":
    main()