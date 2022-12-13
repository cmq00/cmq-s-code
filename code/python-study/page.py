data = set()
fd = open("page.txt")
for line in fd:
    d = line.strip().split('-')
    for i in range(1,len(d) + 1):
        data.add('-'.join(d[:i]))
fd.close()

fd = open("page-more.txt")
for line in fd:
    line = line.strip()
    if not line in data:
        print(line)
fd.close()
