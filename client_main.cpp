#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;


#define BUFFER_SIZE 1024
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

struct message1
{
    int func=0;//操作数
    string BIGSTR[10];//信息
};

//添加新警员
void inpolice(struct message *p)
{
    (*p).func=1;
    cout<<"添加警员"<<endl;
    cout<<"输入姓名：";
    cin >>(*p).PerNam;
    cout<<"输入身份证：";
    cin>>(*p).PerNum;
    cout<<"输入性别：";
    cin >>(*p).sex;
    cout<<"输入警号：";
    cin >>(*p).WPNum;
    cout<<"输入警衔值：";
    cin >>(*p).RaNum;
    cout<<endl;
}
//添加新工作对象
void inworkob(struct message *p)
{
    (*p).func=2;
    cout<<"添加工作对象"<<endl;
    cout<<"输入姓名：";
    cin >>(*p).PerNam;
    cout<<"输入身份证：";
    cin>>(*p).PerNum;
    cout<<"输入性别：";
    cin >>(*p).sex;
    cout<<"输入识别号：";
    cin >>(*p).WPNum;
    cout<<endl;
}
//添加新团队
void inteam(struct message *p)
{
    (*p).func=3;
    cout<<"添加团队"<<endl;
    cout<<"输入团队名：";
    cin >>(*p).TeaNa;
    cout<<"输入负责人（警号）：";
    cin>>(*p).WPNum;
    cout<<endl;
}
//添加新案件
void incase(struct message *p)
{
    (*p).func=4;
    cout<<"添加案件"<<endl;
    cout<<"输入案件名：";
    cin >>(*p).CaNa;
    cout<<"输入案件号：";
    cin >>(*p).CaNu;
    cout<<"输入负责人（警号）：";
    cin>>(*p).WPNum;
    cout<<"输入办案团队号：";
    cin>>(*p).TeaNu;
    cout<<endl;
}
//将警员加入团队
void inPtoT(struct message *p)
{
    (*p).func=5;
    cout<<"将警员添加进团队"<<endl;
    cout<<"输入警号：";
    cin >>(*p).WPNum;
    cout<<"输入团队号：";
    cin >>(*p).TeaNu;
    cout<<endl;
}
//将工作对象加入案件
void inWtoC(struct message *p)
{
    (*p).func=6;
    cout<<"将工作对象添加进案件"<<endl;
    cout<<"输入工作对象识别号：";
    cin >>(*p).WPNum;
    cout<<"输入团队号：";
    cin >>(*p).CaNu;
    cout<<endl;
}
//显示团队成员
void selmem(struct message *p)
{
    (*p).func=7;
    cout<<"输入要查找的团队名：";
    cin >>(*p).TeaNa;
    cout<<endl;
}
//显示案件相关人员
void selcasework(struct message *p)
{
    (*p).func=8;
    cout<<"输入要查找的案件名：";
    cin >>(*p).CaNa;
    cout<<endl;
}
//显示警员
void shopo(struct message *p)
{
    (*p).func=9;
    cout<<endl;
}
//显示工作对象
void showo(struct message *p)
{
    (*p).func=10;
    cout<<endl;
}
//显示案件
void shoca(struct message *p)
{
    (*p).func=11;
    cout<<endl;
}
//显示团队
void shotea(struct message *p)
{
    (*p).func=12;
    cout<<(*p).func<<endl;
}

void showmessage(struct message1 *p)
{
    int funcID=(*p).func;

    switch (funcID)
    {
    case 7:cout<<"团队成员:"<<endl;break;
    case 8:cout<<"案件相关人员:"<<endl;break;
    case 9:cout<<"警员:"<<endl;break;
    case 10:cout<<"工作对象:"<<endl;break;
    case 11:cout<<"案件:"<<endl;break;
    case 12:cout<<"团队:"<<endl;break;
    default:cout<<"非法操作字"<<endl;break;
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<(*p).BIGSTR[i]<<endl;
        if(sizeof((*p).BIGSTR[i+1]) == 0) break;
    }
    
}

int main(){
    
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    
    message *p_min=(message*)malloc(sizeof(message)); //发送的消息
    message1 *p_mou=(message1*)malloc(sizeof(message1)); //接受的消息
    char ch;
    while(1)
    {
        //创建套接字
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        
        cout<<"根据提示输入操作字"<<endl;
        cout<<"a.添加新警员"<<endl;
        cout<<"b.添加新工作对象"<<endl;
        cout<<"c.添加新团队"<<endl;
        cout<<"d.添加新案件"<<endl;
        cout<<"e.将警员加入团队"<<endl;
        cout<<"f.将工作对象加入案件"<<endl;
        cout<<"g.显示团队成员"<<endl;
        cout<<"h.显示案件相关人员"<<endl;
        cout<<"i.显示警员"<<endl;
        cout<<"j.显示工作对象"<<endl;
        cout<<"k.显示案件"<<endl;
        cout<<"l.显示团队"<<endl;
        cout<<"z.退出程序"<<endl;
        cin>>ch;
        cout<<endl;
        switch (ch)
        {
            case 'a':inpolice(p_min);break;
            case 'b':inworkob(p_min);break;
            case 'c':inteam(p_min);break;
            case 'd':incase(p_min);break;
            case 'e':inPtoT(p_min);break;
            case 'f':inWtoC(p_min);break;
            case 'g':selmem(p_min);break;
            case 'h':selcasework(p_min);break;
            case 'i':shopo(p_min);break;
            case 'j':showo(p_min);break;
            case 'k':shoca(p_min);break;
            case 'l':shotea(p_min);break;
            case 'z':{
            close(sock);//关闭套接字
            delete(p_min);
            cout<<"Bye!"<<endl;
            return 0;
            break;}
            default:cout<<"非法操作字"<<endl;break;
        }
        //尝试
        
        int needSend=sizeof(message);
        char *buffer=(char*)malloc(needSend);
        memcpy(buffer,p_min,needSend);

        int pos=0;
        int len=0;
        while(pos < needSend)
        {
            len=send(sock, buffer+pos, BUFFER_SIZE,0);
            if(len <= 0)
            {
                perror("ERRPR");
                break;
            }
            pos+=len;
        }

        int needRecv=sizeof(message1);
        char *buffer=(char*)malloc(needRecv);
        
        int pos2=0;
        int len2;
        while(pos2 < needRecv)
        {
            len = recv(sock, buffer+pos, BUFFER_SIZE, 0);
            if (len2 < 0)
            {
                printf("Server Recieve Data Failed!\n");
                break;
            }
            pos2+=len2;

        }

        memcpy(p_mou,buffer,needRecv);
        showmessage(p_mou);

        free(buffer);
        free(p_min);
        free(p_mou);
        close(sock);



        return 0;
    }
}