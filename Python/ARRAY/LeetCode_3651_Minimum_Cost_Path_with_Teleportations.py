import heapq
from collections import defaultdict

class Solution:
    def minCost(self, grid, k):

        m, n = len(grid), len(grid[0])

        # dist[x][y][used_teleport]
        INF = float('inf')
        dist = [[[INF] * (k + 1) for _ in range(n)] for _ in range(m)]

        dist[0][0][0] = 0

        pq = [(0, 0, 0, 0)]  # cost, x, y, used_teleport

        dirs = [(0, 1), (1, 0)]

        while pq:
            cost, x, y, used = heapq.heappop(pq)

            if (x, y) == (m - 1, n - 1):
                return cost

            if cost != dist[x][y][used]:
                continue

            # -------------------
            # Normal moves
            # -------------------
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy

                if 0 <= nx < m and 0 <= ny < n:
                    nc = cost + grid[nx][ny]

                    if nc < dist[nx][ny][used]:
                        dist[nx][ny][used] = nc
                        heapq.heappush(pq, (nc, nx, ny, used))

            # -------------------
            # Teleport (O(m*n) expansion conceptually)
            # -------------------
            if used < k:
                for i in range(m):
                    for j in range(n):
                        if grid[i][j] <= grid[x][y]:
                            if cost < dist[i][j][used + 1]:
                                dist[i][j][used + 1] = cost
                                heapq.heappush(pq, (cost, i, j, used + 1))

        return -1