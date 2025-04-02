# -*- coding: utf-8 -*-

n = int(input())
m = int(input())

cmp="I"   #IOIOI...

for i in range(n):
    cmp +="OI"
    
s = input()     #탐색할 문자열

cnt = 0

for i in range(m-n):
    if (s[i]=="O"):
        continue
    
    elif (cmp == s[i:i+2*n+1]):
        cnt += 1
        
print(cnt)