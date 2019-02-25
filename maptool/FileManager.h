#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

class CFileManager : public CWinAppEx
{
public:
	CFileManager* GetInstance();
	BOOL LoadAsCsv(LPCTSTR strPath);
	BOOL SaveAsCsv(LPCTSTR strPath);
	std::vector<std::string> ReadRow(std::istream &file, char cDelimiter);

	//afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();

private:
	CFileManager();
	~CFileManager();

	static CFileManager* pFileManager; 
};