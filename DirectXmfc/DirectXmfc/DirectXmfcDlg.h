
// DirectXmfcDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "DirectXdrawing.h"

// CDirectXmfcDlg dialog
class CDirectXmfcDlg : public CDialogEx
{
// Construction
public:
	CDirectXmfcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DIRECTXMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKickIdle();
	afx_msg void OnUpdateUserButton(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_picbox_directXscreen;
	CDirectXdrawing directXObject;

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
