#include "stdafx.h"
#include "FileManager.h"
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

CFileManager* CFileManager::pFileManager = NULL;

CFileManager::CFileManager()
{
}

CFileManager::~CFileManager()
{
}

CFileManager * CFileManager::GetInstance()
{
	if (!pFileManager)
	{
		pFileManager = new CFileManager();
	}
	return pFileManager;
}

BOOL CFileManager::LoadAsCsv(LPCTSTR strPath)
{
	CShapeHandler* pShapeHandler = CShapeHandler::GetInstance();

	//CString strPath = _T("C:\\Users\\ssj0324\\source\\repos\\maptool\\maptool\\Example.csv");

	int nType;
	int nStartX;
	int nStartY;
	int nEndX;
	int nEndY;

	/// in file stream 파일 읽기
	std::ifstream file(strPath);

	if (file.fail()) { return FALSE; } // 파일 읽기 실패

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

BOOL CFileManager::SaveAsCsv(LPCTSTR strPath)
{
	CShapeHandler* pShapeHandler = CShapeHandler::GetInstance();
	
	CString s = strPath;

	s.Append(L".csv");

	//CString strPath = _T("C:\\Users\\ssj0324\\source\\repos\\maptool\\maptool\\Example.csv");
	


	/// out file stream 파일 쓰기
	std::ofstream file(s);

#pragma warning(push)
#pragma warning(disable: 4018) // 파일 쓰기 시도
	for (int i = 0; i < pShapeHandler->GetSize(); i++)
	{
		CShape* pTempShape = pShapeHandler->GetObject(i);

		if (pTempShape == nullptr) { continue; }

		if (pTempShape->GetType() == SHAPE::S_LINE)
		{
			pTempShape = dynamic_cast<CLine*>(pTempShape);
		}
		else
		{
			pTempShape = dynamic_cast<CRectg*>(pTempShape);
		}

		file << pTempShape->GetType() << ','
			<< pTempShape->GetStartPoint().x << ',' << pTempShape->GetStartPoint().y
			<< ',' << pTempShape->GetEndPoint().x << ',' << pTempShape->GetEndPoint().y << '\n';
	}
#pragma warning(pop)

	if (file.fail()) { return FALSE; } // 파일 쓰기 실패

	file.close();

	return TRUE;
}

std::vector<std::string> CFileManager::ReadRow(std::istream & file, char cDelimiter)
{
	std::stringstream StringStream;
	std::vector<std::string> row; //relying on RVO

	while (file.good())
	{
		char cGetFileChar = file.get();

		if (cGetFileChar == cDelimiter) // split 문자 만나면 stream 데이터를 벡터에 넣고 초기화
		{
			row.push_back(StringStream.str());
			StringStream.str("");
		}
		else if (cGetFileChar == '\r' || cGetFileChar == '\n') // 다음 줄을 만나도 stream 데이터를 벡터에 넣고 초기화
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

// void CFileManager::OnFileNew()
// {
//  	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
//  	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);
//  	pView->DeleteAll();
// }

void CFileManager::OnFileOpen()
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

void CFileManager::OnFileSave()
{
// 	 	char filter[] = "Cvs Files (*.csv)|*.csv||";
// 	 	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, filter);
	CFileDialog dlg(FALSE, NULL, NULL, OFN_ALLOWMULTISELECT);
	if (dlg.DoModal() == IDOK)
	{
		POSITION pos = dlg.GetStartPosition();
		while (pos)
		{
			SaveAsCsv(dlg.GetNextPathName(pos));
		}
	}
}