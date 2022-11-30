#ifndef _VARIABLE_h
#define _VARIABLE_h

class Variable {
private:
	String name;
public:
	String getName();
	virtual int value() = 0;
};

#endif