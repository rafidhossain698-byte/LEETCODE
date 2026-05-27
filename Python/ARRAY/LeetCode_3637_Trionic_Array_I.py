class Solution:
    def isTrionic(self, nums: list[int]) -> bool:
        n = len(nums)

        for p in range(1, n - 1):           # 0 < p
            for q in range(p + 1, n - 1):   # p < q < n-1

                # Check nums[0..p] strictly increasing
                inc1 = all(nums[i] < nums[i+1] for i in range(0, p))

                # Check nums[p..q] strictly decreasing
                dec  = all(nums[i] > nums[i+1] for i in range(p, q))

                # Check nums[q..n-1] strictly increasing
                inc2 = all(nums[i] < nums[i+1] for i in range(q, n-1))

                if inc1 and dec and inc2:
                    return True

        return False


# Input
nums = list(map(int, input("Enter nums: ").split()))

sol = Solution()
print("Output:", sol.isTrionic(nums))