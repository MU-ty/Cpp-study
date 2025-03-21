设想一下，你觉得家门口的山非常碍事，下决心发扬“愚公移山”精神，凭借一镐一担打算把山一点一点的移走。虽然精神值得褒奖，而且理论上是可行的，只要给予足够多的时间迟早能做到。但是，实际上并不可能给你那么多时间，所以使用这种办法在有生之年是不可能将山移开的（也许你可以使用更好的办法，比如使用魔法或者设法让天神感动，让他帮你移山）。然而，如果你只是把一个不到半人高的小沙堆给移走，那使用这种方法很快就可以完成了。
算法的世界高深莫测，但是很多问题的解决方法简单而粗暴——就是枚举出所有可能的情况，然后判断或者统计，从而解决问题。在很多程序设计比赛中，有许多比较简单的题目是可以通过枚举暴力解决的；而有的更有具有挑战性的题目虽然有更巧妙的解法，但依然可以使用枚举暴力完成部分任务。
本章将介绍一些枚举与暴力策略，这是非常基础而且重要的，但是对初学者来说还是会有一些挑战。请务必理解本章之前的所有章节后再开始本章的学习。
## 一、 循环枚举
# 10.1 统计方形（数据加强版）
## 题目描述
有一个 $n \times m$ 方格的棋盘，求其方格包含多少正方形、长方形（不包含正方形）。
## 输入格式
一行，两个正整数 $n,m$（$n \leq 5000,m \leq 5000$）。
## 输出格式
一行，两个正整数，分别表示方格包含多少正方形、长方形（不包含正方形）。
## 样例 #1
### 样例输入 #1
```
2 3
```
### 样例输出 #1
```
8 10
```
```cpp
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, m, squ = 0, rec = 0;
    scanf("%lld%lld", &n, &m);
    for (LL x = 0; x <= n; x++) {
        for (LL y = 0; y <= m; y++) {
            LL tmp = min(x, y) + min(y, n - x) + min(n - x, m - y) + min(m - y, x);
            squ += tmp;
            rec += n * m - tmp;
        }
    }
    printf("%lld %lld", squ / 4, rec / 4);
}
```
我们来详细讲解**矩形总数的计算方法**。
---
### **核心思想**
在一个 \( n \times m \) 的棋盘中，每一个矩形可以由两条水平线和两条垂直线框住：
1. 水平线有 \( n+1 \) 条（包括上下边界）。
2. 垂直线有 \( m+1 \) 条（包括左右边界）。
- **选择水平线的方法**：从 \( n+1 \) 条水平线中任意选择 2 条，表示矩形的上下边界。  
  选择的组合数为：
  \[
  C(n+1, 2) = \frac{(n+1) \cdot n}{2}
  \]
- **选择垂直线的方法**：从 \( m+1 \) 条垂直线中任意选择 2 条，表示矩形的左右边界。  
  选择的组合数为：
  \[
  C(m+1, 2) = \frac{(m+1) \cdot m}{2}
  \]
因此，矩形总数为两种选择数的乘积：
\[
\text{矩形总数} = C(n+1, 2) \cdot C(m+1, 2) = \frac{n(n+1)}{2} \cdot \frac{m(m+1)}{2}
\]
---
### **公式**
矩形总数可以直接计算为：
\[
\text{矩形总数} = \left( \frac{n(n+1)}{2} \right) \times \left( \frac{m(m+1)}{2} \right)
\]
---
### **举例**
#### 示例 1：\( 2 \times 3 \) 棋盘
1. 水平线有 \( 2+1 = 3 \) 条。
2. 垂直线有 \( 3+1 = 4 \) 条。
- 水平线的选择数：
  \[
  C(3, 2) = \frac{3 \cdot 2}{2} = 3
  \]
- 垂直线的选择数：
  \[
  C(4, 2) = \frac{4 \cdot 3}{2} = 6
  \]
