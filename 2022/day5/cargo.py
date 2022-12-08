import re

stacks = []
instructions = []
with open("stacks.txt") as file:
    stack_part, instructions_part = file.read().split("\n\n")
    stack_lines = stack_part.split("\n")
    stacks = [[] for i in range(stack_lines[-2].count(" ")+1)]
    for i in range(len(stack_lines)-2, 0-1, -1):
        for c, j in enumerate(range(1, len(stack_lines[i]), 4)):
            if stack_lines[i][j] != " ":
                stacks[c].append(stack_lines[i][j])
    instructions = [list(map(int, re.findall("\d+", line))) for line in instructions_part.split("\n")]

def get_tops_after_instructions_9000():
    for amount, of, to in instructions:
        for i in range(amount):
            stacks[to-1].append(stacks[of-1].pop())
    return ''.join([stack[-1] for stack in stacks])

def get_tops_after_instructions_9001():
    for amount, of, to in instructions:
        stacks[to-1] += (stacks[of-1][-amount:])
        stacks[of-1] = stacks[of-1][:-amount]
    return ''.join([stack[-1] for stack in stacks])


#print(get_tops_after_instructions_9000())
print(get_tops_after_instructions_9001())
        
