"""mov x y - copies y (either a constant value or the content of a register) into register x
inc x - increases the content of register x by one
dec x - decreases the content of register x by one
jnz x y - jumps to an instruction y steps away (positive means forward, negative means backward), but only if x (a constant or a register) is not zero
"""

class machine():
	def __init__(self):
		self.reg={} #registers
		self.pc=0 #program counter

	def mov(self,x,y):
		if y.isdigit():
			self.reg[x] = y
		else:
			self.reg[x] = self.reg[y]

	def inc(self,x):
		self.reg[x] += 1
		
	def dec(self,x):
		self.reg[x] -= 1
		
	def jnz(self,x,y):
		if not y.isdigit():
			x = self.reg[x]
		if x != 0:
			self.pc += y-1

def simple_assembler(program):
	program = [ s.split() for s in program ]
	current = machine()
	while current.pc < len(program):
		print(program[current.pc][0])
		current.program[current.pc][0] #execute instruction
		current.pc += 1
		print(current.pc,current.reg)
	return current.reg


code = '''\
mov a 5
inc a
dec a
dec a
jnz a -1
inc a'''
print(simple_assembler(code.splitlines()))

#print [ s.split() for s in code.splitlines() ]


