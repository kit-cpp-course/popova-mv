#pragma once
#include "Elements.h"

class Polygon 
{
	int N; // кол-во вершин многоугольника
	Point * polygon; // массив вершин
public:
	/*
	* Основной констуктор класса.
	*/
	Polygon(int n);
	/*
	* Возвращает массив диагоналей полученной триангуляции.
	*/
	Diagonal * triangulate();


private:
	/*
	* Расчитывает стоимости триангуляции.
	*/
	float triangCost(int i, int s);
	/*
	* Находит диагонали триангуляции  меньшей стоимостью.
	*/
	void findD(Diagonal * diags, int k, int n, int i, int s);

	float ** diagLen;           // массив длин всех диагоналей
	float costs[100][100][2];	// массив всех стоимостей 
};
