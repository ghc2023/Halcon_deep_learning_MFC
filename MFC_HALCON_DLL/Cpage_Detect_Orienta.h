#pragma once


// Cpage_Detect_Orienta �Ի���

class Cpage_Detect_Orienta : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Detect_Orienta)

public:
	Cpage_Detect_Orienta(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage_Detect_Orienta();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECT_ORIENTA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
