#pragma once
#include<iostream>
#include<mysql.h>


//ѧ���࣬ѧ��ֻ�ܲ�ѯ���ڵ���Ϣ
class student {
public:
	bool csu(MYSQL mysql);//��ѯ
};

//��ʦ�࣬��ʦ���Ա༭����ѯ���ڱ�
class teacher {
public:
	bool alt(MYSQL mysql);//¼�뿼����Ϣ
	bool add(MYSQL mysql);//����һ���γ̰༶
	bool csu(MYSQL mysql);//��ĳ���༶����ĳ��ѧ������ѯ���������
};

//����Ա�࣬����Ա���Բ����������ݿ�
class ad {
public:
	bool alt(MYSQL mysql);//�޸�ĳ�����е�ĳ������
	bool add(MYSQL mysql);//����ĳ�����е�һ������
	bool del(MYSQL mysql);//ɾ��ĳ�����е�ĳ������
	bool csu(MYSQL mysql);//��ѯĳ�����е�ĳ������
};
