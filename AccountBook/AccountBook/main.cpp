#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <locale>
#include "UserData.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stod;
using std::vector;
using std::map;
using std::getline;

bool is_number(const std::string& s)
{
	std::locale loc;
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it, loc)) ++it;
	return !s.empty() && it == s.end();
}

int main() {
	int state = 0;
	vector<UserData> users;
	map<string, UserData> map;
	cout << "Welcome to Account Book!" << endl;
	cout << "enter the name of the participant" << endl;
	while (true) {

		if (state == 0) {
			cout << "Enter payer name and the amount of money he/she paid, enter empty line when finished" << endl;
			cout << "Please type in payer name: ";
			string name;
			getline(cin, name);
			//cout << "name length: " << name.length() << endl;
			if (name.length() == 0) state++;
			else {
				if (map.find(name) == map.end()) {
					cout << "Please type in money he/she paid: (if not pay anything leave it blank) ";
					string money_str;
					getline(cin, money_str);
					double money = 0;
					if (money_str.length() != 0) {
						if (!is_number(money_str)){
							cout << "invalid money value!" << endl;
						continue;
					}

					money = stod(money_str);
				}
				UserData user(name, money);
				users.push_back(user);
				map[name] = user;
			}
		else {
			cout << name << " already existed!" << endl;
		}

		}
	}
		else if (state == 1) {
			if (users.empty()) {
				cout << "empty input!" << endl;
			}
			else {
				cout << "Now computing the amount of money that every one should receive or pay:" << endl;
				double aver = 0;
				for (std::vector<UserData>::iterator it = users.begin(); it != users.end(); ++it) {
					aver += it->getMoney();
				}
				aver /= users.size();
				cout << "everyone should pay: " << aver << " on average" << endl;
				cout << "+ for receiving money, - for pay money to others" << endl;
				for (std::vector<UserData>::iterator it = users.begin(); it != users.end(); ++it) {
					double diff = it->getMoney() - aver;
					string sign = "";
					if (diff > 0) sign = "+";
					cout << it->getName() << '\t' << sign << diff << endl;
				}
			}
			state = 0;
		}

}
return 1;
}