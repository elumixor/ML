import numpy as np
from numpy import array

# A = array([1, 2, 3])
# print(A)
# print(A + 1)
# print()

# A = array([[1, 2], [3, 4]])
# print(A)
# print()
# print(A + 1)
# print()
# print(A + [1, 1])
# print()
# print(A + [[1], [1]])
# print()
# print(A + [[1, 1], [1, 1]])
# print()
# # print(A + [1, 1, 1, 1])
# print(A + [1, 1])
# print()

# A = array([[[0, 0], [0, 0], [0, 0]], [[0, 0], [0, 0], [0, 0]]])
# print(A)

v = np.array([1, 2, 3])
u = np.array([1, 2])
b = np.array([[1, 2], [3, 4], [5, 6]])

c = np.outer(u, v)
bc = np.outer(b, c)

# print(a)
# print(b)
print(c)
print(bc)
