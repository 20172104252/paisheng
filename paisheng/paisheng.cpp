// paisheng.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CDate
{
protected:
	int Years;
	int Month;
	int Day;
public:
	CDate()
	{
		Years = 0;
		Month = 0;
		Day = 0;
	}
	CDate(CDate & temp)
	{
		Years = temp.Years;
		Month = temp.Month;
		Day = temp.Day;
	}
	void Setvalue(int Y, int M, int D)
	{
		Years = Y;
		Month = M;
		Day = D;
	}
	void display()
	{
		cout << Years << "   Years  " << Month << "   Month  " << Day << "    Day  " << endl;
	}
	CDate operator +(CDate temp)
	{
		int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		Years = Years + temp.Years;
		Day = Day + temp.Day;
		if ((Years % 4 == 0 && Years % 100 != 0) || Years % 400 == 0)
			arr[1] = 29;
		if (Day > arr[Month - 1])
		{
			Day = Day - arr[Month - 1];
			Month++;
		}
		Month = Month + temp.Month;
		if (Month > 12)
		{
			Month = Month % 13;
			Years++;
		}
		CDate obj;
		obj.Setvalue(Years, Month, Day);
		return obj;
	}
	static void tomorrow(CDate & temp)
	{
		int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int Year = temp.Years;
		if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
			arr[1] = 29;
		temp.Day++;
		if (temp.Day > arr[temp.Month - 1])
		{
			temp.Month++;
			temp.Day = temp.Day - arr[temp.Month - 2];
		}
		if (temp.Month > 12)
		{
			temp.Years++;
			temp.Month = temp.Month - 12;
		}

	}
};
class CMYDate :public CDate
{

};

int main()
{
	CDate NUM1, NUM2;
	NUM1.Setvalue(0, 12, 31);
	NUM2.Setvalue(0, 12, 1);
	CDate NUM3;
	NUM3 = NUM1 + NUM2;
	NUM3.display();
    return 0;
}

