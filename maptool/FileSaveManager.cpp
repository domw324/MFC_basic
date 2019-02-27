#include "stdafx.h"
#include "define.h"
#include "FileSaveManager.h"
#include "ShapeHandler.h"
#include "Shape.h"
#include "Line.h"
#include "Rect.h"
#include <iosfwd>

CFileSaveManager* CFileSaveManager::pFileManager = NULL;

CFileSaveManager::CFileSaveManager()
{
}

CFileSaveManager::~CFileSaveManager()
{
}

CFileSaveManager * CFileSaveManager::GetInstance()
{
	if (!pFileManager)
	{
		pFileManager = new CFileSaveManager();
	}
	return pFileManager;
}

BOOL CFileSaveManager::SaveAsCsv(LPCTSTR strPath)
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

void CFileSaveManager::OnFileSave()
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