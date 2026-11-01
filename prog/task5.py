from queue import PriorityQueue

def a_star(graph,heuristics,start,goal):
    pq = PriorityQueue()
    pq.put((0+heuristics[start],start,[start]))
    while not pq.empty():
        f,g,node,path=pq.get()
        if node == goal:
            print("a* path:","->".join(path))
            print("total cost:",g)
            return
        for neighbor,cost in graph[node]:
            new_g=g+cost
            new_f=new_g+heuristics[neighbor]
            pq.put((new_f,new_g,node,neighbor,path+[neighbor]))
graph={
    'A':[('B',1),('C',4)],
    'B':[('C',3),('D',1)],
    'C':[('E',2)],
    'D':[('E',1)],
    'E':[],
}
heuristics={
    'A':7,
    
    'B':6,
    'C':2,
    'D':1,
    'E':0,
}
a_star(graph,heuristics,'A','E')