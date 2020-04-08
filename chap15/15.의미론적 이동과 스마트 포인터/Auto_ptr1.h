#include <iostream>

template<class T>
class Auto_ptr    //class로 해놈으로서 재활용 가능 
{
public:
	T *m_ptr = nullptr;

public:
	Auto_ptr(T *ptr = nullptr) //동적할당된 메모리에 포인터 받으면서 초기화 
		: m_ptr(ptr)
	{
	}

	
	~Auto_ptr()    //소멸자에서 nullptr이 아니면 지운다 
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	Auto_ptr(Auto_ptr &a)   //copy constructor
	{
		m_ptr = a.m_ptr;  // auto ptr이 하나 입력으로 들어와서 생성될때
		                  // 현재 ptr에 입력으로 들어온 ptr을 복사해줌
		          
		a.m_ptr = nullptr; // 첫번째 포인터를 nullptr로 (이게 다르다)
	}

	Auto_ptr& operator = (Auto_ptr &a) // copy assignment operator
	{
		if (&a == this)
			return *this;          // 자기거면 하지마 

		delete m_ptr;             // 이미 갖고 있다면 그 메모리 지우고   
		m_ptr = a.m_ptr;          // 새로 들어온 메모리 주소 받고 
		a.m_ptr = nullptr;       // 원래거는 nullptr로 소유권 이전된다 
		return *this;
	}


	T& operator*() const { return *m_ptr; }  // d referencing
	T* operator->() const { return m_ptr; }  //member selection
	bool isNull() const { return m_ptr == nullptr; }
	//진짜 포인터처럼 동작 가능 
};
