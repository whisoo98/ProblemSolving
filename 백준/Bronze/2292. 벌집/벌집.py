a = int(input())

modifiedA = (a-1)/6
for i in range(100_000):
    if modifiedA<=i*(i+1)/2:
        #print(f'num is {j} and answer is{i+1}')
        print(i+1)
        break