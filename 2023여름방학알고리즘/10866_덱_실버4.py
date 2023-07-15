import sys
n = int(input())
data = []
for i in range(n):
    data.append(sys.stdin.readline())

deq = []
for i in range(n):
    line = data[i].split()

    if line[0] == 'push_front':
        deq.insert(0, int(line[1]))
    elif line[0] == 'push_back':
        deq.append(int(line[1]))
    elif line[0] == 'pop_front':
        if len(deq) > 0:
            print(deq.pop(0))
        else:
            print(-1)
    elif line[0] == 'pop_back':
        if len(deq) > 0:
            print(deq.pop())
        else:
            print(-1)
    elif line[0] == 'size':
        print(len(deq))
    elif line[0] == 'empty':
        if len(deq) == 0:
            print(1)
        else:
            print(0)
    elif line[0] == 'front':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])
    elif line[0] == 'back':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[-1])