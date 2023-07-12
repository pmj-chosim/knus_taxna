import sys
n=int(input())
data=[]
command=[]
for i in range(n):
    line=sys.stdin.readline()
    command.append(line)

for i in command:
    before=i.split()
    cmd=before[0]
    if cmd=='push':
        data.append(before[1])
    elif cmd=='pop':
        if len(data)==0:
            print(-1)
        else:
            print(data.pop(0))
    elif cmd=='size':
        print(len(data))
    elif cmd=='empty':
        if len(data)==0:
            print(1)
        else :
            print(0)
    elif cmd=='front':
        if len(data)>0: 
            print(data[0])
        else:
            print(-1)
    elif cmd=='back':
        if len(data)>0: 
            print(data[-1])
        else:
            print(-1)

    elif cmd=='empty':
        if len(data)==0:
            print(1)
        else:
            print(0)