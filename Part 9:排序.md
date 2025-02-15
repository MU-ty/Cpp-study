在生活中我们经常需要对一些东西排序。比如考试评卷后老师会要求你按照成绩高低将试卷排序，玩扑克牌时要按点数排序手牌，在洛谷刷题将题库按照难度排序然后简单题刷起（友情提示：长期只刷简单题不会有长进的）。多亏了排序过程，可以将无序的杂乱无章的东西整理清楚，便于查询统计和利用。
# 一、计数排序
# 9.1 选举学生会
## 题目描述
学校正在选举学生会成员，有 $n$（$n\le 999$）名候选人，每名候选人编号分别从 $1$ 到 $n$，现在收集到了 $m$（$m \le 2000000$）张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。
## 输入格式
输入 $n$ 和 $m$ 以及 $m$ 个选票上的数字。
## 输出格式
求出排序后的选票编号。
## 样例 #1
### 样例输入 #1
```
5 10
2 5 2 2 5 2 2 2 1 2
```
### 样例输出 #1
```
1 2 2 2 2 2 2 2 5 5
```
##  解答
```
# 【深基9.例1】选举学生会

## 题目描述

学校正在选举学生会成员，有 $n$（$n\le 999$）名候选人，每名候选人编号分别从 $1$ 到 $n$，现在收集到了 $m$（$m \le 2000000$）张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。

## 输入格式

输入 $n$ 和 $m$ 以及 $m$ 个选票上的数字。

## 输出格式

求出排序后的选票编号。

## 样例 #1

### 样例输入 #1

```
5 10
2 5 2 2 5 2 2 2 1 2
```

### 样例输出 #1

```cpp
#include<iostream>
using namespace std;
int a[1010] = { 0 }, n, m, tmp;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        a[tmp]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
```

#二、选择排序、冒泡排序、插入排序
## 9.2 数列排序，输入n个数字ai(ai<10^9)，将其从小到大排序后输出
```cpp
//选择排序
for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
        if (a[j] < a[i]) {
            int p = a[i];
            a[i] = a[j];
            a[j] = p;
        }
    }
}
```
![](https://i-blog.csdnimg.cn/blog_migrate/5bef5385d11cd3af05943a6b7577f842.gif#pic_center)

```cpp
//冒泡排序
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n-1-i; j++) {
        if (a[j] > a[j+1]) {
            int p = a[j];
            a[j] = a[j+1];
            a[j=1] = p;
        }
    }
}
```
![](https://i-blog.csdnimg.cn/blog_migrate/cbf9fc66212bb356bdd4200e720b1e07.gif#pic_center)


```cpp
//插入排序
for (int i = 1; i < n ; i++) {
    int now = a[i], j;
    for (int j = i-1; j >=0; j--) {
        if (a[j] > now) {
            a[j + 1] = a[j];
        else break;
        }
    }
        a[j + 1] = now;
}

```
![](https://i-blog.csdnimg.cn/blog_migrate/63a9b3d35a93d9506399773b34715771.gif#pic_center)


#三、快速排序
##9.3快速排序
```cpp
void qsort(int a[],int l,int r){
    int i=1,j=r,flag=a[(l+r)/2],tmp;
    do{
        while(a[i]<flag)i++;
        while(a[j]>flag)j--;
        if(i<=j){
            tmp=a[i];a[i]=a[j];a[j]=tmp;
            i++;j--;
        }
    }while(i<=j);
    if(i<j)  qsort(a,l,j);
    if(i<r)  qsort(a,i,r);
}
```
##补充：随机化快速排序
传统的快速排序在最坏情况下的时间复杂度是 \( O(n^2) \)，这是因为当选择的基准元素总是数组中的最大值或最小值时，分区操作会导致每次划分只减少一个元素。为了避免这种情况，我们可以使用**随机化快速排序**（Randomized QuickSort），它通过随机选择基准元素，使得最坏情况的概率大大降低，从而期望时间复杂度变为 \( O(n \log n) \)。
### 随机化快速排序的原理：
1. 随机选择基准元素：每次选择一个随机的元素作为基准，而不是固定地选择数组的第一个或最后一个元素，这样可以避免数据已经有序的情况，减少最坏情况出现的概率。
2. 其余部分与标准快速排序相同：对基准元素进行分区，递归地对左右两部分进行排序。
### 随机化快速排序实现
以下是 C++ 中实现随机化快速排序的代码：
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

// 随机化快速排序
void randomized_qsort(int a[], int l, int r) {
    if (l >= r) return;

    // 随机选择基准元素并交换
    int random_index = l + rand() % (r - l + 1);
    swap(a[l], a[random_index]);

    int i = l, j = r;
    int pivot = a[l], tmp;
    while (i < j) {
        while (i < r && a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    // 递归排序左右部分
    randomized_qsort(a, l, j);
    randomized_qsort(a, i, r);
}

int main() {
    int n;
    cin >> n;
    int arr[100010];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 设置随机数种子
    srand(time(0));

    // 调用随机化快速排序
    randomized_qsort(arr, 0, n - 1);

    // 输出排序后的结果
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";  // 除第一个元素外前面有空格
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
```
### 主要步骤说明：
1. **随机化选择基准元素**：
   ```cpp
   int random_index = l + rand() % (r - l + 1);
   swap(a[l], a[random_index]);
   ```
   这里通过 `rand()` 随机生成一个索引，选择数组中一个随机的元素与 `a[l]` 交换，以避免出现最坏情况。
