// Cpage_Segment.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "Cpage_Segment.h"
#include "afxdialogex.h"


// Cpage_Segment 对话框

IMPLEMENT_DYNAMIC(Cpage_Segment, CDialogEx)

Cpage_Segment::Cpage_Segment(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage_Segment::IDD, pParent)
{

}

Cpage_Segment::~Cpage_Segment()
{
}

void Cpage_Segment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage_Segment, CDialogEx)
END_MESSAGE_MAP()


// Cpage_Segment 消息处理程序
