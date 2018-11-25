// NVSIntegerEntry.h

#ifndef _NVSINTEGERENTRY_h
#define _NVSINTEGERENTRY_h

#include "Arduino.h"
#include "NVSNamespace.h"

class NVSIntegerEntry
{
public:
	NVSIntegerEntry(NVSNamespace &ns, String name, String label) :
		_namespace(ns), _name(name), _label(label)
	{};

	bool exists();
	int load();
	bool save(int value);
	String name();
	String label();

private:
	String _name;
	String _label;
	NVSNamespace& _namespace;
};

#endif

