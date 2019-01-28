#pragma once
#include<math.h>

//This class contains parent class and all inherited alpha and beta variables
//for the Hodgkin Huxley equations
//GateFunctions can be passed to ChannelGates to calculate values at specific 
//voltages and times

//Abstract Class
class GateFunction {
	int i = 0;
	public:
		GateFunction () {};
		virtual double operator() (double V) = 0;
};

class alphaN : public GateFunction {
	public:
		alphaN() {};
		virtual double operator() (double V);
};

class betaN : public GateFunction {
	public:
		betaN() {};
		virtual double operator() (double V);
};

class alphaM : public GateFunction {
	public:
		alphaM() {};
		virtual double operator() (double V);
};

class betaM : public GateFunction {
	public:
		betaM() {};
		virtual double operator() (double V);
};

class alphaH : public GateFunction {
	public:
		alphaH() {};
		virtual double operator() (double V);
};

class betaH : public GateFunction {
	public:
		betaH() {};
		virtual double operator() (double V);
};
