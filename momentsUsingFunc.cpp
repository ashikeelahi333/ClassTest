#include <iostream>
#include <cmath>
using namespace std;

// Raw Moments
double rm1(int a, int b, int c, int d, int e) {
	double result = a+b+c+d+e;
	return result/5;
}

double rm2(int a, int b, int c, int d, int e) {
	double result = pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2);
	return result/5;
}

double rm3(int a, int b, int c, int d, int e) {
	double result = pow(a, 3) + pow(b, 3) + pow(c, 3) + pow(d, 3) + pow(e, 3);
	return result/5;
}

double rm4(int a, int b, int c, int d, int e) {
	double result = pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4) + pow(e, 4);
	return result/5;
}

// Central Moments

double cm2(int a, int b, int c, int d, int e) {
	double RM1 = rm1(a, b, c, d, e);
	double RM2 = rm2(a, b, c, d, e);
	double result = RM2 - pow(RM1, 2); 
	return result;
}

double cm3(int a, int b, int c, int d, int e) {
	double RM1 = rm1(a, b, c, d, e);
	double RM2 = rm2(a, b, c, d, e);
	double RM3 = rm3(a, b, c, d, e);
	double result = RM3 - 3*RM2*RM1 + 2*pow(RM1, 3); 
	return result;
}


double cm4(int a, int b, int c, int d, int e) {
	double RM1 = rm1(a, b, c, d, e);
	double RM2 = rm2(a, b, c, d, e);
	double RM3 = rm3(a, b, c, d, e);
	double RM4 = rm4(a, b, c, d, e);
	double result = RM4 - 4*RM3*RM1 + 6*RM2*pow(RM1, 2) - 3*pow(RM1, 4); 
	return result;
}


double sk(int a, int b, int c, int d, int e) {
	double CM2 = cm2(a, b, c, d, e);
	double CM3 = cm3(a, b, c, d, e);
	double result = CM3/pow(CM2, 1.5);
	return result;
}

double kr(int a, int b, int c, int d, int e) {
	double CM2 = cm2(a, b, c, d, e);
	double CM4 = cm4(a, b, c, d, e);
	double result = CM4/pow(CM2, 2);
	return result;
}

int main() {
	double RM1 = rm1(1, 2, 3, 4, 5);
	double RM2 = rm2(1, 2, 3, 4, 5);
	double RM3 = rm3(1, 2, 3, 4, 5);
	double RM4 = rm4(1, 2, 3, 4, 5);
	
	cout << "RM1 => " << RM1 << endl;
	cout << "RM2 => " << RM2 << endl;
	cout << "RM3 => " << RM3 << endl;
	cout << "RM4 => " << RM4 << endl;
	
	double CM2 = cm2(1, 2, 3, 4, 5);
	double CM3 = cm3(1, 2, 3, 4, 5);
	double CM4 = cm4(1, 2, 3, 4, 5);
	
	cout << "CM2 => " << CM2 << endl;
	cout << "CM3 => " << CM3 << endl;
	cout << "CM4 => " << CM4 << endl;
	
	double SK = sk(1, 2, 3, 4, 5);
	double KR = kr(1, 2, 3, 4, 5);
	
	cout << "SK => " << SK << endl;
	cout << "KR => " << KR << endl;
}
