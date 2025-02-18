有时候，我们并不关心数据之间的前后关系，也不关心数据的层次关系。一些确定元素只是单纯的聚集在一起，这样的元素聚集体被称为集合。
当希望知道某个数据是否存在一个集合中，或者两个元素是否在同一个集合中时，就需要使用一些集合数据结构来维护集合元素之间的关系。
# 一、 并查集
# 17.1 亲戚
## 题目背景
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
## 题目描述
规定：$x$ 和 $y$ 是亲戚，$y$ 和 $z$ 是亲戚，那么 $x$ 和 $z$ 也是亲戚。如果 $x$，$y$ 是亲戚，那么 $x$ 的亲戚都是 $y$ 的亲戚，$y$ 的亲戚也都是 $x$ 的亲戚。
## 输入格式
第一行：三个整数 $n,m,p$，（$n,m,p \le 5000$），分别表示有 $n$ 个人，$m$ 个亲戚关系，询问 $p$ 对亲戚关系。
以下 $m$ 行：每行两个数 $M_i$，$M_j$，$1 \le M_i,~M_j\le n$，表示 $M_i$ 和 $M_j$ 具有亲戚关系。
接下来 $p$ 行：每行两个数 $P_i,P_j$，询问 $P_i$ 和 $P_j$ 是否具有亲戚关系。
## 输出格式
$p$ 行，每行一个 `Yes` 或 `No`。表示第 $i$ 个询问的答案为“具有”或“不具有”亲戚关系。
## 输入输出样例 #1
### 输入 #1
```
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
```
### 输出 #1
```
Yes
Yes
No
```

```cpp
#include<iostream>
#define MAXN 5010
using namespace std;
int n, m, p, x, y;
int fa[MAXN]; //表示元素i的父结点

int find(int x) {
	if (x == fa[x]) //如果x的父节点是自己，说明x就是这个集合的根节点。
		return x;
	return fa[x] = find(fa[x]); //否则递归查找 x 的父节点，直到找到根节点。在查找的过程中，路径压缩：将路径上所有节点的父节点直接指向根节点，从而加速未来的查找。
}

void join(int c1, int c2) {
	int f1 = find(c1), f2 = find(c2);
	if (f1 != f2)
		fa[f1] = f2;
}

int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		join(x, y);
	}
	for (int i = 0; i < p; i++) {
		cin >> x >> y;
		if (find(x) == find(y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
```
路径压缩：一棵树上每个节点离根越近越好，因此访问一个结点的同时将所有访问到的结点的负责人都设为族长，这样下一次结点找族长经过的结点数就会大大减少，这就是fa[x]=find(fa[x])语句。
注：仅进行路径压缩时间复杂度缩短至O(logn)，还可以进行按秩合并优化（树的深度小的一方的族长指向深度大的一方），将查询复杂度优化至接近常数。

# 17.2 村村通
## 题目描述
某市调查城镇交通状况，得到现有城镇道路统计表。表中列出了每条道路直接连通的城镇。市政府 "村村通工程" 的目标是使全市任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要相互之间可达即可）。请你计算出最少还需要建设多少条道路？
## 输入格式
输入包含若干组测试数据，每组测试数据的第一行给出两个用空格隔开的正整数，分别是城镇数目 $n$ 和道路数目 $m$ ；随后的 $m$ 行对应 $m$ 条道路，每行给出一对用空格隔开的正整数，分别是该条道路直接相连的两个城镇的编号。简单起见，城镇从 $1$ 到 $n$ 编号。
注意：两个城市间可以有多条道路相通。
**在输入数据的最后，为一行一个整数 $0$，代表测试数据的结尾。**
## 输出格式
对于每组数据，对应一行一个整数。表示最少还需要建设的道路数目。
## 输入输出样例 #1
### 输入 #1
```
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
```
### 输出 #1
```
1
0
2
998
```
## 说明/提示
#### 数据规模与约定
对于 $100\%$ 的数据，保证 $1 \le n < 1000$ 。

