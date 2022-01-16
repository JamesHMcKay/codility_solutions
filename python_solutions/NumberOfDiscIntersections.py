def solution(A):
    center_points = list(range(len(A)))
    start = [a - b for a, b in zip(center_points, A)]
    end = [a + b for a, b in zip(center_points, A)]

    open_discs = 0
    
    data = []
    for item in start:
        data.append({"index": item, "type": "start"})

    for item in end:
        data.append({"index": item, "type": "end"})

    def get_index(item):
        return item["index"]

    data.sort(key = get_index)
    n_intersections = 0
    
    for item in data:
        if item["type"] == "start":
            open_discs = open_discs + 1
        if item["type"] == "end":
            open_discs = open_discs - 1
        if item["type"] == "start":
            n_intersections = n_intersections + open_discs - 1
        if n_intersections > 10000000:
            return -1
    return n_intersections