//7.1
# 【深基7.例1】距离函数
## 题目描述
给出平面坐标上不在一条直线上三个点坐标 $(x_1,y_1),(x_2,y_2),(x_3,y_3)$，坐标值是实数，且绝对值不超过 100.00，求围成的三角形周长。保留两位小数。
对于平面上的两个点 $(x_1,y_1),(x_2,y_2)$，则这两个点之间的距离 $dis=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}$
## 输入格式
输入三行，第 $i$ 行表示坐标 $(x_i,y_i)$，以一个空格隔开。
## 输出格式
输出一个两位小数，表示由这三个坐标围成的三角形的周长。
## 样例 #1
### 样例输入 #1
```
0 0
0 3
4 0
```
### 样例输出 #1
```
12.00
```
## 提示
数据保证，坐标均为实数且绝对值不超过 $100$，小数点后最多仅有 $3$ 位。
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
float bianchang(float a,float b,float c,float d) {
    float e = sqrt((c - a) * (c - a) + (d - b) * (d - b));
    return e;
}
int main() {
    float x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    float f = bianchang(x1, y1, x2, y2) + bianchang(x1, y1, x3, y3) + bianchang(x2, y2, x3, y3);
    printf("%.2f", f);
    return 0;
}

//7.2
# 【深基7.例2】质数筛
## 题目描述
输入 $n$ 个不大于 $10^5$ 的正整数。要求全部储存在数组中，去除掉不是质数的数字，依次输出剩余的质数。
## 输入格式
第一行输入一个正整数 $n$，表示整数个数。
第二行输入 $n$ 个正整数 $a_i$，以空格隔开。
## 输出格式
输出一行，依次输出 $a_i$ 中剩余的质数，以空格隔开。
## 样例 #1
### 样例输入 #1
```
5
3 4 5 6 7
```
### 样例输出 #1
```
3 5 7
```
## 提示
数据保证，$1\le n\le100$，$1 \leq a_i \leq 10^5$。

#include<iostream>
using namespace std;
int a[100],n;
bool is_prime(int x){
    if(x==0||x==1) return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(is_prime(a[i])){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}

//7.3
# 【深基7.例3】闰年展示
## 题目描述
输入 $x,y$，输出 $[x,y]$ 区间中闰年个数，并在下一行输出所有闰年年份数字，使用空格隔开。
## 输入格式
输入两个正整数 $x,y$，以空格隔开。
## 输出格式
第一行输出一个正整数，表示 $[x,y]$ 区间中闰年个数。
第二行输出若干个正整数，按照年份单调递增的顺序输出所有闰年年份数字。
## 样例 #1
### 样例输入 #1
```
1989 2001
```
### 样例输出 #1

```
3
1992 1996 2000
```
## 提示
数据保证，$1582\le x < y \le 3000$。

#include<iostream>
using namespace std;
int ans[100], cnt;
int runnian(int a, int b) {
    
    for (int i = a; i <= b; i++) {
        if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
            ans[cnt++]=i;
        }
    }
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    runnian(a, b);
    cout << cnt<<endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i]<<" ";
    }
    return 0;
}

//7.4
# 【深基7.例4】歌唱比赛
## 题目描述
$n(n\le 100)$ 名同学参加歌唱比赛，并接受 $m(m\le 20)$ 名评委的评分，评分范围是 $0$ 到 $10$ 分。这名同学的得分就是这些评委给分中去掉一个最高分，去掉一个最低分，剩下 $m-2$ 个评分的平均数。请问得分最高的同学分数是多少？评分保留 $2$ 位小数。
## 输入格式
第一行两个整数 $n,m$。   
接下来 $n$ 行，每行各 $m$ 个整数，表示得分。
## 输出格式
输出分数最高的同学的分数，保留两位小数。
## 样例 #1
### 样例输入 #1
```
7 6
4 7 2 6 10 7
0 5 0 10 3 10
2 6 8 4 3 6
6 3 6 7 5 8
5 9 3 3 8 1
5 9 9 3 2 0
5 8 0 4 1 10
```
### 样例输出 #1
```
6.00
```

