#pragma once


// Cpage_Class �Ի���

class Cpage_Class : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Class)

public:
	Cpage_Class(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage_Class();

// �Ի�������
	enum { IDD = IDD_DIALOG_CLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPreproParaClass();
	afx_msg void OnBnClickedButtonTrainParaClass();
	afx_msg void OnBnClickedButtonEvaluaParaClass();
	afx_msg void OnBnClickedButtonInferParaClass();
};
