//Node.h

#ifndef __NODE_H__
#define __NODE_H__
#include<string>
#include<iostream>
using namespace std;
//学生类的结构体
 typedef struct {
	int num;
	double grade;
	string name;
}student;
// 结点类
template <class ElemType>
struct Node 
{
// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType> *next;		// 指针域
// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType e, Node<ElemType> *link = NULL);	// 已知数数据元素值和指针建立结构
};
//无参的构造函数
template<class ElemType>
Node<ElemType>::Node(){
	next = NULL;
}
//已知数据元素值和指针建立结构
template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link = NULL) {
	data = e;
	head = link;
}



#endif