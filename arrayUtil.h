struct ArrayUtil{
	void *basePtr;
	int size;
	int length;
};

struct ArrayUtil create(int,int);
int areEqual(struct ArrayUtil a1,struct ArrayUtil a2);