// Cpage_Class.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "Cpage_Class.h"
#include "afxdialogex.h"

#include "MY_CLASS_INFER_PARA.h"
#include "MY_CLASS_EVALUE_PARA.h"
#include "MY_CLASS_TRAIN_PARA.h"
#include  "MY_CLASS_PROPRE_PARA.h"
// Cpage_Class �Ի���;

CMY_CLASS_INFER_PARA DLG_class_infer_para;
CMY_CLASS_TRAIN_PARA DLG_class_train_para;
CMY_CLASS_PROPRE_PARA  DLG_class_propre_para;
CMY_CLASS_EVALUE_PARA DLG_class_evalue_para;

IMPLEMENT_DYNAMIC(Cpage_Class, CDialogEx)

Cpage_Class::Cpage_Class(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage_Class::IDD, pParent)
{

}

Cpage_Class::~Cpage_Class()
{
}

void Cpage_Class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage_Class, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PREPRO_PARA_CLASS, &Cpage_Class::OnBnClickedButtonPreproParaClass)
	ON_BN_CLICKED(IDC_BUTTON_TRAIN_PARA_CLASS, &Cpage_Class::OnBnClickedButtonTrainParaClass)
	ON_BN_CLICKED(IDC_BUTTON_EVALUA_PARA_CLASS, &Cpage_Class::OnBnClickedButtonEvaluaParaClass)
	ON_BN_CLICKED(IDC_BUTTON_INFER_PARA_CLASS, &Cpage_Class::OnBnClickedButtonInferParaClass)
END_MESSAGE_MAP()


// Cpage_Class ��Ϣ�������;

//����Ԥ��������Ի���;
void Cpage_Class::OnBnClickedButtonPreproParaClass()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;

	DLG_class_propre_para.DoModal();

}

//����ѵ�������Ի���;
void Cpage_Class::OnBnClickedButtonTrainParaClass()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;

	DLG_class_train_para.DoModal();
}

//�������������Ի���;
void Cpage_Class::OnBnClickedButtonEvaluaParaClass()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;
	
	DLG_class_evalue_para.DoModal();

}

//�����ƶϲ����Ի���;
void Cpage_Class::OnBnClickedButtonInferParaClass()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;
	DLG_class_infer_para.DoModal();
}
