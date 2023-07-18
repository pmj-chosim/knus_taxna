import sys
line=[]
n=int(input())
for i in range(n):
    line.append(sys.stdin.readline())

for l in line:
    stack=[]
    finish=1
    for w in l:
        if w=='(':
            stack.append(0)
        elif w==')':
            if len(stack)>0:
                stack.pop()
            else:
                finish=0
                break
    if finish==1 and len(stack)==0:
        print("YES")
    else: print("NO")
