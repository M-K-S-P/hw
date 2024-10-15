def mz (a1, a2):
    return [(a1[i], a2[i]) for i in range(min(len(a1), len(a2)))]


a1 = [1,2,3]
a2 = ['a','b','c','d']

print(mz(a1,a2))
