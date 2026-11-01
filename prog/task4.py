import heapq
class Graph:
    def __init__(self):
        self.edges = {}
        self.h = {}
    def add_edge(self, from_node, to_node, cost):
        self.edges.setdefault(from_node, []).append((to_node, cost))
        self.edges.setdefault(to_node, []).append((from_node, cost))
    def set_heuristic(self, node, value):
        self.h[node] = value
    def best_first_search(self, start, goal):
        visited = set()
        priority_queue = [(self.h[start], start)]
        path = []
        while priority_queue:
            _, current = heapq.heappop(priority_queue)
            path.append(current)
            if current == goal:
                print("Goal reached:", goal)
                return path
            visited.add(current)
            for neighbor, _ in self.edges.get(current, []):
                if neighbor not in visited:
                    heapq.heappush(priority_queue, (self.h[neighbor],
                                                    neighbor))
        return None
g = Graph()
g.add_edge('A', 'B', 1)
g.add_edge('A', 'C', 3)
g.add_edge('B', 'D', 4)
g.add_edge('C', 'D', 1)
g.add_edge('C', 'E', 6)
g.add_edge('D', 'F', 2)
g.add_edge('E', 'F', 1)

g.set_heuristic('A', 6)
g.set_heuristic('B', 5)
g.set_heuristic('C', 4)
g.set_heuristic('D', 3)
g.set_heuristic('E', 2)
g.set_heuristic('F', 0)

result = g.best_first_search('A', 'F')
print("Path found:", result)
