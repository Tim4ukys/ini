#include "CConfig.h"
#include "ini.h"

std::string stIniNameFile;
mINI::INIStructure ini;

void CConfig::Init(std::string iniName) {
	stIniNameFile = iniName;
	this->Refresh();
}

/////// private ////////

void CConfig::Refresh() {
	mINI::INIFile fileInstance(stIniNameFile);
	fileInstance.read(ini);
}

void CConfig::Save() {
	mINI::INIFile fileInstance(stIniNameFile);
	fileInstance.write(ini);
}

/////// public ////////

/////// read ///////

int CConfig::GetInt(std::string stKey1, std::string stKey2) {
	this->Refresh();

	int iReturnInteger = NULL;
	int iErrorCode = sscanf(ini[stKey1][stKey2].c_str(), "%d", &iReturnInteger);
	
	if (iErrorCode != EOF && iErrorCode != NULL) 
		return iReturnInteger;

	return -1;
}

float CConfig::GetFloat(std::string stKey1, std::string stKey2) {
	this->Refresh();

	float fReturnFloat = NULL;
	int iErrorCode = sscanf(ini[stKey1][stKey2].c_str(), "%f", &fReturnFloat);
	
	if (iErrorCode != EOF && iErrorCode != NULL) 
		return fReturnFloat;
		
	return -1;
}

bool CConfig::GetBool(std::string stKey1, std::string stKey2) {
	this->Refresh();

	int iReturnBool = NULL;
	int iErrorCode = sscanf(ini[stKey1][stKey2].c_str(), "%d", &iReturnBool);
	
	if (iErrorCode != EOF && iErrorCode != NULL) 
		if (iReturnBool == 1) return true;
		
	return false;
}

std::string CConfig::GetString(std::string stKey1, std::string stKey2) {
	this->Refresh();

	return ini[stKey1][stKey2]; 
}

const char* CConfig::GetConstChar(std::string stKey1, std::string stKey2) {
	this->Refresh();

	return ini[stKey1][stKey2].c_str(); 
}

char CConfig::GetChar(std::string stKey1, std::string stKey2) {
	this->Refresh();
	std::string stGetString = ini[stKey1][stKey2];

	char *chReturnChar;
	strcpy(chReturnChar, stGetString.c_str());

	return *chReturnChar; 
}

/////// write ///////
#include <string>

void CConfig::WriteInt(std::string stKey1, std::string stKey2, int iInt) {
	ini[stKey1][stKey2] = std::to_string(iInt);
	this->Save();
}

void CConfig::WriteFloat(std::string stKey1, std::string stKey2, float fFloat) {
	ini[stKey1][stKey2] = std::to_string(fFloat);
	this->Save();
}

void CConfig::WriteBool(std::string stKey1, std::string stKey2, bool bBool) {
	if (bBool)
		ini[stKey1][stKey2] = std::to_string(1);
	else 
		ini[stKey1][stKey2] = std::to_string(0);

	this->Save();
}

void CConfig::WriteString(std::string stKey1, std::string stKey2, std::string stString) {
	ini[stKey1][stKey2] = stString;
	this->Save();
}

void CConfig::WriteString(std::string stKey1, std::string stKey2, const char* cnhString) {
	ini[stKey1][stKey2] = cnhString;
	this->Save();
}

void CConfig::WriteString(std::string stKey1, std::string stKey2, char chString) {
	ini[stKey1][stKey2] = chString;
	this->Save();
}
