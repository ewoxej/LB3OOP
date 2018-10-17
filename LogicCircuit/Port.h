#pragma once
#include<string>
class Port
{
private:
	std::string port_name;
protected:
	Port();
	Port(std::string);
public:
	std::string getPortName()const;
	void setPortName(std::string);
	virtual bool getValue()const = 0;
	~Port();
};

inline std::string Port::getPortName()const {
	return port_name;
}

inline void Port::setPortName(std::string _pname) {
	port_name =  _pname;
}

