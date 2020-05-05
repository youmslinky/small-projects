def get_generation(cells, generation):
    width_height = get_width_height(cells)
    width = width_height[0]
    height = width_height[1]
    last = cells
    current = [[0 for j in range(0, width)] for i in range(0,height)]
    for gen in range(generation):
        print(f'gen {gen}')
        counts = neighbor_counts(last)
        for row in range(height):
            for col in range(width):
                current[row][col] = get_next_state(last[row][col],
                                                 counts[row][col])
        last = current
    return current

def wrap_index(i,size):
    return i % size

def neighbor_counts(cells):
    width_height = get_width_height(cells)
    width = width_height[0]
    height = width_height[1]
    cell_counts = [[0 for j in range(0, width)] for i in range(0,height)]
    for row in range(height):
        for col in range(width):
            # print(f'checking {row},{col}')
            n_count = 0 #neighbor count
            for i in range(-1,2):
                for j in range(-1,2):
                    neighbor_row = wrap_index(row+i,height)
                    neighbor_col = wrap_index(col+j,width)
                    # print(f'{neighbor_row},{neighbor_col} has {cells[neighbor_row][neighbor_col]}')
                    if cells[neighbor_row][neighbor_col] == 1:
                        n_count += 1
            n_count -= cells[row][col] #subtract center cell
            cell_counts[row][col] = n_count
            # print(f'n_count: {n_count}')
            # print()
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
