#pragma once
#ifndef TYPEFACTORY_H
#define TYPEFACTORY_H


#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <any>
#include <functional>

using namespace std;
class TypeFactory
{
public:
    TypeFactory() {

        ///matching the subtypes to types
        subtype2type["char"] = { "char", "char16_t", "char32_t", "wchar_t" };
        subtype2type["Sinteger"] = { "signed int", "signed short int", "signed char", "singed long int", "signed long long int", "int"};
        subtype2type["Uinteger"] = { "unsigned char", "unsigned short int", "unsigned int", "unsigned long int", "unsigned long long int" };
        subtype2type["float"] = { "float", "double", "long double" };
        subtype2type["boolean"] = { "bool" };
        subtype2type["void"] = { "void" };
        subtype2type["Nuller"] = { "decltype(nullptr)" };
        ///matching the types to objects
        type2object["char"] = []() { return std::make_any<char>(' '); };
        type2object["Sinteger"] = []() { return std::make_any<int>(0); };
        type2object["Uinteger"] = []() { return std::make_any<int>(0); };
        type2object["float"] = []() { return std::make_any<float>(0.0); };
        type2object["boolean"] = []() { return std::make_any<int>(0); };
      // type2object["void"] = []() {return make_any<void>(0.0); };
    //    type2object["Nuller"] = []() { return std::make_any<decltype(nullptr)>(0); };


    };

    any Create(string subtype) {
        try {
            string type;
           // cout << endl;
            for (auto i : subtype2type) {
             //   cout << i.first<<"  ";
              /*  for (auto j : i.second) {
                    cout << j<<endl;
                }*/
                auto  findtype = i.second.find(subtype);
                if (findtype != i.second.end()) {

                    type = i.first;
                }

            }
            auto it = type2object.find(type);
            if (it != type2object.end()) {
                return it->second();

            }
            else {

                cout << "sorry we do not support this type " << type << endl;
            }
        }
        catch(exception e) {
            cout << "Error: " << e.what() << endl;
            return nullptr;
        }

    }
protected:

private:
    unordered_map <string, set<string>> subtype2type;

    unordered_map<string, function<std::any()>> type2object; // Use function to store lambdas


};

#endif // TYPEFACTORY_H
