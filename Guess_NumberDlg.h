// Guess_NumberDlg.h : 头文件
//
#include "Guess.h"
#include "afxwin.h"

#pragma once


// CGuess_NumberDlg 对话框
class CGuess_NumberDlg : public CDialog
{
// 构造
public:
	CGuess_NumberDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GUESS_NUMBER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
