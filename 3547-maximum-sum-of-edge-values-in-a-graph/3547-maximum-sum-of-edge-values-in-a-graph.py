class Solution:
    def maxScore(self, n: int, edges: List[List[int]]) -> int:
        G = defaultdict(list)
        for i, j in edges:
            G[i].append(j)
            G[j].append(i)
        
        def get_comp(i):
            bfs = [i]
            seen[i] = True
            for i in bfs:
                for j in G[i]:
                    if not seen[j]:
                        seen[j] = True
                        bfs.append(j)
            return bfs

        C = []
        L = []
        seen = [False] * n
        for i in range(n):
            if not seen[i]:
                comp = get_comp(i)
                if all(len(G[x]) == 2 for x in comp):
                    C.append(len(comp))
                elif len(comp) > 1:
                    L.append(len(comp))

        def calc(l, r, is_cycle):
            d = deque([r, r])
            res = 0
            for a in range(r - 1, l - 1, -1):
                v = d.popleft()
                res += v * a
                d.append(a)
            return res + d[0] * d[1] * is_cycle

        res = 0
        L = sorted(L)[::-1]
        for k in C:
            res += calc(n - k + 1, n, 1)
            n -= k
        for k in L:
            res += calc(n - k + 1, n, 0)
            n -= k
        return res
        