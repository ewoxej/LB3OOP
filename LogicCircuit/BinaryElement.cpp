#include "BinaryElement.h"


BinaryElement::BinaryElement(Element * _in0, Element * _in1, op_codes _oper_code):
	in0(_in0),
	in1(_in1),
	operation_code(_oper_code)
{
}

bool BinaryElement::evaluate()const
{
	switch (operation_code) 
	{
	case op_codes::AND: return (in0->evaluate() and in1->evaluate()); break;
	case op_codes::OR: return (in0->evaluate() or in1->evaluate()); break;
	case op_codes::XOR:return (in0->evaluate() xor in1->evaluate()); break;
	}
}

BinaryElement::~BinaryElement()
{
}
