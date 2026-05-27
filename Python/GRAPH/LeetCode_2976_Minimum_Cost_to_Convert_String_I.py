class Solution:
    def minimumCost(self, source, target, original, changed, cost):

        INF = float('inf')
        n = 26

        dist = [[INF] * n for _ in range(n)]

        for i in range(n):
            dist[i][i] = 0

        # build graph
        for o, c, w in zip(original, changed, cost):
            u = ord(o) - ord('a')
            v = ord(c) - ord('a')
            dist[u][v] = min(dist[u][v], w)

        # Floyd-Warshall
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]

        # compute answer
        ans = 0

        for s, t in zip(source, target):
            u = ord(s) - ord('a')
            v = ord(t) - ord('a')

            if dist[u][v] == INF:
                return -1

            ans += dist[u][v]

        return ans


# -------------------------
# Input section (VS Code)
# -------------------------
if __name__ == "__main__":

    source = input().strip()
    target = input().strip()

    m = int(input().strip())

    original = []
    changed = []
    cost = []

    for _ in range(m):
        o, c, w = input().split()
        original.append(o)
        changed.append(c)
        cost.append(int(w))

    sol = Solution()
    print(sol.minimumCost(source, target, original, changed, cost))