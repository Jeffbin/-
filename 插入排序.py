a=[1,3,5,4,2,100,20]
for x in range(1,len(a)):
    key=a[x]
    j=x
    while j>0 and key<a[j-1]:
        a[j]=a[j-1]
        j-=1
    a[j]=key

for i in a:
    print(i)
#插入排序
#时间复杂度  o(n的2次方)
#空间复杂度  O（1）
#错误原因:对比了已排序的序列，浪费了时间
