t=int(input())
for i in range(0,t,1):
    result=1
    a,b=input().split()
    a=int(a)
    b=int(b)
    for j in range(0,a,1):
        result *= b-j
        result /= a-j
    print(int(result+0.5))
