def count_nucleotids(s):
    result = s.replace('T', 'U')
    return result
s = open("y.txt", "r")
a=str(s.read())
s.close()
print(count_nucleotids(a))
