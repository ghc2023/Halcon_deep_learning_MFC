// MY_CLASS_INFER_PARA.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "MY_CLASS_INFER_PARA.h"
#include "afxdialogex.h"


// CMY_CLASS_INFER_PARA �Ի���

IMPLEMENT_DYNAMIC(CMY_CLASS_INFER_PARA, CDialogEx)

CMY_CLASS_INFER_PARA::CMY_CLASS_INFER_PARA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMY_CLASS_INFER_PARA::IDD, pParent)
	, cs_ImageDir(_T("C:/Users/Public/Documents/MVTec/HALCON-19.11-Progress/examples/images/pill"))
	, d_class_infer_scalewindows(1.1)
	, i_class_infer_BatchSizeInference(1)
	, cs_class_infer_KeysForDisplay(_T("classification_result"))
	, i_class_infer_MaxNumberofRandomSamples(10)
{

}

CMY_CLASS_INFER_PARA::~CMY_CLASS_INFER_PARA()
{
}

void CMY_CLASS_INFER_PARA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cs_ImageDir);
	DDX_Text(pDX, IDC_EDIT3, d_class_infer_scalewindows);
	DDX_Text(pDX, IDC_EDIT2, i_class_infer_BatchSizeInference);
	DDX_Text(pDX, IDC_EDIT4, cs_class_infer_KeysForDisplay);
	DDX_Text(pDX, IDC_EDIT5, i_class_infer_MaxNumberofRandomSamples);
	DDX_Control(pDX, IDC_COMBO_CLASS_INFER_USEGPU, c_combobox_class_infer_usegpu);

	// Ϊ��Ͽ�ؼ����б������б��none�� ;  
	c_combobox_class_infer_usegpu.AddString(_T("true"));
	// Ϊ��Ͽ�ؼ����б������б��all_channels��;   
	c_combobox_class_infer_usegpu.AddString(_T("false"));
	// Ĭ��ѡ���һ��   ;
	c_combobox_class_infer_usegpu.SetCurSel(0);

}


BEGIN_MESSAGE_MAP(CMY_CLASS_INFER_PARA, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CMY_CLASS_INFER_PARA::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CMY_CLASS_INFER_PARA ��Ϣ�������


void CMY_CLASS_INFER_PARA::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
