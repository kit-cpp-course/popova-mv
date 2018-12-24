#include <iostream>
#include "Polygon.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cin >> N;
	Polygon polygon = Polygon(N);
	Diagonal * diags = polygon.triangulate();

	
	for (int i = 0; i < N - 3; i++) {
		cout << "(" << diags[i].a.x << "," << diags[i].a.y << ")" << "-- (" << diags[i].b.x << "," << diags[i].b.y << ")" << endl;
	}

	return 0;
}