矩形总数：
\[
\text{矩形总数} = 3 \times 6 = 18
\]
---
#### 示例 2：\( 3 \times 3 \) 棋盘
1. 水平线有 \( 3+1 = 4 \) 条。
2. 垂直线有 \( 3+1 = 4 \) 条。

- 水平线的选择数：
  \[
  C(4, 2) = \frac{4 \cdot 3}{2} = 6
  \]

- 垂直线的选择数：
  \[
  C(4, 2) = \frac{4 \cdot 3}{2} = 6
  \]

矩形总数：
\[
\text{矩形总数} = 6 \times 6 = 36
\]
---
### **代码实现**
以下是矩形总数计算的代码实现：
#### C++
```cpp
#include <iostream>
using namespace std;

long long calculate_total_rectangles(int n, int m) {
    return (long long)n * (n + 1) / 2 * (long long)m * (m + 1) / 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << calculate_total_rectangles(n, m) << endl; // 输出: 18
    return 0;
}
```
---
### **总结**
- 矩形总数的计算关键在于理解 “从 \( n+1 \) 条水平线中选择 2 条” 和 “从 \( m+1 \) 条垂直线中选择 2 条”。
- 通过公式直接计算，时间复杂度为 \( O(1) \)。

### **正方形总数的计算**
正方形是一种特殊的矩形，边长相等。计算正方形总数的方法是逐步统计不同边长的正方形数量。
---
### **思路**
1. **边长为 \( k \) 的正方形**：
   - 要构成一个边长为 \( k \) 的正方形，其左上角的位置范围为：
     - 行：\( 1 \) 到 \( n-k+1 \)
     - 列：\( 1 \) 到 \( m-k+1 \)
   - 因此，边长为 \( k \) 的正方形数量为：
     \[
     \text{数量} = (n-k+1) \times (m-k+1)
     \]
2. **累加所有可能边长的正方形**：
   - 边长可以从 \( 1 \) 到 \( \min(n, m) \)。
   - 总正方形数为：
     \[
     \text{正方形总数} = \sum_{k=1}^{\min(n, m)} (n-k+1) \times (m-k+1)
     \]
---
### **公式**
正方形总数：
\[
\text{正方形总数} = \sum_{k=1}^{\min(n, m)} (n-k+1) \times (m-k+1)
\]
---
### **举例**
#### 示例 1：\( 2 \times 3 \) 的棋盘
1. **边长为 1 的正方形**：
   - 左上角的行范围：\( 1 \) 到 \( 2 \)。
   - 左上角的列范围：\( 1 \) 到 \( 3 \)。
   - 数量：\( 2 \times 3 = 6 \)。
2. **边长为 2 的正方形**：
   - 左上角的行范围：\( 1 \) 到 \( 1 \)。
   - 左上角的列范围：\( 1 \) 到 \( 2 \)。
   - 数量：\( 1 \times 2 = 2 \)。
3. **总正方形数**：
   \[
   \text{正方形总数} = 6 + 2 = 8
   \]

---
#### 示例 2：\( 3 \times 3 \) 的棋盘
1. **边长为 1 的正方形**：
   - 左上角的行范围：\( 1 \) 到 \( 3 \)。
   - 左上角的列范围：\( 1 \) 到 \( 3 \)。
   - 数量：\( 3 \times 3 = 9 \)。
2. **边长为 2 的正方形**：
   - 左上角的行范围：\( 1 \) 到 \( 2 \)。
   - 左上角的列范围：\( 1 \) 到 \( 2 \)。
   - 数量：\( 2 \times 2 = 4 \)。
3. **边长为 3 的正方形**：
   - 左上角的行范围：\( 1 \) 到 \( 1 \)。
   - 左上角的列范围：\( 1 \) 到 \( 1 \)。
   - 数量：\( 1 \times 1 = 1 \)。
4. **总正方形数**：
   \[
   \text{正方形总数} = 9 + 4 + 1 = 14
   \]
