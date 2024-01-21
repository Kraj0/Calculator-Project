
// Kalkulator_dla_elektronikow.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#define _AFXDLL

// CKalkulatordlaelektronikowApp:
// See Kalkulator_dla_elektronikow.cpp for the implementation of this class
//

class CKalkulatordlaelektronikowApp : public CWinApp
{
public:
	CKalkulatordlaelektronikowApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CKalkulatordlaelektronikowApp theApp;
