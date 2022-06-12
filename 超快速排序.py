def mersort(arr):
    if(len(arr)<2):
        return arr
    middle=len(arr)//2
    left=arr[:middle]
    right=arr[middle:]
    return merge(mersort(left),mersort(right))
def merge(left, right):
    result=[]
    #global op
    while left and right:#当左列表和右列表同时存在的时候，他两开始比较，result列表存放较小的值
        if left[0]<right[0]:
            result.append(left.pop(0))#pop，弹出列表的数，并且它不会再出现在列表里

        else:
            result.append(right.pop(0))

    while left:#当一个列表的值弹完了以后，把另一个表剩下的值添加上去
        result.append(left.pop(0))
    while right:
        result.append(right.pop(0))

    return result

def counts(n, a=list):

    count1=0
    for i in range(0,n):
        for j in range(i+1,n):
            if a[i]>a[j]:
                count1=count1+1
    return count1










print("输入a的值")
a=int(input())
op=0

b=[]
k=[]

while a!=0 :
    b=[]
    op=0
    for i in range(0,a):
        c=int(input())
        b.append(c)
    op=counts(len(b),b)
    mersort(b)

    k.append(op)
    print("输入a的值")
    a=int(input())
    
for o in range(0,len(k)):
    print(k[o])
