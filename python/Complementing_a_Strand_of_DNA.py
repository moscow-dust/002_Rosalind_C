import Bio
from Bio.Seq import Seq
from Bio.Alphabet import generic_dna

def replication_DNA(s):
    sequence = Seq(s)
    a=sequence.reverse_complement()
    return a
a = open("y.txt", "r")
s=str(a.read())
a.close()
print(replication_DNA(s))

