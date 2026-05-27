import heapq
from collections import defaultdict

class Solution:
    def minCost(self, n, edges):

        graph = defaultdict(list)
        rev = defaultdict(list)

        for u, v, w in edges:
            graph[u].append((v, w))
            rev[v].append((u, w))

        INF = float('inf')
        dist = [INF] * n
        dist[0] = 0

        pq = [(0, 0)]  # (cost, node)

        while pq:
            cost, u = heapq.heappop(pq)

            if cost > dist[u]:
                continue

            if u == n - 1:
                return cost

            # normal edges
            for v, w in graph[u]:
                if cost + w < dist[v]:
                    dist[v] = cost + w
                    heapq.heappush(pq, (dist[v], v))

            # reverse edges
            for prev, w in rev[u]:
                if cost + 2 * w < dist[prev]:
                    dist[prev] = cost + 2 * w
                    heapq.heappush(pq, (dist[prev], prev))

        return -1


if __name__ == "__main__":

    sol = Solution()

    # ===== INPUT SECTION =====
    n = int(input().strip())
    m = int(input().strip())

    edges = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        edges.append([u, v, w])

    # ===== OUTPUT =====
    print(sol.minCost(n, edges))