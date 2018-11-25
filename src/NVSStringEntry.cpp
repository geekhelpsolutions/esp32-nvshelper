// 
// 
// 

#include "NVSStringEntry.h"
#include "NVSNamespace.h"

bool NVSStringEntry::exists() {
	return _namespace.existsString(_name);
}

String NVSStringEntry::load() {
	return _namespace.loadString(_name);
}

bool NVSStringEntry::save(String value) {
	return _namespace.saveString(_name, value);
}

String NVSStringEntry::name() {
	return _name;
}

String NVSStringEntry::label() {
	return _label;
}
