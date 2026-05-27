class Solution:
    def maxTrionicSum(self, nums: list[int]) -> int:
        n = len(nums)

        # Precompute: for each index i, how far left can we go strictly increasing ending at i
        # left[i] = leftmost index l such that nums[l..i] is strictly increasing
        left = [0] * n
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                left[i] = left[i-1]
            else:
                left[i] = i

        # Precompute: for each index i, how far right can we go strictly increasing starting at i
        # right[i] = rightmost index r such that nums[i..r] is strictly increasing
        right = [0] * n
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                right[i] = right[i+1]
            else:
                right[i] = i

        # Precompute prefix sums for O(1) range sum queries
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]

        def range_sum(l, r):
            return prefix[r+1] - prefix[l]

        result = float('-inf')

        # Try every valid (p, q) pair where p is peak, q is valley
        # p must have: left[p] < p (increasing from some l to p)
        #              nums[p] > nums[p+1] (start of decrease)
        # q must have: nums[q] < nums[q+1] (start of increase)
        #              right[q] > q (increasing from q to some r)

        for p in range(1, n-2):
            if left[p] == p:        # no increasing segment ending at p
                continue
            if nums[p] <= nums[p+1]: # not a peak
                continue

            for q in range(p+1, n-1):
                if nums[q-1] <= nums[q]:  # not decreasing into q
                    break
                if right[q] == q:         # no increasing segment starting at q
                    continue
                if nums[q] >= nums[q+1]:  # not a valley
                    continue

                l = left[p]
                r = right[q]
                total = range_sum(l, r)
                result = max(result, total)

        return result


# Input
nums = list(map(int, input("Enter nums: ").split()))

sol = Solution()
print("Output:", sol.maxTrionicSum(nums))