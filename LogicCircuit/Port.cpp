#include "Port.h"

Port::Port() :port_name("") { }
Port::Port(std::string _pname)
{
	setPortName(_pname);
}


Port::~Port()
{
}
