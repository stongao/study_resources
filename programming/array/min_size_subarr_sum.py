#Leetcode - https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        curr_sum = 0
        n = len(nums)
        min_len = n + 1
        
        start = 0
        end = 0
        while end < n:
            
            while curr_sum < s and end < n:
                curr_sum += nums[end]
                end += 1
                if curr_sum < 0 and s > 0:
                    curr_sum = 0
                    start = end
                
            while start < n and curr_sum >= s:
                if(end - start < min_len):
                    min_len = end - start
                
                curr_sum -= nums[start]
                start += 1
        if min_len == n+1:
            return 0
        return min_len
            
