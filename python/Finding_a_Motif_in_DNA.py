def ft_substring(s, ss):
    i=0
    list_of_index = []
    while(i<len(s) and s.find(ss,i)!=-1):
        index = s.find(ss,i)
        list_of_index.append(index+1)
        i=i+1
    return list_of_index
s= "CAACGGTCAACGGTCAACGGTACGCAACGGTGGCAACGGTCAACGGTGGT"
ss = "CAACGGTCA"
without_dublicates = set(ft_substring(s,ss))
ls = list(without_dublicates)
ls.sort()
print(ls)
