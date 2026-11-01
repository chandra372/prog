from asyncio import graph
from collections import heapq

import heapq
graph={
    's':['a','b'],
    'a':['c','d'],
    'b':['e',],
    'c':[ ],
    'd':['g'],
    'e':['g'],
    'g':[ ]
}
heuristics={
    's':5,
    'a':4,
    'b':6,

    'c':4,
    'd':2,
    'e':3,
    'g':0
}
def best_first_search(start,goal):
    visited=set()
    pq=[]
    heapq.heappush(pq,(heuristics[start],start))
    while pq:
        h,current=heapq.heappop(pq)
        print("visiting node:",current)
        if current==goal:
            print("Goal node found!")
            return
        if current not in visited:
            visited.add(current)
            for neighbor in graph[current]:
                if neighbor not in visited:
                    heapq.heappush(pq,(heuristics[neighbor],neighbor))
                    print("goal node not found.")
best_first_search('s','g')