---
### **代码实现**
#### Python实现
#### C++实现
```cpp
#include <iostream>
using namespace std;

long long calculate_total_squares(int n, int m) {
    long long total_squares = 0;
    for (int k = 1; k <= min(n, m); ++k) {
        total_squares += (long long)(n - k + 1) * (m - k + 1);
    }
    return total_squares;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << calculate_total_squares(n, m) << endl;  // 输出: 8
    return 0;
}
```
---
### **总结**
1. **正方形的核心计算逻辑**：每个边长 \( k \) 的正方形数量为 \( (n-k+1) \times (m-k+1) \)，逐步累加即可。
2. **时间复杂度**：由于边长 \( k \) 最多遍历到 \( \min(n, m) \)，时间复杂度为 \( O(\min(n, m)) \)。
3. **优势**：对于 \( n, m \leq 5000 \) 的大棋盘，计算速度非常快。

# 10.2 烤鸡
## 题目背景
猪猪Hanke 得到了一只鸡。
## 题目描述
猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 $10$ 种配料（芥末、孜然等），每种配料可以放 $1$ 到 $3$ 克，任意烤鸡的美味程度为所有配料质量之和。
现在， Hanke 想要知道，如果给你一个美味程度 $n$ ，请输出这 $10$ 种配料的所有搭配方案。
## 输入格式
一个正整数 $n$，表示美味程度。
## 输出格式
第一行，方案总数。
第二行至结束，$10$ 个数，表示每种配料所放的质量，按字典序排列。
如果没有符合要求的方法，就只要在第一行输出一个 $0$。
## 样例 #1
### 样例输入 #1
```
11
```
### 样例输出 #1
```
10
1 1 1 1 1 1 1 1 1 2 
1 1 1 1 1 1 1 1 2 1 
1 1 1 1 1 1 1 2 1 1 
1 1 1 1 1 1 2 1 1 1 
1 1 1 1 1 2 1 1 1 1 
1 1 1 1 2 1 1 1 1 1 
1 1 1 2 1 1 1 1 1 1 
1 1 2 1 1 1 1 1 1 1 
1 2 1 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 1 1
```
## 提示
对于 $100\%$ 的数据，$n \leq 5000$。

```cpp
#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int n,ans=0,cnt=10;
    scanf("%d",&n);
    rep(a,1,3) rep(b,1,3) rep(c,1,3) rep(d,1,3) rep(e,1,3)
      rep(f,1,3) rep(g,1,3) rep(h,1,3) rep(i,1,3) rep(j,1,3)
        if(a+b+c+d+e+f+g+h+i+j==n){
            ans++;
        }
    printf("%d\n",ans);
    rep(a,1,3) rep(b,1,3) rep(c,1,3) rep(d,1,3) rep(e,1,3)
      rep(f,1,3) rep(g,1,3) rep(h,1,3) rep(i,1,3) rep(j,1,3)
        if(a+b+c+d+e+f+g+h+i+j==n){
            printf("%d %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i,j);
        }
    return 0;
}
```

# 10.3三连击（升级版）
## 题目描述
将 $1, 2,\ldots, 9$ 共 $9$ 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 $A:B:C$，试求出所有满足条件的三个三位数，若无解，输出 `No!!!`。
//感谢黄小U饮品完善题意
## 输入格式
三个数，$A,B,C$。
## 输出格式
若干行，每行 $3$ 个数字。按照每行第一个数字升序排列。
## 样例 #1
### 样例输入 #1
```
1 2 3
```
### 样例输出 #1
```
192 384 576
219 438 657
273 546 819
327 654 981
```
## 提示
保证 $A<B<C$。
---
$\text{upd 2022.8.3}$：新增加二组 Hack 数据。

