#include <iostream>

template<class T>
class Auto_ptr    //class�� �س����μ� ��Ȱ�� ���� 
{
public:
	T *m_ptr = nullptr;

public:
	Auto_ptr(T *ptr = nullptr) //�����Ҵ�� �޸𸮿� ������ �����鼭 �ʱ�ȭ 
		: m_ptr(ptr)
	{
	}

	
	~Auto_ptr()    //�Ҹ��ڿ��� nullptr�� �ƴϸ� ����� 
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	Auto_ptr(Auto_ptr &a)   //copy constructor
	{
		m_ptr = a.m_ptr;  // auto ptr�� �ϳ� �Է����� ���ͼ� �����ɶ�
		                  // ���� ptr�� �Է����� ���� ptr�� ��������
		          
		a.m_ptr = nullptr; // ù��° �����͸� nullptr�� (�̰� �ٸ���)
	}

	Auto_ptr& operator = (Auto_ptr &a) // copy assignment operator
	{
		if (&a == this)
			return *this;          // �ڱ�Ÿ� ������ 

		delete m_ptr;             // �̹� ���� �ִٸ� �� �޸� �����   
		m_ptr = a.m_ptr;          // ���� ���� �޸� �ּ� �ް� 
		a.m_ptr = nullptr;       // �����Ŵ� nullptr�� ������ �����ȴ� 
		return *this;
	}


	T& operator*() const { return *m_ptr; }  // d referencing
	T* operator->() const { return m_ptr; }  //member selection
	bool isNull() const { return m_ptr == nullptr; }
	//��¥ ������ó�� ���� ���� 
};
