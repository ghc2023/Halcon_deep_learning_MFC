// Cpage_Segment.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "Cpage_Segment.h"
#include "afxdialogex.h"


// Cpage_Segment �Ի���

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


// Cpage_Segment ��Ϣ�������
