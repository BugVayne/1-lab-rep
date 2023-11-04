#pragma once
#include<iostream>

using namespace std;

class TTT {
private:
	int matrix_size = 3;
	char** arr;
public:
	int GetMatrixSize() { return this->matrix_size; }
	void SetMatrixSize();
	void CreateMatrix();
	void PrintMatrix();
	void MakeAMove(char pl);
	char AllCheck();
	char DiagonalCheck();
	char HorizontalCheck();
	char VerticalCheck();
	bool AllBoardIsFull();
	void DeleteMatrix();
	void MENU();
};
