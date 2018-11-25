// NVSStringEntry.h

#ifndef _NVSSTRINGENTRY_h
#define _NVSSTRINGENTRY_h

#include "Arduino.h"
#include "NVSNamespace.h"

class NVSStringEntry
{
public:
	NVSStringEntry(NVSNamespace &ns, String name, String label) :
		_namespace(ns), _name(name), _label(label)
	{};

	bool exists();
	String load();
	bool save(String value);
	String name();
	String label();

private:
	String _name;
	String _label;
	NVSNamespace& _namespace;
};

#endif

