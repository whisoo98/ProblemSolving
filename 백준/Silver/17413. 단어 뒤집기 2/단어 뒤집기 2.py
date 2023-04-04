import re
s = input()
idx = 0
ans = ''
while idx<len(s) and idx != -1:
    i = s[idx]
    if i == '<':
        temp = s.find('>')
        s_temp = s[idx:temp+1]
        ans += s_temp
        s = s[temp+1:]
    else:
        temp = s.find('<')
        if temp != -1:
            s_temp = s[idx:temp]
        elif temp == -1:
            s_temp = s[idx:]
        s_temp_list = s_temp.split()
        for t_idx,s_temp_word in enumerate(s_temp_list):
            ans += s_temp_word[::-1]
            if t_idx + 1 != len(s_temp_list):
                ans += ' '
        s = s[temp:]
    if(temp == -1):
        break
print(ans)