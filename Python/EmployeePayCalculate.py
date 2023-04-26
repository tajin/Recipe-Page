'''
//First attempt

payrate = 20
employees = []
employee_hours = [0]*10


for i in range(10):
    employees.append("Employee " + str(i+1))

for i in range(len(employee_hours)):
    weekly_hours = int(input(f"HOw many hours did employee {str(i+1)} work this week: "))
    employee_hours[i] = weekly_hours * payrate

final_pay = {employees[i]: employee_hours[i] for i in range(len(employees))}


for i in range(len(final_pay)):
    print(key[i] + value[i])
print(final_pay)'''


#Refined attempt

payrate = 20
employees = []
employee_hours = [0]*10


for i in range(10):
    employees.append("Employee " + str(i+1))

for i in range(len(employee_hours)):
    weekly_hours = int(input(f"HOw many hours did employee {str(i+1)} work this week: "))
    employee_hours[i] = weekly_hours * payrate

final_pay = {employees[i]: employee_hours[i] for i in range(len(employees))}

print(final_pay)

