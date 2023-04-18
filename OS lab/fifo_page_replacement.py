# Atharv Patil 112116007
from collections import *
s = int(input("Enter the frame size: "))
print("Enter pages")
a = list(map(int, input().split()))
q = deque(["#"]*s)
faults = 0
for i in a:
    k = faults
    if i in q:
        pass
    else:
        q.append(i)
        if len(q) > s:
            q.popleft()
        faults += 1
    print(*q, end=" ")
    if k != faults:
        print("Page fault")
    else:
        print()
print("Total no. of page faults:", faults)
