#pragma once
#include "Element.h"
class BinaryElement :
	public Element
{
public: enum class  op_codes : char { AND, OR, XOR };
private:
	Element * in0;
	Element * in1;
	const op_codes operation_code;
	BinaryElement() = delete;
public:
	BinaryElement(Element* _in0,Element* _in1,op_codes _oper_code);
	bool evaluate()const override;
	~BinaryElement();
};

