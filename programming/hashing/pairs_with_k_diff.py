# Interviewbit - https://www.interviewbit.com/problems/diffk-ii/
class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return an integer
    def diffPossible(self, A, B):
        # Create empty dict, use array elements as keys, increase count to account for multiple appearances.
        d = dict()
        for a in A:
            if a in d:
                d[a] = d[a] + 1
            else:
                d[a] = 1

        for a in A:
            # i != j, this will happen only if B = 0 and we're looking at same index, hence, i will be = j.
            # However reduce the count since the element has been considered.
            if  B == 0 and d[a] == 1:
                d[a] = d[a] - 1
                continue
            if a+B in d and d[a+B] != 0:
                return 1
            if a-B in d and d[a-B] != 0:
                return 0
            d[a] = d[a] - 1
        return 0
