def md(di):
    idi = {} 
    for i,j in di.items(): 
        idi[j] = idi.get(j, []) + [i]
    for i,j in idi.items():
        if len(j) == 1:
            idi[i] = j[0]
        else:
            idi[i] = tuple(j)
    return idi
d = {"I": 123,
     "P": 325,
     "L": 325,
     }
errd = {1234:'qwer','er': [1234, 234]}
print(md(d))
print(md(errd))

