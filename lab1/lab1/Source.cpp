#include"Header.h"

void TTT::SetMatrixSize() {
	cout << "Enter the size of the field > ";
	cin>>matrix_size;
	if (matrix_size <= 0)
	{
		cout << " You r kinda dumb if you think array can be with an negative size";
		return SetMatrixSize();
	}
 }

void TTT::CreateMatrix()
{
	arr = new char* [matrix_size];
	for (size_t i = 0; i < matrix_size; i++)
		arr[i] = new char[matrix_size];	
	for (size_t i = 0; i < matrix_size; i++)
		for (size_t j = 0; j < matrix_size; j++)		
			arr[i][j] = ' ';
}

void TTT::PrintMatrix()
{
	system("cls");
	cout << endl;
	for (size_t k = 0; k < matrix_size; k++)
		cout << " -----  ";
	cout << endl;
	for (size_t i = 0; i < matrix_size; i++)
	{
		for (size_t j = 0; j < matrix_size; j++)
			cout << " | " << arr[i][j] <<" |  ";
		cout << endl;
		for (size_t k = 0; k < matrix_size; k++)
			cout << " -----  ";
		cout << "\n";
	}
}

void TTT::MakeAMove(char pl)
{
	int pos;
	cin >> pos;
	if (pos > matrix_size * matrix_size)
	{
		cout << "tutututu max verchtappen";
		return this->MakeAMove(pl);
	}

	int counter = 0;
	for (size_t i = 0; i < matrix_size; i++)
		for (size_t j = 0; j < matrix_size; j++)
		{
			counter++;
			if (counter==pos && arr[i][j] != 'X' && arr[i][j] != 'O')
				arr[i][j] = pl;
			else if (counter == pos && (arr[i][j] != 'X' || arr[i][j] != 'O'))
			{
				cout << " This place is already taken choose another > \n";
				return this->MakeAMove(pl);
			}
		}
	this->PrintMatrix();
}

char TTT::DiagonalCheck()
{
	char temp = arr[0][0];
	int counter = 0;
	for (size_t i = 0; i < matrix_size; i++)
	{
		if ((arr[i][i] != 'X' && arr[i][i] != 'O') || arr[i][i] != temp)
			break;
		counter++;
		if (counter==matrix_size)
			return temp;		
	}
	temp = arr[matrix_size-1][0];
	counter = 0;
	for (size_t i = 0; i < matrix_size; i++)
	{
		if ((arr[(matrix_size -1) - i][i] != 'X' && arr[(matrix_size - 1) - i][i] != 'O') || arr[(matrix_size - 1) - i][i] != temp)
			break;
		counter++;
		if (counter == matrix_size)
			return temp;
	}
	return 'L';
}

char TTT::HorizontalCheck()
{
	for (size_t i = 0; i < matrix_size; i++)
	{
		char temp=arr[i][0];
		if (temp != 'X' && temp != 'O')
			continue;
		int counter = 1;
		for (size_t j = 1; j < matrix_size; j++)
		{
			if (arr[i][j] != temp)
				break;
			else
				counter++;
			if(counter==matrix_size)
				return temp;
		}
	}
	return 'L';
}

char TTT::VerticalCheck()
{
	for (size_t i = 0; i < matrix_size; i++)
	{
		char temp = arr[0][i];
		if (temp != 'X' && temp != 'O')
			continue;
		int counter = 1;
		for (size_t j = 1; j < matrix_size; j++)
		{
			if (arr[j][i] != temp)
				break;
			else			
				counter++;			
			if(counter==matrix_size)
				return temp;
		}
	}
	return 'L';
}

bool TTT:: AllBoardIsFull()
{
	for (size_t i = 0; i < matrix_size; i++)
	{
		for (size_t j = 0; j < matrix_size; j++)
		{
			if (arr[i][j] == ' ')
				return false;
		}
	}
	return true;
}

char TTT::AllCheck()
{
	char VC= this->VerticalCheck();
	if (VC == 'X')
		return 'X';
	else if (VC == 'O')
		return 'O';
	char DC = this->DiagonalCheck();
	if (DC == 'X')
		return 'X';
	else if (DC == 'O')
		return 'O';
	char HC = this->HorizontalCheck();
	if (HC == 'X')
		return 'X';
	else if (HC == 'O')
		return 'O';
	return 'L';
}

void TTT::MENU()
{
	bool game = true;
	char player = 'X';
	while (true)
	{
		this->PrintMatrix();
		switch (player)
		{
		case 'X':
		{
			cout << " It's player " << player << " turn > \n";
			this->MakeAMove(player); player = 'O'; break;
		}
		case 'O':
		{
			cout << " It's player " << player << " turn > \n";
			this->MakeAMove(player); player = 'X'; break;
		}
		default: cout << "--------------smth wrong happend---------------"; exit; break;
		}
		if (this->AllCheck() != 'L')
		{
			cout <<"\a\n\t ------ " << this->AllCheck() << " Won the game with ease --------- \n\a";
			break;
		}
		if (this->AllBoardIsFull())
		{ 
			cout << " ---------- HAHAHA you both lost ----------- \n\n\n";
			break;
		}

	}
	cout << "\a\a\a\t---------------Game is over--------------\a\a\a";
	return;
}

void TTT::DeleteMatrix()
{
	for (size_t i = 0; i < matrix_size; i++)
		delete[] arr[i];
	delete[] arr;
	return;
}

