# Interviewbit- https://www.interviewbit.com/problems/add-one-to-number/
class Solution:
    # @param A : list of integers
    # @return a list of integers
    def plusOne(self, A):
        carry = 1
        loop_start_last_elem_index = len(A) - 1
        loop_end_index_minus_one = -1
        loop_direction = -1
        for elem_index in range(loop_start_last_elem_index, loop_end_index_minus_one, loop_direction):
            elem = A[elem_index]
            A[elem_index] = (elem + carry) % 10
            carry = (elem + carry) // 10
        if carry:
            A.insert(0, 1)
        elem_index = 0
        while elem_index < len(A)-1:
            if A[elem_index] != 0:
                break
            elem_index = elem_index+1
        return A[elem_index:]
