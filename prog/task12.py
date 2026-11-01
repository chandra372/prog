import heapq
def h(state,goal):
    return sum(s!=g for s, g in zip(state,goal))
def astra(state,goal):
    pq=[(h(state,goal),0,state,[])]
    visited=set()
    while pq:
        f,g,state,path=heapq.heappop(pq)
        if state==goal:
            print("solution:\n",'\n ',path+[state])
            return
        visited.add(state)
        zero=state.index(0)
        moves=[-1,1,-3,3]
        for m in moves:
            new=zero+m
            if 0<=new<9:
                s=list(state)
                s[zero],s[new]=s[new],s[zero]
                tup=tuple(s)
                if tup not in visited:
                    heapq.heappush(pq,(g+1+h(tup,goal),g+1,tup,path+[state]))
start=(1,2,3,4,0,5,6,7,8)
goal=(1,2,3,4,5,6,7,8,0)
astra(start,goal)