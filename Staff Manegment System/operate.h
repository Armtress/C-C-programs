#pragma once
#include<iostream>
#include<mysql.h>


//学生类，学生只能查询考勤的信息
class student {
public:
	bool csu(MYSQL mysql);//查询
};

//教师类，教师可以编辑，查询考勤表
class teacher {
public:
	bool alt(MYSQL mysql);//录入考勤信息
	bool add(MYSQL mysql);//新增一个课程班级
	bool csu(MYSQL mysql);//按某个班级或者某个学生，查询考勤情况。
};

//管理员类，管理员可以操纵整个数据库
class ad {
public:
	bool alt(MYSQL mysql);//修改某个表中的某条数据
	bool add(MYSQL mysql);//新增某个表中的一条数据
	bool del(MYSQL mysql);//删除某个表中的某条数据
	bool csu(MYSQL mysql);//查询某个表中的某条数据
};
