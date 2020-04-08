#pragma once
#include <iostream>
#include "Resource2.h"

template<class T>
class Auto_ptr    //class로 해놈으로서 재활용 가능 
{
public:
	T* m_ptr;

public:
	Auto_ptr(T* ptr = nullptr) //동적할당된 메모리에 포인터 받으면서 초기화 
		: m_ptr(ptr)
	{
		cout << "Auto ptr default constructor" << endl;
	}


	~Auto_ptr()    //소멸자에서 nullptr이 아니면 지운다 
	{
		cout << "Auto ptr destructor" << endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	Auto_ptr(const Auto_ptr& a)   //copy constructor, L-value reference
	{
		cout << "Auto ptr copy constructor" << endl;
		
		//deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;  //Resource2.h 부분에 copy assignment operator 호출한것 Resource & operator = (Resource & res) 호출한것 
	}   //m_ptr resource 같은 class일 경우 operator overloading 된것이 호출되고 사용 될 것이다
	    // 연산자이지만, 내부적으로 우리가 작성한 함수를 호출 한다, deep copy 수행하기 때문에 느려질 것이다.  
	
	Auto_ptr& operator = (const Auto_ptr& a) // copy assignment operator
	{
		cout << "Auto ptr copy assignment" << endl;
		if (&a == this)
			return *this;          // 자기거면 하지마, prevent self-assignment 

		if (m_ptr != nullptr) delete m_ptr;

		// deep copy
		m_ptr = new T;          
		*m_ptr = *a.m_ptr;     //모든 데이터 하나하나 복사 하므로 느려짐
		
		return *this;
		
	}
	//copy constructor나 copy assignment를 사용하고 싶지 않을때 아래 코드 사용 
	//Auto_ptr(const Auto_ptr& a) = delete;  
	//Auto_ptr& operator = (const Auto_ptr& a) = delete;


	Auto_ptr(Auto_ptr&& a) // 앞서 copy~~와 비교해서 속도 훨씬 빨라짐
		// && 는 R-value reference 
		: m_ptr(a.m_ptr)   // deep copy를 하지 않는다 
		// 포인터를 그냥 복사한다음 58번줄처럼 입력으로 들어온 a를 nullptr로 만듦.  
	{
		a.m_ptr = nullptr;  // r value이니 곧 사라질애 아님? 굳이 nullptr로 대입까지 할일?
                            // 위험부담 줄이기 위해 소멸자에서 nullptr 아니면 지우게 되어있으므로 

		cout << "Auto_ptr move constructor" << endl;

	}


	Auto_ptr& operator=(Auto_ptr&& a) 
		// R-value reference 로 들어온다 잠깐 생겼다 사라질것들, shallow copy move 
		// 데이터를 포인터 상태로 싹 옮겨버린다 집을 넘겨줄때 집을 통째 옮기는게 아닌 열쇠를 넘기는것 
	{
		cout << "Auto ptr move assignment" << endl;

		if (&a == this) //prevent self-assignment 
			return *this;

		if (!m_ptr) delete m_ptr; // move를 받기 위해 이미 메모리 갖고 있었다면 지운다

		//shallow copy
		m_ptr = a.m_ptr;  // 포인터를 그냥 복사하는것 resource의 포인터만 복사 메모리의 첫 주소만 복사 
		a.m_ptr = nullptr; // 넌 이제 소유권을 아예 넘겨준 것이다는 의미 

		return *this;

	}


	T& operator*() const { return *m_ptr; }  // d referencing
	T* operator->() const { return m_ptr; }  //member selection
	bool isNull() const { return m_ptr == nullptr; }
	//진짜 포인터처럼 동작 가능 
}; 
