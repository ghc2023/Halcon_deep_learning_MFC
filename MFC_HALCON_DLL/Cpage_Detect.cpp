// Cpage_Detect.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "Cpage_Detect.h"
#include "afxdialogex.h"


// Cpage_Detect 对话框

IMPLEMENT_DYNAMIC(Cpage_Detect, CDialogEx)

Cpage_Detect::Cpage_Detect(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage_Detect::IDD, pParent)
{

}

Cpage_Detect::~Cpage_Detect()
{
}

void Cpage_Detect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage_Detect, CDialogEx)
END_MESSAGE_MAP()


// Cpage_Detect 消息处理程序
