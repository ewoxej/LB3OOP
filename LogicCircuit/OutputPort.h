#pragma once
#include "Port.h"
class Element;
class OutputPort :
	public Port
{
private:
	Element * element;
public:
	OutputPort();
	OutputPort(std::string,Element*);
	void connectWith(Element*);
	void disconnect();
	bool getValue()const override;
	~OutputPort();
};

