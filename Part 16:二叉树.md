我们之前介绍了线性表这一类数据结构，并且学习了如何使用线性表解决一类特定的问题（数据具有明显的前后关系，可以进行线性连接）。本章将介绍一类新的数据结构——二叉树。
看看窗外的橡树吧。一般来说，树有一个粗壮的树干，再往上面树干就会分成两叉或者多叉，接着树枝会继续一直分下去，一直分到末端的叶子为止（不过也有可能是花或者果子）。
如想统计一棵苹果树上面有多少苹果，只需要知道树杈左边的苹果数量和树杈右边的苹果数量，然后计算它们的和就行了。至于树杈左边有多少个苹果？可以使用一样的方法来统计，把这个分枝当作树干，然后统计这个树干的左分杈和右分杈的苹果数量和……直到统计到树枝末端每一个苹果，然后依次汇总就可以得到苹果的数量 。
很明显，树形结构不仅能表示数据间的指向关系，还能表示出数据的层次关系，而有很明显的递归性质。因此，我们可以利用树的性质解决更多种类的问题。

# 一、二叉树概念和建立
二叉树是一种特殊的树，每次分叉不超过两部分。
# 16.1 淘汰赛
## 题目描述
有 $2^n$（$n\le7$）个国家参加世界杯决赛圈且进入淘汰赛环节。已经知道各个国家的能力值，且都不相等。能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者晋级。3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠军。给出各个国家的能力值，请问亚军是哪个国家？
## 输入格式
第一行一个整数 $n$，表示一共 $2^n$ 个国家参赛。
第二行 $2^n$ 个整数，第 $i$ 个整数表示编号为 $i$ 的国家的能力值（$1\leq i \leq 2^n$）。
数据保证不存在平局。
## 输出格式
仅一个整数，表示亚军国家的编号。
## 输入输出样例 #1
### 输入 #1
```
3
4 2 3 1 10 5 9 7
```
### 输出 #1
```
1
```

```cppp
#include<cstdio>
#include<iostream>
using namespace std;
int value[260],winner[260];
int n;
void dfs(int x){
    if(x>=1<<n)
        return;
    else{
        dfs(2*x);
        dfs(2*x+1);
        int lvalue=value[2*x],rvalue=value[2*x+1];
        if(lvalue>rvalue){
            value[x]=lvalue;
            winner[x]=winner[2*x];
        }else{
            value[x]=rvalue;
            winner[x]=winner[2*x+1];
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<1<<n;i++){
        cin>>value[i+(1<<n)];
        winner[i+(1<<n)]=i+1;
    }
    dfs(1);
    cout<<(value[2] > value[3]?winner[3]:winner[2]);
    return 0;
}
```


注：原书中代码三元表达式需要加括号

考虑到这是一个完美二叉树，1到(1<<n)-1编号都是非子结点，编号不小于1<<n都是叶子结点。本题使用value[i]来记录叶子结点的实力值，或是非子结点的改子树的最大值；使用winner[i]来记录该子树的获胜者。当所有比赛模拟完毕，winnner[1]记录了整场比赛的冠军，value[i]记录了冠军的实力值。这时比较一下谁是决赛败者，输出败者的国家编号，即整场比赛的亚军。
由于需要维护和子树相关的两个值————value和winner，所以建立了两个数组存储子树的信息，有时只需要维护子树的获胜者，也可不建立这样的数组，而是将dfs函数定义为具体返回值函数，然后在递归函数中处理这个值，事实上，函数也可以返回两个（甚至多个）返回值，也可以使用STL中的pair容器做到。

# 16.2 淘汰赛2，如果国家个数不是 $2^n$ 个，而是一个任意正整数，这棵树会什么样？

如果一个结点除了最后一层以外，其他层的结点都是满的，而且最后一层的结点是从左到右的一排连续的，那么这样的·二叉树称为完全二叉树。

# P4913 【深基16.例3】二叉树深度
## 题目描述
有一个 $n(n \le 10^6)$ 个结点的二叉树。给出每个结点的两个子结点编号（均不超过 $n$），建立一棵二叉树（根节点的编号为 $1$），如果是叶子结点，则输入 `0 0`。
建好这棵二叉树之后，请求出它的深度。二叉树的**深度**是指从根节点到叶子结点时，最多经过了几层。
## 输入格式
第一行一个整数 $n$，表示结点数。
之后 $n$ 行，第 $i$ 行两个整数 $l$、$r$，分别表示结点 $i$ 的左右子结点编号。若 $l=0$ 则表示无左子结点，$r=0$ 同理。
## 输出格式
一个整数，表示最大结点深度。
## 输入输出样例 #1
### 输入 #1
```
7
2 7
3 6
4 5
0 0
0 0
0 0
0 0
```
### 输出 #1
```
4
```

