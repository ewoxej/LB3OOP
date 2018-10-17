#include "UnaryElement.h"



bool UnaryElement::evaluate()const
{
	switch (operation_code) 
	{
	case op_codes::BUFFER: 
		return in->evaluate(); break;
	case op_codes::INVERTOR: 
		return !(in->evaluate()); break;
	}
}

UnaryElement::UnaryElement(Element * _in, op_codes _oper_code):
	in(_in),
	operation_code(_oper_code)
{
}

UnaryElement::~UnaryElement()
{
}
