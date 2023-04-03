h,m = map(int, input().split())
time = int(input())

day = h*60 + m +time
day%=1440

print(f'{day//60} {day%60}')