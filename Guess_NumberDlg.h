// Guess_NumberDlg.h : ͷ�ļ�
//
#include "Guess.h"
#include "afxwin.h"

#pragma once


// CGuess_NumberDlg �Ի���
class CGuess_NumberDlg : public CDialog
{
// ����
public:
	CGuess_NumberDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GUESS_NUMBER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	Guess m_Guess;
public:
	afx_msg void OnBnClickedAnswer();
	DWORD m_dwBegin;
	DWORD m_dwEnd;
	afx_msg void OnBnClickedInit();
	afx_msg void OnBnClickedOk();
	DWORD m_dwEdit;
	CListBox m_InfoList;
};
