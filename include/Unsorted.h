#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Unsorted_table
{
private:

	vector<vector<int>> v;
	int max_size;
	int cur_size;

public:

	Unsorted_table()
	{
		cur_size = 0;
		max_size = 0;
	}

	Unsorted_table(const vector<vector<int>>& _new)
	{
		v = _new;
		cur_size = _new.size();
		max_size = cur_size;
	}

	void insert(const int key, const int value)
	{
		if (cur_size == max_size)
		{
			max_size = max_size * 1.3 + 1;
			v.resize(max_size);
		}
		v[cur_size] = { key, value };
		++cur_size;
	}

	void del(const int key)
	{
		for (int i = 0; i < cur_size; i++)
		{
			if (v[i][0] == key)
			{
				v[i] = v[cur_size - 1];
				cur_size--;
				return;
			}
		}
		throw 1;
	}

	int val(const int key)
	{
		for (int i = 0; i < cur_size; i++)
		{
			if (v[i][0] == key)
				return v[i][1];
		}
		throw 1;
	}

	int size()
	{
		return cur_size;
	}

	friend ostream& operator<<(ostream& out, Unsorted_table a);
};

ostream& operator<<(ostream& out, Unsorted_table a)
{
	out << "{ ";
	for (int i = 0; i < a.cur_size; i++)
	{
		out << "( " << a.v[i][0] << ", " << a.v[i][1] << " ) ";
	}
	out << "}";
	return out;
}