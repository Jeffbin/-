BFS解题思路：
地图类：
找到一个合适的数组来存储地图，再用一个used表示是否遍历过这个点，设置一个点的结构体
来存储坐标和费用。然后依次遍历所有能走的方法，如果符合条件且没有遍历过这个坐标，则入队；
遍历完方法后把队列的第一个点出队，循环，直到输出结果
非地图类：
找到每步都能怎么走的方法，然后也是用队列的方法遍历，直到输出结果

大坑；
1.输出只含有1和0的数时可以用n*10或n*10+1的方法来
2.一定要用used【】【】来表示点已经遍历过，否则会死循环，爆内存
3.出现大数时要用long long，否则会溢出
4.可以用数学上的方法判读素数

心得体会：
1.选择输出字符串时，设一个二维字符数组，可以给定一个整型数组来选定输出那段字符串
2.在函数里面初始化队列，以免前面的队列没销毁产生错误
3.编译错误时可以使用g++编译器试一下
