
// MFC_HALCON_DLL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_HALCON_DLLApp: 
// �йش����ʵ�֣������ MFC_HALCON_DLL.cpp
//

class CMFC_HALCON_DLLApp : public CWinApp
{
public:
	CMFC_HALCON_DLLApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_HALCON_DLLApp theApp;