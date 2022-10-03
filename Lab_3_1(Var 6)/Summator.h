#pragma once
#include <iostream>
#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator {
public:
	~Summator() override;
	Summator();
	Summator(const size_t n);

	double calculate() override;
};