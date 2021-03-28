#pragma once 
#include <iostream>

class CConfig {
public:
	// Инициализация класса
	void Init(std::string iniName);

	/////////// read ///////////

	// Возращает число
	int GetInt(std::string stKey1, std::string stKey2);
	// Возращает дробное число
	float GetFloat(std::string stKey1, std::string stKey2);
	// Возращает true или false
	bool GetBool(std::string stKey1, std::string stKey2);

	// Возращает std::string
	std::string GetString(std::string stKey1, std::string stKey2);
	// Возращает const char*
	const char* GetConstChar(std::string stKey1, std::string stKey2);
	// Возращает char
	char GetChar(std::string stKey1, std::string stKey2);


	/////////// write ///////////

	// Записывает число в ini файл
	void WriteInt(std::string stKey1, std::string stKey2, int iInt);
	// Записывает дробное число в ini файл
	void WriteFloat(std::string stKey1, std::string stKey2, float fFloat);
	// Записывает true или false в ini файл
	void WriteBool(std::string stKey1, std::string stKey2, bool bBool);

	// Записывает std::string в ini файл
	void WriteString(std::string stKey1, std::string stKey2, std::string stString);
	// Записывает const char* в ini файл
	void WriteString(std::string stKey1, std::string stKey2, const char* cnhString);
	// Записывает char в ini файл
	void WriteString(std::string stKey1, std::string stKey2, char chString);
private:
	// Сохраняет ini структуру в файл
	void Save();
	// Загружает ini структуру в переменную
	void Refresh();
};
