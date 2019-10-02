class Guess
{
private:
	unsigned long m_nGuessNum;
	unsigned int m_seed;
public:
	Guess();
	void Init(unsigned long min,unsigned long max);
	bool Compare(unsigned long answer,int &same1,int &same2);
	inline unsigned long GetAnswer() { return m_nGuessNum; }
private:
	void Random_Seed(int seed=0);
	int Random_Int(int min, int max);
	float Random_Float(float min, float max);
	void ToArray(unsigned long num,char *a);
};