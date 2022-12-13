import json

f = open("trip.jsonl")                  
line = f.readline()                  
while line:   
    text = json.loads(line.strip())
    import pdb
    #if text['id'] == 28712:
    #   pdb.set_trace()
    #pdb.set_trace()
    line = f.readline()
    s = text['data'].split('\n')
    list = []
    for id in range(len(text['label'])):
        list.append(text['label'][id][0])
    ff = 1
    cnt = 0
    for id in range(len(s)):
        for ch in s[id]:
            if(cnt in list):
                print(text['id'],end = ' ')
                print(text['data'].split('\n')[0],end = ' ')
                if(s[id][0] == '无'):
                    ff = 3
                for ch in s[id]:
                    if(ch == '\t'):
                        break
                    print(ch,end = '')
                print(end = ' ')
                print(ff)
            cnt += 1
        cnt += 1
f.close()
