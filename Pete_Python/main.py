import numpy as np
from sympy import symbols, Eq, Matrix, solve, sympify

def swap_rows(M, row_index_1, row_index_2): 
    M = M.copy()
   
    M[[row_index_1, row_index_2]] = M[[row_index_2, row_index_1]]
    return M

def get_index_first_non_zero_value_from_column(M, column, starting_row):
    # Get the column array starting from the specified row
    column_array = M[starting_row:,column]
    for i, val in enumerate(column_array):

        if not np.isclose(val, 0, atol = 1e-5):
            
            index = i + starting_row
            return index
  
    return -1

def get_index_first_non_zero_value_from_row(M, row, augmented = False):

    # Create a copy to avoid modifying the original matrix
    M = M.copy()


    # If it is an augmented matrix, then ignore the constant values
    if augmented == True:
        # Isolating the coefficient matrix (removing the constant terms)
        M = M[:,:-1]
        
    # Get the desired row
    row_array = M[row]
    for i, val in enumerate(row_array):
        # If finds a non zero value, returns the index. Otherwise returns -1.
        if not np.isclose(val, 0, atol = 1e-5):
            return i
    return -1

def augmented_matrix(A, B):
   
    augmented_M = np.hstack((A,B))
    return augmented_M

def row_echelon_form(A, B):

    det_A = np.linalg.det(A)
    if np.isclose(det_A, 0) == True:
        return 'Singular system'

    A = A.copy()
    B = B.copy()
   
    A = A.astype('float64')
    B = B.astype('float64')


    num_rows = len(A) 
    M = augmented_matrix(A, B)
    

    for row in range(num_rows):
        pivot_candidate = M[row, row]
        if np.isclose(pivot_candidate, 0) == True: 
            first_non_zero_value_below_pivot_candidate = get_index_first_non_zero_value_from_column(M, row, row) 
            M = swap_rows(M, row, first_non_zero_value_below_pivot_candidate) 
            pivot = M[row,row] 
        else:
            pivot = pivot_candidate 
     
        M[row] = 1/pivot * M[row]
       
        for j in range(row + 1, num_rows): 

            value_below_pivot = M[j,row]
            M[j] = M[j] - value_below_pivot*M[row]

    return M

# GRADED FUNCTION: back_substitution

def back_substitution(M):
    
    # Make a copy of the input matrix to avoid modifying the original
    M = M.copy()

    # Get the number of rows (and columns) in the matrix of coefficients
    num_rows = M.shape[0]
    
    # Iterate from bottom to top
    for row in reversed(range(num_rows)): 
        substitution_row = M[row,:]

        # Get the index of the first non-zero element in the substitution row. Remember to pass the correct value to the argument augmented.
        index = index = get_index_first_non_zero_value_from_column(M, row, row)

        # Iterate over the rows above the substitution_row
        for j in range(row): 

            # Get the row to be reduced. The indexing here is similar as above, with the row variable replaced by the j variable.
            row_to_reduce = M[j,:]

            # Get the value of the element at the found index in the row to reduce
            value = row_to_reduce[index]
            
            # Perform the back substitution step using the formula row_to_reduce -> row_to_reduce - value * substitution_row
            row_to_reduce = row_to_reduce - value * substitution_row
            M[j,:] = row_to_reduce

 
    solution = M[:,-1]
    
    return solution

def gaussian_elimination(A, B):

    # Get the matrix in row echelon form
    row_echelon_M = row_echelon_form(A, B)

    # If the system is non-singular, then perform back substitution to get the result. 
    # Since the function row_echelon_form returns a string if there is no solution, let's check for that.
    # The function isinstance checks if the first argument has the type as the second argument, returning True if it does and False otherwise.
    if not isinstance(row_echelon_M, str): 
        solution = back_substitution(row_echelon_M)


    return solution



def string_to_augmented_matrix(equations):
    # Split the input string into individual equations
    equation_list = equations.split('\n')
    equation_list = [x for x in equation_list if x != '']
    # Create a list to store the coefficients and constants
    coefficients = []
    
    ss = ''
    for c in equations:
        if c in 'abcdefghijklmnopqrstuvwxyz':
            if c not in ss:
                ss += c + ' '
    ss = ss[:-1]
    
    # Create symbols for variables x, y, z, etc.
    variables = symbols(ss)
    # Parse each equation and extract coefficients and constants
    for equation in equation_list:
        # Remove spaces and split into left and right sides
        sides = equation.replace(' ', '').split('=')
        
        # Parse the left side using SymPy's parser
        left_side = sympify(sides[0])
        
        # Extract coefficients for variables
        coefficients.append([left_side.coeff(variable) for variable in variables])
        
        # Append the constant term
        coefficients[-1].append(int(sides[1]))

    # Create a matrix from the coefficients
    augmented_matrix = Matrix(coefficients)
    augmented_matrix = np.array(augmented_matrix).astype("float64")

    A, B = augmented_matrix[:,:-1], augmented_matrix[:,-1].reshape(-1,1)
    
    return ss, A, B

equations = """
3*x + 6*y + 6*w + 8*z = 1
5*x + 3*y + 6*w = -10
4*y - 5*w + 8*z = 8
4*w + 8*z = 9
"""

variables, A, B = string_to_augmented_matrix(equations)

sols = gaussian_elimination(A, B)

if not isinstance(sols, str):
    for variable, solution in zip(variables.split(' '),sols):
        print(f"{variable} = {solution:.4f}")
else:
    print(sols)

    