2.1 同1-1中
2.2
#include<cstdio>
#include<cmath>
int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1f", s);
    return 0;
}
2.3 略
2.4
        0
        0.9999998808
2.5
  #include<cstdio>
    int main(){
        int a,b;
        scanf("%d %d",&a,&b);
        int c=(10*a+b)/19;
        printf("%d",c);
        return 0;
    }
2.6
  #include<bits/stdc++.h>//万能头文件
using namespace std;
int m,t,s;
int main()
{
	cin>>m>>t>>s;
	if(t==0)//特判t=0的情况
	{
		cout<<0<<endl;
		return 0;
	}
	if(s%t==0)//如果s是t的整数倍
		cout<<max(m-s/t,0)<<endl;
	else//如果不是
		cout<<max(m-s/t-1,0)<<endl;
	return 0;//程序结束
}
2.7
  
