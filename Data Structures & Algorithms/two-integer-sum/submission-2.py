class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {} # hash table of things that are seen
        # key = vals in nums
        # val = indices of nums

        for i,x in enumerate(nums):
            need = target-x
            if need in seen:
                return [seen[need],i]
            seen[x] = i