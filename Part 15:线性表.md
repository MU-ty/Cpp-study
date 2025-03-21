我们之前已经研究过很多算法了！比如，二分法可以用来“给定单调函数，求零点”；冒泡排序可以用来“给定一个数组，将其排序后输出”……你已经知道算法很有用，接下来要学习的数据结构，也一样很有用！初学数据结构，您可能会觉得无从下手；不过不用担心，本书会用很多生活中实际存在的例子来解释这些数据结构。
比如，在商场里面排队结账，或者在网上“秒杀”商品，差别很大；但它们都遵循着相同的规则——讲“先来后到”。早来的，就早买到商品；晚来的，就晚买到商品，甚至可能买不到商品。可以利用“先来后到”这一规则，把这两种排队模式统一起来——它们都是“队列”，都可以用队列这一数据结构来模拟。然后建模，编写计算机程序解决这些问题。
这一章，先开始学习线性表。线性表是最简单、最基本的一种数据结构，一个线性表示多个具有相同类型数据“串在一起”，每个元素有前驱（前一个元素）后继（后一个元素）。根据不同的特性，线性表也分为栈、队列、链表等等。因为这些特性，数据结构可以解决不同种类的问题。

# 一、数组
---
## 可变长度数组：头文件<vector>
使用方法：
1）vector<int>v(N,i)  建立一个可变长度数组v，内部元素类型为int，该变量数组最开始有N个元素，每个元素初始化为i。可以省略i，默认值为0，也可以把(N,i)同时省略，此时长度为0，内部元素类型也可以换成其他类型如double。
2）v.size()  返回数组v的长度
3）v.push_back(a) 将元素a插入到数组v的末尾，并增加数组的长度
4）v.resize(n,m) 重新调整数组大小为n，如果n比原来小，则删除多余的信息；如果n比原来大，则新增的部分都初始化为m，其中m可以省略
5）vector<int>::iterator it  定义一个名字叫作it的迭代器
6）v.begin() 返回数组v的首元素（v[0]）的指针（迭代器）
7）v.end()  返回数组v首元素末尾的下一个元素的指针（迭代器），这个指针类似于空指针，不指向任何元素
除了使用数组下标，还能通过“迭代器”来访问数组中的元素。迭代器类似于指针但并不能划等号，这里it可以认为是一个指向vector中元素的指针
it可以++或--变成前一个或后一个元素的指针，也能和指针一样用*it取该指针中的元素
由于迭代器和指针在表现方式上很接近，所以v[i]和 *(v.begin(+i))是一样的，都是取对应元素的值
然而，竞赛中经常只把vector当作普通的可变数组来使用，比较少用到迭代器
---
# 15.1询问学号
## 题目描述
有 $n(n \le 2 \times 10^6)$ 名同学陆陆续续进入教室。我们知道每名同学的学号（在 $1$ 到 $10^9$ 之间），按进教室的顺序给出。上课了，老师想知道第 $i$ 个进入教室的同学的学号是什么（最先进入教室的同学 $i=1$），询问次数不超过 $10^5$ 次。
## 输入格式
第一行 $2$ 个整数 $n$ 和 $m$，表示学生个数和询问次数。
第二行 $n$ 个整数，表示按顺序进入教室的学号。
第三行 $m$ 个整数，表示询问第几个进入教室的同学。
## 输出格式
输出 $m$ 个整数表示答案，用换行隔开。
## 样例 #1
### 样例输入 #1
```
10 3
1 9 2 60 8 17 11 4 5 14
1 5 9
```
### 样例输出 #1
```
1
8
5
```

```cpp
#include<iostream>
#include<vector>
using namespace std;
int n, m, tmp;
int main() {
	vector<int> stu;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		stu.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << stu[tmp - 1] << endl;
	}
	return 0;
}
```

