#include "CircuitSimulator.h"
#include<iterator>
#include<iostream>

CircuitSimulator::CircuitSimulator(std::string filename, CombinationalCircuit * _crc):crc(_crc)
{
	std::cout.setf(std::ios::boolalpha);
	stream = new std::ifstream(filename);
}

void CircuitSimulator::Simulate()
{
	std::copy(
		std::istream_iterator<std::string>(*stream),
		std::istream_iterator<std::string>(),
		std::front_inserter(list)
	);
	while (!list.empty()) {
		getCommand();
	}
}

bool CircuitSimulator::portValue( )const {
	if (list.back() == "false")return false;
	if (list.back() == "true") return true;
std::cerr << "Incorrect logic value\n"; system("pause"); exit(1);
}


void CircuitSimulator::set_input( ) {
	InputPort* tmp = (InputPort*)crc->portByName(list.back());
	list.pop_back();
	if (tmp != nullptr) {
		tmp->setValue(portValue());
		std::cout << "Input " << tmp->getPortName() << " is " << tmp->getValue() << "\n";
	}
	else { std::cerr << "Undefined port name\n"; system("pause"); exit(1); }

}
void CircuitSimulator::show_port( )const {
	OutputPort* tmp = (OutputPort*)crc->portByName(list.back());
	if (tmp != nullptr) {
		std::cout<<"Output "<<tmp->getPortName()<<" is "<<tmp->getValue()<<"\n";
	}
	else { std::cerr << "Undefined port name\n"; system("pause"); exit(1); }
}


void CircuitSimulator::getCommand() {
	if (list.back().at(0) == '#') std::cout << list.back()<<"\n";
	if (list.back() == "set_input" || list.back() == "SET_INPUT") { list.pop_back(); set_input(); }
	if (list.back() == "show_port" || list.back() == "SHOW_PORT") { list.pop_back(); show_port(); }
	list.pop_back();

}

CircuitSimulator::~CircuitSimulator()
{
	delete stream;
}
