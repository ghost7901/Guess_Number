// Guess_Number.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CGuess_NumberApp:
// �йش����ʵ�֣������ Guess_Number.cpp
//

class CGuess_NumberApp : public CWinApp
{
public:
	CGuess_NumberApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGuess_NumberApp theApp;
