class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        for char in letters:
            if char > target:
                return char
        return letters[0]

# Input
letters = input("Enter letters separated by spaces: ").split()
target = input("Enter target character: ")

# Run
sol = Solution()
result = sol.nextGreatestLetter(letters, target)
print("Output:", result)