```cpp
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int b[10];
void go(int x) {
	b[x % 10] = 1;
	b[x / 10 % 10] = 1;
	b[x / 100] = 1;
}
bool check(int x, int y, int z) {
	memset(b, 0, sizeof(b));
	if (y > 999 || z > 999) return 0;
	go(x), go(y), go(z);
	for (int i = 1; i <= 9; i++) {
		if (!b[i])  return 0;
	}
	return 1;
}
int main() {
	long long A, B, C, x, y, z, cnt = 0;
	cin >> A >> B >> C;
	for (x = 123; x <= 987; x++) {
		if (x * B % A || x * C % A)  continue;
		y = x * B / A, z = x * C / A;
		if (check(x, y, z))
			printf("%lld %lld %lld\n", x, y, z), cnt++;
	}
	if (!cnt)  puts("No!!!");
	return 0;
}
```
## 二、子集枚举
# 10.4 选数
## 题目描述
已知 $n$ 个整数 $x_1,x_2,\cdots,x_n$，以及 $1$ 个整数 $k$（$k<n$）。从 $n$ 个整数中任选 $k$ 个整数相加，可分别得到一系列的和。例如当 $n=4$，$k=3$，$4$ 个整数分别为 $3,7,12,19$ 时，可得全部的组合与它们的和为：
$3+7+12=22$
$3+7+19=29$
$7+12+19=38$
$3+12+19=34$
现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：$3+7+19=29$。
## 输入格式
第一行两个空格隔开的整数 $n,k$（$1 \le n \le 20$，$k<n$）。
第二行 $n$ 个整数，分别为 $x_1,x_2,\cdots,x_n$（$1 \le x_i \le 5\times 10^6$）。
## 输出格式
输出一个整数，表示种类数。
## 样例 #1
### 样例输入 #1
```
4 3
3 7 12 19
```
### 样例输出 #1
```
1
```
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int a[30];
bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)  return 0;
    }
    return 1;
}
int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int U = 1 << n;
    for (int S = 0; S < U; S++) {
        if (__builtin_popcount(S) == k) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
            }
            if (check(sum))   ans++;
        }
    }

    cout << ans;
    return 0;
}
```

# 10.5 组合的输出
## 题目描述
排列与组合是常用的数学方法，其中组合就是从 $n$ 个元素中抽出 $r$ 个元素（不分顺序且 $r \le n$），我们可以简单地将 $n$ 个元素理解为自然数 $1,2,\dots,n$，从中任取 $r$ 个数。
现要求你输出所有组合。
例如 $n=5,r=3$，所有组合为：
$123,124,125,134,135,145,234,235,245,345$。
## 输入格式
一行两个自然数 $n,r(1<n<21,0 \le r \le n)$。
## 输出格式
所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，每个元素占三个字符的位置，所有的组合也按字典顺序。
**注意哦！输出时，每个数字需要 $3$ 个场宽。以 C++ 为例，你可以使用下列代码：**
```cpp
cout << setw(3) << x;
```
输出占 $3$ 个场宽的数 $x$。注意你需要头文件 `iomanip`。
## 样例 #1
### 样例输入 #1
```
5 3
```
### 样例输出 #1
```
1  2  3
  1  2  4
  1  2  5
  1  3  4
  1  3  5
  1  4  5
  2  3  4
  2  3  5
  2  4  5
  3  4  5
```

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int a[30];
int main(){
    int n,r;
    cin>>n>>r;
    for(int s=(1<<n)-1;s>=0;s--){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s&(1<<i)){
                a[cnt++]=i;
            }
        }
        if(cnt==r){
            for(int i=r-1;i>=0;i--)
                printf("%3d",n-a[i]);
            puts(" ");
        }
    }
    return 0;
}
```

