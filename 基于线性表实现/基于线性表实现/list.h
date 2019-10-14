#ifndef LIST_H__
#define SQ_LIST_H__
// ANSI C++��׼��ͷ�ļ�
#include <cstring>					// ��׼������
#include <iostream>					// ��׼������
using namespace std;
// �궨��
#define DEFAULT_SIZE 1000			// ȱʡԪ�ظ���
#define DEFAULT_INFINITY 1000000	// ȱʡ�����
//�����е�ѧ����
typedef struct {
	int num ;//ѧ��
	double grade ;//����
	string name; //����

}student;

template <class ElemType>
class SqList 
{
protected:
// ˳�������ݳ�Ա
	int length;					// ˳���ĵ�ǰ���� 
	int maxLength;				// ˳�����������
	ElemType *data;			// Ԫ�ش洢�ռ���׵�ַ 
public:
// ˳���ĺ�����Ա
	SqList(int size = DEFAULT_SIZE);	// ����һ���ձ� 
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// ��������v�����ݹ���˳��� 
	
	int GetLength() const;		// ȡ˳�����			 
	bool IsEmpty() const;		// �ж�˳����Ƿ�Ϊ��
	void Clear();				// ��˳������
	void Traverse(void (*Visit)(const ElemType &)) const;	// ����˳���
	int LocateElem(const ElemType &e) const;	// Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
	ElemType GetElem(int i) const;	// ȡ˳����е�i��Ԫ�ص�ֵ	
	int SetElem(int i, const ElemType &e);	// �޸�˳����е�i��Ԫ�ص�ֵ
	int DeleteElem(int i);      // ɾ��˳����е�i��Ԫ��		
	int InsertElem(int i, const ElemType &e); // ��˳����i��λ�ò���Ԫ��
 	int InsertElem(const ElemType &e);        // ��˳����β����Ԫ��
	SqList(const SqList<ElemType> &sa);        // ���ƹ��캯��
	SqList<ElemType> &operator =(const SqList<ElemType> &sa); // ��ֵ�������
};


//��һ���ձ�
template<class ElemType>
 SqList<ElemType>::SqList(int size = DEFAULT_SIZE){
	length = 0;
	data = new ElemType[size];
};
//�����������ݽ�һ����
template<class ElemType>
SqList<ElemType>::SqList(ElemType v[], int n, int size = DEFAULT_SIZE)//�����������ݹ������Ա�
{
	length =  n;
	maxLength = size;
	data = v;
};
//��ȡ���г���
template <class ElemType>
int SqList<ElemType>::GetLength() const{
	return length;
};
//�жϱ��Ƿ�Ϊ��
template<class ElemType>
bool SqList<ElemType>::IsEmpty() const{
	length==0?false:true;
}
//��ձ�
template<class ElemType>
void SqList<ElemType>::Clear(){
	length = 0;
	data = NULL;
}
//������
template<class ElemType>
void SqList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	if(length==0) cout<<"�ձ���"<<endl;
	for(int i = 0; i< length ; i++){
		Visit(data[i]);
	}
}
//Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
template<class ElemType>
int SqList<ElemType>::LocateElem(const ElemType &e) const{
	for(int i = 0 ; i < length ; i++)
	{
		if(data[i]==e) return i+1;
		else return -1;
	}
}
//// ȡ˳����е�i��Ԫ�ص�ֵ
template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const
{
	for(int n=0 ; n<length ; n++)
	{
		if(n==i-1)   return data[i-1];
		
	
	}
};	
//	// �޸�˳����е�i��Ԫ�ص�ֵ/*����1��ʾ�޸ĳɹ�*/
template<class ElemType>
int SqList<ElemType>::SetElem(int i, const ElemType &e)
{
	
	if(i>length) {return 0;}
	for(int n = 0 ; n<length ; n++){
		if(i-1==n) {data[i-1]=e;return 1;}
		
	}
	
}
//ɾ�����е�i��Ԫ��
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
				
				return 1;//ɾ���ɹ�
			}
		}
	}
}
// ��˳����i��λ�ò���Ԫ��
template<class ElemType>
int SqList<ElemType>::InsertElem(int i, const ElemType &e){
	if(i<0||i>length) return 0;//��ʾ����ʧ��
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
			return 1;//��ʾ����ɹ�
		}
	}
}
// ��˳����β����Ԫ��
template<class ElemType>
int SqList<ElemType>::InsertElem(const ElemType &e){
	data[length] = e;
	length++;
	
	
	return 1;//��ӳɹ�
}  
// ���ƹ��캯��    
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
//�������η�
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