def water_jug(x, y, target):
    visited = set()
    stack = [(0, 0)]
    while stack:
        a, b = stack.pop()
        if (a, b) in visited:
            continue
        print((a, b))
        visited.add((a, b))
        if a == target or b == target:
            print("Target reached!")
            return
        stack.extend([
            (x, b),
            (a, y),
            (0, b),
            (a, 0),
            (min(x, a + b), max(0, a + b - x)),
            (max(0, a + b - y), min(y, a + b))
        ])
    print("Target not reachable!")
water_jug(4, 3, 2)