#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include <afxwin.h>

class CFileSaveManager : public CDocument
{
public:
	CFileSaveManager* GetInstance();
	BOOL SaveAsCsv(LPCTSTR strPath);

	afx_msg void OnFileSave();

private:
	CFileSaveManager();
	~CFileSaveManager();

	static CFileSaveManager* pFileManager;
};