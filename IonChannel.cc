#include"IonChannel.h"
#include<iostream>
IonChannel::IonChannel(std::vector<ChannelGate> &gates, std::vector<int> &degrees, double revPot, double conductance) : gateList(gates), gateDegreeList(degrees), revPotential(revPot), conductance(conductance){}

IonChannel::IonChannel(double revPot, double conductance) : revPotential(revPot), conductance(conductance){
	//Initialize Variables to be empty vectors
	this->gateList = std::vector<ChannelGate>();
	this->gateDegreeList = std::vector<int>();
}

//if the gate = n, and deg = 4
//product = n^4*(V-revPotential)
double IonChannel::calcI(double V, double time) {
	double product = (V - revPotential);
	product *= conductance;
	
	for(std::size_t i = 0; i < gateList.size(); ++i) {
		for(int deg = 0; deg < gateDegreeList[i]; ++deg) {
			product *= gateList[i].calcGate(V, time);
		}
	}
	return product;
}
