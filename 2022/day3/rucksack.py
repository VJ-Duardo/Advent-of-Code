rucksacks = []
groups = []
with open("items.txt") as file:
    lines = file.read().splitlines()
    rucksacks = [(set(line[:len(line)//2]), set(line[len(line)//2:])) for line in lines]
    for i in range(0, len(lines), 3):
        groups += [(set(lines[i]), set(lines[i+1]), set(lines[i+2]))]

def get_duplicate(container):
    for item in container:
        duplicate = item[0].intersection(*item[1:]).pop()
        yield ord(duplicate) - 96 if duplicate.islower() else ord(duplicate) - 38

def get_duplicate_item_priorities():
    return sum(get_duplicate(rucksacks))

def get_group_item_priorities():
    return sum(get_duplicate(groups))

print(get_duplicate_item_priorities())
print(get_group_item_priorities())
