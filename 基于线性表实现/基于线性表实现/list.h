#ifndef LIST_H__
#define SQ_LIST_H__
// ANSI C++标准库头文件
#include <cstring>					// 标准串操作
#include <iostream>					// 标准流操作
using namespace std;
// 宏定义
#define DEFAULT_SIZE 1000			// 缺省元素个数
#define DEFAULT_INFINITY 1000000	// 缺省无穷大
//数组中的学生类
typedef struct {
	int num ;//学号
	double grade ;//绩点
	string name; //姓名

}student;

template <class ElemType>
class SqList 
{
protected:
// 顺序表的数据成员
	int length;					// 顺序表的当前长度 
	int maxLength;				// 顺序表的最大容量
	ElemType *data;			// 元素存储空间的首地址 
public:
// 顺序表的函数成员
	SqList(int size = DEFAULT_SIZE);	// 构造一个空表 
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// 根据数组v的内容构造顺序表 
	
	int GetLength() const;		// 取顺序表长度			 
	bool IsEmpty() const;		// 判断顺序表是否为空
	void Clear();				// 将顺序表清空
	void Traverse(void (*Visit)(const ElemType &)) const;	// 遍历顺序表
	int LocateElem(const ElemType &e) const;	// 元素定位，求指定元素在顺序表中的位置
	ElemType GetElem(int i) const;	// 取顺序表中第i个元素的值	
	int SetElem(int i, const ElemType &e);	// 修改顺序表中第i个元素的值
	int DeleteElem(int i);      // 删除顺序表中第i个元素		
	int InsertElem(int i, const ElemType &e); // 在顺序表第i个位置插入元素
 	int InsertElem(const ElemType &e);        // 在顺序表表尾插入元素
	SqList(const SqList<ElemType> &sa);        // 复制构造函数
	SqList<ElemType> &operator =(const SqList<ElemType> &sa); // 赋值语句重载
};


//建一个空表
template<class ElemType>
 SqList<ElemType>::SqList(int size = DEFAULT_SIZE){
	length = 0;
	data = new ElemType[size];
};
//根据数组内容建一个表
template<class ElemType>
SqList<ElemType>::SqList(ElemType v[], int n, int size = DEFAULT_SIZE)//根据数组内容构造线性表
{
	length =  n;
	maxLength = size;
	data = v;
};
//获取表中长度
template <class ElemType>
int SqList<ElemType>::GetLength() const{
	return length;
};
//判断表是否为空
template<class ElemType>
bool SqList<ElemType>::IsEmpty() const{
	length==0?false:true;
}
//清空表
template<class ElemType>
void SqList<ElemType>::Clear(){
	length = 0;
	data = NULL;
}
//遍历表
template<class ElemType>
void SqList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	if(length==0) cout<<"空表！！"<<endl;
	for(int i = 0; i< length ; i++){
		Visit(data[i]);
	}
}
//元素定位，求指定元素在顺序表中的位置
template<class ElemType>
int SqList<ElemType>::LocateElem(const ElemType &e) const{
	for(int i = 0 ; i < length ; i++)
	{
		if(data[i]==e) return i+1;
		else return -1;
	}
}
//// 取顺序表中第i个元素的值
template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const
{
	for(int n=0 ; n<length ; n++)
	{
		if(n==i-1)   return data[i-1];
		
	
	}
};	
//	// 修改顺序表中第i个元素的值/*返回1表示修改成功*/
template<class ElemType>
int SqList<ElemType>::SetElem(int i, const ElemType &e)
{
	
	if(i>length) {return 0;}
	for(int n = 0 ; n<length ; n++){
		if(i-1==n) {data[i-1]=e;return 1;}
		
	}
	
}
//删除表中第i个元素
template<class ElemType>
int SqList<ElemType>::DeleteElem(int i){
	if(i>length||i<0) return 0;
	else {
		for(int n = 0; n<length ; n++){
			if(i-1==n){
				while(i<length){
					data[i-1] = data[i];
					i++;
				}
				length--;
				
				return 1;//删除成功
			}
		}
	}
}
// 在顺序表第i个位置插入元素
template<class ElemType>
int SqList<ElemType>::InsertElem(int i, const ElemType &e){
	if(i<0||i>length) return 0;//表示插入失败
	for(int n = 0 ; n<length ;n++)
	{
		if(i-1==n){
			int j =length-1;
			while(j>=i-1)
			{
				data[j+1] = data[j];
				j--;
			}
			data[i-1] = e;
			length++;
			return 1;//表示插入成功
		}
	}
}
// 在顺序表表尾插入元素
template<class ElemType>
int SqList<ElemType>::InsertElem(const ElemType &e){
	data[length] = e;
	length++;
	
	
	return 1;//添加成功
}  
// 复制构造函数    
template<class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> &sa){
	length = sa.length;
	maxLength = sa.maxLength;
	data = new ElemType[sa.length] ;
	for(int i = 0 ; i<length ;i++)
	{
		data[i] = sa.data[i];
	}

}
//重载修饰符
template<class ElemType>
SqList<ElemType>& SqList<ElemType>::operator =(const SqList<ElemType> &sa){
	SqList a;
	a.length = sa.length;
	a.maxLength = sa.maxLength;
	a.data = new ElemType[sa.length] ;
	for(int i = 0 ; i<length ;i++)
	{
		a.data[i] = sa.data[i];
	}
	return a;

}

#endif