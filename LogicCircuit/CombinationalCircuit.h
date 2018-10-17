#pragma once
#include"InputPort.h"
#include"OutputPort.h"
#include<vector>
#include<map>
/////////////////////////////////////////////////////////
#define CIRCUIT(name) CombinationalCircuit* name = new CombinationalCircuit
#define INPUT(name) InputPort* name = new InputPort(#name);InputPortElement* name##_e = new InputPortElement(name)
#define OUTPUT(name,elem) OutputPort* name=new OutputPort(#name,elem)
#define BINELEMENT(name,in0,in1,operation) BinaryElement* name = new BinaryElement(in0, in1, BinaryElement::op_codes::operation);
#define UNELEMENT(name,in0,operation) UnaryElement* name = new UnaryElement(in0, UnaryElement::op_codes::operation);
#define TERELEMENT(name,in0,in1,in2,operation) BinaryElement name##tmp(in0, in1, BinaryElement::op_codes::operation);\
BinaryElement* name = new BinaryElement(&name##tmp, in2, BinaryElement::op_codes::operation);\
/////////////////////////////////////////////////////////

class Element;
class Port;
/////////////////////////////////////////////////////////
class CombinationalCircuit
{
private:
	typedef std::map<std::string, Port*> port_container;
	std::vector<Element*> elements;
	port_container ports;
	CombinationalCircuit(CombinationalCircuit&)=delete;
	CombinationalCircuit operator=(CombinationalCircuit&) = delete;
public:
	void addElement(Element* _e);
	void addPort(Port* _p);
	void removeElement(Element* _e);
	void removePort(Port* _p);
	bool hasElement(Element* _e)const;
	bool hasPort(Port* _p)const;
	Port* portByName(std::string name)const;
	CombinationalCircuit();
	CombinationalCircuit(std::initializer_list<Port*>, std::initializer_list<Element*>);
	~CombinationalCircuit();
};

