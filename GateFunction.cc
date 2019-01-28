#include "GateFunction.h"

//Implementation of each function is taken from the assignment
double alphaN::operator() (double V) {
	double numer = 0.01*(V+50.0);
	double denom = (1.0-exp((V+50.0)/(-10.0))); 
	return numer / denom;
}


double betaN::operator() (double V) {
	return 0.125*exp((V+60.0)/(-80.0));
}

double alphaM::operator() (double V) {
	double numer = 0.1*(V+35.0);
	double denom = (1.0 - exp((V+35.0)/(-10.0)));
	return numer / denom;
}

double betaM::operator() (double V) {
	return 4.0*exp((V+60.0)/(-18.0));
}

double alphaH::operator() (double V) {
	return 0.07*exp((V+60.0)/(-20.0));	
}

double betaH::operator() (double V) {
	double numer = 1.0;
	double denom = (1.0 + exp((V+30.0)/(-10.0)));
	return numer / denom;
}
