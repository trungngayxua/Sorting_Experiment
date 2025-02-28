def sort_and_time(filename):
    with open(filename, "r") as f:
        lines = f.readlines()

    for line in lines:
        numbers = list(map(int, line.split()))
        numbers.sort()

sort_and_time("input.txt")
