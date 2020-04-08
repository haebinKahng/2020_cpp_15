#pragma once
#include <iostream>
#include "Resource2.h"

template<class T>
class Auto_ptr    //class�� �س����μ� ��Ȱ�� ���� 
{
public:
	T* m_ptr;

public:
	Auto_ptr(T* ptr = nullptr) //�����Ҵ�� �޸𸮿� ������ �����鼭 �ʱ�ȭ 
		: m_ptr(ptr)
	{
		cout << "Auto ptr default constructor" << endl;
	}


	~Auto_ptr()    //�Ҹ��ڿ��� nullptr�� �ƴϸ� ����� 
	{
		cout << "Auto ptr destructor" << endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	Auto_ptr(const Auto_ptr& a)   //copy constructor, L-value reference
	{
		cout << "Auto ptr copy constructor" << endl;
		
		//deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;  //Resource2.h �κп� copy assignment operator ȣ���Ѱ� Resource & operator = (Resource & res) ȣ���Ѱ� 
	}   //m_ptr resource ���� class�� ��� operator overloading �Ȱ��� ȣ��ǰ� ��� �� ���̴�
	    // ������������, ���������� �츮�� �ۼ��� �Լ��� ȣ�� �Ѵ�, deep copy �����ϱ� ������ ������ ���̴�.  
	
	Auto_ptr& operator = (const Auto_ptr& a) // copy assignment operator
	{
		cout << "Auto ptr copy assignment" << endl;
		if (&a == this)
			return *this;          // �ڱ�Ÿ� ������, prevent self-assignment 

		if (m_ptr != nullptr) delete m_ptr;

		// deep copy
		m_ptr = new T;          
		*m_ptr = *a.m_ptr;     //��� ������ �ϳ��ϳ� ���� �ϹǷ� ������
		
		return *this;
		
	}
	//copy constructor�� copy assignment�� ����ϰ� ���� ������ �Ʒ� �ڵ� ��� 
	//Auto_ptr(const Auto_ptr& a) = delete;  
	//Auto_ptr& operator = (const Auto_ptr& a) = delete;


	Auto_ptr(Auto_ptr&& a) // �ռ� copy~~�� ���ؼ� �ӵ� �ξ� ������
		// && �� R-value reference 
		: m_ptr(a.m_ptr)   // deep copy�� ���� �ʴ´� 
		// �����͸� �׳� �����Ѵ��� 58����ó�� �Է����� ���� a�� nullptr�� ����.  
	{
		a.m_ptr = nullptr;  // r value�̴� �� ������� �ƴ�? ���� nullptr�� ���Ա��� ����?
                            // ����δ� ���̱� ���� �Ҹ��ڿ��� nullptr �ƴϸ� ����� �Ǿ������Ƿ� 

		cout << "Auto_ptr move constructor" << endl;

	}


	Auto_ptr& operator=(Auto_ptr&& a) 
		// R-value reference �� ���´� ��� ����� ������͵�, shallow copy move 
		// �����͸� ������ ���·� �� �Űܹ����� ���� �Ѱ��ٶ� ���� ��° �ű�°� �ƴ� ���踦 �ѱ�°� 
	{
		cout << "Auto ptr move assignment" << endl;

		if (&a == this) //prevent self-assignment 
			return *this;

		if (!m_ptr) delete m_ptr; // move�� �ޱ� ���� �̹� �޸� ���� �־��ٸ� �����

		//shallow copy
		m_ptr = a.m_ptr;  // �����͸� �׳� �����ϴ°� resource�� �����͸� ���� �޸��� ù �ּҸ� ���� 
		a.m_ptr = nullptr; // �� ���� �������� �ƿ� �Ѱ��� ���̴ٴ� �ǹ� 

		return *this;

	}


	T& operator*() const { return *m_ptr; }  // d referencing
	T* operator->() const { return m_ptr; }  //member selection
	bool isNull() const { return m_ptr == nullptr; }
	//��¥ ������ó�� ���� ���� 
}; 
