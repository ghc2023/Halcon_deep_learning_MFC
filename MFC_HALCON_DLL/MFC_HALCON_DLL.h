
// MFC_HALCON_DLL.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMFC_HALCON_DLLApp: 
// 有关此类的实现，请参阅 MFC_HALCON_DLL.cpp
//

class CMFC_HALCON_DLLApp : public CWinApp
{
public:
	CMFC_HALCON_DLLApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFC_HALCON_DLLApp theApp;