```cpp
#include<iostream>
#define MAXN 5010
using namespace std;

int n, m, p, x, y;
int fa[MAXN];

// 查找操作，带路径压缩
int find(int x) {
    if (x == fa[x])  // 如果 x 是自己的父节点，说明它是根
        return x;
    return fa[x] = find(fa[x]);  // 路径压缩
}

// 合并操作
void join(int c1, int c2) {
    int f1 = find(c1), f2 = find(c2);
    if (f1 != f2)
        fa[f1] = f2;  // 将 f1 所在的集合合并到 f2 所在的集合
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0) break;  // 结束条件

        // 初始化并查集，每个城镇的父节点初始为自己
        for (int i = 1; i <= n; i++)
            fa[i] = i;

        // 处理 m 条道路，连接相应的城镇
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            join(x, y);
        }

        // 计算连通分量的个数
        int connected_components = 0;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i)  // 如果 i 是根节点，说明它是一个新连通分量
                connected_components++;
        }

        // 最少需要建设的道路数是连通分量数 - 1
        cout << connected_components - 1 << endl;
    }

    return 0;
}
```

# 二、Hash表
一个简单问题：给定n个自然数，值域[0,$10^9$]，求出这n个自然数中共有多少个不同的自然数
取一个模数，定义一个大小为mod的数组，然后把每个数对mod取模，如果两个数取模后相等，则两个数相同。
```cpp
#include<iostream>
#define mod 233333
using namespace std;
int n, x, ans, a[mod + 2];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		x %= mod;
		if (!a[x])
			a[x] = 1, ans++;
	}
	cout << ans << endl;
	return 0;
}
```
优势：减少了空间的利用，只需定义一个大小为mod的数组；
劣势：如果有两个不同的数恰好对mod取模之后得到相同的结果，那么算法正确性不能保证，产生冲突
优化方法：使其既保证正确性，又降低时间和空间复杂度，可以把int的数组改为vector<int>的数组或一个链表，然后将取模后为同一个数的所有值都存在其对应的vector或者链表中。
然后每次判断一个数x是否存在的时候，遍历x%mod位置的vector或链表中所有元素，看是否含有x即可，改进代码如下：
```cpp
#include<iostream>
#include<vector>
#define mod 233333
using namespace std;
int n, x, ans;
vector <int>linker[mod + 2];
inline void insert(int x) {
	for (int i = 0; i < linker[x % mod].size(); i++)
		if (linker[x % mod][i] == x)
			return;
	linker[x % mod].push_back(x);
	ans++;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		insert(x);
	}
	cout << ans << endl;
	return 0;
}
```
前面讨论的是对数字的处理，而一个字符串该如何当作一个数字？使用ASCII编码，将单个字符映射成一个数字的方式。例如，字符串abAB01就可以映射成[97,98,65,66,48,49]。希望把这串序列映射成0到mod-1中的一个数字，称为字符串的Hash值。转换方式和k进制转换成十进制一样，就是不断进行迭代运算hash=(hash*k+s[i])%mod即可。
基数k可以任选，但是一般来说不少于128（ASCII字符集的数量）。当然，求Hash值的方法不唯一，例如如果字符集局限于a到z的小写字母，也可以把每个字母映射为0到25，此时基数是26.
这里的模数mod会取一个比较大的质数以减少可能的冲突，而且在空间足够的时候越大越好。常用的模数有10007、999983等，可以根据实际情况选择。
由于可能有多个不同的字符串对应同一个Hash值，对每一个Hash值建立一个vector（或链表），用来存储对应于每个Hash值的字符串，这样每次只需将这个插入的字符串和其Has值相同的所有字符串比较，看是否相等，就可以知道这个字符串有没有出现过了。

