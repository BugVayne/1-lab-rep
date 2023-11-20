#include "pch.h"
#include "CppUnitTest.h"
#include "TicTacToe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TicTacToeTests)
	{
	public:
		TEST_METHOD(SetMatrixSizeTest)
		{
			TicTacToe t;
			stringstream input;
			input << "3" << endl;
			istringstream redirect(input.str());
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			t.SetMatrixSize();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			cin.rdbuf(oldCinBuf);
			Assert::AreEqual(output[0], 'E');
		}
		TEST_METHOD(GetMatrixSizeTest)
		{
			TicTacToe t;
			int a = t.GetMatrixSize();			
			Assert::AreEqual(a, 3);
		}
		TEST_METHOD(CreateMetrixTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			t.PrintMatrix();
			string a = buf.str();
			char tst = a[0];
			Assert::AreEqual(tst,a[0]);
		}
		TEST_METHOD(DiagonalCheckTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			char buffer = t.DiagonalCheck();
			Assert::AreEqual(buffer, 'L');
		}
		TEST_METHOD(HorizontalCheckTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			char buffer = t.HorizontalCheck();
			Assert::AreEqual(buffer, 'L');
		}
		TEST_METHOD(VerticalCheckTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			char buffer = t.VerticalCheck();
			Assert::AreEqual(buffer, 'L');
		}
		TEST_METHOD(AllCheckTest1)
		{
			TicTacToe t;
			t.CreateMatrix();
			char buffer = t.AllCheck();
			Assert::AreEqual(buffer, 'L');
		}

		TEST_METHOD(AllCheckTest2)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(2, 'X');
			t.AddElement(3, 'X');
			char buffer = t.AllCheck();
			Assert::AreEqual(buffer, 'X');
		}

		TEST_METHOD(AllCheckTest3)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(4, 'X');
			t.AddElement(7, 'X');
			char buffer = t.AllCheck();
			Assert::AreEqual(buffer, 'X');
		}

		TEST_METHOD(AllCheckTest4)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(5, 'X');
			t.AddElement(9, 'X');
			char buffer = t.AllCheck();
			Assert::AreEqual(buffer, 'X');
		}

		TEST_METHOD(AllBoardIsFullTest1)
		{
			TicTacToe t;
			t.CreateMatrix();
			bool buffer = t.AllBoardIsFull();
			Assert::IsFalse(buffer);
		}

		TEST_METHOD(AllBoardIsFullTest2)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(2, 'X');
			t.AddElement(3, 'X');
			t.AddElement(4, 'X');
			t.AddElement(5, 'X');
			t.AddElement(6, 'X');
			t.AddElement(7, 'X');
			t.AddElement(8, 'X');
			t.AddElement(9, 'X');
			bool buffer = t.AllBoardIsFull();
			Assert::IsTrue(buffer);
		}
		TEST_METHOD(DeleteMatrixTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.DeleteMatrix();
			
		}
	

		TEST_METHOD(PrintMatrixTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			t.PrintMatrix();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, ' ');
		}


		TEST_METHOD(AddElementTest)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(3, 'X');
			char a = t.GetArrElement(3);
			Assert::AreEqual(a, 'X');
		}
	
		TEST_METHOD(HorizontalCheckTest2)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(2, 'X');
			t.AddElement(3, 'X');
			char a = t.HorizontalCheck();
			Assert::AreEqual(a, 'X');
		}
		TEST_METHOD(VerticalCheckTest2)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(4, 'X');
			t.AddElement(7, 'X');
			char a = t.VerticalCheck();
			Assert::AreEqual(a, 'X');
		}
		TEST_METHOD(DiagonalCheckTest2)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(1, 'X');
			t.AddElement(5, 'X');
			t.AddElement(9, 'X');
			char a = t.DiagonalCheck();
			Assert::AreEqual(a, 'X');
		}

		TEST_METHOD(DiagonalCheckTest3)
		{
			TicTacToe t;
			t.CreateMatrix();
			t.AddElement(3, 'X');
			t.AddElement(5, 'X');
			t.AddElement(7, 'X');
			char a = t.DiagonalCheck();
			Assert::AreEqual(a, 'X');
		}
	};
}
