#include <iostream>
#include"operate.h"
using namespace std;

int main() {
    cout << "-----------------------��ӭ��-----------------------\n";

    cout << "������������\n1. ѧ��\n2. ��ʦ\n3. ����Ա\n";
    int x;
    cin >> x;

    if (x != 1 && x != 2 && x != 3) 
    {
        cout << "����������������˳�ϵͳ....\n";
        return 0;
    }

    
    MYSQL mysql;    //����mysql����
    //���䣬��ʼ��MYSQL����
    if (mysql_init(&mysql) == NULL)
    {
        cout << "mysql_init():" << mysql_error(&mysql) << endl;
        return -1;
    }
    char password[20];
    cout << "�������������\n";
    cin >> password ;
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", password, "attendance", 3306, NULL, 0) == NULL)
    {
        cout << "mysql_real_connect():" << mysql_error(&mysql) << endl;
        return -1;
    }
    system("cls");
    cout << "�ɹ����ӵ����ݿ� \n";
    
    switch (x) {
    case 1:
        student s;
        while (1) {
            cout << "-----------------------�����б�-----------------------\n"
                << "1. ��ѯ������Ϣ����\n"  << "2. �˳�ϵͳ\n";
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
                cout << "�����������,����������\n";
                break;
            }
            system("pause");
            system("cls");
        }
        break;

    case 2:
        teacher t;
        while (1) {
            cout << "-----------------------�����б�-----------------------\n"
                << "1. ¼�뿼����Ϣ\n" << "2. ����һ���γ̰༶\n"<<"3. ��ĳ���༶����ĳ��ѧ������ѯ�������\n"<<"4. �˳�ϵͳ\n";
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
                cout << "�����������,����������\n";
                break;
            }

            system("pause");
            system("cls");
        }
        break;

    case 3:
        ad ad;
        while (1) {
            cout << "-----------------------�����б�-----------------------\n"
                << "1. �޸�ĳ�����е�ĳ������\n" << "2. ����ĳ�����е�һ������\n" << "3. ɾ��ĳ�����е�ĳ������\n" << "4. ��ѯĳ�����е�ĳ������\n"<<"5. �˳�ϵͳ\n";
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
                cout << "�����������,����������\n";
                break;
            }
            system("pause");
            system("cls");
        }
        break;
    }

    return 0;
}