# 17.3 【模板】字符串哈
## 题目描述
如题，给定 $N$ 个字符串（第 $i$ 个字符串长度为 $M_i$，字符串内包含数字、大小写字母，大小写敏感），请求出 $N$ 个字符串中共有多少个不同的字符串。
**友情提醒：如果真的想好好练习哈希的话，请自觉。**
## 输入格式
第一行包含一个整数 $N$，为字符串的个数。
接下来 $N$ 行每行包含一个字符串，为所提供的字符串。
## 输出格式
输出包含一行，包含一个整数，为不同的字符串个数。
## 输入输出样例 #1
### 输入 #1
```
5
abc
aaaa
abc
abcc
12345
```
### 输出 #1
```
4
```
## 说明/提示
对于 $30\%$ 的数据：$N\leq 10$，$M_i≈6$，$Mmax\leq 15$。
对于 $70\%$ 的数据：$N\leq 1000$，$M_i≈100$，$Mmax\leq 150$。
对于 $100\%$ 的数据：$N\leq 10000$，$M_i≈1000$，$Mmax\leq 1500$。
样例说明：
样例中第一个字符串(abc)和第三个字符串(abc)是一样的，所以所提供字符串的集合为{aaaa,abc,abcc,12345}，故共计4个不同的字符串。
Tip：
感兴趣的话，你们可以先看一看以下三题：
BZOJ3097：http://www.lydsy.com/JudgeOnline/problem.php?id=3097
BZOJ3098：http://www.lydsy.com/JudgeOnline/problem.php?id=3098
BZOJ3099：http://www.lydsy.com/JudgeOnline/problem.php?id=3099
如果你仔细研究过了（或者至少仔细看过AC人数的话），我想你一定会明白字符串哈希的正确姿势的^\_^

```cpp
#include<iostream>
#include<string>
#include<vector>
#define MAXN 1510
#define base 261
#define mod 23333
using namespace std;
int n, ans;
char s[MAXN];
vector<string>linker[mod + 2];
inline void insert() {
	int hash = 1;
	for (int i = 0; s[i]; i++) {
		hash = (hash * 111 * base + s[i]) % mod;
	}
	string t = s;
	for (int i = 0; i < linker[hash].size(); i++)
		if (linker[hash][i] == t)
			return;
	linker[hash].push_back(t);
	ans++;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s, insert();
	cout << ans << endl;
	return 0;
}
```

# 17.4 Cities and States S  省市
## 题目描述
Farmer John 有若干头奶牛。为了训练奶牛们的智力，Farmer John 在谷仓的墙上放了一张美国地图。地图上表明了每个城市及其所在州的代码（前两位大写字母）。
由于奶牛在谷仓里花了很多时间看这张地图，他们开始注意到一些奇怪的关系。例如，FLINT 的前两个字母就是 MIAMI 所在的 `FL` 州，MIAMI 的前两个字母则是 FLINT 所在的 `MI` 州。  
确切地说，对于两个城市，它们的前两个字母互为对方所在州的名称。
我们称两个城市是一个一对「特殊」的城市，如果他们具有上面的特性，并且来自不同的州。对于总共 $N$ 座城市，奶牛想知道有多少对「特殊」的城市存在。请帮助他们解决这个有趣的地理难题！
## 输入格式
输入共 $N + 1$ 行。
第一行一个正整数 $N$，表示地图上的城市的个数。  
接下来 $N$ 行，每行两个字符串，分别表示一个城市的名称（$2 \sim 10$ 个大写字母）和所在州的代码（$2$ 个大写字母）。同一个州内不会有两个同名的城市。
## 输出格式
输出共一行一个整数，代表特殊的城市对数。
## 输入输出样例 #1
### 输入 #1
```
6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
```
### 输出 #
```
1
```
## 说明/提示
### 数据规模与约
对于 $100\%$ 的数据，$1 \leq N \leq 2 \times 10 ^ 5$，城市名称长度不超过 $10$。

```cpp
#include<iostream>
#include<vector>
#define mod 233333
using namespace std;
int n;
char a[12], b[12];
long long ans;
vector<pair<int, int>>linker[mod + 2];

inline int gethash(char a[], char b[]) {
	return (a[0] - 'A') + (a[1] - 'A') * 26 + (b[0] - 'A') * 26 * 26 + (b[1] - 'A') * 26 * 26 * 26;
}

inline void insert(int x){
	for (int i = 0; i < linker[x % mod].size(); i++) {
		if (linker[x % mod][i].first == x) {
			linker[x % mod][i].second++;
			break;
		}
	}
	linker[x % mod].push_back(pair<int, int>(x, 1));
}

inline int find(int x) {
	for (int i = 0; i < linker[x % mod].size(); i++)
		if(linker[x%mod][i].first==x)
			return linker[x % mod][i].second;
	return 0;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		a[2] = 0;
		if (a[0] != b[0 ]|| a[1] != b[1])
			ans += find(gethash(b,a));
		insert(gethash(a, b));
	}
	cout << ans << endl;
	return 0;
}
```
