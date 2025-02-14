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
int fa[MAXN];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
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
