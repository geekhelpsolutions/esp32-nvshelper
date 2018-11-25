// NVSNamespace.h

#ifndef _NVSNAMESPACE_h
#define _NVSNAMESPACE_h

#include "Arduino.h"
#include <nvs_flash.h>

class NVSStringEntry;
class NVSIntegerEntry;

class NVSNamespace
{
public:
	NVSNamespace(String name) : _name(name) {};
	bool begin();

	NVSStringEntry stringEntry(String name, String label);
	bool existsString(String name);
	String loadString(String name);
	bool saveString(String name, String value);

	NVSIntegerEntry integerEntry(String name, String label);
	bool existsInteger(String name);
	int loadInteger(String name);
	bool saveInteger(String name, int value);

	bool printErrors = true;

private:
	String _name;
	nvs_handle _handle;

	bool _isNotErr(esp_err_t err);
};

#endif

