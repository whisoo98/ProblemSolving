import string

alphabets = string.ascii_uppercase

String = input().upper()
Count = list()

for alphabet in alphabets:
    Count.append(String.count(alphabet))

if Count.count(max(Count))>1:
    print('?')
else:
    print(alphabets[Count.index(max(Count))])
