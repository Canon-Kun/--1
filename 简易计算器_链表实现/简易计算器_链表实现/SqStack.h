#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
// ANSI C++标准库头文件
#include <cstring>
#include"Node.h"				// 标准串操作
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
								 
	Node<ElemType> *head;					
public:
//  顺序栈的方法声明及重载编译系统默认方法声明:
	SqStack();				// 构造函数
	int getLength() const;							// 求栈的长度			 
	bool isEmpty() ;							// 判断栈是否为空
	void clear();									// 将栈清空
	void traverse(void (*Visit)(const ElemType &)) const;	// 遍历栈
	int push(const ElemType e);				    // 入栈
	ElemType getTop();				    // 取顶元素
	ElemType pop();					    // 出栈
	SqStack(const SqStack<ElemType> &s);		// 复制构造函数
	SqStack<ElemType> &operator =(const SqStack<ElemType> &s); // 赋值语句重载
};
//构造函数
template<class ElemType>
SqStack<ElemType>::SqStack(){
	top=-1;
	head = new Node<ElemType>;
	head->next = NULL;
	
}
//求栈的长度
template<class ElemType>
int SqStack<ElemType>::getLength() const{
	return top+1;
}
//判断栈是否为空
template<class ElemType>
bool SqStack<ElemType>::isEmpty() {if(top==-1) return true;else return false;}
//遍历栈
template<class ElemType>
void SqStack<ElemType>::traverse(void (*Visit)(const ElemType &)) const{
	Node<ElemType> *p = head;
	while(p){Visit(p->data),p=p->next}
}
//入栈
template<class ElemType>
int SqStack<ElemType>::push(const ElemType e){
	Node<ElemType> *p = head;
	Node<ElemType> *q = new Node<ElemType> ;
	if(p->next==NULL){
		q->data = e;
		q->next = NULL;
		p->next=q;
		top++;
		return 1;
	}
	while(p->next!=NULL){	
		p = p->next;//让它移动到最后一位；
	}
		q->data = e;
		q->next = NULL;
		p->next = q;
		top++;
	return 1;
}
//取栈顶元素
template<class ElemType>
ElemType SqStack<ElemType>::getTop(){
	Node<ElemType>* p = head;
	while(p->next!=NULL){p=p->next;}
	return p->data;
}
//出栈
template<class ElemType>
ElemType SqStack<ElemType>::pop(){
	Node<ElemType>* q=head;
	
	while(q->next->next){q=q->next;}
	ElemType e =q->next->data ;
	q->next = q->next->next;
	top--;
	return e;
}
//复制构造函数
template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &s){
	Node<ElemType> *p1 = head;
	Node<ElemType> *p2 = s.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	top = s.top;

}
//重载运算符
template<class ElemType>
SqStack<ElemType> & SqStack<ElemType>::operator =(const SqStack<ElemType> &s)
{
	SqStack<ElemType> a;
	a.top = s.top;
	Node<ElemType> *p1 = a.head;
	Node<ElemType> *p2 = s.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	return a;
}
#endif