#include<algorithm>
#include<cstdio>
using namespace std;
int s[25],n,m,maxsum;
void stat(int a[],int m){
    int maxscore =0,minscore =10,sum=0;
    for(int i=0;i<m;i++){
        maxscore=max(a[i],maxscore);
        minscore=min(a[i],minscore);
        sum+=a[i];
    }
    maxsum=max(maxsum,sum-maxscore-minscore);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",7s[j]);
        }
        stat(s,m);
    }
    printf("%.2f",double(maxsum)/(m-2));
    return 0;
}

//7.5交换两个变量的值
#include<iostream>
using namespace std;
void swap(int &x,int &y){
  int t=x;
  x=y;
  y=t;
}
int main(){
  int a,b;
  cin>>a>>b;
  swap(a,b);
  cout<<a<<" "<<b<<endl;
  return 0;
}

//7.6自动修正加强版，设计一个函数，将一个string类型的字符串中的小写字母转换为大写字母，输出原字符串和新字符串。
#include<iostream>
#include<string>
using namespace std;

string to_upper(string s) {
	for (int i = 0; i < s.length(); i++)
		if ('a' <= s[i] && s[i] <= 'z')
			s[i] -= 'a' - 'A';
	return s;
}

int main() {
	string s1, s2;
	getline(cin, s1);//std::getline 是一个用于从输入流中读取字符并将其存储到字符串中的函数，直到遇到换行符为止。
	s2 = to_upper(s1);
	cout << s1 << endl << s2 << endl;
}

//7.7
# 【深基7.例7】计算阶乘
## 题目描述
求 $n!$，也就是 $1\times2\times3\dots\times n$。
挑战：尝试不使用循环语句（for、while）完成这个任务。
## 输入格式
第一行输入一个正整数 $n$。
## 输出格式
输出一个正整数，表示 $n!$。
## 样例 #1
### 样例输入 #1
```
3
```
### 样例输出 #1
```
6
```
## 提示
数据保证，$1 \leq n\le12$。

#include<iostream>
using namespace std;
int jiecheng(int n){
    if(n==1)  return 1;
    return n*jiecheng(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<jiecheng(n);
    return 0;
}

//7.8
# 赦免战俘
## 题目背景
借助反作弊系统，一些在月赛有抄袭作弊行为的选手被抓出来了！
## 题目描述
现有 $2^n\times 2^n (n\le10)$ 名作弊者站成一个正方形方阵等候 kkksc03 的发落。kkksc03 决定赦免一些作弊者。他将正方形矩阵均分为 4 个更小的正方形矩阵，每个更小的矩阵的边长是原矩阵的一半。其中左上角那一个矩阵的所有作弊者都将得到赦免，剩下 3 个小矩阵中，每一个矩阵继续分为 4 个更小的矩阵，然后通过同样的方式赦免作弊者……直到矩阵无法再分下去为止。所有没有被赦免的作弊者都将被处以棕名处罚。
给出 $n$，请输出每名作弊者的命运，其中 0 代表被赦免，1 代表不被赦免。
## 输入格式
一个整数 $n$。
## 输出格式
$2^n \times 2^n$ 的 01 矩阵，代表每个人是否被赦免。数字之间有一个空格。
## 样例 #1
### 样例输入 #1
```
3
```
### 样例输出 #1
```
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 1
0 0 0 0 1 1 1 1
0 0 0 1 0 0 0 1
0 0 1 1 0 0 1 1
0 1 0 1 0 1 0 1
1 1 1 1 1 1 1 1
```
#include<cstdio>
using namespace std;
int a[1050][1050],n;
void cal(int x,int y,int n){
    if(n==0) a[x][y]=1;
    else{
        cal(x+(1<<n-1),y,n-1);
        cal(x,y+(1<<n-1),n-1);
        cal(x+(1<<n-1),y+(1<<n-1),n-1);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    cal(0,0,n);
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<1<<n;j++){
            printf("%d%c",a[i][j],j==(1<<n)-1?'\n':' ');
        }
    }
    return 0;
}

