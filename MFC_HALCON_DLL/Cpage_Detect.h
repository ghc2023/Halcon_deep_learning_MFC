#pragma once


// Cpage_Detect �Ի���

class Cpage_Detect : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Detect)

public:
	Cpage_Detect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage_Detect();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
