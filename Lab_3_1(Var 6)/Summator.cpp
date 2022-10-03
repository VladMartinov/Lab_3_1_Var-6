#include <iostream>
#include <string>
#include "Summator.h"

Summator::~Summator() {
	std::cout << "\nDestructor : Summator Removed!\n";
}

Summator::Summator() {
	countOfOperand_ = 20;
	arrayOfOperand_ = new double[countOfOperand_] {0};
}

Summator::Summator(const size_t n) {
	countOfOperand_ = n;
	arrayOfOperand_ = new double[countOfOperand_] {0};
}

double Summator::calculate() {
	result_ = *(arrayOfOperand_ + 0);
	log_ = "";
	log_ += formatDouble(*(arrayOfOperand_ + 0)) + " plus ";

	for (size_t i = 1; i < countOfOperand_; i++) {
		result_ += *(arrayOfOperand_ + i);
		if (i == countOfOperand_ - 1)
			log_ += formatDouble(*(arrayOfOperand_ + i));
		else 
			log_ += formatDouble(*(arrayOfOperand_ + i)) + " plus ";
	}
	return result_;
}