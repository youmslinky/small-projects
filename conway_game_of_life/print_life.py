full_block = "█"
light_shade = "░"

def cells2String(cells):
    output = ""
    for row in cells:
        for col in row:
            if(col == 0):
                output += light_shade
            else:
                output += full_block
        output += "\n"
    return output
