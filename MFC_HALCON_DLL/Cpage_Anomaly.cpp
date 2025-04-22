// Cpage_Anomaly.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "Cpage_Anomaly.h"
#include "afxdialogex.h"


// Cpage_Anomaly 对话框

IMPLEMENT_DYNAMIC(Cpage_Anomaly, CDialogEx)

Cpage_Anomaly::Cpage_Anomaly(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage_Anomaly::IDD, pParent)
{

}

Cpage_Anomaly::~Cpage_Anomaly()
{
}

void Cpage_Anomaly::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage_Anomaly, CDialogEx)
END_MESSAGE_MAP()


// Cpage_Anomaly 消息处理程序
