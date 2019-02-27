#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

class CFileOpenManager : public CWinAppEx
{
public:
	CFileOpenManager* GetInstance();
	BOOL LoadAsCsv(LPCTSTR strPath);
	std::vector<std::string> ReadRow(std::istream &file, char cDelimiter);

	//afx_msg void OnFileNew();
	afx_msg void OnFileOpen();

private:
	CFileOpenManager();
	~CFileOpenManager();

	static CFileOpenManager* pFileManager; 
};