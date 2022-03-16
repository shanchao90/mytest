#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <mysql/mysql.h>

using namespace std;
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
class person
{
public:
   person(int si,int pi,string pn):sysid (si),perid(pi),perName (pn){}
   
   int re_idsys() const { return sysid;}//返回ID
   int re_idper() const { return perid;}//返回身份证
   string re_perName () const {return perName;}//返回姓名
   void re_all();//返回所有
   void ins();//增 to db
   void del();//删
   void upd();//改
   void sel();//查

private:
   int sysid;//系统内ID
   int perid;//身份证
   string perName;//姓名 
};

inline void person::re_all(){

}

class casebase
{
public:

private:

};

class MysqlDB
{
private:
    MYSQL mysql;
    MYSQL_ROW row;
    MYSQL_RES *result;
    MYSQL_FIELD *field;
public:
    MysqlDB()
    {
        if( mysql_init( &mysql ) == NULL )
        {
            cout << "init error, line: " << __LINE__ << endl;
            exit(-1);
        }
    }
    ~MysqlDB()
    {
        mysql_close( &mysql );
    }
    void connect( string host, string user, string passwd,  string database )
    {
        //成功返回MYSQL指向的指针，失败返回NULL
        if( !mysql_real_connect( &mysql, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0 ) )
        {
            cout << "connect error, line: " << __LINE__ << endl;
            exit(-1);
        }
    }
    void add();
    void del();
    void update();
    void print();
};

void MysqlDB::add()
{
    string id, name, sex, birthday;
    do
    {
        cout << "请输入学生信息:\n";
        cin >> id >> name >> sex >> birthday;
        string sql = "insert into stu values('" + id + "', '" + name + "', '" + sex + "', '" + birthday + "');";
        cout << sql << endl;
        mysql_query( &mysql, sql.c_str() );
        cout << "是否继续（y/n）: ";
        cin >> id;
    } while( id == "y" );
}

void MysqlDB::del()
{
    string id;
    do
    {
        cout << "请输入删除学生信息的ID:\n";
        cin >> id;
        string sql = "delete from stu where id='" + id +"';";
        cout << sql << endl;
        mysql_query( &mysql, sql.c_str() );
        cout << "是否继续（y/n）: ";
        cin >> id;
    } while( id == "y" );
}

void MysqlDB::update()
{
    string id, filed,value;
    do
    {
        cout << "请输入修改学生信息ID，字段，值:\n";
        cin >> id >> filed >> value;
        //update myclass set name="张大仙" where id='1230011';
        string sql = "update stu set " + filed +"='" + value + "' where ID='" + id + "';";
        cout << sql << endl;
        mysql_query( &mysql, sql.c_str() );
        cout << "是否继续（y/n）: ";
        cin >> id;
    } while( id == "y" );
}

void MysqlDB::print()
{
    // string sql = "select * from info where name = '" + name + "';";  //要有''
    string sql = "select * from stu;";
    //成功返回0
    mysql_query( &mysql, sql.c_str() );
    //获取查询查询结果；成功返回result的指针，失败返回NULL
    result = mysql_store_result( &mysql );
    if( !result )
    {
        cout << "result error, line : " << __LINE__ << endl;
        return ;
    }

    int num;
    num = mysql_num_fields( result );  //返回字段个数
    for( int i = 0; i < num; i++ )
    {
        field = mysql_fetch_field_direct( result, i );  //返回字段类型
        cout << field->name << "\t\t";  //输出字段名
    }
    cout << endl;

    while( row = mysql_fetch_row( result ), row  != NULL )
    {
        for( int i = 0; i < num; i++ )
        {
            cout << row[i] << "\t\t";
        }
        cout << endl;
    }
}


int main(int argc,char *argv[])
{
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);



    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    //向客户端发送数据
    char str[] = "Hello World!";
    write(clnt_sock, str, sizeof(str));
   

    //关闭套接字
    close(clnt_sock);
    close(serv_sock);

    string s;

    while(1)
    {
        person p1(1,1,"1");
        person* p = & p1;
        write(clnt_sock, p, sizeof(str));
    }


    MysqlDB db;
    db.connect( "localhost", "root", "cnp200@HW", "student" );
    db.print();

    db.add();
    db.print();

    db.update();
    db.print();

    db.del();
    db.print();

    return 0;




    return 0;
}
