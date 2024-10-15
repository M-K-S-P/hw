def mg(ins):
    return [list(map(float, i.split())) for i in ins.split('|')]

print(mg('1 2 | 3 4'))
