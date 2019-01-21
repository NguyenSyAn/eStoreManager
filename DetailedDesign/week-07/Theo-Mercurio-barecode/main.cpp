//
//  main.cpp
//  Codebare
//
//  Created by Theo Mercurio on 05/11/2018.
//  Copyright © 2018 Theo Mercurio. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <map>

// Those datas come from import
std::map<int, std::vector<int>> array_of_all_ids_mapped_to_codes = { { 1, { 3, 2, 2, 5, 1, 5, 9, 4 } }, { 2, { 2, 8, 7, 2, 1, 9, 3, 6 } } };
std::map<int, std::string> array_of_all_ids_mapped_to_names = { { 1, "Saucisson" }, { 2, "Baguette"} };

bool Contains(std::vector<int> code, std::map<int, std::vector<int>> arr) {
    for (auto elem: arr) {
        if (elem.second == code) {
            return true;
        }
    }
    return false;
}

int findElement(std::vector<int> value, std::map<int, std::vector<int>> arr) {
    int found = NULL;
    for (auto elem : arr) {
        if (elem.second == value) {
            found = elem.first;
            break;
        }
    }
    return found;
}

std::string findElement(int value, std::map<int, std::string> arr) {
    std::string found = NULL;
    for (auto elem : arr) {
        if (elem.first == value) {
            found = elem.second;
            break;
        }
    }
    return found;
}

int getMax(std::map<int, std::vector<int>> arr) {
    int max = 0;
    for (auto elem: arr) {
        if (max < elem.first) {
            max = elem.first;
        }
    }
    return max;
}

class Product {
private:
    int id;
    std::vector<int> code;
    std::string name;
public:
    Product(std::vector<int> code = {}, std::string name = "") {
        if (!code.size() || !Contains(code, array_of_all_ids_mapped_to_codes)) {
            setId(id);
            // You should display a message to inform the user that a code has been created for this product
            setCode(code);
            setName(name);
            // Stock new product into datas imported
            array_of_all_ids_mapped_to_codes[id] = code;
        }
        else {
            setId(findElement(code, array_of_all_ids_mapped_to_codes));
            setCode(code);
            setName(findElement(id, array_of_all_ids_mapped_to_names));
        }
    }
    int getId() {
        return id;
    }
    std::vector<int> getCode() {
        return code;
    }
    std::string getStringCode() {
        std::string stringCode = "";
        for (auto e : code) {
            stringCode += std::to_string(e);
        }
        return stringCode;
    }
    std::string getName() {
        return name;
    }
    void setId(int _id) {
        if (_id) {
            id = _id;
        }
        else {
            id = getMax(array_of_all_ids_mapped_to_codes) + 1;
        }
    }
    void setCode(std::vector<int> _code) {
        int len = 8;
        if (_code.size() == len) {
            code = _code;
        }
        else {
            std::vector<int> arr(len, 0);
            for (int i = 0; i < len; i++) {
                arr[i] = rand() % 10;
            }
            code = arr;
        }
    }
    void setName(std::string _name) {
        if (_name.size() == 0) {
            std::cout << "Enter product name: ";
            std::getline(std::cin, _name, '\n');
        }
        name = _name;
    }
};

int main(int argc, char* argv[])
{
    srand((unsigned)time(0));
    /*
     ------------------------------------------------------------------
     /!\ POSSIBLE INITIAL VALUES TO SET UP BEFORE RUNNING THIS CODE /!\
     ------------------------------------------------------------------
     
     1) Create new product
     std::vector<int> code = {};
     std::string name = "";
     
     2) Check if this code exists. If not: create new code for the mentionned name
     std::vector<int> code = {1, 2, 3, 4, 5, 6, 7, 8};
     std::string name = "Chocolatine";
     
     3) Check if this code exists. If yes: show product name.
     std::vector<int> code = { 2, 8, 7, 2, 1, 9, 3, 6 };
     std::string name = "";
     
     -------------------------
     
     You need to set up how you import initial datas. They are temporary already initilized at the very top of this code.
     */
    std::vector<int> code = {};
    std::string name = "";
    Product p = Product();
    printf("Code: %s, id: %d, name: %s\n", p.getStringCode().c_str(), p.getId(), p.getName().c_str());
    getchar();
    return 0;
}

