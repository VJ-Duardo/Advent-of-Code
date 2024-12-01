calorie_counts = 0
with open("inventory.txt") as file:
    calorie_counts = [sum(list(map(int, chunk.split("\n")))) for chunk in file.read().split("\n\n")]
    calorie_counts.sort(reverse=True)


def get_highest_calories(n):
    calorie_sum = 0
    for i in range(n):
        calorie_sum += calorie_counts[i]
    return calorie_sum

print(get_highest_calories(1))
print(get_highest_calories(3))
