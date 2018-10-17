#pragma once
#include "Element.h"
class InputPort;
class InputPortElement :
	public Element
{
private:
	InputPort * in;
	InputPortElement()=delete;
public:
	InputPortElement(InputPort*);
	bool evaluate()const override;
	~InputPortElement();
};

