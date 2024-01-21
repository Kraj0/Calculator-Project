
// Kalkulator_dla_elektronikowDlg.h : header file
//

#pragma once

#define _AFXDLL

// CKalkulatordlaelektronikowDlg dialog
class CKalkulatordlaelektronikowDlg : public CDialogEx
{
// Construction
public:
	CKalkulatordlaelektronikowDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KALKULATOR_DLA_ELEKTRONIKOW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox conversion_type;
	CString value_dec;
	CString value_bin;
	CString value_oct;
	CString value_hex;
	CString initial_value;
	afx_msg void OnBnClickedButton2();
	CString float_value;
};