# 15.2 寄包柜
## 题目描述
超市里有 $n(1\le n\le10^5)$ 个寄包柜。每个寄包柜格子数量不一，第 $i$ 个寄包柜有 $a_i(1\le a_i\le10^5)$ 个格子，不过我们并不知道各个 $a_i$ 的值。对于每个寄包柜，格子编号从 1 开始，一直到 $a_i$。现在有 $q(1 \le q\le10^5)$ 次操作：
- `1 i j k`：在第 $i$ 个柜子的第 $j$ 个格子存入物品 $k(0\le k\le 10^9)$。当 $k=0$ 时说明清空该格子。
- `2 i j`：查询第 $i$ 个柜子的第 $j$ 个格子中的物品是什么，保证查询的柜子有存过东西。
已知超市里共计不会超过 $10^7$ 个寄包格子，$a_i$ 是确定然而未知的，但是保证一定不小于该柜子存物品请求的格子编号的最大值。当然也有可能某些寄包柜中一个格子都没有。
## 输入格式
第一行 2 个整数 $n$ 和 $q$，寄包柜个数和询问次数。
接下来 $q$ 个行，每行有若干个整数，表示一次操作。
## 输出格式
对于查询操作时，输出答案，以换行隔开。
## 样例 #1
### 样例输入 #1
```
5 4
1 3 10000 118014
1 1 1 1
2 3 10000
2 1 1
```
### 样例输出 #1
```
118014
1
```

```cpp
#include<iostream>
#include<vector>
using namespace std;
int n, q, opt, i, j, k;
int main() {
	cin >> n >> q;
	vector<vector<int>>locker(n + 1);
	while (q--) {
		cin >> opt;
		if (opt == 1) {
			cin >> i >> j >> k;
			if (locker[i].size() < j + 1)
				locker[i].resize(j + 1);
			locker[i][j] = k;
		}
		else {
			cin >> i >> j;
			cout << locker[i][j] << endl;
		}
	}
	return 0;
}
```

## 数组复杂度是O(1)，但整段移位操作（在中间插入删除数据）或搜索指定元素（如果没有排序），时间复杂度是O(n)。

# 二、栈
## 15.3 洗盘子1
如果a比b早加入，a一定比b后退出，                                                                      
这种数据结构是栈，后进先出LIFO
## 15.4 洗盘子2
1、void push(x) 将x压入栈，对应放餐盘
2、void pop()   弹出栈顶元素，对应取走餐盘
3、int top()    查询栈顶元素，由此知道接下来该洗哪个餐盘

