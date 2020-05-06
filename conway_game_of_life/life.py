def get_generation(cells, generation,wrap=True):
    width_height = get_width_height(cells)
    width = width_height[0]
    height = width_height[1]
    last = cells
    current = [[0 for j in range(0, width)] for i in range(0,height)]
    for gen in range(generation):
        counts = neighbor_counts(last,wrap=wrap)
        for row in range(height):
            for col in range(width):
                current[row][col] = get_next_state(last[row][col],
                                                 counts[row][col])
        last = current
    return current

def wrap_index(i,size):
    return i % size

def neighbor_counts(cells,wrap=True):
    width_height = get_width_height(cells)
    width = width_height[0]
    height = width_height[1]
    cell_counts = [[0 for j in range(0, width)] for i in range(0,height)]
    for row in range(height):
        for col in range(width):
            n_count = 0 #neighbor count
            for i in range(-1,2):
                for j in range(-1,2):
                    neighbor_row = row+i
                    neighbor_col = col+j
                    if wrap:
                        neighbor_row = wrap_index(neighbor_row,height)
                        neighbor_col = wrap_index(neighbor_col,width)
                        if cells[neighbor_row][neighbor_col] == 1:
                            n_count += 1
                    else:
                        if neighbor_row < 0 or neighbor_row >= height or neighbor_col < 0 or neighbor_col >= width:
                            pass
                        elif cells[neighbor_row][neighbor_col] == 1:
                            n_count += 1
            n_count -= cells[row][col] #subtract center cell
            cell_counts[row][col] = n_count
    return cell_counts

def get_width_height(cells):
    if(len(cells) == 0):
        return (0,0)
    try:
        width = len(cells[0])
        height = len(cells)
    except:
        height = 1
        width = len(cells)
    return (width,height)

def get_next_state(state,n):
    if(state == 1 and (n == 2 or n == 3)):
        return 1
    elif(state == 0 and n == 3):
        return 1
    else:
        return 0