## 三、排列枚举
# 10.3 （重现）三连击（升级版）
## 题目描述
将 $1, 2,\ldots, 9$ 共 $9$ 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 $A:B:C$，试求出所有满足条件的三个三位数，若无解，输出 `No!!!`。
//感谢黄小U饮品完善题意
## 输入格式
三个，$A,B,C$。
## 输出格式
若干行，每行 $3$ 个数字。按照每行第一个数字升序排列。
## 样例 #1
### 样例输入 #1
```
1 2 3
```
### 样例输出 #1
```
192 384 576
219 438 657
273 546 819
327 654 981
```
## 提示
保证 $A<B<C$。
---
$\text{upd 2022.8.3}$：新增加二组 Hack 数据。

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int a[10];
int main(){
    long long A,B,C,x,y,z,cnt=0;
    cin>>A>>B>>C;
    for(int i=1;i<=9;i++)
        a[i]=i;
    do{
        x=a[1]*100+a[2]*10+a[3];
        y=a[4]*100+a[5]*10+a[6];
        z=a[7]*100+a[8]*10+a[9];
        if(x*B==y*A&&y*C==z*B)
            printf("%lld %lld %lld\n",x,y,z),cnt++;
    }while(next_permutation(a+1,a+10));
    if(!cnt)puts("No!!!");
    return 0;
}
```
## 解释
`next_permutation(a + 1, a + 10)` 是一个标准的 C++ 库函数，用于生成数组或容器的下一个字典序排列。它的作用是对数组 `a[1]` 到 `a[9]`（不包含 `a[0]`）进行排列，生成下一个字典序更大的排列。
### 何时调用 `next_permutation(a + 1, a + 10)`？
调用 `next_permutation(a + 1, a + 10)` 的目的是 **生成 `a[1]` 到 `a[9]` 的下一个排列**，并在每次排列时检查是否符合题目中的条件。
### 1. **初始化**：
在程序开始时，`a` 数组已经初始化为 `1, 2, 3, ..., 9`
```cpp
for (int i = 1; i <= 9; i++)
    a[i] = i;
```
- 这样，`a[1]` 到 `a[9]` 最初的排列是：`1, 2, 3, 4, 5, 6, 7, 8, 9`。
### 2. **排列生成**：
在 `do...while` 循环中，使用 `next_permutation(a + 1, a + 10)` 来生成 `a[1]` 到 `a[9]` 的所有排列。
```cpp
do {
    x = a[1] * 100 + a[2] * 10 + a[3];
    y = a[4] * 100 + a[5] * 10 + a[6];
    z = a[7] * 100 + a[8] * 10 + a[9];
    if (x * B == y * A && y * C == z * B)
        printf("%lld %lld %lld\n", x, y, z), cnt++;
} while (next_permutation(a + 1, a + 10));
```
- `next_permutation(a + 1, a + 10)` 会生成下一个排列，直到遍历完所有排列。
### 3. **如何工作**：
- `next_permutation(a + 1, a + 10)` 会尝试生成数组 `a[1]` 到 `a[9]` 的下一个字典序排列。它会：
  - 从数组的右端开始，寻找一个可以交换的位置，使得排列变得更大（字典序更大）。
  - 如果找到了这样的地方，它就交换并继续调整剩余部分；如果没有找到，说明已经是最大的排列，返回 `false`，循环停止。
### 举例：
假设 `a` 的初始值为：`[1, 2, 3, 4, 5, 6, 7, 8, 9]`。
1. 第一次调用 `next_permutation` 后，数组变为：`[1, 2, 3, 4, 5, 6, 7, 9, 8]`（找到了能改变的地方，交换了 `8` 和 `9`）。
2. 第二次调用 `next_permutation` 后，数组变为：`[1, 2, 3, 4, 5, 6, 8, 7, 9]`。
3. 继续调用 `next_permutation`，数组会依次变成：
   - `[1, 2, 3, 4, 5, 6, 9, 7, 8]`
   - `[1, 2, 3, 4, 5, 7, 6, 8, 9]`
   - …直到生成所有排列。
### 4. **循环结束条件**：
当 `next_permutation(a + 1, a + 10)` 返回 `false` 时，表示所有排列已经生成完毕，循环会结束。
### 总结：
- **`next_permutation(a + 1, a + 10)`** 在每次循环结束时被调用，用于生成 `a[1]` 到 `a[9]` 的下一个排列。
- 每次生成一个新的排列后，程序会检查当前排列是否满足给定的比例关系 \( A : B : C \)。
- 当所有排列都被检查完毕后，循环会结束，程序根据是否找到符合条件的解来输出结果。

# 10.6 全排列问题
## 题目描述
按照字典序输出自然数 $1$ 到 $n$ 所有不重复的排列，即 $n$ 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。
## 输入格式
一个整数 $n$。
## 输出格式
由 $1 \sim n$ 组成的所有不重复的数字序列，每行一个序列。
每个数字保留 $5$ 个场宽。
## 样例 #1
### 样例输入 #1
```
3
```
### 样例输出 #1
```
1    2    3
    1    3    2
    2    1    3
    2    3    1
    3    1    2
    3    2    1
