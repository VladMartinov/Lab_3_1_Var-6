#include <iostream>
#include <string>
#include "Substractor.h"

Substractor::~Substractor() {
	std::cout << "\nDestructor : Substractor Removed!\n";
}

Substractor::Substractor() {
	countOfOperand_ = 20;
	arrayOfOperand_ = new double[countOfOperand_] {0};
}

Substractor::Substractor(const size_t n) {
	countOfOperand_ = n;
	arrayOfOperand_ = new double[countOfOperand_] {0};
}

double Substractor::calculate() {
	result_ = *(arrayOfOperand_ + 0);
	log_ = "";
	log_ += formatDouble(*(arrayOfOperand_ + 0)) + " minus ";

	for (size_t i = 1; i < countOfOperand_; i++) {
		result_ -= *(arrayOfOperand_ + i);
		if (i == countOfOperand_ - 1)
			log_ += formatDouble(*(arrayOfOperand_ + i));
		else
			log_ += formatDouble(*(arrayOfOperand_ + i)) + " minus ";
	}
	return result_;
}