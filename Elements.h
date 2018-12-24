#pragma once
/*
* ќписывает точку в дискретной системе координат.
*/
struct Point
{
	int x;
	int y;

public:
	/*
	* ќсновной констуктор класса.
	*/
	Point(int x, int y) : x(x), y(y) {}
	/*
	*  онстуктор по умолчанию.
	*/
	Point() {}
};
/*
* ќписывает диагональ.
*/
struct Diagonal
{
	Point a; //точка начала диагонали
	Point b; //точка конца диагонали

public:
	/*
	* ќсновной констуктор класса.
	*/
	Diagonal(Point a, Point b) : a(a), b(b) {}
	/*
	*  онстуктор по умолчанию.
	*/
	Diagonal() {};
};