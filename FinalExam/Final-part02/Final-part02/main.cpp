#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <future>
using namespace std;

struct Permit
{
	unsigned int m_bitPattern;
	char m_number[8];
};

class PermitContainer
{
private:
	vector<Permit> _buf;
public:
	PermitContainer() {
		Permit data;
		unsigned int d;
		std::ifstream input;
		input.open("permits.bin", std::ios::in | std::ios::binary);
		while (input) {
			data.m_bitPattern = 0;
			if (input.eof())
				break;
			int readSize = sizeof(data);
			input.read((char*)&data, readSize);

			_buf.push_back(data);
		}
	}

	int size()const
	{
		return _buf.size();
	}

	Permit operator[] (const int index)const
	{
		return _buf[index];
	}

	std::future<vector<Permit>> findExpired(int start, int end) const
	{
		PermitContainer self = *this;
		return std::async(std::launch::async, [=]()
		{
			vector<Permit> ret;
			int i = start;
			for (; i < end; i++)
				if ((_buf[i].m_bitPattern & (1u << 4)))
					ret.push_back(_buf[i]);
			return ret;
		});

	}

	PermitContainer(const PermitContainer&) = delete;
	PermitContainer& operator=(const PermitContainer&) = delete;
	PermitContainer(const PermitContainer&&) = delete;
	~PermitContainer() {};
};

string getKey(const Permit& c)
{
	int i;
	string ret = "";
	for (i = 0; i < 7; ++i)
		if (c.m_bitPattern & (1u << (6 - i)))
			ret += 'x';
		else
			ret += '.';
	return ret;
}

int main()
{
	char ch[1024];
	PermitContainer cc;
	int i, k;
	int count = (cc.size() / 4);
	std::future<vector<Permit>> a = cc.findExpired(0, count);
	std::future<vector<Permit>> b = cc.findExpired(count, count * 2);
	std::future<vector<Permit>> c = cc.findExpired(count * 2, count * 3);
	std::future<vector<Permit>> d = cc.findExpired(count * 3, cc.size());
	vector<Permit> aRet[4];
	aRet[0] = a.get();
	aRet[1] = b.get();
	aRet[2] = c.get();
	aRet[3] = d.get();
	for (const vector<Permit>& buf : aRet)
	{
		for (const Permit& data : buf) {
			cout << data.m_number << ":" << getKey(data) << endl;
			
		}
	}
	return 0;
}