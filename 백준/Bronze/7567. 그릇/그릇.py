bowls = input()
prev = bowls[0]
height = 10
for bowl in bowls[1:]:
    if prev == bowl:
        height+=5
    else:
        height += 10
    prev = bowl
print(height)