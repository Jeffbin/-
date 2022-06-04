a=[1,3,5,4,2,100,20]
for x in range(0,len(a)):
    for i in range(0,len(a)-x-1):

        if a[i]>a[i+1]:
           a[i],a[i+1]=a[i+1],a[i]

for k in a:
    print(k)
#冒泡排序
#时间复杂度  O(n的二次方)
#空间复杂度  O(1)
#错误原因：没有忘记了后面的已经排序的序列不需要再对比了
