#include <iostream>
#include "pch.h"
#include "resource1.h"
using namespace std;

void dosomething(const int &lref)  //parameter l-value
{
	cout << "L-value ref" << endl;  //move-semantics 사용 불가 

}

void dosomething(const int &&ref) //parameter r-value
{
	cout << "R-value ref" << endl;    //ref에 담긴 data move-semantics에서 가져온다. 다른데서 쓸 일이 없기 때문  
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();  //함수에서 리턴한 값을 가지고 있는 r value 
	const int cx = 6;
	const int cy = getResult();

	// L-value reference  compile 안되는 것들은 주석처리 

	int &lr1 = x;    // Modifiable l-values
	//int &lr2 = cx; // Non-Modifiable l-values const 값이나 21같이 r-value는 불가 
	//int &lr3 = 5; //  R-values

	const int &lr4 = x; // Modifiable l-values
	const int &lr5 = cx; // Non-Modifiable l-values
	const int &lr6 = 5;  //  R-values   마치 symbolic const 로만 사용하겠다 수정 없이 

	// R-value reference  compile 안되는 것들은 주석처리

	//int &&rr1 = x;   // Modifiable l-values
	//int &&rr2 = cx;  // Non-Modifiable l-values
	int &&rr3 = 5;     //  R-values
	int &&rrr = getResult();

	cout << rr3 << endl;   // 5가 나옴
	rr3 = 10;
	cout << rr3 << endl;   // 10으로 변경 

	//const int &&rr4 = x;   // Modifiable l-values
	//const int &&rr5 =cx;   // Non-Modifiable l-values
	const int &&rr6 = 5;     //  R-values

	// operator overloading 
	// L/R-value reference parameters
	dosomething(x);  //l-value reference를 para갖는 dosth 호출 
	//dosomething(cx);
	dosomething(5); //r-value reference를 para갖는 dosth 호출
	dosomething(getResult());

	return 0;

}