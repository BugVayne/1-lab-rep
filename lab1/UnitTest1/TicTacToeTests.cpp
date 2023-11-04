#include "pch.h"
#include "CppUnitTest.h"
#include "Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TicTacToeTests)
	{
	public:
		

		TEST_METHOD(SetMatrixSizeTest)
		{
			TTT t;
			stringstream input;
			input << "3" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			t.SetMatrixSize();
			cin.rdbuf(oldCinBuf);
			Assert::AreEqual(t.GetMatrixSize(), 3);
		}
		TEST_METHOD(GetMatrixSizeTest)
		{
			TTT t;
			int a = t.GetMatrixSize();			
			Assert::AreEqual(a, 3);
		}
		TEST_METHOD(CreateMetrixTest)
		{
			TTT t;
			t.CreateMatrix();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			t.PrintMatrix();
			string a = buf.str();
			char tst = ' ';
			Assert::AreEqual(tst,);
		}
	};
}
