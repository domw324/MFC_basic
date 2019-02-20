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
END_MESSAGE_MAP()

void CDlgTab2::OnBnClickedButtonLine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/// 여기서는 MainFrm의 모드를 바꾸는 용도로만 사용한다.

 	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// 프레임 윈도우 포인터
 	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// 활성화된 뷰의 포인터

	pView->SetDrawMode(MODE::DRAW_LINE);
	pView->DrawLine();
																			  // 
// 
// 	CDC* p = pView->GetWindowDC();
// 
// 	int nStartX, nStartY, nEndX, nEndY;
// 	nStartX = nStartY = 10;
// 	nEndX = nEndY = 200;
// 	p->MoveTo(nStartX, nStartY);
// 	p->LineTo(nEndX, nEndY);
// 	
// 	pView->ReleaseDC(p);
	
}

void CDlgTab2::OnBnClickedButtonRect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/// 여기서는 MainFrm의 모드를 바꾸는 용도로만 사용한다.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// 프레임 윈도우 포인터
	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// 활성화된 뷰의 포인터

	pView->SetDrawMode(MODE::DRAW_RECT);
	pView->DrawRect();

 //
 //	CDC* p = pView->GetWindowDC();
 //
 //	int nStartX, nStartY, nEndX, nEndY;
 //	nStartX = nStartY = 10;
 //	nEndX = nEndY = 200;
	//p->Rectangle(nStartX, nStartY, nEndX, nEndY);
 //	
 //	pView->ReleaseDC(p);
}