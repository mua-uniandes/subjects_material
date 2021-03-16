

def dfs(nodes, v):
    visited = [0]*length(nodes)
    dfsUtil(nodes, v, visited)

def dfsUtil(nodes, v, visited):
    visited[v] = 1
    for u in nodes[v]:
        if not visited[u]:
            dfsUtil(nodes, u, visited)
