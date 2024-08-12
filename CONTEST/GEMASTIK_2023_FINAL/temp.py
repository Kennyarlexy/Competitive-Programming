import numpy as np

# Create two matrices
matrix_a = np.array([[1, 2], [3, 4]])
matrix_b = np.array([[5, 6], [7, 8]])


# Perform matrix multiplication
result = np.matmul(matrix_a, matrix_b)
result_2 = matrix_a * matrix_b

print(result)
print(result_2)
