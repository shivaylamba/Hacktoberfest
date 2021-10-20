from IPython.display import clear_output
mult_table = [
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
[1, 2, 3, 4, 0, 6, 7, 8, 9, 5],
[2, 3, 4, 0, 1, 7, 8, 9, 5, 6],
[3, 4, 0, 1, 2, 8, 9, 5, 6, 7],
[4, 0, 1, 2, 3, 9, 5, 6, 7, 8],
[5, 9, 8, 7, 6, 0, 4, 3, 2, 1],
[6, 5, 9, 8, 7, 1, 0, 4, 3, 2],
[7, 6, 5, 9, 8, 2, 1, 0, 4, 3],
[8, 7, 6, 5, 9, 3, 2, 1, 0, 4],
[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
]

perm_table = [
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
[1, 5, 7, 6, 2, 8, 3, 0, 9, 4],
[5, 8, 0, 3, 7, 9, 6, 1, 4, 2],
[8, 9, 1, 6, 0, 4, 3, 5, 2, 7],
[9, 4, 5, 3, 1, 2, 6, 8, 7, 0],
[4, 2, 8, 6, 5, 7, 3, 9, 0, 1],
[2, 7, 9, 3, 8, 0, 6, 4, 1, 5],
[7, 0, 4, 6, 9, 1, 3, 2, 5, 8]
]

inv_table = [0, 4, 3, 2, 1, 5, 6, 7, 8, 9]

def checksum(number):
    c = 0
    for i, item in enumerate(reversed(str(number))):
        c = mult_table[c][perm_table[i % 8][int(item)]]
    return c
def user_data():
    number='wr'
    while (number.isnumeric()==False) or len(number)!=12:
        number=input('Your Aadhar number is: ')
        if len(number)!=12:
            print('Enter a 12 digit aadhar number')
        if number.isnumeric()==False:
            print('Invalid input!')
    return number
Aadhar=user_data()
clear_output()
if checksum(Aadhar)==0:
    print('your number is a valid aadhar number')
else:
    print('Invalid aadhar number')