```cpp
int stack[MAXN];
innt p = 0;
void push(int x) {
	if (p >= MAXN) {
		printf("Stack overflow.");
	}
	else {
		stack[p] = x;
		p += 1;
	}
}
void pop() {
	if (p == 0)
		printf("Stack is empty");
	else
		p -= 1;
}

int top() {
	if (p == 0) {
		printf("Stack is empty");
		return -1;
	}
	else
		return stack[p - 1];
}
```
利用上面3个函数可以重新描述洗盘子过程
```
push(1);push(2);push(3);
printf("Wash[%d]\n",top());pop();
printf("Wash[%d]\n",top());pop();
push(4);push(5);
printf("Wash[%d]\n",top());pop();
printf("Wash[%d]\n",top());pop();
printf("Wash[%d]\n",top());pop();
```
----
可以使用STL提供的stack容器
栈的头文件是<stack>，有以下几种方法
1、stack<int>s    建立一个栈s，其内部元素类型是int
2、s.push(a)      将元素a压进栈s
3、s.pop()        将s的栈顶元素弹出
4、s.top()        查询s的栈顶元素
5、s.size()       查询s的元素个数
6、s.empty()      查询s是否为空
----
# 15.5平衡的括号 Parentheses Balance
## 题面翻译
输入一个包含“()”和“[]”的括号序列，判断是否合法。
具体规则：
1. 空串合法；
2. 如果A和B合法，那么AB合法；
3. 如果A合法(A)和[A]都合法
感谢 @陶文祥  提供的翻译。
## 题目描述
[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=614
[PDF](https://uva.onlinejudge.org/external/6/p673.pdf)
![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA673/728efd32dd652b878d710325c5df71cd208a3358.png)
## 输入格式
![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA673/3cc54568c99948acb78df4a79d8f158d490682b2.png)
## 输出格式
![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA673/11abbee807a097f07185a3ad1b6a0383dbcdc0b8.png)
## 样例 #1
### 样例输入 #1
```
3
([])
(([()])))
([()[]()])()
```
### 样例输出 #1
```
Yes
No
Yes
```

```cpp
#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
stack<char>s;
int num;
char trans(char a) {
	if (a == ')')  return '(';
	if (a == ']')return '[';
	if (a == '}')  return '{';
	return '\0';
}
int main() {
	cin >> num;
	string p;
	getline(cin, p);
	while (num--) {
		while (!s.empty())  
			s.pop();
		getline(cin, p);
		for (int i = 0; i < p.size(); ++i) {
			if (s.empty()) {
				s.push(p[i]);
				continue;
			}
			if (trans(p[i]) == s.top())
				s.pop();
			else s.push(p[i]);
		}
		if (s.empty())   printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
```
##遇到一个坑点：使用cin读入一个独占的数字后，其读入的指针在这一行的末尾，如果再使用getline读入一行字符串时，只会读到空串（第一行），如果希望读到第二行，必须假装读入这一行，可以使用getline，也可以使用getchar。

# 15.6后缀表达式
## 题目描述
所谓后缀表达式是指这样的一个表达式：式中不再引用括号，运算符号放在两个运算对象之后，所有计算按运算符号出现的顺序，严格地由左而右新进行（不用考虑运算符的优先级）。
本题中运算符仅包含 $\texttt{+-*/}$。保证对于 $\texttt{/}$ 运算除数不为 0。特别地，其中 $\texttt{/}$ 运算的结果需要**向 0 取整**（即与 C++ `/` 运算的规则一致）。
如：$\texttt{3*(5-2)+7}$ 对应的后缀表达式为：$\texttt{3.5.2.-*7.+@}$。在该式中，`@` 为表达式的结束符号。`.` 为操作数的结束符号。
## 输入格式
输入一行一个字符串 $s$，表示后缀表达式。
## 输出格式
输出一个整数，表示表达式的值。
## 样例 #1
### 样例输入 #1
```
3.5.2.-*7.+@
```
### 样例输出 #1
```
16
```
## 样例 #
### 样例输入 #2
```
10.28.30./*7.-@
```
### 样例输出 #2
```
-7
```
## 提示
数据保证，$1 \leq |s| \leq 50$，答案和计算过程中的每一个值的绝对值不超过 $10^9$。

```cpp
#include<stack>
#include<cstdio>
using namespace std;
stack<int>n;
int s = 0, x, y;
int main() {
	char ch;
	do {
		ch = getchar();
		if (ch >= '0' && ch <= '9')
			s = s * 10 + ch - '0';
		else if (ch == '.')
			n.push(s), s = 0;
		else if (ch != '@') {
			x = n.top();
			n.pop();
			y = n.top();
			n.pop();
			switch (ch) {
			case'+':n.push(x + y); break;
			case'-':n.push(y-x); break;
			case'*':n.push(x * y); break;
			case'/':n.push(y/x); break;
			}
		}
	} while (ch != '@');
	printf("%d\n", n.top());
	return 0;
}
```

# 判断一个程序能否用栈来模拟，看是否满足后进先出或先进后出

## 三、队列
## 15.7超市排队1
如果a比b先排入队伍，那么a比b先结账，队列是先进先出的线性表
## 15.8超市排队2
1、void push(x)     将x压入队列，一个人排队站在队尾
2、void pop()       弹出队首的元素，排在最前面的人结完了账，离开队列
3、int front()      查询队首的元素，这样可以知道现在该谁结账
```cpp
int queue[MAXN];
int head = 0;
int tail = 0;
void push(int x) {
	if (tail >= MAXN)
		printf("Queue overflow.");
	else {
		queue[tail] = x; 
		taill += 1;
	}
}

void pop() {
	if (head == tail)
		printf("Queue is empty");
	else
		head += 1;
}

int front() {
	if (head == tail) {
		printf("queue is empty");
		return -1;
	}
	else {
		return queue[head];
	}
}
```
考虑到如果队列数组的实现和现实中的收银台一样，每次查询数组的第一个元素，退出队列时队列中的所有元素往前移动一格，那么运行效率是非常低的，可以让队伍本身保持静止，而收银员却从前往后移动，每次服务一个人后向后走，就会避免整体移动
### 栈vs队列
栈只有一个出入口；队列是后端入，前端出.需要两个指针
依靠3个函数，使用代码来描述收银的过程
```cpp
push(1); push(2); push(3);
printf("Serve customer:[%d]\n", front()); pop();
printf("Serve customer:[%d]\n", front()); pop();
push(4); push(5);
printf("Serve customer:[%d]\n", front()); pop();
printf("Serve customer:[%d]\n", front()); pop();
printf("Serve customer:[%d]\n", front()); pop();
```
## 和栈一样，同样可以使用STL来操作，头文件<queue>，有以下几种方法
1、queue<int>q   建立一个队列q，其内部元素类型是int。
2、q.push(a)     将元素a插入到队列q的末尾
3、q.pop()       删除队列q的队首元素
4、q.front()     查询q的队首元素
5、q.back()      查询q的队尾元素
6、q.size()      查询q的元素个数
7、q.empty()     查询q是否为空

# 15.9约瑟夫问题
## 题目描述
$n$ 个人围成一圈，从第一个人开始报数,数到 $m$ 的人出列，再由下一个人重新从 $1$ 开始报数，数到 $m$ 的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。
**注意：本题和《深入浅出-基础篇》上例题的表述稍有不同。书上表述是给出淘汰 $n-1$ 名小朋友，而该题是全部出圈。**
## 输入格式
输入两个整数 $n,m$。
## 输出格式
输出一行 $n$ 个整数，按顺序输出每个出圈人的编号。
## 样例 #1
### 样例输入 #1
```
10 3
```
### 样例输出 #1
```
3 6 9 2 7 1 8 5 10 4
```
## 提示
$1 \le m, n \le 100$

```cpp
#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int n, k;
void work() {
    // 初始化队列，将所有人的编号 1 到 n 放入队列
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    // 当队列中还有多于一个人时，继续操作
    while (!q.empty()) {
        // 将队列前 k-1 个元素移动到队列末尾
        for (int i = 1; i < k; i++) {
            q.push(q.front());  // 把队列最前面的元素移到队列的末尾
            q.pop();  // 移除队列最前面的元素
        }

        // 输出当前队列的第一个元素（即第 k 个出列的人）
        printf("%d", q.front());
        q.pop();  // 出列

        // 如果队列不为空，则输出空格（不是最后一个出列的人）
        if (!q.empty()) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);  // 读取 n 和 k
    work();  // 调用函数处理
    return 0;
}
```
## 如果数据有先进先出性质，那么可以考虑使用队列；队列常常使用在各类广度优先搜索算法上

# 四、链表
## 15.10排队记录
n名同学在排队进入洛谷大厦，然后解散自由活动，现在希望知道当初排队的顺序，然而并没有记录队伍是怎样排的。但好消息是，已经知道编号是1排在最前面，除此之外，每个人都知道自己后面是谁。如何利用这些消息，还原出那天晚上的排队顺序？

假设这些同学的编号从1到4，他们记得站在后面的同学分别是4、3、0、2（0说明后面没人）。能推算出原来他们排队1的顺序是什么吗？可以用Next[x]来表示x这个用户后面排的是谁。特殊地，Next[x]=0表示后面没人了，那么很容易写出代码：
```
for(int i=1;i!=00;i=Next[x])
    printf("%d ",i);
```
时间复杂度为O(n),启示：如果知道每个元素之前/之后是谁，就可以恢复整个表的排列顺序。
利用这种方式，来存储元素排列顺序的表，称为链表。
接下来，考虑另一个问题，本来n个同学在好好排队，但来了一个不守规矩的同学（5号），插队到4号后面，而其余的同学顺序不变，插队后，队伍是什么样？
暴力方法：使用数组记录排队顺序；发生插队，把插队者放到对应的位置，其余元素向后移一位。若m人插队，总复杂度将达到O(mn)。
更快的方法，如果已经知道每个元素之后是谁，就可以恢复整个表的排列顺序。如果用这个思路来完成这个问题？还是以Next[x]来表示x后面是谁。
那么一个插队行为“y插到了x的后面”，就是x后面变成了y；y后面变成了原来在x后面的人。代码如下：
```
void insert(int x,int y){
	Next[y]=Next[x];
	Next[x]=y;
}
```
这时，有另外一名同学（2号）等不及了，退出队伍，如何实现?
```

void remove(int x){
	Next[x]=Next[Next[x]];
}
```
这里必须知道x的前一名同学是谁才能删除x

## 虽说每个结点可以找到自己相邻结点的表就是链表，不过链表有很多种。下面列举一些
1、单链表：每个结点记录自己的后继
2、双链表：每个结点记录自己的前驱和后继，可以向前向后走
3、循环单链表：本身是一个单链表，但最后一个结点的后继为第一个结点，从而连成了环型结构
4、循环双链表：本身是一个双链表，连成环状
5、块状链表：将若干个元素压缩成一块，将这些块串联起来
6、跳表：相当于平衡树，每个结点都拥有自己的右指针和下指针，通过分层的方式来加速查询，而每个元素的层数有概率决定

## 15.11 排队模拟
实现一个数据结构，维护一张表（最初只有一个元素1）。需要支持下面的操作，其中x和y都是int范围内的正整数，，且都不一样，操作数量不多于2000.
1、ins_back(x,y)  将元素y插入到x后面
2、ins_front(x,y) 将元素y插入到x前面
3、ask_back(x)    询问x后面的元素
4、ask_front(x)   询问x前面的元素
5、del(x)         从表中删除元素x，不改变其他的先后顺序
显然，双向链表
```cpp
struct node {
    int pre, nxt;
    int key;
    node(int _key=0,int _pre=0,int _nxt=0)
    {
        pre = _pre; nxt = _nxt; key = _key;
    }
};

node s[1005];
int tot = 0;

int find(int x) {
    int now = 1;
    while (now && s[now].key != x)
        now = s[now].nxt;
    return now;
}

void ins_back(int x, int y) {
    int now = find(x);
    s[++tot] = node(y, now, s[now].nxt);
    s[s[now].nxt].pre = tot;
    s[now].nxt = tot;
}

void ins_front(int x, int y) {
    int now = find(x);
    s[++tot] = node(y, s[now].pre, now);
    s[s[now].pre].nxt = tot;
    s[now].pre = tot;
}

int ask_back(int x) {
    int now = find(x);
    return s[s[now].pre].key;
}

int ask_front(int x) {
    int now = find(x);
    return s[s[now].pre].key;
}

void del(int x) {
    int now = find(x);
    int le = s[now].pre, rt = s[now].nxt;
    s[le].nxt = rt;
    s[rt].pre = le;

}
```
上面代码实现了链表的各项功能，但效率较低。因为每次操作都会调用find函数以查找x所在的结点编号，这个过程的时间复杂度是O(n)，但也有改进方法，创教一个数组，用于存放每个数字对应的结点编号来代替find函数，如果数字范围非常大，可以使用Hash算法或map容器来记录结点编号。

# 15.12队列安排
## 题目描述
一个学校里老师要将班上 $N$ 个同学排成一列，同学被编号为 $1\sim N$，他采取如下的方法：
1. 先将 $1$ 号同学安排进队列，这时队列中只有他一个人；
2. $2\sim N$ 号同学依次入列，编号为 $i$ 的同学入列方式为：老师指定编号为 $i$ 的同学站在编号为 $1\sim(i-1)$ 中某位同学（即之前已经入列的同学）的左边或右边；
3. 从队列中去掉 $M$ 个同学，其他同学位置顺序不变。
在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。
## 输入格式
第一行一个整数 $N$，表示了有 $N$ 个同学。
第 $2\sim N$ 行，第 $i$ 行包含两个整数 $k,p$，其中 $k$ 为小于 $i$ 的正整数，$p$ 为 $0$ 或者 $1$。若 $p$ 为 $0$，则表示将 $i$ 号同学插入到 $k$ 号同学的左边，$p$ 为 $1$ 则表示插入到右边。
第 $N+1$ 行为一个整数 $M$，表示去掉的同学数目。
接下来 $M$ 行，每行一个正整数 $x$，表示将 $x$ 号同学从队列中移去，如果 $x$ 号同学已经不在队列中则忽略这一条指令。
## 输出格式
一行，包含最多 $N$ 个空格隔开的整数，表示了队列从左到右所有同学的编号。
## 样例 #1
### 样例输入 #1
```
4
1 0
2 1
1 0
2
3
3
```
### 样例输出 #1
```
2 4 1
```
## 提示
**【样例解释】**
将同学 $2$ 插入至同学 $1$ 左边，此时队列为：
`2 1`
将同学 $3$ 插入至同学 $2$ 右边，此时队列为：
`2 3 1`  
将同学 $4$ 插入至同学 $1$ 左边，此时队列为：
`2 3 4 1`  
将同学 $3$ 从队列中移出，此时队列为：
`2 4 1`  
同学 $3$ 已经不在队列中，忽略最后一条指令
最终队列：
`2 4 1`  
**【数据范围】**
对于 $20\%$ 的数据，$1\leq N\leq 10$。
对于 $40\%$ 的数据，$1\leq N\leq 1000$。
对于 $100\%$ 的数据，$1<M\leq N\leq 10^5$。

```cpp
#include<iostream>
using namespace std;

struct node {
    int pre, nxt, key;
    node(int _key=0,int _pre=0,int _nxt=0)
    {
        pre = _pre; nxt = _nxt; key = _key;
    }
};

node s[100005];
int n, m, tot = 0, index[100005] = { 0 };

void ins_back(int x, int y) {
    int now = index[x];
    s[++tot] = node(y, now, s[now].nxt);
    s[s[now].nxt].pre = tot;
    s[now].nxt = tot;
    index[y] = tot;
}

void ins_front(int x, int y) {
    int now = index[x];
    s[++tot] = node(y, s[now].pre, now);
    s[s[now].pre].nxt = tot;
    s[now].pre = tot;
    index[y] = tot;
}

void del(int x) {
    int now = index[x];
    int le = s[now].pre, rt = s[now].nxt;
    s[le].nxt = rt;
    s[rt].pre = le;
    index[x] = 0;
}

int main() {
    int x, k, p, now;
    cin >> n;
    s[0] = node();
    ins_back(0, 1);
    for (int i = 2; i <= n; i++) {
        cin >> k >> p;
        p ? ins_back(k, i) : ins_front(k, i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (index[x])   del(x);
    }
    now = s[0].nxt;
    while (now) {
        cout << s[now].key << ' ';
        now = s[now].nxt;
    }
    return 0;
}
```
其实删除操作不是必要的，考虑到最后输出的过程，相当于同学们从左到右报出自己的编号，其实可以不执行删除操作，而是让这些“被删除”的人闭嘴（建立一个shutup数组，数组用于记录学生是否闭嘴），假装他们不存在。

# 15.13 约瑟夫问题
## 题目描述
$n$ 个人围成一圈，从第一个人开始报数,数到 $m$ 的人出列，再由下一个人重新从 $1$ 开始报数，数到 $m$ 的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。
**注意：本题和《深入浅出-基础篇》上例题的表述稍有不同。书上表述是给出淘汰 $n-1$ 名小朋友，而该题是全部出圈。**
## 输入格式
输入两个整数 $n,m$。
## 输出格式
输出一行 $n$ 个整数，按顺序输出每个出圈人的编号。
## 输入输出样例 #1
### 输入 #1
```
10 3
```
### 输出 #1
```
3 6 9 2 7 1 8 5 10 4
```
## 说明/提示
$1 \le m, n \le 100$

除了使用队列，也可以使用链表
----
## 使用STL来简化操作，头文件list 
1、list<int>a;   定义一个int类型链表a
2、int arr[5]={1,2,3};list<int>a(arr,arr+3);   从数组arr中的前三个元素作为链表a的初始值
3、a.size()    返回链表结点数量
4、list<int>::iterator it;    定义一个名为it的迭代器（指针）
5、a.begin();a.end();         链表开始和末尾的迭代器指针
6、it++;it--;                 迭代器指向前一个和后一个元素
7、a.push_front(x);a.push_back(x);   在链表开头或结尾插入元素x
8、a.insert(it,x)             在迭代器it前面插入元素x
9、a.pop_front();a.pop_back();  在删除链表开头或者末尾
10、a.erase(it)               删除迭代器it所在的元素
11、for(it=a.begin(0;it!=a.end();it++)    遍历链表
----

```cpp
#include<iostream>
#include<list>
using namespace std;
list<int>a;
int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    list<int>::iterator it, now;
    it = a.begin();
    while (!a.empty()) {
        cnt++;
        now = it;
        if (++it == a.end())
            it = a.begin();
        if (cnt == m) {
            cout << *now << ' ';
            a.erase(now);
            cnt = 0;
        }
    }
    return 0;
}
```
注意：遍历时如果要删除元素，一定要备份出来一个迭代器；否则，it原来指向的结点删除后就不复存在了，导致下一个结点时会访问无效内存。

# END
