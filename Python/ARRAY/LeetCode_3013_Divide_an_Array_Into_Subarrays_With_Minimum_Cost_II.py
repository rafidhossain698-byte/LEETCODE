from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums: list[int], k: int, dist: int) -> int:

        n = len(nums)
        need = k - 1  # how many more we need to pick

        small = SortedList()  # smallest `need` elements
        large = SortedList()  # remaining elements
        small_sum = 0
        
        def add(val):
            nonlocal small_sum
            if len(small) < need:
                small.add(val)
                small_sum += val
            elif small and val < small[-1]:
                small.add(val)
                small_sum += val
                # move largest of small to large
                moved = small.pop()
                small_sum -= moved
                large.add(moved)
            else:
                large.add(val)
        
        def remove(val):
            nonlocal small_sum
            if val in small:
                small.remove(val)
                small_sum -= val
                # pull smallest from large to small if available
                if large and len(small) < need:
                    moved = large.pop(0)
                    small.add(moved)
                    small_sum += moved
            else:
                large.remove(val)
        
        # Initialize window [1, 1+dist]
        for i in range(1, dist + 2):
            add(nums[i])
        
        result = float('inf')
        if len(small) == need:
            result = nums[0] + small_sum
        
        # Slide the window
        for i in range(dist + 2, n):
            add(nums[i])
            remove(nums[i - dist - 1])
            if len(small) == need:
                result = min(result, nums[0] + small_sum)
        
        return result


# Input
nums = list(map(int, input("Enter nums: ").split()))
k = int(input("Enter k: "))
dist = int(input("Enter dist: "))

sol = Solution()
print("Output:", sol.minimumCost(nums, k, dist))