#include<iostream>
#include<string>
#include"mainStreen.h"
#include"list.h"
using namespace std;
void add();//添加学生信息
void displaySingle();//显示单个学生信息；
void displayAll();//显示所有学生信息的声明
void find();//查找学生信息
void del();//删除指定位置信息
void update();//更新指定位置信息
void stats();//统计人数
void clear();//格式化
void Sort(SqList<student> &L);//排序算法
SqList<student> stulist;
student stu;
int main(){
	display();
	int n;cin>>n;//输入选项
	while(n!=0){
		
		switch(n){
	    case 1: displayAll() ; break;
		case 2 :add();break;
		case 3:find();break;
		case 4:del();break;
		case 5:update();break;
		case 6:stats();break;
		case 7:Sort(stulist);break;
		case 8:clear();break;
	}
		display();
		cin>>n;
	}
		system("pause");
	return 0;
}


void displaySingle(const student& stu){
	cout<<"学生的姓名为："<<stu.name<<endl;
	cout<<"学号："<<stu.num<<endl;
	cout<<"绩点"<<stu.grade<<endl;
	cout<<endl;
}
void displayAll(){
	stulist.Traverse(displaySingle);
}
void add(){

cout<<"输入学生信息"<<endl;
cout<<"姓名：";
cin>>stu.name;
cout<<"学号：";
cin>>stu.num;
cout<<"绩点：";
cin>>stu.grade;
int a = stulist.InsertElem(stu);
if(a==1) cout<<"添加成功"<<endl;
else cout<<"添加失败"<<endl;
}


void find(){
	cout<<"你找第几个呀小可爱？"<<endl;
	int n;
	cin>>n;
	cout<<endl;
	cout<<"第"<<n<<"个学生的信息如下"<<endl;
	cout<<"姓名：";
	cout<<stulist.GetElem(n).name<<endl;
	cout<<"学号：";
	cout<<stulist.GetElem(n).num<<endl;
	cout<<"绩点：";
	cout<<stulist.GetElem(n).grade<<endl;
	cout<<endl;
}

void del(){
	cout<<"你想删除第几个啊，小可爱？"<<endl;
	int n;
	cin>>n;
	stulist.DeleteElem(n);
	cout<<"删除结果如下："<<endl;
	cout<<endl;
	displayAll();

}
void update(){
	cout<<"你想更新第几个啊，小可爱？"<<endl;
	int n;
	student temp;
	cin>>n;
	cout<<"更新信息为："<<endl;
	cout<<"姓名：";
	cin>>temp.name;
	cout<<"学号：";
	cin>>temp.num;
	cout<<"绩点：";
	cin>>temp.grade;
	stulist.SetElem(n,temp);
	cout<<endl;
	cout<<"更新结果如下"<<endl;
	displayAll();

}
void stats(){
	cout<<"学生总人数为:  ";
	cout<<stulist.GetLength()<<"人"<<endl;
}
void clear(){

	stulist.Clear();
	cout<<"格式化成功"<<endl;
}
void Sort(SqList<student> &L)
{
	student I;
	student J;
	for (int i = 1; i <= L.GetLength(); i++)
	{
		I = L.GetElem(i);
		for (int j = i + 1; j <= L.GetLength(); j++)
		{
			J = L.GetElem(j);
			if (J.grade < I.grade) 
			{
				//交换i,j两个位置的数据成员
				L.SetElem(i, J);
				L.SetElem(j, I);
				I = J;
			}
		}
	}
	cout<<"排序完成"<<endl;
}