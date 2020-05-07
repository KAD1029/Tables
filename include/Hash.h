#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Hash_table
{
private:

	vector<vector<int>> v;
	int max_size;
	int cur_size;
	int a, b, p;

	int func(int i)
	{
		int res = ((a * i + b) % p) % max_size;
		return res;
	}

public:

	Hash_table(int n)
	{
		cur_size = 0;
		max_size = n * n;

		p = rand() % 100;
		a = rand() % (p - 1) + 1;
		b = rand() % p;

		v.resize(max_size, { NULL, NULL });
	}

	void insert(const int key, const int value)
	{
		v[func(key)] = { key, value };
		++cur_size;
	}

	void del(const int key)
	{
		v[func(key)] = { NULL, NULL };
		--cur_size;
	}

	int val(const int key)
	{
		return v[func(key)][1];
	}

	int size()
	{
		return cur_size;
	}

	friend ostream& operator<<(ostream& out, Hash_table a);

};

ostream& operator<<(ostream& out, Hash_table a)
{
	out << "{ ";
	for (int i = 0; i < a.max_size; i++)
	{
		if (a.v[i][1])
			out << "( " << a.v[i][0] << ", " << a.v[i][1] << " ) ";
	}
	out << "}";
	return out;
}