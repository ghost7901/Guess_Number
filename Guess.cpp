#include "stdafx.h"
#include <mmsystem.h>
#include "guess.h"

#pragma comment(lib,"winmm.lib")

Guess::Guess()
{
	m_seed=0;
	m_nGuessNum=0;
}

void Guess::Init(unsigned long min,unsigned long max)
{
	Random_Seed();
	m_nGuessNum=Random_Int(min,max);
}

void Guess::Random_Seed(int seed)
{
	if(!seed) m_seed=timeGetTime();
	else m_seed=seed;
}

int Guess::Random_Int(int min, int max)
{
	m_seed=214013*m_seed+2531011;
	return min+(m_seed ^ m_seed>>15)%(max-min+1);
}

float Guess::Random_Float(float min, float max)
{
	m_seed=214013*m_seed+2531011;
	return min+(m_seed>>16)*(1.0f/65535.0f)*(max-min);
}

void Guess::ToArray(unsigned long num,char *a)
{
	int i=0;
	do
	{
		a[i++]=num%10;
		num/=10;
	}while(num);
}

bool Guess::Compare(unsigned long answer,int &same1,int &same2)
{
	if(answer==m_nGuessNum) return true;

	char a[100],b[100];
	memset(a,-1,100);
	memset(b,-1,100);
	ToArray(m_nGuessNum,a);
	ToArray(answer,b);

	same1=same2=0;
	
	int i=0;
	do
	{
		if(a[i]==b[i]) same2++;
	}while(a[++i]!=-1 && b[i]!=-1);

	
	for(int i=0;b[i]!=-1;i++)
		for(int j=0;a[j]!=-1;j++)
			if(b[i]==a[j])
			{
				same1++;
				a[j]=-2;
				break;
			}

	return false;
}