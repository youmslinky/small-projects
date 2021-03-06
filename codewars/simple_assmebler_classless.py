def get_value(s,reg):
    try:
        return int(s)
    except:
        return reg[s]

def simple_assembler(program):
    program = [ s.split() for s in program ]
    reg={} #registers
    pc=0 #program counter
    while pc < len(program):
        currentInstruction = program[pc]
        x = currentInstruction[1]
        if 'mov' == currentInstruction[0]:
            reg[x] = get_value(currentInstruction[2],reg)

        elif 'inc' == currentInstruction[0]:
            reg[x] += 1
        
        elif 'dec' == currentInstruction[0]:
            reg[x] -= 1
        
        elif 'jnz' == currentInstruction[0]:
            y = int(currentInstruction[2])
            x = get_value(currentInstruction[1],reg)
            if x != 0:
                pc += y-1
        pc += 1
    return reg


"""mov x y - copies y (either a constant value or the content of a register) into register x
inc x - increases the content of register x by one
dec x - decreases the content of register x by one
jnz x y - jumps to an instruction y steps away (positive means forward, negative means backward), but only if x (a constant or a register) is not zero
"""

code = '''\
mov a 5
inc a
dec a
dec a
jnz a -1
inc a'''
print(simple_assembler(code.splitlines()))

#print [ s.split() for s in code.splitlines() ]


