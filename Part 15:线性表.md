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


