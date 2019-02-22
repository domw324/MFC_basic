#pragma once


// ControlView 보기

#include "DlgTab1.h"
#include "DlgTab2.h"
#include "Resource.h"
#include "Shape.h"

class CControlView : public CFormView
{
	DECLARE_DYNCREATE(CControlView)

protected:
	CControlView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CControlView();

public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.

	enum { IDD = IDD_CONTROLVIEW };

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	/// TAb Control의 제어변수를 추가해주는 부분
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	/// Tab Control의 멤버변수 추가
	CTabCtrl m_ctlTab;
	CDlgTab1* m_pDialog1;
	CDlgTab2* m_pDialog2;
	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult); /// 탭을 클릭했을 때 이벤트
	virtual void InsertTree(int nShapeType, int nId);
	virtual void DeleteTreeBack(int nShapeType);
	virtual void DeleteTreeAll();
};