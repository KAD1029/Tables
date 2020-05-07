#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorted_table
{
private:
	//abc

	vector<vector<int>> v;
	int max_size;
	int cur_size;

	int max(const int a, const int b)
	{
		if (a > b)
			return a;
		return b;
	}

	int min(const int a, const int b)
	{
		if (a < b)
			return a;
		return b;
	}

	int binary_search(const vector<vector<int>>& v, int val, int size)
	{
		int a = 0, b = size - 1;
		while (a < b - 1)
		{
			if (v[(b - a) / 2][0] < val)
				a = max((b - a) / 2, a + 1);
			else
				b = min((b - a) / 2, b - 1);
		}
		if (a == b)
		{
			if (val <= v[a][0])
				return a;
			else
				return a + 1;
		}
		else
		{
			if (val <= v[a][0])
				return a;
			else if (val <= v[b][0])
				return b;
			else
				return b + 1;
		}
	}

public:

	Sorted_table()
	{
		cur_size = 0;
		max_size = 0;
	}

	Sorted_table(const vector<vector<int>>& _new)
	{
		v = _new;
		cur_size = _new.size();
		max_size = cur_size;
		sort(v.begin(), v.end());
	}

	void insert(const int key, const int value)
	{
		if (cur_size == max_size)
		{
			max_size = max_size * 1.3 + 1;
			v.resize(max_size);
		}

		int pos = binary_search(v, key, cur_size);
		for (int i = cur_size; i > pos; --i)
		{
			v[i] = v[i - 1];
		}
		v[pos] = { key, value };
		cur_size++;

	}

	void del(const int key)
	{
		int pos = binary_search(v, key, cur_size);
		for (int i = pos; i < cur_size - 1; i++)
		{
			v[i] = v[i + 1];
		}
		cur_size--;
	}

	int val(const int key)
	{
		int pos = binary_search(v, key, cur_size);
		return v[pos][1];
	}

	int size()
	{
		return cur_size;
	}

	friend ostream& operator<<(ostream& out, Sorted_table a);
};

ostream& operator<<(ostream& out, Sorted_table a)
{
	out << "{ ";
	for (int i = 0; i < a.cur_size; i++)
	{
		out << "( " << a.v[i][0] << ", " << a.v[i][1] << " ) ";
	}
	out << "}";
	return out;
}