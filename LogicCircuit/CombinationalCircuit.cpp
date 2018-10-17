#include "CombinationalCircuit.h"
#include"Element.h"
#include"Port.h"
CombinationalCircuit::CombinationalCircuit()
{
}

CombinationalCircuit::CombinationalCircuit(std::initializer_list<Port*> pt, std::initializer_list<Element*> el):elements(el)
{
	for (auto i : pt) {
		ports.insert(std::pair<std::string,Port*>(i->getPortName(),i));
	}
}


CombinationalCircuit::~CombinationalCircuit()
{
	for (auto i : elements) {
		delete i;
	}
	for (auto i : ports) {
		delete i.second;
	}
}

void CombinationalCircuit::addElement(Element * _e)
{
	if (_e != nullptr) elements.push_back(_e);
}

void CombinationalCircuit::addPort(Port * _p)
{
	if (_p != nullptr) ports.insert(std::pair<std::string,Port*>(_p->getPortName(),_p));
}

void CombinationalCircuit::removeElement(Element * _e)
{
	auto it=std::find(elements.begin(), elements.end(), _e);
	if (it != elements.end()) elements.erase(it);
}

void CombinationalCircuit::removePort(Port * _p)
{
	auto it = ports.find(_p->getPortName());
	if (it != ports.end()) ports.erase(it);
}

bool CombinationalCircuit::hasElement(Element * _e)const
{
	auto it = std::find(elements.begin(), elements.end(), _e);
	if (it != elements.end()) return true;
	return false;
}

bool CombinationalCircuit::hasPort(Port * _p)const
{
	auto it = ports.find(_p->getPortName());
	if (it != ports.end()) return true;
	return false;
}

Port * CombinationalCircuit::portByName(std::string name)const
{
	auto it=ports.find(name);
	if (it != ports.end()) return (it->second);
	return nullptr;
}
