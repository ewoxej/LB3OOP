#include "OutputPort.h"
#include"Element.h"

OutputPort::OutputPort():element(nullptr)
{
}

OutputPort::OutputPort(std::string pname,Element * _el):element(_el),Port(pname)
{
}

void OutputPort::connectWith(Element * _el)
{
	element = _el;
}

void OutputPort::disconnect()
{
	element = nullptr;
}

bool OutputPort::getValue()const
{
	if(element==nullptr)
	return false;
	else return element->evaluate();
}

OutputPort::~OutputPort()
{
}
