// 
// 
// 

#include "NVSIntegerEntry.h"
#include "NVSNamespace.h"

bool NVSIntegerEntry::exists() {
	return _namespace.existsInteger(_name);
}

int NVSIntegerEntry::load() {
	return _namespace.loadInteger(_name);
}

bool NVSIntegerEntry::save(int value) {
	return _namespace.saveInteger(_name, value);
}

String NVSIntegerEntry::name() {
	return _name;
}

String NVSIntegerEntry::label() {
	return _label;
}
