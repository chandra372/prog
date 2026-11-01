from collections import deque
graph={
    'a':['b','c'],
    'b':['d','e'],
    'c':['f'],
    'd':[],
    'e':['f'],
    'f':[]
}
def dfs_recursive(graph,node,visited=None):
    if visited is None:

        visited=set()
    if node not in visited:
        print(node,end=' ')
        visited.add(node)
        for neighbor in graph[node]:
            dfs_recursive(graph,neighbor,visited)
print("dfs traversal:")
dfs_recursive(graph,'a' )
