'''Write a program that accepts a list of numbers and a value n

chosen by the user. The program will then display all the numbers in the list

larger than n.'''


import random
nums = []
greater = []

for i in range(10):
    nums.append(random.randint(0,100))

n = int(input("Please input an integer (0-100): "))

nums.sort()

for i in range(len(nums)):
    if n < nums[i]:
        greater.append(nums[i])

print(f'{greater} are greater than your int')
