assignments = []
with open("assignment.txt") as file:
    assignments = [line.split(",") for line in file.read().splitlines()]

    def create_range(interval):
        return list(range(interval[0], interval[1]+1))
    assignments = list(map(lambda sections: tuple(map(lambda section: create_range(list(map(int, section.split("-")))), sections)), assignments))

    
def count_intersecting_pairs():
    cont_count = 0
    inters_count = 0
    for left, right in assignments:
        pair_intersect = list(set(left) & set(right))
        pair_intersect.sort()
        if pair_intersect == left or pair_intersect == right:
            cont_count += 1
        if len(pair_intersect) > 0:
            inters_count += 1
    return (cont_count, inters_count)


containing_count, intersecting_count = count_intersecting_pairs()
print(containing_count)
print(intersecting_count)
