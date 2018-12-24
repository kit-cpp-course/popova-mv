#pragma once
/*
* Описывает точку в дискретной системе координат.
*/
struct Point
{
	int x;
	int y;

public:
	/*
	* Основной констуктор класса.
	*/
	Point(int x, int y) : x(x), y(y) {}
	/*
	* Констуктор по умолчанию.
	*/
	Point() {}
};
/*
* Описывает диагональ.
*/
struct Diagonal
{
	Point a; //точка начала диагонали
	Point b; //точка конца диагонали

public:
	/*
	* Основной констуктор класса.
	*/
	Diagonal(Point a, Point b) : a(a), b(b) {}
	/*
	* Констуктор по умолчанию.
	*/
	Diagonal() {};
};