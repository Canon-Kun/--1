#include<iostream>
#include<string>
#include"mainStreen.h"
#include"list.h"
using namespace std;
void add();//���ѧ����Ϣ
void displaySingle();//��ʾ����ѧ����Ϣ��
void displayAll();//��ʾ����ѧ����Ϣ������
void find();//����ѧ����Ϣ
void del();//ɾ��ָ��λ����Ϣ
void update();//����ָ��λ����Ϣ
void stats();//ͳ������
void clear();//��ʽ��
void Sort(SqList<student> &L);//�����㷨
SqList<student> stulist;
student stu;
int main(){
	display();
	int n;cin>>n;//����ѡ��
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
	cout<<"ѧ��������Ϊ��"<<stu.name<<endl;
	cout<<"ѧ�ţ�"<<stu.num<<endl;
	cout<<"����"<<stu.grade<<endl;
	cout<<endl;
}
void displayAll(){
	stulist.Traverse(displaySingle);
}
void add(){

cout<<"����ѧ����Ϣ"<<endl;
cout<<"������";
cin>>stu.name;
cout<<"ѧ�ţ�";
cin>>stu.num;
cout<<"���㣺";
cin>>stu.grade;
int a = stulist.InsertElem(stu);
if(a==1) cout<<"��ӳɹ�"<<endl;
else cout<<"���ʧ��"<<endl;
}


void find(){
	cout<<"���ҵڼ���ѽС�ɰ���"<<endl;
	int n;
	cin>>n;
	cout<<endl;
	cout<<"��"<<n<<"��ѧ������Ϣ����"<<endl;
	cout<<"������";
	cout<<stulist.GetElem(n).name<<endl;
	cout<<"ѧ�ţ�";
	cout<<stulist.GetElem(n).num<<endl;
	cout<<"���㣺";
	cout<<stulist.GetElem(n).grade<<endl;
	cout<<endl;
}

void del(){
	cout<<"����ɾ���ڼ�������С�ɰ���"<<endl;
	int n;
	cin>>n;
	stulist.DeleteElem(n);
	cout<<"ɾ��������£�"<<endl;
	cout<<endl;
	displayAll();

}
void update(){
	cout<<"������µڼ�������С�ɰ���"<<endl;
	int n;
	student temp;
	cin>>n;
	cout<<"������ϢΪ��"<<endl;
	cout<<"������";
	cin>>temp.name;
	cout<<"ѧ�ţ�";
	cin>>temp.num;
	cout<<"���㣺";
	cin>>temp.grade;
	stulist.SetElem(n,temp);
	cout<<endl;
	cout<<"���½������"<<endl;
	displayAll();

}
void stats(){
	cout<<"ѧ��������Ϊ:  ";
	cout<<stulist.GetLength()<<"��"<<endl;
}
void clear(){

	stulist.Clear();
	cout<<"��ʽ���ɹ�"<<endl;
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
				//����i,j����λ�õ����ݳ�Ա
				L.SetElem(i, J);
				L.SetElem(j, I);
				I = J;
			}
		}
	}
	cout<<"�������"<<endl;
}