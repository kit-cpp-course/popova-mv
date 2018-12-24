#include <iostream>
#include <cmath>
#include "Polygon.h"
using namespace std;

float ** diagLen;
float *** costs;

Polygon::Polygon(int n) {
	N = n;
	polygon = new Point[n];
	cout << "Введите координаты вершин по часовой стрелке: " << endl;

	for (int i = 0; i < N; i++) {
		cin >> polygon[i].x >> polygon[i].y;
	}
}

Diagonal * Polygon::triangulate() {

	diagLen = new float *[N];
	for (int i = 0;i<N;i++)
	{
		diagLen[i] = new float[N];
	}

	for (int i = 0;i<N;i++)
	{
		for (int k = i;k<N;k++)
		{
			if ((i + 1 == k) || (k + 1 == i) || (i == k) || ((i == 0) && (k == (N - 1))) || ((i == (N - 1)) && (k == 0))) {
				diagLen[i][k] = 0;
				diagLen[k][i] = 0;
			}
			else {
				float tmp = sqrt((polygon[i].x - polygon[k].x) ^ 2 + (polygon[i].y - polygon[k].y) ^ 2);
				diagLen[i][k] = tmp;
				diagLen[k][i] = tmp;
			}
		}
	}

	for (int s = 1;s <= N;s++)
	{
		for (int i = 0;i<N;i++)
		{
			if (s<4) costs[i][s][0] = 0;
			else costs[i][s][0] = -1;
		}
	}

	triangCost(0, N);
	
	Diagonal * diags = new Diagonal[N - 3];
	
	findD(diags, costs[0][N][1], 0, 0, N);

	return diags;
}

void Polygon::findD(Diagonal * diags, int k, int n, int i, int s) {

	if (diagLen[i][i + k] != 0) {
		diags[n] = Diagonal(polygon[i], polygon[i + k]);
		n++;
	}

	if (diagLen[i + k][i + s - 1] != 0) {
		diags[n] = Diagonal(polygon[i + k], polygon[i + s - 1]);
		n++;
	}

	if (costs[i][k + 1][0] != 0) {
		findD(diags, costs[i][k + 1][1], n, i, k + 1);
	}
	
	if (costs[i + k][s - k][0] != 0) {
		findD(diags, costs[i + k][s - k][1], n, i + k, s - k);
	}
}

float Polygon::triangCost(int i, int s)
{
	float Ctmp;
	float Min = -1; 
	int Pos;
	if (costs[i][s][0] == -1)
	{
		for (int k = 1;k <= s - 2;k++)
		{
			Ctmp = triangCost(i, k + 1) + triangCost(i + k, s - k) + diagLen[i][i + k] + diagLen[i + k][i + s - 1];
			if (Min == -1)
			{
				Min = Ctmp;
				Pos = k;
			}
			else if (Min>Ctmp)
			{
				Min = Ctmp; 
				Pos = k;
			}
		}
		costs[i][s][0] = Min;
		costs[i][s][1] = Pos;
		return Min;
	}
	else return 0;
}