```cpp
#include<iostream>
using namespace std;
const int MAXN = 2e5 + 7;
struct Node {
	int left, right;
}t[MAXN];
int n;
void build() {
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &t[i].left, &t[i].right);
	}
}

int dfs(int x) {
	if(!x)   return 0;
	return max(dfs(t[x].left), dfs(t[x].right)) + 1;
}

int main() {
	cin >> n;
	build();
	cout << dfs(1);
	return 0;
}
```

# 二、二叉树的遍历
二叉树的遍历是将一棵二叉树从根结点开始，按照指定顺序，不重复、不遗漏地访问每一个结点，在完成一些任务中，必须要访问所有结点的信息，那么就需要按照某种方式不重复地、不遗漏地访问所有结点。

## 16.4 二叉树的层次遍历
遍历：沿着某条搜索路线，依次对树中的每一个结点均作一次且仅一次访问。
直接对二叉树进行广度优先搜索，将根结点放入初始队列中，取出每次出队的结点，即可得到层次遍历。
取出时别忘了把这个结点的子结点放到队伍的末尾。
二叉树的层次遍历就是1 2 7 3 6 4 5

## 16.5 二叉树的深度优先遍历，同16.3 输入一个二叉树，然后输出这个二叉树前序、中序、后序遍历。
对于任意给定结点，可以访问该结点本身、遍历左子树、遍历右子树。根据在某个结点中遍历的顺序不同，有以下3种遍历方式。
1、前序遍历：首先访问根结点，然后遍历左子树，最后遍历右子树。
2、中序遍历：首先遍历左子树，然后访问根结点，最后遍历右子树。
3、后序遍历：首先遍历左子树，然后遍历右子树，最后访问根结点。

```cpp
void pre_order(int x){
    printf("%d\n",x);
    if(t[x].left)  pre_order(t[x].left);
    if(t[x].right)  pre_order(t[x].right);
}
void in_order(int x){
    if(t[x].left)  pre_order(t[x].left);
    printf("%d\n",x);
    if(t[x].right)  pre_order(t[x].right);
}
void post_order(int x){
    if(t[x].left)  pre_order(t[x].left);
    if(t[x].right)  pre_order(t[x].right);
    printf("%d\n",x);
}
```

# 16.6 美国血统 American Heritage
## 题目描述
农夫约翰非常认真地对待他的奶牛们的血统。然而他不是一个真正优秀的记帐员。他把他的奶牛 们的家谱作成二叉树，并且把二叉树以更线性的“树的中序遍历”和“树的前序遍历”的符号加以记录而 不是用图形的方法。
你的任务是在被给予奶牛家谱的“树中序遍历”和“树前序遍历”的符号后，创建奶牛家谱的“树的 后序遍历”的符号。每一头奶牛的姓名被译为一个唯一的字母。（你可能已经知道你可以在知道树的两 种遍历以后可以经常地重建这棵树。）显然，这里的树不会有多于 $26$ 个的顶点。
这是在样例输入和样例输出中的树的图形表达方式：
```plain
　　　　　　　　 C
　　　　　　   /  \
　　　　　　  /　　\
　　　　　　 B　　  G
　　　　　　/ \　　/
　　　　   A   D  H
　　　　　　  / \
　　　　　　 E   F

```
附注：
- 树的中序遍历是按照左子树，根，右子树的顺序访问节点；
- 树的前序遍历是按照根，左子树，右子树的顺序访问节点；
- 树的后序遍历是按照左子树，右子树，根的顺序访问节点。
## 输入格式
第一行一个字符串，表示该树的中序遍历。
第二行一个字符串，表示该树的前序遍历。
## 输出格式
单独的一行表示该树的后序遍历。
## 输入输出样例 #1
### 输入 #1
```
ABEDFCHG
CBADEFGH
```
### 输出 #1
```
AEFDBHGC
```

```cpp
#include <iostream>
#include <string>
using namespace std;

string a, b; // a是前序，b是中序

void build(int l1, int r1, int l2, int r2) {
    for (int i = l2; i <= r2; ++i) {
        if (b[i] == a[l1]) { // 找到根节点在中序的位置
            build(l1 + 1, l1 + (i - l2), l2, i - 1); // 左子树
            build(l1 + (i - l2) + 1, r1, i + 1, r2); // 右子树
            cout << a[l1];
            return;
        }
    }
}

int main() {
    cin >> b >> a; // 输入中序和前序
    int n = a.size();
    build(0, n - 1, 0, n - 1);
    cout << endl;
    return 0;
}
```

 # 三、二叉树的综合应用
 
