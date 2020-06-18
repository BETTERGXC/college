//A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
//A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
//现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。



#include<iostream>
using namespace std;
 
int main()
{   int a, b, c, d;
    int A, B, C;
    while(cin>>a>>b>>c>>d)
    {
        A=(a+c)/2;
        B=(b+d)/2;
        C=(d-b)/2;
        if(A-B==a && B-C==b && A+B==c && B+C==d)
        {
            cout<<A<<" "<<B<<" "<<C<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}