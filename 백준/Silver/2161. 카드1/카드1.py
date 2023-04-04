n = int(input())
cards = [i for i in range(1,n+1)]

while cards:
    print(cards.pop(0), end = ' ')
    if cards:
        cards.append(cards.pop(0))