#include <iostream>
#include"operate.h"
using namespace std;

int main() {
    cout << "-----------------------欢迎！-----------------------\n";

    cout << "请输入你的身份\n1. 学生\n2. 教师\n3. 管理员\n";
    int x;
    cin >> x;

    if (x != 1 && x != 2 && x != 3) 
    {
        cout << "你的输入有误，正在退出系统....\n";
        return 0;
    }

    
    MYSQL mysql;    //定义mysql对象
    //分配，初始化MYSQL对象
    if (mysql_init(&mysql) == NULL)
    {
        cout << "mysql_init():" << mysql_error(&mysql) << endl;
        return -1;
    }
    char password[20];
    cout << "请输入你的密码\n";
    cin >> password ;
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", password, "attendance", 3306, NULL, 0) == NULL)
    {
        cout << "mysql_real_connect():" << mysql_error(&mysql) << endl;
        return -1;
    }
    system("cls");
    cout << "成功连接到数据库 \n";
    
    switch (x) {
    case 1:
        student s;
        while (1) {
            cout << "-----------------------功能列表-----------------------\n"
                << "1. 查询考勤信息数据\n"  << "2. 退出系统\n";
            int a;
            cin >> a;
            switch (a) {
            case 1:
                cout << "\n";
                s.csu(mysql);
                break;
            case 2:
                cout << "\n";
                mysql_close(&mysql);
                return 0;
            default:
                cout << "你的输入有误,请重新输入\n";
                break;
            }
            system("pause");
            system("cls");
        }
        break;

    case 2:
        teacher t;
        while (1) {
            cout << "-----------------------功能列表-----------------------\n"
                << "1. 录入考勤信息\n" << "2. 新增一个课程班级\n"<<"3. 按某个班级或者某个学生，查询考勤情况\n"<<"4. 退出系统\n";
            int a;
            cin >> a;
            switch (a) {
            case 1:
                cout << "\n";
                t.alt(mysql);
                break;
            case 2:
                t.add(mysql);
                break;
            case 3:
                t.csu(mysql);
                break;
            case 4:
                cout << "\n";
                mysql_close(&mysql);
                return 0;
            default:
                cout << "你的输入有误,请重新输入\n";
                break;
            }

            system("pause");
            system("cls");
        }
        break;

    case 3:
        ad ad;
        while (1) {
            cout << "-----------------------功能列表-----------------------\n"
                << "1. 修改某个表中的某条数据\n" << "2. 新增某个表中的一条数据\n" << "3. 删除某个表中的某条数据\n" << "4. 查询某个表中的某条数据\n"<<"5. 退出系统\n";
            int a;
            cin >> a;
            switch (a) {
            case 1:
                cout << "\n";
                ad.alt(mysql);
                break;
            case 2:
                ad.add(mysql);
                break;
            case 3:
                ad.del(mysql);
                break;
            case 4:
                ad.csu(mysql);
                break;
            case 5:
                cout << "\n";
                mysql_close(&mysql);
                return 0;
            default:
                cout << "你的输入有误,请重新输入\n";
                break;
            }
            system("pause");
            system("cls");
        }
        break;
    }

    return 0;
}