from heapq import *
from collections import *
from tabulate import tabulate
# Round Robin
n = int(input("No. of Tasks: "))
print("Enter arrival time and burst time ")
l = []
pp = []
o = 0
for i in range(n):
    a, b = map(int, input().split())
    pp.append([a, b])
    o = max(o, a)
    heappush(l, [a, b, i])

tq = int(input("Enter time quantum: "))

buffer = deque()
time = start = 0

ans = [0]*n
order = []
while l or buffer:
    while l:
        a, b, i = heappop(l)
        if a > time:
            heappush(l, [a, b, i])
            break
        else:
            buffer.append([a, b, i])
    while buffer:
        aa, b, idx = buffer.popleft()
        if aa > time:
            start = time = aa
        k = min(b, tq)
        b -= k
        time += k
        while l:
            a, bb, i = heappop(l)
            if a > time:
                heappush(l, [a, bb, i])
                break
            else:
                buffer.append([a, bb, i])
        order.append([idx, start, time])
        if b:
            buffer.append([aa, b, idx])
        else:
            ans[idx] = time
        start = time
head = ["AT", "BT", "CT", "TAT", "WT"]
ok = []
for i in range(n):
    ok.append([pp[i][0],
               pp[i][1],
               ans[i],
               ans[i]-pp[i][0],
               ans[i]-pp[i][0]-pp[i][1]
               ])

print(tabulate(ok, headers=head, tablefmt="grid"))
for i, j, k in order:
    print(i, j, k)
