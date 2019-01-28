#pragma once

#include"ChannelGate.h"
#include<vector>

//This class takes a list of gates (with associated degree) and reversal potential
//and calculates the current for that ion channel
//E.g. a Potassium channel has 4 n gates and Ek = -80mV

class IonChannel {
	private:
		std::vector<ChannelGate> gateList;
		std::vector<int> gateDegreeList;
		double revPotential;				//mV
		double conductance;
		
	public:
		IonChannel(std::vector<ChannelGate> &, std::vector<int> &, double, double);
		//Overloaded Constructor for Leak Channel (no Activation/Inactivation Gates) 
		IonChannel(double, double);
		double calcI(double, double);
		double getRevPotential() {return revPotential;}

};
