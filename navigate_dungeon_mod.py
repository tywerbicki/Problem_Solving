import queue

def Explore_Dungeon(dungeon):

    nrow = len(dungeon) ; ncol = len(dungeon[0])
    previous = [ [None for _ in range(ncol)] for _ in range(nrow) ] 
    
    try:
        for i in range(nrow):
            for j in range(ncol):
                if dungeon[i][j] == "S":
                    start = (i, j)
                    raise Exception
    except Exception:
        pass
    
    q = queue.Queue(maxsize = nrow * ncol)
    q.put(start) ; previous[start[0]][start[1]] = "Start" 

    while(not q.empty()):
        
        r, c = q.get()
        if dungeon[r][c] == "E":
            return Retrace_Steps(previous, (r, c))
        else:
            if (r > 0):
                if (dungeon[r-1][c] != "#") and isinstance(previous[r-1][c], type(None)): 
                    q.put((r-1, c)) ; previous[r-1][c] = (r, c)
            if (r < nrow - 1):
                if (dungeon[r+1][c] != "#") and isinstance(previous[r+1][c], type(None)):
                    q.put((r+1, c)) ; previous[r+1][c] = (r, c)
            if (c > 0):
                if (dungeon[r][c-1] != "#") and isinstance(previous[r][c-1], type(None)):
                    q.put((r, c-1)) ; previous[r][c-1] = (r, c)
            if (c < ncol - 1):
                if (dungeon[r][c+1] != "#") and isinstance(previous[r][c+1], type(None)):
                    q.put((r, c+1)) ; previous[r][c+1] = (r, c)
            
    return [-1]

def Retrace_Steps(previous, end):

    path = [end]
    while (path[0] != "Start"):
        r, c = path[0]
        path.insert(0, previous[r][c])

    return path[1:]

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