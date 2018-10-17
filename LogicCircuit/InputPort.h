#pragma once
#include "Port.h"
class InputPort :
	public Port
{
private:
	bool value;
public:
	InputPort(bool _val=false);
	InputPort(const char* portname,bool _val=false);
	void setValue(bool _val);
	bool getValue()const override;
	~InputPort();
};

