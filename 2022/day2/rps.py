mapping = {'A': 1,
           'B': 2,
           'C': 3,
           'X': 1,
           'Y': 2,
           'Z': 3}
results = [0, 3, 6]
result_matrix = [[3, 6, 0],
                 [0, 3, 6],
                 [6, 0, 3]]
moves = []
with open("strategy.txt") as file:
    moves = [[mapping[line[0]], mapping[line[-1]]] for line in file.read().splitlines()]

def get_best_score():
    points = 0
    for (j, k) in moves:
        points += (k + result_matrix[j-1][k-1])
    return points

def get_planned_ends_score():
    for i, (j, k) in enumerate(moves):
        moves[i][1] = result_matrix[j-1].index(results[k-1])+1
    return get_best_score()

print(get_best_score())
print(get_planned_ends_score())
    
    
