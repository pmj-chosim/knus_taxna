import sys

n=int(input())
data=[]
for i in range(n):
    line=sys.stdin.readline().split()
    line[0]=int(line[0])
    line.append(i)
    data.append(line)
    
data=sorted(data, key=lambda x:(x[0], x[2]))
#입력 받은 순대로 list 정렬되어 있고 x[0]도 
# 입력 받은 순에서 x[0] 차이 값만 정렬이니
# data=sorted(data, key=lambda x:(x[0])) 해도 정답
for i in range(n):
    print(data[i][0], data[i][1])