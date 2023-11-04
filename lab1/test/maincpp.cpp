#include<iostream>
#include"Header.h"
using namespace std;

int main() {
	TTT t;
	t.SetMatrixSize();
	t.CreateMatrix();
	t.MENU();
	t.DeleteMatrix();
	return 0;	
}