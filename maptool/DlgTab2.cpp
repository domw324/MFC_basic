// DlgTab2.cpp: 구현 파일
//

#include "stdafx.h"
#include "maptool.h"
#include "DlgTab2.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ControlView.h"
#include "maptoolView.h"
#include "define.h"

// CDlgTab2 대화 상자

IMPLEMENT_DYNAMIC(CDlgTab2, CDialog)

CDlgTab2::CDlgTab2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{
}

CDlgTab2::~CDlgTab2()
{
}

// CDlgTab2 메시지 처리기

BEGIN_MESSAGE_MAP(CDlgTab2, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LINE, &CDlgTab2::OnBnClickedButtonLine)
	ON_BN_CLICKED(IDC_BUTTON_RECT, &CDlgTab2::OnBnClickedButtonRect)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CDlgTab2::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_ALL, &CDlgTab2::OnBnClickedButtonDeleteAll)
END_MESSAGE_MAP()

void CDlgTab2::OnBnClickedButtonLine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/// maptoolView의 m_nDrawmode를 바꾸는 용도로만 사용

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);

	pView->SetDrawMode(MODE::DRAW_LINE);	
}

void CDlgTab2::OnBnClickedButtonRect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/// maptoolView의 m_nDrawmode를 바꾸는 용도로만 사용

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);

	pView->SetDrawMode(MODE::DRAW_RECT);
}

void CDlgTab2::OnBnClickedButtonBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);

	pView->DeleteBack();
}


void CDlgTab2::OnBnClickedButtonDeleteAll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/// maptoolView의 스케치 모두 삭제

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0);

	pView->DeleteAll();
}
