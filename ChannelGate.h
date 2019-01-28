#pragma once
#include<math.h>
#include"GateFunction.h"
#include<vector>

//This class calculates the current for an activation/inactivation gate
//given the functions, alpha and beta, and the value of the gate at t = 0
class ChannelGate
{
    private:
	GateFunction* alpha;
	GateFunction* beta;
	std::vector<double> values;
	double valueAtTZero;
    public:
        ChannelGate(GateFunction* a, GateFunction* b, double);
	double calcInf(double);
	double calcTao(double);
	double calcGate(double, double);
};
