def dfs(u):
    visited[u] = 1
    print(u + 1, end=" ")
    for i in range(n):
        if visited[i] == 0 and graph[u][i] == 1:
            dfs(i)

queue=[] 
front,rear=0,0
def bfs(u):
    queue.append(u)
    visited[u]=1
    while len(queue):
        now=queue.pop(0)
        print(now+1, end=" ")
        for i in range(n):
            if graph[now][i]==1 and visited[i]==0:
                queue.append(i)
                visited[i]=1


n, m, v = map(int, input().split())

# 그래프 초기화
graph = [[0 for _ in range(n)] for _ in range(n)]
visited = [0 for _ in range(n)]

# 그래프 간선 정보 입력
for _ in range(m):
    a, b = map(int, input().split())
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1

# DFS 호출
dfs(v - 1)
print()
#초기화
visited = [0 for _ in range(n)]
bfs(v-1)