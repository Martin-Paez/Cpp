#ifndef _DEVICE_h
#define _DEVICE_h

#include <list>

using namespace std;

class Device {
private:
	String name;
	list<Variable> vars;
public:
	String getName();
};

#endif

