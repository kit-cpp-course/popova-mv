#pragma once
/*
* ��������� ����� � ���������� ������� ���������.
*/
struct Point
{
	int x;
	int y;

public:
	/*
	* �������� ���������� ������.
	*/
	Point(int x, int y) : x(x), y(y) {}
	/*
	* ���������� �� ���������.
	*/
	Point() {}
};
/*
* ��������� ���������.
*/
struct Diagonal
{
	Point a; //����� ������ ���������
	Point b; //����� ����� ���������

public:
	/*
	* �������� ���������� ������.
	*/
	Diagonal(Point a, Point b) : a(a), b(b) {}
	/*
	* ���������� �� ���������.
	*/
	Diagonal() {};
};