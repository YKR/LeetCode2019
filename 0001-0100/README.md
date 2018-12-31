# LeetCode2019 0001-0100

- [X] 0001
花式过题。基本思路是从大到小排序后，两指针分别从nums的头部和尾部开始扫描
i-->          <--j
|                |
0 1 2 3 ... n-2 n-1
如果 nums[i] + nums[j] > target，则++i
如果 nums[i] + nums[j] < target，则--j
如果相等就返回输出。
上一次的做法是构造(nums[i], i)为元素的vector并快速排序
这一次本来想使用lambda表达式排序，但是爆内存了（可能是Lambda表达式的问题？）
于是利用map是平衡树的特点，把(nums[i], i)塞进树里，随机访问时就已经排好序了（不过map是红黑树，时间效率上差一点）
但是map中不能存在相同的键，所以实际上把它的value类型变成了vector。此时可能会有i == j的情况，需要特殊判断一下
- [X] 0002
链表，没什么算法可写。需要注意边界条件，比如前导0
- [X] 0003
基本思路是扫描字符串时记录扫描过的字符的位置。
当访问一个新字符x时，递增当前累积子串ss的长度len；若ss中存在x，则将len变为curr[x] - last[x]。每一步用len更新ans
这一次使用了map记录字符位置，时间效率O(nlogn)。事实上用桶排序思路的话（字符只有256个），可以把logn项缩减掉
- [X] 0004
如果手写归并排序的一步，时间O(m+n)，好处是容易写
最优解思路是：令nums1为nums1、nums2中size较小的那一个，目的是从nums1中取出x个数，nums2中取出half-x个数（half是总数的一半），
使得取出来的数组成了nums1+nums2中小的一半，此时未取出的数自然是nums1+nums2中大的一半，那么根据有序性至多只需要比较四个数的大小即可
此时可以二分x，故时间为O(log(min(m,n)))。坏处是边界条件很头疼
- [X] 0005
一般解法是O(n^2)的，包括上次的暴力枚举对称中心和这次的dp
官方正解里有一个叫[Manacher's Algorithm](https://en.wikipedia.org/wiki/Longest_palindromic_substring)的算法
TODO: 了解并阐述Manacher's Algorithm
- [X] 0006
纯粹的字符串处理题，就偷懒复制了上次的代码了。不过要写得简短有效还是不容易的。