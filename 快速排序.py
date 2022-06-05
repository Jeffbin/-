a=[5,3,1,4,2,100,20]
k=len(a)#数组a的长度
#p=a[k-1]#标定    分出来的每个数组都需要一个标定，可以在下面的函数定义

def quicksort(arr, low, high):

    if low>=high:
        return
    l=low
    h=high
    p = arr[low]  # 基准
    while l<h:
        while l < h and arr[h] >= p:
            h = h - 1
        arr[l] = arr[h]

        while l < h and arr[l] < p:
            l = l + 1
        arr[h] =  arr[l]
    arr[l]=p

    #l，h变化，high,low不变化
    quicksort(arr,low,l-1)
    quicksort(arr,l+1,high)

quicksort(a,0,k-1)
print(a)
#算法概述：挑选元组第一个为基准值，比较元组，比基准大的在右边，比基准小的在左边，依次分为几个小元组以达到分治
#时间复杂度为O（n的二次方）,但看其他方法能变成O（n）
#空间复杂度为O(1)
#前后节点法，但是有错误，不懂错在哪
#错误原因，没有设置递归出口
#错误原因二：开始没有理解算法，交换了arr[h]和arr[l]的值
