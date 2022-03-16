#include <iostream>
using namespace std;
#include<stdio.h>

struct message
{
    int func=0;//操作数
    string PerNam;//姓名
    string PerNum;//身份证
    string sex;//性别
    string WPNum;//警号或识别号
    string RaNam;//警衔
    int RaNum=0;//警衔值
    string Story;//详细
    string CaNa;//案件名
    string CaNu;//案件号
    string TeaNa;//团队名
    string TeaNu;//团队号
};

struct stud
{
	int num;
	char sub;
};

void fun_1(struct stud *a)
{
    cout<<"输入1：";
    cin>>a->num;
    cout<<"输入2：";
    cin>>(*a).sub;
}

void fun_2(struct stud *a)
{
    cout<<(*a).num<<endl;
    cout<<(*a).sub<<endl;
}

int main()
{
/*	struct stud m;
    stud *p=&m;
    
    

    char ch;
    while(1)
    {
        cout<<"tital"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 'a':
            fun_1(p);
            break;
        case 'b':
            fun_2(p);
            break;
        case 'c':
            cout<<"Bye!"<<endl;
            return 0;
            break;
        default:cout<<"非法操作字";
            break;
        }
    }
    */
    struct message m;
    int size = sizeof(m.func);
    cout<<size<<endl;

    return 0;
}