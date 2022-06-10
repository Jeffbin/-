# a=[1,3,5,4,2,100,20]
# k=len(a)-1
# def merge(a,b):
#     c=[]
#     h=j=0
#     while j<len(a) and h<len(b):
#         if a[j]<b[h]:
#             c.append(a[j])
#             j+=1
#         else:
#             c.append(b[h])
#             h+=1
#     if j == len(a):
#         for i in b[h:]:
#             c.append(i)
#     else:
#         for i in a[j:]:
#             c.append(i)
#     return c
#
#
#
#
# def mergesort(arr,low,high):
#     if len(arr)<=1:
#         return arr
#     l=low
#     h=high
#     mid=(l+h)//2
#
#     if l==mid:
#         b=arr[l]
#         d=arr[mid+1]
#     else:
#         b=arr[l:mid+1]
#         d=arr[mid+1:h+1]
#
#     larr=mergesort(b,l,mid-1)
#     harr=mergesort(d,mid+1,h)
#     merge(larr,harr)
#
#
#
# mergesort(a,0,k)
# print(a)
# #算法概述：把元组一直分成两份，直到不可再分，然后递归排序
# #时间复杂度：O(nlogn)
# #空间复杂度：O(n)
# #错误原因：无法递归出来   未解决




#修改
def mersort(arr):
    if(len(arr)<2):
        return arr
    middle=len(arr)//2
    left=arr[:middle]
    right=arr[middle:]
    return merge(mersort(left),mersort(right))
def merge(left,right):
    result=[]
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
a=[1,3,5,4,2,100,20]
k=mersort(a)
print(k)
# #算法概述：把元组一直分成两份，直到不可再分，然后递归排序
# #时间复杂度：O(nlogn)
#合并每一层的时间复杂度为n,一共有log2N层
# #空间复杂度：O(n)
#使用了一个大小为N的列表存放结果
