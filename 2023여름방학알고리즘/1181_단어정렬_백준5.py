import sys

n=int(input())
word=[]
for i in range(n):
    word.append(sys.stdin.readline())

word=list(set(word))

word=sorted(word, key=lambda x: (len(x),x))

print(''.join(word))
