ID = input()
arr = [[':fan:',':fan:',':fan:'],[':fan:',':appa:',':fan:'],[':fan:',':fan:',':fan:']]
arr[1][1] = ':'+ID+':'
for i in range(3):
    for j in range(3):
        print(arr[i][j],sep='',end='')
    print()