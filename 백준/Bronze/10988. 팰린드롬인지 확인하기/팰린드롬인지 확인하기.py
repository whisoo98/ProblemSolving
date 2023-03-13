s = input()
chk=1
for i in range(len(s)):
    if s[i]!=s[-1-i]:
        chk=0
print(chk)
