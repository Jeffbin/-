def mersort(arr):
    if(len(arr)<2):
        return arr
    middle=len(arr)//2
    left=arr[:middle]
    right=arr[middle:]
    return merge_ordered_list(mersort(left),mersort(right))

# def merge(left, right):
#     result=[]
#     #global op
#     while left and right:#当左列表和右列表同时存在的时候，他两开始比较，result列表存放较小的值
#         if left[0]<right[0]:
#             result.append(left.pop(0))#pop，弹出列表的数，并且它不会再出现在列表里
#
#         else:
#             result.append(right.pop(0))
#
#     while left:#当一个列表的值弹完了以后，把另一个表剩下的值添加上去
#         result.append(left.pop(0))
#     while right:
#         result.append(right.pop(0))
#
#     return result
# #





def merge_ordered_list(left, right):
    global inversion_count
    res = [0]*(len(left)+len(right))
    lc = rc = 0
    i=0
    while lc < len(left) and rc < len(right):
        if left[lc] <= right[rc]:
            res[i]=left[lc]
            lc += 1
            i=i+1
        else:
            res[i]=right[rc]
            rc += 1
            i=i+1
            # 统计逆序对个数
            inversion_count += len(left[lc:])
    for i in range(i,len(left)+len(right)):
        if lc<len(left):
            res[i]=left[lc]
            lc=lc+1
        if rc<len(right):
            res[i]=right[rc]
            rc=rc+1
    return res


while 1:
    inversion_count=0
    n = int(input())
    arr = [None]*n
    if n == 0:
        break
    for i in range(n):
        arr[i]=int(input())
    mersort(arr)
    print(inversion_count)

#
# import time
# start=time.time()
#
# print("输入a的值")
# a=int(input())
# op=0
#
# b=[]
# k=[]
#
# while a!=0 :
#     b=[]
#     inversion_count = 0
#     for i in range(0,a):
#         c=int(input())
#         b.append(c)
#     #op=counts(len(b),b)
#     mersort(b)
#
#     k.append(inversion_count)
#     print("输入a的值")
#     a=int(input())
#
# for o in range(0,len(k)):
#     print(k[o])
# end=time.time()
# print(end)
