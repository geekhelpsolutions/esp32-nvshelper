// 
// 
// 

#include "NVSNamespace.h"
#include "NVSStringEntry.h"
#include "NVSIntegerEntry.h"

bool NVSNamespace::begin() {
	bool success = true;
	success &= _isNotErr(nvs_flash_init());
	success &= _isNotErr(nvs_open(_name.c_str(), NVS_READWRITE, &_handle));
	return success;
}

NVSStringEntry NVSNamespace::stringEntry(String name, String label) {
	return NVSStringEntry(*this, name, label);
}

bool NVSNamespace::existsString(String name) {
	size_t length;
	return _isNotErr(nvs_get_str(_handle, name.c_str(), NULL, &length));
}

String NVSNamespace::loadString(String name) {
	size_t length;
	_isNotErr(nvs_get_str(_handle, name.c_str(), NULL, &length));
	char* buffer = (char*)malloc(length);
	_isNotErr(nvs_get_str(_handle, name.c_str(), buffer, &length));
	return String(buffer);
}

bool NVSNamespace::saveString(String name, String value) {
	bool success = true;
	success &= _isNotErr(nvs_set_str(_handle, name.c_str(), value.c_str()));
	success &= _isNotErr(nvs_commit(_handle));
	return success;
}

NVSIntegerEntry NVSNamespace::integerEntry(String name, String label) {
	return NVSIntegerEntry(*this, name, label);
}

bool NVSNamespace::existsInteger(String name) {
	int output;
	return _isNotErr(nvs_get_i32(_handle, name.c_str(), &output));
}

int NVSNamespace::loadInteger(String name) {
	int output;
	_isNotErr(nvs_get_i32(_handle, name.c_str(), &output));
	return output;
}

bool NVSNamespace::saveInteger(String name, int value) {
	bool success = true;
	success &= _isNotErr(nvs_set_i32(_handle, name.c_str(), value));
	success &= _isNotErr(nvs_commit(_handle));
	return success;
}

bool NVSNamespace::_isNotErr(esp_err_t err) {
	if (err == ESP_OK) return true;
	if (printErrors) {
		Serial.print("ESP Error ");
		Serial.print(err);
		Serial.print(": ");
		Serial.println(esp_err_to_name(err));
	}
	return false;
}
