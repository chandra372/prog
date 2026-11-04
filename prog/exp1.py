from collections import deque
graph={
    'a':['b','c'],
    'b':['d','e'],
    'c':['f'],
    'd':[],
    'e':['f'],
    'f':[],

}
def bfs(graph,start):
    visited=set()
    queue=deque([start])
    while queue:
        node=queue.popleft()
        if node not in visited:
            print(node,end=' ')
            visited.add(node)
            queue.extend(graph[node])
print("\nBFS traverssal:")
bfs(graph,'a')