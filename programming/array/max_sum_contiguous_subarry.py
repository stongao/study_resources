# interviewbit - https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maxSubArray(self, A):
        psum = 0
        maxsum = int(sys.maxsize) * -1
        for i in A:
            psum = psum + i
            if psum > maxsum:
                maxsum = psum
            if psum < 0:
                psum = 0
        return maxsum
