#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
// ANSI C++标准库头文件
#include <cstring>					// 标准串操作
#include <iostream>					// 标准流操作
using namespace std;				
#define DEFAULT_SIZE 100
// 顺序栈模板类
template<class ElemType>
class SqStack 
{
protected:
// 顺序栈的数据成员:
	int top;										// 栈顶指针 
	int maxSize;									// 栈的最大容量 
	ElemType *data;								// 元素存储空间
public:
//  顺序栈的方法声明及重载编译系统默认方法声明:
	SqStack();				// 构造函数
	
	int getLength() const;							// 求栈的长度			 
	bool isEmpty() ;							// 判断栈是否为空
	void clear();									// 将栈清空
	void traverse(void (*Visit)(const ElemType &)) const;	// 遍历栈
	int push(const ElemType e);				    // 入栈
	ElemType getTop() const;				    // 取顶元素
	ElemType pop() ;					    // 出栈
	SqStack(const SqStack<ElemType> &s);		// 复制构造函数
	SqStack<ElemType> &operator =(const SqStack<ElemType> &s); // 赋值语句重载
};

//构造函数
template<class ElemType>
SqStack<ElemType>::SqStack(){
	int size = DEFAULT_SIZE;
	top = -1;
	maxSize = size;
	data = new ElemType[size];
}

//求栈的长度
template<class ElemType>
int SqStack<ElemType>::getLength() const{return top+1;}
//判断栈是否为空
template<class ElemType>
bool SqStack<ElemType>::isEmpty(){if(top==-1) return true;
else return false;
}
//将栈清空
template<class ElemType>
void SqStack<ElemType>::clear(){
	while(top!=-1){
		top--;
		delete data[top];
	}
}
//遍历栈内元素
template<class ElemType>
void SqStack<ElemType>::traverse(void (*Visit)(const ElemType &)) const{
	if(top==-1){cout<<"空表"<<endl;}
	for(int i=top ; i>-1;i--){
		Visit(data[i]);
	}
}
//入栈
template<class ElemType>
int SqStack<ElemType>::push(const ElemType e){
	data[++top] = e;
	return 1;
}
//取顶元素
template<class ElemType>
ElemType SqStack<ElemType>::getTop() const{
	ElemType e = data[top];
	return e;
}
//出栈
template<class ElemType>
ElemType SqStack<ElemType>::pop() {
	ElemType e;
	e = data[top];
	top--;
	return e;
}
//复制构造函数
template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &s){
	top = s.top;
	while(s.top!=-1&&top!=-1){
		data[top] = s.data[s.top];
		top--;s.top--;
	}
}
//赋值语句重载
template<class ElemType>
SqStack<ElemType>& SqStack<ElemType>::operator=(const SqStack<ElemType> &s){
	SqStack<ElemTyep> a;
	a.top = s.top;
	while(s.top!=-1&&a.top!=-1){
		a.data[top] = s.data[s.top];
		a.top--;s.top--;
	}
	return a;
}
#endif
