1-1
1.翻译表达式
3x+5y=3*x+5*y
c+1/ab=(c+1)/(a*b)
根号下3a的3次幂：sqrt(3*pow(a,3))
(n+2)(n-9):(n+2)*(n-9)
2.下列变量名哪些合法：
kkksc03   OhILoveLuoguVeryMuch  _Iapple char kkk@SH  a   iPhone  11dimensions   __stdcall
char 非法
kkk@SH 非法
11dimensions非法
其余合法
                    变量名的命名规则如下：
                    变量名只能由字母（A-Z 或 a-z）、数字（0-9）和下划线（_）组成。
                    变量名不能以数字开头。
                    变量名不能是 C 语言的关键字或保留字（如 int、char、return 等）。
                    变量名对大小写敏感（如 a 和 A 是两个不同的变量名）。
3.运行part1-1中所有程序
4.编写程序：
4.1 3名同学3小时可以扫3间房间，9名同学9h可以扫干净几间教室
#include <iostream>
using namespace std;
int main() {
    // 定义变量
    int people = 9;       // 人数
    int hours = 9;        // 工作时间（小时）
    double efficiency = 1.0 / 3.0; // 每人每小时效率（间房间/人/小时）
    // 计算总工作量
    double totalRooms = people * hours * efficiency;
    // 输出结果
    cout << "9名同学9小时可以扫干净的教室数： " << totalRooms << " 间" << endl;
    return 0;
}

4.2 长方形长和宽之和为24cm,长比宽多4cm,求面积
#include <iostream>
using namespace std;
int main() {
    // 定义变量
    int perimeter = 24; // 长和宽的和
    int diff = 4;       // 长比宽多4cm
    int width, length, area;
    // 计算宽和长
    width = (perimeter - diff) / 2;
    length = width + diff;
    // 计算面积
    area = length * width;
    // 输出结果
    cout << "长方形的长为：" << length << " cm" << endl;
    cout << "长方形的宽为：" << width << " cm" << endl;
    cout << "长方形的面积为：" << area << " cm^2" << endl;
    return 0;
}

4.3 A和U在程序设计比赛中得分之和为480，U的得分是 A的1.4倍，请问，他们分别得了多少分？
#include<iostream>
using namespace std;
int main() {
	int a, u;
	a = 480 / 2.4;
	u = 480 - a;
	cout << a << " " << u;
	return 0;
}

4.4 分苹果，若每人分3个，则多11个；每人分4个，则少一个，问：几个同学？几个苹果？
#include <iostream>
using namespace std;
int main() {
    // 定义变量
    int students, apples;
    // 遍历求解
    for (int x = 1; x < 100; ++x) { // 假设同学数量在 1 到 100 内
        int y1 = 3 * x + 11; // 每人分3个苹果的总数
        int y2 = 4 * x - 1;  // 每人分4个苹果的总数
        if (y1 == y2) {      // 找到满足条件的解
            students = x;
            apples = y1; // 或 y2，结果一样
            break;
        }
    }
    // 输出结果
    cout << "共有 " << students << " 个同学。" << endl;
    cout << "共有 " << apples << " 个苹果。" << endl;

    return 0;
}

4.5 A每分钟输入120个字符，U每分钟输入80个字符，U比A先开始打字12min,问A开始打字后多久才能赶上U？
#include <iostream>
using namespace std;
int main() {
    // 定义变量
    int speedA = 120;  // A 每分钟输入的字符数
    int speedU = 80;   // U 每分钟输入的字符数
    int leadTimeU = 12; // U 早开始的时间（分钟）
    // 计算 A 开始打字后多久追上 U
    int timeToCatchUp = (speedU * leadTimeU) / (speedA - speedU);
    // 输出结果
    cout << "A 开始打字后 " << timeToCatchUp << " 分钟可以赶上 U。" << endl;
    return 0;
}

4.6 一个笼子有若干个兔子和鸡，有35个头，94只脚，问鸡兔各多少？
#include <iostream>
using namespace std;
int main() {
    // 定义变量
    int heads = 35; // 总头数
    int legs = 94;  // 总脚数
    // 枚举法求解（遍历鸡和兔的数量）
    for (int chickens = 0; chickens <= heads; ++chickens) {
        int rabbits = heads - chickens; // 兔子的数量
        // 判断是否满足脚的数量
        if (2 * chickens + 4 * rabbits == legs) {
            cout << "鸡的数量为: " << chickens << endl;
            cout << "兔子的数量为: " << rabbits << endl;
            break; // 找到答案后跳出循环
        }
    }
    return 0;
}

4.7 银行定期存款年利率是一年3.5%，五年定存4%，A和U手上各有10000元，A决定每次存一年期，到期后将连本带利再存一年，直到存五年。U直接存五年。请问五年后各有多少钱？
#include <iostream>
#include <cmath> // 用于幂运算
using namespace std;
int main() {
    // 初始本金
    double principalA = 10000.0; // A 的本金
    double principalU = 10000.0; // U 的本金
    // 利率
    double rateA = 0.035; // A 的年利率（3.5%）
    double rateU = 0.04;  // U 的五年期利率（4%）
    // A 的逐年存款计算
    for (int i = 0; i < 5; ++i) {
        principalA *= (1 + rateA);
    }
    // U 的五年期存款计算
    principalU *= pow(1 + rateU, 5);
    // 输出结果
    cout << "五年后 A 的总金额为: " << principalA << " 元" << endl;
    cout << "五年后 U 的总金额为: " << principalU << " 元" << endl;
    return 0;
}












