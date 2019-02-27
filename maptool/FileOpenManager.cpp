#include "stdafx.h"
#include "FileOpenManager.h"
#include "ShapeHandler.h"
#include <iostream>
#include <iosfwd>
#include <string>
#include "define.h"
#include "Shape.h"
#include "Line.h"
#include "Rect.h"
#include "MainFrm.h"
#include "maptoolView.h"

CFileOpenManager* CFileOpenManager::pFileManager = NULL;

CFileOpenManager::CFileOpenManager()
{
}

CFileOpenManager::~CFileOpenManager()
{
}

CFileOpenManager * CFileOpenManager::GetInstance()
{
	if (!pFileManager)
	{
		pFileManager = new CFileOpenManager();
	}
	return pFileManager;
}

BOOL CFileOpenManager::LoadAsCsv(LPCTSTR strPath)
{
	CShapeHandler* pShapeHandler = CShapeHandler::GetInstance();

	//CString strPath = _T("C:\\Users\\ssj0324\\source\\repos\\maptool\\maptool\\Example.csv");

	int nType;
	int nStartX;
	int nStartY;
	int nEndX;
	int nEndY;

	/// in file stream ���� �б�
	std::ifstream file(strPath);

	if (file.fail()) { return FALSE; } // ���� �б� ����

	while (file.good())
	{
		std::vector<std::string> strRowData = ReadRow(file, ',');

		nType = atoi(strRowData[0].c_str());
		nStartX = atoi(strRowData[1].c_str());
		nStartY = atoi(strRowData[2].c_str());
		nEndX = atoi(strRowData[3].c_str());
		nEndY = atoi(strRowData[4].c_str());

		pShapeHandler->CreateShape(nType, CPoint(nStartX, nStartY), CPoint(nEndX, nEndY));
	}

	file.close();

	return TRUE;
}

std::vector<std::string> CFileOpenManager::ReadRow(std::istream & file, char cDelimiter)
{
	std::stringstream StringStream;
	std::vector<std::string> row; //relying on RVO

	while (file.good())
	{
		char cGetFileChar = file.get();

		if (cGetFileChar == cDelimiter) // split ���� ������ stream �����͸� ���Ϳ� �ְ� �ʱ�ȭ
		{
			row.push_back(StringStream.str());
			StringStream.str("");
		}
		else if (cGetFileChar == '\r' || cGetFileChar == '\n') // ���� ���� ������ stream �����͸� ���Ϳ� �ְ� �ʱ�ȭ
		{
			if (file.peek() == '\n') { file.get(); }

			row.push_back(StringStream.str());
			return row;
		}
		else
		{
			StringStream << cGetFileChar;
		}
	}

	return row;
}

// void CFileOpenManager::OnFileNew()
// {
//  	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
//  	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);
//  	pView->DeleteAll();
// }

void CFileOpenManager::OnFileOpen()
{
// 	char filter[] = "Cvs Files (*.csv)|*.csv||";
// 	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, filter);
	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT); 
	if (dlg.DoModal() == IDOK)
	{
		POSITION pos = dlg.GetStartPosition();
		while (pos)
		{
			LoadAsCsv(dlg.GetNextPathName(pos));
		}
	}

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);
	pView->OnPaint();
}