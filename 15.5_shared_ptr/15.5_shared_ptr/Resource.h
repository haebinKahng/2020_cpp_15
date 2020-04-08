#pragma once

#include <iostream>
using namespace std;


class Resource
{
public:
	int *m_data = nullptr;  //규모 큰 데이터 처리하기 위해 동적 array로 
	unsigned m_length = 0;  //데이터 갯수 담을 수 있다

public:
	Resource()
	{
		cout << "Resource default constructed" << endl;

	}

	Resource(unsigned length)
	{
		cout << "Resource length constructed" << endl;

		this->m_data = new int[length]; //메모리 할당받아 가지고 있기
		this->m_length = length;
	}

	Resource(const Resource &res) //복사 생성자 
	{
		cout << "Resource copy constructed" << endl;

		Resource(res.m_length);

		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];   // 내용물 전부 복사, deep copy 
	}

	~Resource()   //소멸자, 메모리 다쓰면 지운다 
	{
		cout << "Resource destroyed" << endl;
		if (m_data != nullptr) delete[] m_data;
	}

	Resource & operator = (Resource & res)
	{
		cout << "Resource copy assignment" << endl;

		if (&res == this) return *this;
		if (this->m_data != nullptr) delete[] m_data;

		m_length = res.m_length;
		m_data = new int[m_length];

		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];     //모든 원소 deepcopy, copy assignment 호출 되면 느려진다 

		return *this;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			cout << m_data[i] << " ";
		cout << endl;

	}

	void setAll(const int& v)  // 값을 초기화해주기 위해 만든 함수 
	{
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = v;
	}

};