2. **递归调用**：
   递归的过程与标准快速排序一样，分为左右两部分分别排序。
3. **时间复杂度**：
   随机化快速排序的平均时间复杂度是 \( O(n \log n) \)，最坏情况下的时间复杂度是 \( O(n^2) \)，但是因为基准元素是随机选取的，最坏情况的概率极低。因此在实际应用中，时间复杂度接近 \( O(n \log n) \)。
4. **输出格式**：
   在输出时，我们确保输出格式正确，数与数之间用空格隔开，并且末尾没有多余的空格。
### 注意：
1. **`rand()` 和 `srand()`**：我们使用 `rand()` 来生成随机数，`srand(time(0))` 用于设置随机数种子，确保每次运行时随机数的顺序不同。
2. **性能**：由于我们采用了随机化快速排序，排序性能通常非常好，能有效处理大规模数据。
### 样例测试：
**输入：**
```
5
4 2 4 5 1
```
**输出：**
```
1 2 4 4 5
```
通过这种方式，快速排序的最坏情况概率大大降低，并且在实际数据中表现较好。如果 `N` 过大，仍然可以在 \( O(n \log n) \) 时间内完成排序。

# 9.4 求第 k 小的数
## 题目描述
输入 $n$（$1 \le n < 5000000$ 且 $n$ 为奇数）个数字 $a_i$（$1 \le a_i < {10}^9$），输出这些数字的第 $k$ 小的数。最小的数是第 $0$ 小。
请尽量不要使用 `nth_element` 来写本题，因为本题的重点在于练习分治算法。
## 样例 #1
### 样例输入 #1
```
5 1
4 3 2 1 5
```
### 样例输出 #1
```
2
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int x[5000005],k;
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	sort(x,x+n);//快排
	printf("%d",x[k]);
}
```

#四、排序算法的应用
# 9.5 明明的随机数
## 题目描述
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了 $N$ 个 $1$ 到 $1000$ 之间的随机整数 $(N\leq100)$，对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
## 输入格式
输入有两行，第 $1$ 行为 $1$ 个正整数，表示所生成的随机数的个数 $N$。
第 $2$ 行有 $N$ 个用空格隔开的正整数，为所产生的随机数。
## 输出格式
输出也是两行，第 $1$ 行为 $1$ 个正整数 $M$，表示不相同的随机数的个数。
第 $2$ 行为 $M$ 个用空格隔开的正整数，为从小到大排好序的不相同的随机数。
## 样例 #1
### 样例输入 #1
```
10
20 40 32 67 40 20 89 300 400 15
```
### 样例输出 #1
```
8
15 20 32 40 67 89 300 400
```
## 9.5 第一种完整代码
```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int const MAXN =1010;
int a[MAXN],ans[MAXN],n,cnt=0,tmp=-1;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]!=tmp){
            ans[cnt++]=a[i];
        }
        tmp=a[i];
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
```
sort时间复杂度是 \( O(n \log n) \)，如果对数组a[1]到a[n]排序，就要用sort(a+1,a+n+1).
如果要求从大到小排序，只需定义一个名字是cmp的自定义比较函数即可，这个函数的输入是两个元素，如果第一个在第二个之前，则返回true，否则返回false。代码如下：
```c
bool cmp(int a,int b){
  return a>b;
}
```
unique(a,a+n):对a数组从a[0]到a[n-1]进行去重，要求a数组已经有序，返回去重后的最后一个元素对应的指针，使用unique就可以不用ans新数组了，可以直接获得去重后的数组和最终元素个数
核心代码：
```c
sort(a,a+n);
cnt=unique(a,a+n)-a;
cout<<cnt<<endl;
for(int i=0;i<cnt;i++)
    cout<<a[i]<<' ';
```

