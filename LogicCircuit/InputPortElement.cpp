#include "InputPortElement.h"
#include"InputPort.h"
InputPortElement::InputPortElement(InputPort * _in):
	in(_in)
{
}

bool InputPortElement::evaluate()const
{
	return in->getValue();
}


InputPortElement::~InputPortElement()
{
}
