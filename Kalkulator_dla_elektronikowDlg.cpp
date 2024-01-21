
// Kalkulator_dla_elektronikowDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Kalkulator_dla_elektronikow.h"
#include "Kalkulator_dla_elektronikowDlg.h"
#include "afxdialogex.h"
#include <string>
#include <iostream>
#include "Conversions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define _AFXDLL
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKalkulatordlaelektronikowDlg dialog



CKalkulatordlaelektronikowDlg::CKalkulatordlaelektronikowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KALKULATOR_DLA_ELEKTRONIKOW_DIALOG, pParent)
	, value_dec(_T(""))
	, value_bin(_T(""))
	, value_oct(_T(""))
	, value_hex(_T(""))
	, initial_value(_T(""))
	, float_value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKalkulatordlaelektronikowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, conversion_type);
	DDX_Text(pDX, IDC_EDIT3, value_dec);
	DDX_Text(pDX, IDC_EDIT5, value_bin);
	DDX_Text(pDX, IDC_EDIT4, value_oct);
	DDX_Text(pDX, IDC_EDIT6, value_hex);
	DDX_Text(pDX, IDC_EDIT1, initial_value);
}

BEGIN_MESSAGE_MAP(CKalkulatordlaelektronikowDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CKalkulatordlaelektronikowDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKalkulatordlaelektronikowDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CKalkulatordlaelektronikowDlg message handlers

BOOL CKalkulatordlaelektronikowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// Pobianie wskaŸnika do obiektu ComboBox
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO2);

	if (pComboBox != nullptr)
	{
		//Ustawianie wysokoœci wyboru opcji
		pComboBox->SetItemHeight(-2, 20); // -2 oznacza ustawienie wysokoœci dla wszystkich elementów
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKalkulatordlaelektronikowDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKalkulatordlaelektronikowDlg::OnPaint()
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
HCURSOR CKalkulatordlaelektronikowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

Conversions Calc;

void CKalkulatordlaelektronikowDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);

	CString type_of_data;

	int nIndex = conversion_type.GetCurSel(); //zczytanie danych  comboboxa 
	conversion_type.GetLBText(nIndex, type_of_data);
	std::string system = CT2A(type_of_data); //konwersja na stringa z CStringa z comboxa
	std::string value;
	value = CT2A(initial_value); //wczytanie wartosci z edit controla 
	std::string dec;

	if (initial_value.IsEmpty()) {
		MessageBox(_T("Enter the correct value!"), _T("Error"), MB_OK | MB_ICONERROR);
		return;
	}

	if (system == "Bin" && initial_value.SpanIncluding(_T("01")) == initial_value) { //sprawdzenie poprawnosci wpisanej liczby
		dec = Calc.binary2decimal(value);
	}
	else if (system == "Oct" && initial_value.SpanIncluding(_T("01234567")) == initial_value) { //sprawdzenie poprawnosci wpisanej liczby
		dec = Calc.oct2decimal(value);
	}
	else if (system == "Hex" && initial_value.SpanIncluding(_T("0123456789abcdefABCDEF")) == initial_value) { //sprawdzenie poprawnosci wpisanej liczby
		dec = Calc.hex2decimal(value);
	}
	else if (system == "Dec" && initial_value.SpanIncluding(_T("0123456789")) == initial_value) { //sprawdzenie poprawnosci wpisanej liczby
		dec = value;
	}
	else {
		MessageBox(_T("Enter the correct number!"), _T("Error"), MB_OK | MB_ICONERROR);  //wyskakujace okienko przy bledzie wpisywania
		return;
	}

	std::string bin = Calc.decimal2binary(dec); //Conversion from decimal to binary
	std::string oct = Calc.decimal2oct(dec); //Conversion from decimal to octal
	std::string hex = Calc.decimal2hex(dec); //Conversion from decimal to hex

	value_dec = dec.c_str(); //Filling Edit control
	value_bin = bin.c_str(); //Filling Edit control
	value_oct = oct.c_str(); //Filling Edit control
	value_hex = hex.c_str(); //Filling Edit control

	UpdateData(FALSE);
}

void CKalkulatordlaelektronikowDlg::OnBnClickedButton2()  //Przycisk Reset który czyœci pole do wpisywania oraz pole wynikowe
{
	UpdateData(TRUE);
	std::string clear = "";
	value_dec = clear.c_str(); //clear empty control
	value_bin = clear.c_str(); //clear empty control
	value_oct = clear.c_str(); //clear empty control
	value_hex = clear.c_str(); //clear empty control
	initial_value = clear.c_str();
	UpdateData(FALSE);
}