## 9.5 第二种完整代码
```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int n, cnt = 0,a[1010];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cnt = unique(a, a + n) - a;
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << a[i] << ' ';
    return 0;
}
```
# 9.6 奖学金
## 题目描述
某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前 $5$ 名学生发奖学金。期末，每个学生都有 $3$ 门课的成绩：语文、数学、英语。先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学排在前面，这样，每个学生的排序是唯一确定的。
任务：先根据输入的 $3$ 门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。
注意，在前 $5$ 名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。例如，在某个正确答案中，如果前两行的输出数据（每行输出两个数：学号、总分) 是：
```plain
7 279  
5 279
```
这两行数据的含义是：总分最高的两个同学的学号依次是 $7$ 号、$5$ 号。这两名同学的总分都是 $279$ (总分等于输入的语文、数学、英语三科成绩之和) ，但学号为 $7$ 的学生语文成绩更高一些。
如果你的前两名的输出数据是：
```plain
5 279  
7 279
```
则按输出错误处理，不能得分。
## 输入格式
共 $n+1$ 行。
第 $1$ 行为一个正整数 $n \le 300$，表示该校参加评选的学生人数。
第 $2$ 到 $n+1$ 行，每行有 $3$ 个用空格隔开的数字，每个数字都在 $0$ 到 $100$ 之间。第 $j$ 行的 $3$ 个数字依次表示学号为 $j-1$ 的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为 $1\sim n$（恰好是输入数据的行号减 $1$）。
保证所给的数据都是正确的，不必检验。
## 输出格式
共 $5$ 行，每行是两个用空格隔开的正整数，依次表示前 $5$ 名学生的学号和总分。
## 样例 #1
### 样例输入 #1
```
6
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
```
### 样例输出 #1
```
6 265
4 264
3 258
2 244
1 237
```
## 样例 #2
### 样例输入 #2
```
8
80 89 89
88 98 78
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
```
### 样例输出 #2
```
8 265
2 264
6 264
1 258
5 258
```

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int const MAXN =310;
int n;
struct student {
    int id,chinese,total;
}a[MAXN];

int cmp(student a,student b){
    if(a.total!=b.total)   return a.total>b.total;
    if(a.chinese!=b.chinese)   return a.chinese>b.chinese;
    return a.id<b.id;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int math,english;
        cin>>a[i].chinese>>math>>english;
        a[i].total=a[i].chinese+math+english;
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++)
        cout<<a[i].id<<" "<<a[i].total<<endl;
    return 0;
}
```

# 9.7 宇宙总统
## 题目描述
地球历公元 6036 年，全宇宙准备竞选一个最贤能的人当总统，共有 $n$ 个非凡拔尖的人竞选总统，现在票数已经统计完毕，请你算出谁能够当上总统。
## 输入格式
第一行为一个整数 $n$，代表竞选总统的人数。
接下来有 $n$ 行，分别为第一个候选人到第 $n$ 个候选人的票数。
## 输出格式
共两行，第一行是一个整数 $m$，为当上总统的人的号数。
第二行是当上总统的人的选票。
## 样例 #1
### 样例输入 #1
```
5
98765
12365
87954
1022356
985678
```
### 样例输出 #1
```
4
1022356
```
## 提示
票数可能会很大，可能会到 $100$ 位数字。
$1 \leq n \leq 20$。

```cpp
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int const maxn = 25;
struct node {
    string x;
    int num;
}s[maxn];

bool cmp(node a, node b) {
    if (a.x.length() != b.x.length())
	return a.x.length() > b.x.length();
    return a.x > b.x;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].x;
        s[i].num = i + 1;
    }
    sort(s, s + n, cmp);
    cout << s[0].num << endl;
    cout << s[0].x << endl;
    return 0;
}
```
## 数字较大，没办法用long long直接存下来，最方便是使用字符串（自己写比较器）。

END
