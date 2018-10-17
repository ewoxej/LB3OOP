#pragma once
#include "Element.h"
class UnaryElement :
	public Element
{
public:	enum class  op_codes : bool { INVERTOR, BUFFER };
private:
	Element * in;
	const op_codes operation_code;
	UnaryElement()=delete;
public:
	UnaryElement(Element* _in,op_codes _oper_code);
	bool evaluate()const override;
	~UnaryElement();
};

