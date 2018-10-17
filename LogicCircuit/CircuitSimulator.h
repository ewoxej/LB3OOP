#pragma once
#include"CombinationalCircuit.h"
#include<fstream>
#include<string>
#include<list>
class CircuitSimulator
{
	std::ifstream* stream;
	CombinationalCircuit* crc;
	std::list<std::string> list;
public:
	CircuitSimulator(std::string filename,CombinationalCircuit* _crc);
	void set_input();
	bool portValue()const;
	void show_port()const;
	void getCommand();
	void Simulate();
	~CircuitSimulator();
};

