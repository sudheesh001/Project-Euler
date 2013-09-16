encountered = set()
n_duplicates = 0
for base in range(2,101):
    n = base
    for exp in range(2,101):
        n *= base
        if n in encountered:
            n_duplicates += 1
        else:
            encountered.add(n)
print ((99*99) - n_duplicates)