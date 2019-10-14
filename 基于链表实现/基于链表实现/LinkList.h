#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"	
#include<iostream>// 结点类

// 单链表类
template <class ElemType>
class LinkList 
{
protected:
//  单链表的数据成员
	Node<ElemType> *head;				// 头结点指针
	int length;					// 单链表长度 

public:
//  单链表的函数成员 
	LinkList();							// 无参数的构造函数
	LinkList(ElemType v[], int n);		// 有参数的构造函数
	
	int GetLength() const;				// 求单链表长度			 
	bool IsEmpty() const;	 			// 判断单链表是否为空
	void Clear();						// 将单链表清空
	void Traverse(void (*Visit)(const ElemType &)) const;// 遍历单链表
	int LocateElem(const ElemType &e) const;	         // 元素定位 
	ElemType GetElem(int index) const;	 // 求指定位置的元素	
	int SetElem(int index, const ElemType &e);	 // 设置指定位置的元素值
	int DeleteElem(int index);		 // 删除元素		
	int InsertElem(int index, const ElemType &e);	 // 在制定位置插入元素
	int InsertElem(const ElemType &e);	             // 在表尾插入元素
	LinkList(const LinkList<ElemType> &la);            // 复制构造函数
	LinkList<ElemType> &operator =(const LinkList<ElemType> &la); // 重载赋值运算 
};
//无参构造函数
template<class ElemType>
LinkList<ElemType>::LinkList(){
	head = new Node<ElemType>;
	head->next = NULL;
	length = 0;

}
//有参数构造函数
template<class ElemType>
LinkList<ElemType>::LinkList(ElemType v[] , int n ){

	head = new ElemType v[];
	length = n;
}
//返回链表长度..
template<class ElemType>
int LinkList<ElemType>::GetLength()const{
	return length;

}
//判断这个链表是否为空表
template<class ElemType>
bool LinkList<ElemType>::IsEmpty()const{
	length==0?true:false;
}
//清空链表
template<class ElemType>
void LinkList<ElemType>::Clear(){
	Node<ElemType> *p = head->next;
	while(head->next!=NULL && p->next!=NULL){
		head->next = p->next;
		delete p ;
		p = head->next;
	}
	head->next = NULL;
	delete p;

	length = 0;
}
//遍历链表
template<class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const{
Node<ElemType> *p= head ;
while(p->next){
	Visit(p->next->data);
	p = p->next;
}


}
//元素定位
template<class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const{
	int count = 1;
	Node<ElemType>*p = head;
	while(p->next!=NULL){
		if((*p).data==e) return count;
		p = p->next;
	}
	if((*p).data==e) return count;


	return 0;
}
//求指定位置的元素值
template<class ElemType>
ElemType LinkList<ElemType>::GetElem(int index) const{

	int count = 1;
	Node<ElemType>*p = head;
	while(p->next){
		if(count==index) {return p->next->data;}
		p = p->next;count++;
	}
	if(p->next==NULL&&index==length){return p->data;}
}
//设置指定位置的元素值
template<class ElemType>
int LinkList<ElemType>::SetElem(int index, const ElemType &e){
	int count = 1;
	Node<ElemType> *p = head;
	while(p){
		if(count==index){p->next->data = e;return 1;}
		else {
		p = p->next;
		count++;
		}
	}
}
//删除指定元素
template<class ElemType>
int  LinkList<ElemType>::DeleteElem(int index){
	int count = 1;
	Node<ElemType> *p = head;
	while(p->next){
		if(count==index){
			Node<ElemType> *q = p->next;
			if(q->next==NULL){delete q;p->next = NULL;length--;return 1;}
			else {
				p->next=q->next;
				delete q;
				
				length--;
				return 1;
			}
			
		}
			p = p->next;
			count++;
	}
}
//在指定位置插入元素
template<class ElemType>
int LinkList<ElemType>::InsertElem(int index, const ElemType &e){
	int count = 1;
	Node<ElemType> *p = head;
	Node<ElemType> *q;
	if(index==1){q->data = e;q->next = p;head = q; return 1; }//在第一个位置插入；
	while(p){
		if(count==index-1){q->data = e;q->next = p->next;p->next = q; return 1;}
		else {
			count++;
			p = p->next;
		}
	}
}
//在表的尾部插入元素
template <class ElemType>
int LinkList<ElemType>::InsertElem(const ElemType &e){
	Node<ElemType> *p = head;
	Node<ElemType> *q = new Node<ElemType> ;
	if(p->next==NULL){
		q->data = e;
		q->next = NULL;
		p->next=q;
		length++;
		return 1;
	}
	while(p->next!=NULL){	
		p = p->next;//让它移动到最后一位；
	}
		q->data = e;
		q->next = NULL;
		p->next = q;
		length++;
	return 1;
}
//复制构造函数
template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &la){
	pheader = new Node<ElemType>;
	Node<ElemType> *p1 = head;
	Node<ElemType> *p2 = la.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	length = la.length;

}        
//重载运算符
template<class ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator =(const LinkList<ElemType> &la){
	LinkList<ElemType> a;
	a.length = la.length;
	Node<ElemType> *p1 = a.head;
	Node<ElemType> *p2 = la.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	return a;
} 
#endif