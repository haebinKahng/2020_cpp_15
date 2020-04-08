#include <iostream>
#include "pch.h"
#include "resource1.h"
using namespace std;

void dosomething(const int &lref)  //parameter l-value
{
	cout << "L-value ref" << endl;  //move-semantics ��� �Ұ� 

}

void dosomething(const int &&ref) //parameter r-value
{
	cout << "R-value ref" << endl;    //ref�� ��� data move-semantics���� �����´�. �ٸ����� �� ���� ���� ����  
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();  //�Լ����� ������ ���� ������ �ִ� r value 
	const int cx = 6;
	const int cy = getResult();

	// L-value reference  compile �ȵǴ� �͵��� �ּ�ó�� 

	int &lr1 = x;    // Modifiable l-values
	//int &lr2 = cx; // Non-Modifiable l-values const ���̳� 21���� r-value�� �Ұ� 
	//int &lr3 = 5; //  R-values

	const int &lr4 = x; // Modifiable l-values
	const int &lr5 = cx; // Non-Modifiable l-values
	const int &lr6 = 5;  //  R-values   ��ġ symbolic const �θ� ����ϰڴ� ���� ���� 

	// R-value reference  compile �ȵǴ� �͵��� �ּ�ó��

	//int &&rr1 = x;   // Modifiable l-values
	//int &&rr2 = cx;  // Non-Modifiable l-values
	int &&rr3 = 5;     //  R-values
	int &&rrr = getResult();

	cout << rr3 << endl;   // 5�� ����
	rr3 = 10;
	cout << rr3 << endl;   // 10���� ���� 

	//const int &&rr4 = x;   // Modifiable l-values
	//const int &&rr5 =cx;   // Non-Modifiable l-values
	const int &&rr6 = 5;     //  R-values

	// operator overloading 
	// L/R-value reference parameters
	dosomething(x);  //l-value reference�� para���� dosth ȣ�� 
	//dosomething(cx);
	dosomething(5); //r-value reference�� para���� dosth ȣ��
	dosomething(getResult());

	return 0;

}