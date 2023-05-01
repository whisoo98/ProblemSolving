polynomial = input()


if 'x' in polynomial:
    posx = polynomial.find('x')
    coeff = int(polynomial[:posx])
    coeff//=2
    rest = polynomial[posx:]
    if len(rest)>2:
        b_coeff = int(rest[2:])
        rest = rest[:2]
        if b_coeff == -1:
            rest += '-'
        elif b_coeff == 1:
            pass
        else:
            rest+= str(b_coeff)
    if rest == 'x':
        ans = rest+'+W'
    else:
        ans = rest + 'x+W'
    if coeff == 1:
        print('x',ans,sep='')
    elif coeff == -1:
        print('-x',ans,sep='')
    else:
        print(coeff,'x',ans,sep='')
    pass
else:
    coeff = int(polynomial)
    if coeff == 1:
        print('x+W')
    elif coeff== -1:
        print('-x+W')
    elif coeff == 0:
        print('W')
    else:
        print(polynomial+'x+W')