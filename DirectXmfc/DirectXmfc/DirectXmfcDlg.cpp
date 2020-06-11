
// DirectXmfcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DirectXmfc.h"
#include "DirectXmfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDirectXmfcDlg dialog
int start_check = 0;
HWND hWnd;
bool app_exit = false;
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);// the WindowProc function prototype

CDirectXmfcDlg::CDirectXmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDirectXmfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDirectXmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, picbox_directXscreen, m_picbox_directXscreen);
}

BEGIN_MESSAGE_MAP(CDirectXmfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE_VOID(WM_KICKIDLE, OnKickIdle)
  //OnUpdateUserButton(IDC_BUTTON1, OnUpdateUserButton)

  ON_BN_CLICKED(IDOK, &CDirectXmfcDlg::OnBnClickedOk)
  ON_BN_CLICKED(IDCANCEL, &CDirectXmfcDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDirectXmfcDlg message handlers

BOOL CDirectXmfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CStatic* p = (CStatic*)GetDlgItem(picbox_directXscreen);
	hWnd = p->GetSafeHwnd();

	directXObject.InitD3D(hWnd);
	directXObject.initScene(hWnd);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CDirectXmfcDlg::OnKickIdle(){
	//start_check++;

		directXObject.DrawScene();

	UpdateDialogControls(this, TRUE);

}



LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	
	case WM_DESTROY:

		app_exit = true;
		PostQuitMessage(0);
		return 0;
		//case WM_MOUSEMOVE:
		//	x = LOWORD(lParam);
		//	y = HIWORD(lParam);
		//	return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
void CDirectXmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDirectXmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDirectXmfcDlg::OnBnClickedOk()
{
//	app_exit = true;
	directXObject.CleanD3D();
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CDirectXmfcDlg::OnBnClickedCancel()
{
	directXObject.CleanD3D();
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
