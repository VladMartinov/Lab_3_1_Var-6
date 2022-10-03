#include <iostream>
#include <fstream>
#include <string>
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Substractor.h"
#include "Summator.h"

using namespace std;

void readTheFile(std::string& s, const std::string& filename) {
	string path = "Lab3.log";
	ifstream in(path, ios::binary);
	s = "\n";

	for (int i = 0; i < 3; i++) {
		size_t l;
		in.read((char*)&l, sizeof(size_t));
		char* str = new char[l + 1];
		in.read(str, l);
		str[l] = 0;

		double result;
		in.read((char*)&result, sizeof(double));

		s += str;
		s += "\nResult: " + to_string(result);
		s += "\n";
		delete[] str;
	}
	
	in.close();
}


int main() {
	ExpressionEvaluator* evaluators[3];
	cout << "============= READ THE LOG (1 str for test) =============\n";
	string readLog = "";
	readTheFile(readLog,"Lab3.log");
	cout << readLog;
	cout << "\n============= END THE LOG =============\n";


	evaluators[0] = new CustomExpressionEvaluator(6);
	double cust_operands[] = { 5, 15, -8, 1, 2, 3 };
	evaluators[0]->setOperands(cust_operands, 6);

	evaluators[1] = new Substractor(4);
	double subs_operands[] = { 10.5, 2.5, -3, 1.5 };
	evaluators[1]->setOperands(subs_operands, 4);

	evaluators[2] = new Summator(3);
	evaluators[2]->setOperand(0, 1.5);
	evaluators[2]->setOperand(1, -4);
	evaluators[2]->setOperand(2, 2.5);

	fstream clear_file("Lab3.log", ios::out);
	clear_file.close();
	

	for (size_t i = 0; i < 3; ++i)
	{
		cout << endl;
		for (int j = 0; j < evaluators[i]->getCountOfOperand(); j++) {
			if (j == evaluators[i]->getCountOfOperand() - 1)
				cout << "Operand" << j + 1 << "\n";
			else
				cout << "Operand" << j + 1 << ", ";
		}
		double result = evaluators[i]->calculate();
		evaluators[i]->logToScreen();
		evaluators[i]->logToFile("Lab3.log");
		cout << "\nResult: " << result << "\n\n";
	}

	cout << "\n======================== START SHUFFLE ========================\n\n";

	for (size_t i = 0; i < 3; ++i)
	{
		if (evaluators[i]->getIsOrderImportant()) {

			for (int j = 0; j < evaluators[i]->getCountOfOperand(); j++) {
				if (j == evaluators[i]->getCountOfOperand() - 1)
					cout << "Operand" << j + 1 << "\n";
				else
					cout << "Operand" << j + 1 << ", ";
			}

			evaluators[i]->shuffle();
			double result = evaluators[i]->calculate();
			evaluators[i]->logToScreen();
			cout << "\nResult: " << result << "\n\n";

			evaluators[i]->shuffle(0, 3);
			result = evaluators[i]->calculate();
			evaluators[i]->logToScreen();
			cout << "\nResult: " << result << "\n\n";
		}

	}

	cout << "========================  END SHUFFLE  ========================\n";
	
	for (int i = 0; i < 3; ++i)
		delete evaluators[i];
	
	return 0;
}