import heapq

class Node:
    def __init__(self, val, idx):
        self.val = val
        self.idx = idx
        self.prev = None
        self.next = None
        self.alive = True


class Solution:
    def minimumPairRemoval(self, nums):

        n = len(nums)
        nodes = [Node(nums[i], i) for i in range(n)]

        for i in range(n):
            if i > 0:
                nodes[i].prev = nodes[i - 1]
            if i < n - 1:
                nodes[i].next = nodes[i + 1]

        heap = []
        counter = 0  # versioning

        def push(left):
            if left and left.next and left.alive and left.next.alive:
                nonlocal counter
                heapq.heappush(heap, (left.val + left.next.val, counter, left))
                counter += 1

        for i in range(n - 1):
            push(nodes[i])

        def is_non_decreasing(head):
            cur = head
            while cur and cur.next:
                if cur.val > cur.next.val:
                    return False
                cur = cur.next
            return True

        head = nodes[0]
        ops = 0

        while True:

            if is_non_decreasing(head):
                return ops

            # get valid pair
            while heap:
                s, _, left = heapq.heappop(heap)
                if not left.alive:
                    continue
                if not left.next or not left.next.alive:
                    continue
                break

            right = left.next

            # merge
            left.val += right.val
            right.alive = False

            nxt = right.next
            left.next = nxt
            if nxt:
                nxt.prev = left

            # update head if needed
            if head == right:
                head = left

            # push affected pairs only
            push(left.prev)
            push(left)

            ops += 1