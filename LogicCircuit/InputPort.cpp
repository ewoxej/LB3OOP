#include "InputPort.h"
InputPort::InputPort(bool _val):
	value(_val)
{
}



InputPort::InputPort(const char* portname, bool _val):
	Port::Port(portname),value(_val)
{
}

void InputPort::setValue(bool _val)
{
	value = _val;
}

bool InputPort::getValue()const
{
	return value;
}

InputPort::~InputPort()
{
}
