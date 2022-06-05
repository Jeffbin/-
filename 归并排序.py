a=[1,3,5,4,2,100,20]
k=len(a)-1
def merge(a,b):
    c=[]
    h=j=0
    while j<len(a) and h<len(b):
        if a[j]<b[h]:
            c.append(a[j])
            j+=1
        else:
            c.append(b[h])
            h+=1
    if j == len(a):
        for i in b[h:]:
            c.append(i)
    else:
        for i in a[j:]:
            c.append(i)
    return c




def mergesort(arr,low,high):
    if len(arr)<=1:
        return arr
    l=low
    h=high
    mid=(l+h)//2

    if l==mid:
        b=arr[l]
        d=arr[mid+1]
    else:
        b=arr[l:mid+1]
        d=arr[mid+1:h+1]

    larr=mergesort(b,l,mid)
    harr=mergesort(d,mid+1,h)
    merge(larr,harr)



mergesort(a,0,k)
print(a)
#算法概述：把元组一直分成两份，直到不可再分，然后递归排序
#时间复杂度：O(nlogn)
#空间复杂度：O(n)
#错误原因：无法递归出来   未解决
