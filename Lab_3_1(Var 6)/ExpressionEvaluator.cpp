#include <iostream>
#include <fstream>
#include "ExpressionEvaluator.h"

using namespace std;

ExpressionEvaluator::~ExpressionEvaluator() {
	delete arrayOfOperand_;
	arrayOfOperand_ = NULL;
	std::cout << "\nDestructor : ExpressionEvaluator Removed!\n";
}

ExpressionEvaluator::ExpressionEvaluator() {
	countOfOperand_ = 20;
	arrayOfOperand_ = new double[countOfOperand_] {0};
}

ExpressionEvaluator::ExpressionEvaluator(const size_t n) {
	countOfOperand_ = n;
	arrayOfOperand_ = new double[countOfOperand_] {0};
}

size_t ExpressionEvaluator::getCountOfOperand() {
	return countOfOperand_;
}


double ExpressionEvaluator::getResult() {
	return result_;
}

bool ExpressionEvaluator::getIsOrderImportant() {
	return IsOrderImportant_;
}


void ExpressionEvaluator::setOperand(size_t pos, double value) {
	arrayOfOperand_[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (size_t i = 0; i < n && i < countOfOperand_; i++) {
		arrayOfOperand_[i] = ops[i];
	}
}

void ExpressionEvaluator::logToScreen() {
	std::cout << log_;
}

void ExpressionEvaluator::logToFile(const string& filename) {
	string path = filename;
	ofstream out(path, ofstream::app, ios::binary);

	size_t l = log_.length();

	out.write((const char*)&l, sizeof(size_t));
	out.write(log_.data(), l);

	result_ = atof(formatDouble(result_).c_str());
	out.write((const char*)&result_, sizeof(double));
	out.close();
}

void ExpressionEvaluator::shuffle()
{
	// инициализация генератора случайных чисел
	srand(time(NULL));

	// реализация алгоритма перестановки
	for (int i = countOfOperand_ - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);

		double tmp = arrayOfOperand_[j];
		arrayOfOperand_[j] = arrayOfOperand_[i];
		arrayOfOperand_[i] = tmp;
	}
}

void ExpressionEvaluator::shuffle(size_t i, size_t j)
{
	double tmp = arrayOfOperand_[j];
	arrayOfOperand_[j] = arrayOfOperand_[i];
	arrayOfOperand_[i] = tmp;
}

string ExpressionEvaluator::formatDouble(double num) {
	string s = to_string(num);

	if (s[s.size() - 1] == '0')
		for (size_t i = s.size() - 1; s[i] == '0'; i--)
			s.erase(i, 1);

	if (s[s.size() - 1] == '.')
		s.erase(s.size() - 1, 1);

	if (s[0] == '-')
		s = '(' + s + ')';
	return s;
}
