def sequence(months, pair):
    if months == 0:
        return 0
    elif months == 1:
        return 1
    else:
        return(sequence((months-1), pair)+(sequence((months-2), pair)*pair))
pair = 3
months = 2
print(sequence(months,pair))


