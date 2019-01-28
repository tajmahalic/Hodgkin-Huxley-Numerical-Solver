
#include "IonChannel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>

//Reversal Potentials
constexpr double Ena = 55;		// mV
constexpr double Ek  = -72;		// mV
constexpr double El  = -49.387;	// mV

constexpr double Gna = 120; 	// mS/cm^2
constexpr double Gk  = 36; 		// mS/cm^2
constexpr double Gl  = 0.3; 	// mS/cm^2

void hodgkinHuxley(double maxTime, double timestep, double startV, double stimCurrent, double stimDur, double stimStart, const char* filename) {

	//First make all channels
	
	//M and H gates for Sodium Channel
	ChannelGate mGate(new alphaM(), new betaM(), 0.0529808); //0.0529808
	ChannelGate hGate(new alphaH(), new betaH(), 0.596989); //0.596989
	//N gate for Potassium Channel
	ChannelGate nGate(new alphaN(), new betaN(), 0.317762); //0.317762

	//Adds gates and degrees to vectors	
	std::vector<ChannelGate> sodiumGates;
	sodiumGates.push_back(mGate);
	sodiumGates.push_back(hGate);		
	std::vector<int> sodiumGateDegrees;
	sodiumGateDegrees.push_back(3);
	sodiumGateDegrees.push_back(1);
	
	std::vector<ChannelGate> potassiumGates;
	potassiumGates.push_back(nGate);
	std::vector<int>potassiumGateDegrees;
	potassiumGateDegrees.push_back(4);
	
	//Initialize Ion Channels
	IonChannel KChannel = IonChannel(potassiumGates, potassiumGateDegrees, Ek, Gk);
	IonChannel NaChannel = IonChannel(sodiumGates, sodiumGateDegrees, Ena, Gna);
	//And Leak Channel
	IonChannel LeakChannel = IonChannel(El, Gl);
	
	
	
	double v = startV;
	
	//Opening File
	std::ofstream file;
	file.open(filename);
	
	file << "Time" << stimCurrent << "\t" << "Voltage" << stimCurrent << "\n";
	
	for(double t = 0; t < maxTime; t+=timestep) {
		
		file << t << "\t" << v << "\n";
		
		double ionCurrent = -1*KChannel.calcI(v,t) - NaChannel.calcI(v,t) - LeakChannel.calcI(v,t);
		
		//if the pulse hasn't ended yet, add the stim current
		if (t > stimStart && t < stimStart + stimDur) {
			ionCurrent += stimCurrent;
		}
		
		
		//file2 << t << "\t" << mGate.calcGate(v, t) << "\n";
		//file3 << t << "\t" << hGate.calcGate(v, t) << "\n";
		//file4 << t << "\t" << nGate.calcGate(v, t) << "\n";
		
		
		double dVdt = ionCurrent;
		
		v = v + timestep*dVdt;
		
	}
	
	std::cout << nGate.calcGate(v, maxTime) << "\t" << mGate.calcGate(v, maxTime) << "\t" << hGate.calcGate(v,maxTime) << std::endl;
	
	file.close();
	
	
}

//Output filenames
const char filename[] = "HH.txt";

int main() {
	
	//Constants for voltage iteration and current calc

	constexpr double startV = -60;		//mV
	constexpr double maxTime = 50;    	//ms
	constexpr double timestep = 0.01;	//ms
	constexpr double stimCurrent = 0;	//mV
	constexpr double stimDur = 1;	//ms
	constexpr double stimStart = 1;		//ms
	
	hodgkinHuxley(maxTime, timestep, startV, 7, stimDur, stimStart, "HH7.txt");
	hodgkinHuxley(maxTime, timestep, startV, 8, stimDur, stimStart, "HH8.txt");
	hodgkinHuxley(maxTime, timestep, startV, 9, stimDur, stimStart, "HH9.txt");
	hodgkinHuxley(maxTime, timestep, startV, 10, stimDur, stimStart, "HH10.txt");
	hodgkinHuxley(maxTime, timestep, startV, 20, stimDur, stimStart, "HH20.txt");
	
	
}