```
## 提示
$1 \leq n \leq 9$。

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10], n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    do {
        for (int i = 1; i <= n; i++) {
            printf("%5d", a[i]);
            if (i == n) printf("\n");
        }
    } while (next_permutation(a + 1, a + n + 1));
    return 0;
}
```

# 10.7 火星人
## 题目描述
人类终于登上了火星的土地并且见到了神秘的火星人。人类和火星人都无法理解对方的语言，但是我们的科学家发明了一种用数字交流的方法。这种交流方法是这样的，首先，火星人把一个非常大的数字告诉人类科学家，科学家破解这个数字的含义后，再把一个很小的数字加到这个大数上面，把结果告诉火星人，作为人类的回答。
火星人用一种非常简单的方式来表示数字――掰手指。火星人只有一只手，但这只手上有成千上万的手指，这些手指排成一列，分别编号为 $1,2,3,\cdots$。火星人的任意两根手指都能随意交换位置，他们就是通过这方法计数的。
一个火星人用一个人类的手演示了如何用手指计数。如果把五根手指――拇指、食指、中指、无名指和小指分别编号为 $1,2,3,4$ 和 $5$，当它们按正常顺序排列时，形成了 $5$ 位数 $12345$，当你交换无名指和小指的位置时，会形成 $5$ 位数 $12354$，当你把五个手指的顺序完全颠倒时，会形成 $54321$，在所有能够形成的 $120$ 个 $5$ 位数中，$12345$ 最小，它表示 $1$；$12354$ 第二小，它表示 $2$；$54321$ 最大，它表示 $120$。下表展示了只有 $3$ 根手指时能够形成的 $6$ 个 $3$ 位数和它们代表的数字：
| 三进制数 | 代表的数字 |
|:-:|:-:|
| $123$ | $1$ |
| $132$ | $2$ |
| $213$ | $3$ |
| $231$ | $4$ |
| $312$ | $5$ |
| $321$ | $6$ |
现在你有幸成为了第一个和火星人交流的地球人。一个火星人会让你看他的手指，科学家会告诉你要加上去的很小的数。你的任务是，把火星人用手指表示的数与科学家告诉你的数相加，并根据相加的结果改变火星人手指的排列顺序。输入数据保证这个结果不会超出火星人手指能表示的范围。
## 输入格式
共三行。  
第一行一个正整数 $N$，表示火星人手指的数目（$1 \le N \le 10000$）。  
第二行是一个正整数 $M$，表示要加上去的小整数（$1  \le  M  \le  100$）。  
下一行是 $1$ 到 $N$ 这 $N$ 个整数的一个排列，用空格隔开，表示火星人手指的排列顺序。
## 输出格式
$N$ 个整数，表示改变后的火星人手指的排列顺序。每两个相邻的数中间用一个空格分开，不能有多余的空格。
## 样例 #1
### 样例输入 #1
```
5
3
1 2 3 4 5
```
### 样例输出 #1
```
1 2 4 5 3
```
## 提示
对于 $30\%$ 的数据，$N \le 15$。
对于 $60\%$ 的数据，$N \le 50$。
对于 $100\%$ 的数据，$N \le 10000$。

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[10010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        next_permutation(a+1,a+1+n);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
```
## -----END-----
