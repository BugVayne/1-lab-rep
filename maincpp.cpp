#include<iostream>
#include"TicTacToe.h"
using namespace std;

int main() {
	TicTacToe t;
	t.SetMatrixSize();
	t.CreateMatrix();
	t.Menu();
	t.DeleteMatrix();
	return 0;	
}