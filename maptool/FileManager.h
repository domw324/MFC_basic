#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

class CFileManager
{
public:
	CFileManager();
	~CFileManager();

	CFileManager* GetInstance();
	bool LoadAsCsv();
	bool SaveAsCsv();
	std::vector<std::string> ReadRow(std::istream &file, char cDelimiter);

private:
	static CFileManager* pFileManager;
};