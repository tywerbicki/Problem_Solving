import queue

def Explore_Dungeon(dungeon):

    nrow = len(dungeon) ; ncol = len(dungeon[0])
    visited = [ [False for _ in range(ncol)] for _ in range(nrow) ]
    
    try:
        for i in range(nrow):
            for j in range(ncol):
                if dungeon[i][j] == "S":
                    start = (i, j, 0)
                    raise Exception
    except Exception:
        pass
    
    q = queue.Queue(maxsize = nrow * ncol)
    q.put(start)

    while(not q.empty()):
        
        r, c, d = q.get()
        if (r < 0 or r == nrow) or (c < 0 or c == ncol) : continue
        if (dungeon[r][c] == "#") : continue
        if (visited[r][c]) : continue
        if dungeon[r][c] == "E":
            return d
        else:
            visited[r][c] = True
            q.put((r+1, c, d+1))
            q.put((r-1, c, d+1))
            q.put((r, c+1, d+1))
            q.put((r, c-1, d+1))

    return -1

if __name__ == "__main__":

    dungeon = [
        ['S', ".", ".", "#", ".", ".", "."],
        [".", "#", ".", ".", ".", "#", "."],
        [".", "#", ".", ".", ".", ".", "."],
        [".", ".", "#", "#", ".", ".", "."],
        ["#", ".", "#", "E", ".", "#", "."]
    ]

    shortest_path = Explore_Dungeon(dungeon)

    print(f"Shortest Path: {shortest_path}")