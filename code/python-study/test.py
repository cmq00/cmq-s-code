import time


def fun():
	cnt = 1
	for i in range(1,100000):
		cnt += 1
	return cnt

stime = time.time()
cnt = fun()
etime = time.time()
print(etime - stime)



