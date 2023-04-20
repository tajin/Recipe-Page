list1 = ['a', 'b', 'c', 'd']
list2 = []

for i in range(1, len(list1)+1):
    list2.append(list1[-i])


print(list1)
print(list2)