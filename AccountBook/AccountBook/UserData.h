#pragma once
#include <string>

using std::string;

class UserData
{
public:
	UserData();
	UserData(string n, double m) { money = m; name = n; }
	~UserData();
	void setName(string n) { name = n; }
	void setMoney(double m) { money = m; }
	string getName() { return name; }
	double getMoney() { return money; }
private:
	string name;
	double money;
};

