import re
pattern = r'^>\w+'
dna = []
sequences = []
result=[]
with open('y.txt') as f:
        seq0 = ''
        for line in f:
            nameOfSequence = re.search(pattern, line)
            if line == '':
                sequences.append(seq0)
            if nameOfSequence:
               name =  line.rstrip("\n")
               dna.append(line)
               sequences.append(seq0)
               seq0 = ''
            else:
                seq = line.replace('\n', '')
                seq0=seq0+seq
del sequences[0]
for i in range (len(sequences)):
    g=sequences[i].count("G")
    c=sequences[i].count("C")
    res ="%.6f"%( ((g+c)/len(sequences[i]))*100)
    result.append(res)
max_element = result[0]
for j in range(len(result)):
    if result[j] > max_element:
            max_element = result[j]
            maxIndex = j
print(result[maxIndex])
print(dna[maxIndex])