//7.9
# 【深基7.例9】最厉害的学生
## 题目描述
现有 $N$ 名同学参加了期末考试，并且获得了每名同学的信息：姓名（不超过 $8$ 个字符的仅有英文小写字母的字符串）、语文、数学、英语成绩（均为不超过 $150$ 的自然数）。总分最高的学生就是最厉害的，请输出最厉害的学生各项信息（姓名、各科成绩）。如果有多个总分相同的学生，输出靠前的那位。
## 输入格式
第一行输入一个正整数 $N$，表示学生个数。
第二行开始，往下 $N$ 行，对于每一行首先先输入一个字符串表示学生姓名，再输入三个自然数表示语文、数学、英语的成绩。均用空格相隔。
## 输出格式
输出最厉害的学生。
## 样例 #1
### 样例输入 #1

```
3
senpai 114 51 4
lxl 114 10 23
fafa 51 42 60
```
### 样例输出 #1
```
senpai 114 51 4
```
## 提示
数据保证，$1 \leq N \leq 1000$，姓名为长度不超过 $8$ 的字符串，语文、数学、英语成绩均为不超过 $150$ 的自然数。

#include<iostream>
#include<string>
using namespace std;
struct student{
    string name;
    int chinese,math,english;
}a,ans;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a.name>>a.chinese>>a.math>>a.english;
        if(a.chinese+a.math+a.english>ans.chinese+ans.math+ans.english||i==1)
            ans=a;
    }
    cout<<ans.name<<" "<<ans.chinese<<" "<<ans.math<<" "<<ans.english<<endl;
    return 0;
}

//7.10

# 【深基7.例10】旗鼓相当的对手 - 加强版
## 题目描述
现有 $N(N\le 1000)$ 名同学参加了期末考试，并且获得了每名同学的信息：姓名（不超过 $8$ 个字符的字符串，没有空格）、语文、数学、英语成绩（均为不超过 $150$ 的自然数）。如果某对学生 $\text{<}i,j\text{>}$ 的每一科成绩的分差都不大于 $5$，且总分分差不大于 $10$，那么这对学生就是“旗鼓相当的对手”。现在我们想知道这些同学中，哪些是“旗鼓相当的对手”？请输出他们的姓名。
所有人的姓名是按照字典序给出的，输出时也应该按照字典序输出所有对手组合。也就是说，这对组合的第一个名字的字典序应该小于第二个；如果两个组合中第一个名字不一样，则第一个名字字典序小的先输出；如果两个组合的第一个名字一样但第二个名字不同，则第二个名字字典序小的先输出。
## 输入格式
第一行输入一个正整数 $N$，表示学生个数。
第二行开始，往下 $N$ 行，对于每一行首先先输入一个字符串表示学生姓名，再输入三个自然数表示语文、数学、英语的成绩。均用空格相隔。
## 输出格式
输出若干行，每行两个以空格隔开的字符串，表示一组旗鼓相当的对手。注意题目描述中的输出格式。
## 样例 #1
### 样例输入 #1
```
3
fafa 90 90 90
lxl 95 85 90
senpai 100 80 91
```
### 样例输出 #1
```
fafa lxl
lxl senpai
```
## 提示
数据保证，$1 \leq N \leq 1000$，姓名为长度不超过 $8$ 的字符串，语文、数学、英语成绩均为不超过 $150$ 的自然数。

#include<iostream>
#include<string>
using namespace std;

int n, x, ans;
struct student {
    string name;
    int chinese, math, english;
};
struct student a[1024];
bool check(int x, int y, int z) {
    return x <= y + z && y <= x + z;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].chinese >> a[i].math >> a[i].english;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (check(a[i].chinese, a[j].chinese, 5)
                && check(a[i].math, a[j].math, 5)
                && check(a[i].english, a[j].english, 5)
                && check(a[i].chinese + a[i].math + a[i].english,
                    a[j].chinese + a[j].math + a[j].english, 10))
                cout << a[i].name << " " << a[j].name << " " << endl;
        }
    }
    return 0;
}
