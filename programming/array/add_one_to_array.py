# Interviewbit- https://www.interviewbit.com/problems/add-one-to-number/
class Solution:
    # @param A : list of integers
    # @return a list of integers
    def plusOne(self, A):
        carry = 1
        for i in range(len(A) -1, -1, -1):
            t = A[i]
            A[i] = (t + carry) % 10
            carry = (t + carry) // 10
        if carry:
            A.insert(0,1)
        i = 0
        while i < len(A)-1:
            if A[i] != 0:
                break
            i = i+1
        return A[i:]
