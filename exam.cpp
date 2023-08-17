#include"MyVector.cpp"

int main()
{
	MyVector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (auto i:v)
	{
		cout <<i<< " ";
	}
	cout << endl;

	v.pop_back();
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	v.insert(v.begin() + 2, 100);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	v.erase(v.end() - 1);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	if (!v.empty())
	{
		cout << "size : " << v.size() << endl;
		cout << "capacity : " << v.capacity() << endl;
	}

	cout << v[5] << endl;

	MyVector<int>v1(v);

	MyVector<int> v2;
	v2 = v;
	int x = (v2 == v);
	if (x == 1)
		cout << "TRUE" << endl;
	else 
		cout << "FALSE" << endl;

	system("pause");
	return 0;
}
