#pragma once


// Cpage_Anomaly �Ի���

class Cpage_Anomaly : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Anomaly)

public:
	Cpage_Anomaly(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage_Anomaly();

// �Ի�������
	enum { IDD = IDD_DIALOG_ANOMALY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
