import sys

n, m= map(int, input().split())
list=list(map(int, input().split()))
list.sort()
inf=0
for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            mege=list[i]+list[j]+list[k]
            if mege>=inf and mege<=m:
                inf=mege
            elif mege>m:
                break
print(inf)