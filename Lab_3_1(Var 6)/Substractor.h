#pragma once
#include <iostream>
#include "ExpressionEvaluator.h"

class Substractor : public ExpressionEvaluator {
public:
	~Substractor() override;
	Substractor();
	Substractor(const size_t n);

	double calculate() override;
};