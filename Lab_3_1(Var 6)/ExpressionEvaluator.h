#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "ILoggable.h"
#include "IShuffle.h"

class ExpressionEvaluator : public ILoggable , public IShuffle {
public:
	ExpressionEvaluator();
	ExpressionEvaluator(const size_t n);
	virtual ~ExpressionEvaluator();

	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	size_t getCountOfOperand();
	double getResult();
	bool getIsOrderImportant();
	void shuffle() override;
	void shuffle(size_t i, size_t j) override;

	//======================================= Реализация класса ILoggable
	void logToScreen() override;
	void logToFile(const std::string& filename) override;

	virtual double calculate() = 0;
	std::string formatDouble(double num);
protected:
	size_t countOfOperand_;
	double* arrayOfOperand_;
	bool IsOrderImportant_ = false;

	double result_ = 0;
	std::string log_ = "\nNo one logs\n"; //+std::to_string(42); // Working
};