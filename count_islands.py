def Traverse(map, start, cache, nrow, ncol):

    if (start[0] < 0) or (start[0] == nrow) or (start[1] < 0) or (start[1] == ncol):
        return
    if map[start[0]][start[1]] == "W": return
    if (tuple(start) in cache): 
        return 
    else: 
        cache.add(tuple(start))
    
    moves = [ [start[0] - 1, start[1]],
              [start[0] + 1, start[1]],
              [start[0], start[1] + 1],
              [start[0], start[1] - 1] ]

    for move in moves:
        Traverse(map, move, cache, nrow, ncol)

def Count_Islands(map):

    nrow = len(map) ; ncol = len(map[0])
    cache = set()
    count = 0
    for i in range(nrow):
        for j in range(ncol):
            if map[i][j] == "L":
                if (i, j) not in cache:
                    count += 1
                    Traverse(map, [i, j], cache, nrow, ncol)
    return count

if __name__ == "__main__":

    map = [
        ["W", "L", "W", "W", "L", "W"],
        ["L", "L", "W", "W", "L", "W"],
        ["W", "L", "W", "W", "W", "W"],
        ["W", "W", "W", "L", "L", "W"],
        ["W", "L", "W", "L", "L", "W"],
        ["W", "W", "W", "W", "W", "W"]
    ]

    num_islands = Count_Islands(map)
    print(f"Number of islands: {num_islands}")

    map = [
        ["W", "L", "W", "W", "W"],
        ["W", "L", "W", "W", "W"],
        ["W", "W", "W", "L", "W"], 
        ["W", "W", "L", "L", "W"], 
        ["L", "W", "W", "L", "L"], 
        ["L", "L", "W", "W", "W"]
    ]

    num_islands = Count_Islands(map)
    print(f"Number of islands: {num_islands}")
