class Solution:
    def minimumCost(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Try all valid split points i and j where 0 < i < j < n
        min_cost = float('inf')
        
        for i in range(1, n - 1):        # second subarray starts at i
            for j in range(i + 1, n):    # third subarray starts at j
                cost = nums[0] + nums[i] + nums[j]
                min_cost = min(min_cost, cost)
        
        return min_cost


# Input
nums = list(map(int, input("Enter numbers separated by spaces: ").split()))

# Run
sol = Solution()
result = sol.minimumCost(nums)
print("Output:", result)