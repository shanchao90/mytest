#include <iostream>
using namespace std;
#include<stdio.h>
 
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
	struct stud m;
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
    return 0;
}