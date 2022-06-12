def sort(b=list):
    op=0
    for x in range(0,len(b)):
        for y in range(0,len(b)-x-1):
            if b[y]>b[y+1]:
                b[y],b[y+1]=b[y+1],b[y]
                op=op+1
    return op



print("输入a的值")
a=int(input())

b=[]
k=[]

while a!=0:
    b=[]
    for i in range(0,a):
        c=int(input())
        b.append(c)
    k.append(sort(b))
    print("输入a的值")
    a=int(input())
for o in range(0,len(k)):
    print(k[o])