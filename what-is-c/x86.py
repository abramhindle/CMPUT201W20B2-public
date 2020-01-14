# Unrealistic high level x86
# - memory slots instead of actual memory
# - lack of opcodes
# - try changing the value of max in the program

N = 60 # size of memory
registers = {
    "rsp":N-1, #stack pointer
    "rbp":N-1, #base pointer
    "rdi":0,   #destination 
    "rsi":0,   #source
    "rax":0,   # anything and returns
    "rbx":0,   # anything and returns
    "rcx":0,   # anything
    "rdx":0,   # anything
    "rip":0    # instruction pointer (where in the program
}

flags = {
    "zf":False
}

memory = [0 for i in range(N)] # memory

def push(x):
    """ push register x onto the stack """
    memory[registers["rsp"]] = registers[x]
    registers["rsp"] -= 1

def pop(x):
    """ pop from stack to x where x is a register name """
    registers[x] = memory[registers["rsp"]]
    registers["rsp"] += 1

def mov(x,y):
    """ copy from x to y, x can be a register or a number """
    if isinstance(x,str):
        registers[y] = registers[x]
    else:
        registers[y] = x

def add(x,y):
    """ add y to x, store in x, y can be a number """
    if isinstance(y,str):
        registers[x] += registers[y]
    else:
        registers[x] += y

def cmpl(x,y):
    """ Compare x and y set flags["zf"] true if the same """
    if isinstance(x,str) and isinstance(y,str):
        flags["zf"] = registers[y] == registers[x]
    elif isinstance(x,str) and not isinstance(y,str):
        flags["zf"] = y == registers[x]
    elif not isinstance(x,str) and isinstance(y,str):
        flags["zf"] = x == registers[y]
    else:
        raise Exception("Why are we here?")

def jne(x):
    """ jump if not equal, if flags["zf"] is not true jump to x """
    if not flags["zf"]:
        registers["rip"] = x

def je(x):
    """ jump if not equal, if flags["zf"] is not true jump to x """
    if flags["zf"]:
        registers["rip"] = x

def jmp(x):
    """ jump to x """
    registers["rip"] = x


def execute():
    """ execute 1 step of the interpreter """
    instruction = memory[registers["rip"]]
    registers["rip"] += 1 # next instruction
    print("Instruction: %s" % str(instruction))
    if isinstance(instruction,tuple):
        opcode = instruction[0]
        f = opcodes[opcode]
        f(*list(instruction[1:]))
    else:
        raise Exception("End of Program")

def nop():
    """ No op, does nothing """
    None

opcodes = {
    "push":push,
    "pop":pop,
    "mov":mov,
    "add":add,
    "jmp":jmp,
    "cmpl":cmpl,
    "je":je,
    "jne":jne,
    "nop":nop
}
"""
int main() {
    i = 0;
    max = 5;
    while(i != max) {
        i = i + 1;
    }
}
"""
program = [("push","rbp"),("mov","rsp","rbp"), # 0,1: just save state
           ("mov",0,"rax"),                    # 2: i = 0;
           ("mov",5,"rbx"),                    # 3: max = 5;           
           ("cmpl","rax","rbx"),               # 4: compare i and max : while (i != max)
           ("je",9),                           # 5: if i == max jump to instruction at memory address 9
           ("add","rax",1),                    # 6: i = i + 1;
           ("push","rax"),                     # 7: store current value of i on the stack
           ("jmp", 4),                         # 8: jump back to the top of the loop
           ("nop",)]                            # 9: do nothing

# copy program to memory
for i in range(len(program)):
    memory[i] = program[i]

while 1:
    print(memory)
    print(registers)
    execute()
