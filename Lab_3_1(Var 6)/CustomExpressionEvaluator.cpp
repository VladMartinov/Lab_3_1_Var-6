#include <iostream>
#include <string>
#include "CustomExpressionEvaluator.h"

CustomExpressionEvaluator::~CustomExpressionEvaluator() {
	std::cout << "\nDestructor : CustomExpressionEvaluator Removed!\n";
}

CustomExpressionEvaluator::CustomExpressionEvaluator() {
	countOfOperand_ = 20;
	arrayOfOperand_ = new double[countOfOperand_] {0};
	IsOrderImportant_ = true;
}

CustomExpressionEvaluator::CustomExpressionEvaluator(const size_t n) {
	countOfOperand_ = n;
	arrayOfOperand_ = new double[countOfOperand_] {0};
	IsOrderImportant_ = true;
}

double CustomExpressionEvaluator::calculate() {
	log_ = "";
	result_ += (*(arrayOfOperand_ + 0) + *(arrayOfOperand_ + 1)) / 2;
	log_ += "( " + formatDouble(* (arrayOfOperand_ + 0)) + " plus ";
	log_ += formatDouble(*(arrayOfOperand_ + 1)) + " )" + " division " + "2" + " plus ";

	for (size_t i = 2; i < countOfOperand_; i++) {
		result_ += *(arrayOfOperand_ + i);

		if (i == countOfOperand_ - 1)
			log_ += formatDouble(*(arrayOfOperand_ + i));
		else
			log_ += formatDouble(*(arrayOfOperand_ + i)) + " plus\ ";
	}

	return result_;
}

