#pragma once
#include "Elements.h"

class Polygon 
{
	int N; // ���-�� ������ ��������������
	Point * polygon; // ������ ������
public:
	/*
	* �������� ���������� ������.
	*/
	Polygon(int n);
	/*
	* ���������� ������ ���������� ���������� ������������.
	*/
	Diagonal * triangulate();


private:
	/*
	* ����������� ��������� ������������.
	*/
	float triangCost(int i, int s);
	/*
	* ������� ��������� ������������  ������� ����������.
	*/
	void findD(Diagonal * diags, int k, int n, int i, int s);

	float ** diagLen;           // ������ ���� ���� ����������
	float costs[100][100][2];	// ������ ���� ���������� 
};
