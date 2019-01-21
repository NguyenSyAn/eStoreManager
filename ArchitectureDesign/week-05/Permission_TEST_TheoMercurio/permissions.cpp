#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "tools.h"
#include "User.h"

namespace permissions {
	void GetRole() {
		bool gotName = false;
		std::string readName, readRole;
		std::ifstream file("Roles.txt", std::ios::in);
		while ((file >> readName >> readRole) && (!gotName)) {
			if (readName == "Name") { continue; }
			if (readName == user.GetName()) { user.SetRole(readRole); gotName = true; }
		}
		file.close();
	}

	void GetPermissions() {
		bool readFunctionNames = true, readFunctionValues = false;
		int count = 0;
		std::string word;
		std::vector<std::string> functionList;
		std::ifstream file("Permissions.txt", std::ios::in);
		user.AddPermission("Permissions");
		while (file >> word) {
			if (word == "Role") { continue; }
			if (word == "Administrator") { readFunctionNames = false; }
			if (word == user.GetRole()) { readFunctionValues = true; continue; }
			if (readFunctionNames) { functionList.push_back(word); }
			if (readFunctionValues) {
				if (word.length() == 1) { 
					if (word == "1") { user.AddFunction(functionList[count], "Permissions"); }
					count++;
				}
				else { readFunctionValues = false; break; }
			}
		}
		file.close();
		for (auto function : functionList) {
			if (!tools::ContainsStr(function, user.GetPermissions()["Permissions"])) { continue; }
			bool readFunctionNames = true, readFunctionValues = false;
			int count = 0;
			std::string permissionName = "Permission" + function, word;
			std::vector<std::string> functionList;
			std::ifstream file(permissionName +".txt", std::ios::in);
			if (file) {
				user.AddPermission(permissionName);
				while (file >> word) {
					if (word == "Role") { continue; }
					if (word == "Administrator") { readFunctionNames = false; }
					if (word == user.GetRole()) { readFunctionValues = true; continue; }
					if (readFunctionNames) { functionList.push_back(word); }
					if (readFunctionValues) {
						if (word.length() == 1) {
							if (word == "1") { user.AddFunction(functionList[count], permissionName); }
							count++;
						}
						else { readFunctionValues = false; break; }
					}
				}
			}
			file.close();
		}
	}

	void Script() {
		GetRole();
		GetPermissions();
		std::cout << "\n"; user.ShowPermissionsDetail();
	}
}
