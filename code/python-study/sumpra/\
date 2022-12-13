import math
n = input()
n = int(n)
a = n // 2
dict = {}
dict[0] = 0
dict[1] = 1
dict[2] = 2
dict[3] = 2

for i in range(4,1004):
    dict[i] = 0

for i in range(4,n + 1):    
    #print(i)
    for j in range(i // 2 + 1):
        #print(j)
        dict[i] = dict[i] + dict[j]
    dict[i] = dict[i] + 1

print(dict[n])
