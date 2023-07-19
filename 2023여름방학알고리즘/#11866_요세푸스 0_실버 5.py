import sys
n,k=map(int,input().split())
list=[x for x in range(1,n+1)]
new=[]
index=0

while len(list)>1:
    index=(index+k-1)%len(list)
    new.append(list.pop(index))
new.append(list.pop())

print("<", end="")
for i in range(n):
    if i==n-1:
        print(str(new[i])+">")
        break
    print(str(new[i])+", ", end="")