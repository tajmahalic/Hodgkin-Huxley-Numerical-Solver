#include "ChannelGate.h"
#include <math.h>

ChannelGate::ChannelGate(GateFunction *a, GateFunction *b, double x) : alpha(a), beta(b), valueAtTZero(x) {
	values.push_back(valueAtTZero);
}

//All equations are given in the hw assignment
double ChannelGate::calcTao(double V) {
	return 1/((*alpha)(V)+(*beta)(V));	
}

double ChannelGate::calcInf(double V) {
	return (*alpha)(V)/((*alpha)(V)+(*beta)(V));
}

double ChannelGate::calcGate(double V, double time) {
	double inf = calcInf(V);
	double tao = calcTao(V); 
	values.push_back(inf - (inf - valueAtTZero)*exp(-1*time/tao)); 
	
	return values.back();
}
