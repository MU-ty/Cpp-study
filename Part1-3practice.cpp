3.1-3.3 略
3.4 注意四舍五入
#include<iostream>
#include <iomanip> //使用了 iomanip 库中的 setprecision(1) 和 fixed 来确保输出保留一位小数。
using namespace std;
int main(){
    int a;
    double fee;
    cin>>a;
    if(a<=150){
        fee=a*0.4463;
    }
    else if(a>150&&a<=400){
        fee=0.4463*150+(a-150)*0.4663;
    }
    else{
        fee=0.4463*150+250*0.4663+(a-400)*0.5663;
    }
    cout << fixed << setprecision(1) << fee << endl;
    return 0;
}
//也可使用int((fee * 10) + 0.5) / 10.0
//将 fee 乘以 10（把小数点右移一位）。加上 0.5，确保对原始值进行四舍五入。将结果转换为整数（去除小数部分）。然后再除以 10.0，将小数点移回来。

3.5
#include<iostream>
using namespace std;

int main() {
    int x;   // 起始星期几
    long int n;  // 总天数
    cin >> x >> n;

    // 计算开始的星期几后经过n天的总天数，排除周末的天数
    long int workDays = 0;  // 工作日数
    long int totalWeeks = n / 7;  // 完整的周数
    long int remainingDays = n % 7;  // 剩余的天数

    // 每周有5天工作日
    workDays = totalWeeks * 5;

    // 计算剩余天数中的工作日数
    for (int i = 0; i < remainingDays; ++i) {
        int currentDay = (x + i - 1) % 7 + 1;  // 当前天是星期几
        if (currentDay <= 5) {  // 如果是工作日
            workDays++;
        }
    }

    // 每个工作日游泳250公里
    cout << workDays * 250 << endl;

    return 0;
}

3.6
#include<bits/stdc++.h>
using namespace std;
int a, b, c, s, x;
int z = 1; 
int main() {
    cin >> a >> b >> c;
    s = min(a, min(b, c));
    x = max(a, max(b, c));
    for (int i = 2; i <=s; i++) {
        if (s % i == 0 && x % i == 0) {
            z = i;
        }
    }
    cout << s / z << "/" << x / z;
    return 0;
}

3.7
#include<cstdio>
using namespace std;
int main(){
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int h;
    scanf("%d",&h);
    int count=0;
    for(int i=0;i<10;i++){
        if(a[i]<=h+30) count++;
    }
    printf("%d",count);
    return 0;
}

3.8
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>=b) swap(a,b);
    if(a>=c) swap(a,c);
    if(b>=c) swap(b,c);
    
    if(a+b<=c){
        cout<<"Not triangle"<<endl;
    }else{
        if(a*a+b*b==c*c)  cout<<"Right triangle"<<endl;
        else if(a*a+b*b>c*c)  cout<<"Acute triangle"<<endl;
        else  cout<<"Obtuse triangle"<<endl;
        if(a==b||b==c||a==c)   cout<<"Isosceles triangle"<<endl;
        if(a == b && b == c)  cout<<"Equilateral triangle"<<endl;
    }
    return 0;
}

3.9
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 读取输入
    int A, B, C;
    cin >> A >> B >> C;
    string order;
    cin >> order;

    // 将数字存储在一个vector中，并排序
    vector<int> numbers = {A, B, C};
    sort(numbers.begin(), numbers.end());

    // 输出按字母顺序排列的数字
    for (char c : order) {
        if (c == 'A') {
            cout << numbers[0] << " ";
        } else if (c == 'B') {
            cout << numbers[1] << " ";
        } else if (c == 'C') {
            cout << numbers[2] << " ";
        }
    }
    cout << endl;

    return 0;
}


这段代码的目的是根据输入的字母顺序，输出三个整数按照指定顺序排列后的结果。下面我们逐行解析代码的实现：
1. 引入头文件和命名空间
#include <iostream>：引入 C++ 标准输入输出库，用于读取输入和输出结果。
#include <vector>：引入 vector 容器类，用于存储数字。
#include <algorithm>：引入算法库，这里用来排序数字。
using namespace std;：使用标准命名空间，省去每次调用标准库成员时写 std:: 前缀。
2. 主函数开始
int A, B, C;：定义三个整数 A, B, C 用于存储输入的三个数字。
cin >> A >> B >> C;：读取这三个整数。
string order;：定义一个字符串 order，用于存储按字母顺序排列的三个字母（如 ABC 或 CAB）。
cin >> order;：读取字母顺序字符串。
3. 将数字存储在一个 vector 中并排序
vector<int> numbers = {A, B, C};：创建一个整数类型的 vector 容器，并将 A, B, C 存入其中。
sort(numbers.begin(), numbers.end());：对 numbers 向量进行排序，sort 函数会按升序排序这三个整数，确保 numbers 中的元素按从小到大的顺序排列。排序后，numbers[0] 存储最小的数字，numbers[1] 存储第二小的数字，numbers[2] 存储最大的数字。
4. 根据字母顺序输出数字
for (char c : order)：循环遍历 order 字符串中的每个字符，c 为当前字符。
if (c == 'A') { cout << numbers[0] << " "; }：如果当前字符是 A，则输出排序后的最小数字 numbers[0]。
else if (c == 'B') { cout << numbers[1] << " "; }：如果当前字符是 B，则输出排序后的第二小数字 numbers[1]。
else if (c == 'C') { cout << numbers[2] << " "; }：如果当前字符是 C，则输出排序后的最大数字 numbers[2]。
cout << endl;：输出换行，结束输出。
5. 返回 0
return 0;：表示程序正常结束，返回操作系统。
总结
输入包括三个整数和一个字母顺序字符串。整数先排序，然后根据字母顺序输出相应的整数。
使用 vector 存储数字并利用 sort 排序，确保数字顺序为升序。
根据输入的字母顺序，选择相应的数字进行输出。
