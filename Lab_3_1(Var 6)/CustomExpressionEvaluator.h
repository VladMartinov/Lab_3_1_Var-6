#pragma once
#include <iostream>
#include "ExpressionEvaluator.h"

class CustomExpressionEvaluator : public ExpressionEvaluator {
public:

	~CustomExpressionEvaluator() override;
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(const size_t n);

	double calculate() override;
};