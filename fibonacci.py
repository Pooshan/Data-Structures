__author__ = 'Pooshan'

parents, babies = (1, 1)
while babies < 100:
    print('This generation has {0} babies' .format(babies))
    parents, babies = (babies, parents + babies)

'''
Output:
This generation has 1 babies
This generation has 2 babies
This generation has 3 babies
This generation has 5 babies
This generation has 8 babies
This generation has 13 babies
This generation has 21 babies
This generation has 34 babies
This generation has 55 babies
This generation has 89 babies
'''