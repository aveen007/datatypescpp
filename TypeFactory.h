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
#include<utility>

using namespace std;
class TypeFactory
{
public:
    // Hash function for std::pair
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            return hash1 ^ hash2; // Combine the hashes
        }
    };
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
        type2object["char"] = []() { return std::make_unique<CharObject>(); };
        type2object["Sinteger"] = []() { return std::make_unique<SIntObject>(); };
        type2object["Uinteger"] = []() { return std::make_unique<UIntObject>(); };
        type2object["float"] = []() { return std::make_unique<FloatObject>(); };
        type2object["boolean"] = []() { return std::make_unique<BooleanObject>(); };
        /// <summary>
        /// defining operations
        /// </summary>
         
        operations[{"char", "char"}] = { "+", "-" };   // char can be concatenated or compared
        operations[{"Sinteger", "Sinteger"}] = { "+", "-", "*", "/", "%" };// arithmetic operations
        operations[{"Uinteger", "Uinteger"}] = { "+", "-", "*", "/", "%" }; // arithmetic operations
        operations[{"float", "float"}] = { "+", "-", "*", "/", "%" }; // arithmetic operations
        operations[{"boolean", "boolean"}] = { "AND", "OR", "NOT" }; // boolean operations
        operations[{"boolean", "boolean"}] = { "XOR" }, // additional boolean interpretation
            operations[{"Sinteger", "float"}] = { "+", "-", "*", "/" }; // promoting Sinteger to float
        operations[{"Uinteger", "float"}] = { "+", "-", "*", "/" }; // promoting Uinteger to float
        operations[{"Sinteger", "boolean"}] = { "+", "-" }; // casting boolean to integer
        operations[{"Uinteger", "boolean"}] = { "+", "-" }; // casting boolean to integer
        operations[{"char", "Sinteger"}] = { "+" }; // only concatenation
        operations[{"char", "Uinteger"}] = { "+" }; // only concatenation
        operations[{"char", "float"}] = { "+" }; // only concatenation (float needs casting)
        operations[{"Sinteger", "Uinteger"}] = { "+", "-", "*", "/", "%" }; // arithmetic operations
        operations[{"float", "Sinteger"}] = { "+", "-", "*", "/" }; // promoting Sinteger to float
        operations[{"float", "Uinteger"}] = { "+", "-", "*", "/" }; // promoting Uinteger to float
        operations[{"Sinteger", "char"}] = { "+" }; // concatenation
        operations[{"Uinteger", "char"}] = { "+" }; // concatenation
        operations[{"float", "char"}] = { "+" };// float should allow char concatenation


    }
    string subtype2typef(string subtype) {
        string type = "";
        for (auto i : subtype2type) {

            auto  findtype = i.second.find(subtype);
            if (findtype != i.second.end()) {

                type = i.first;
            }

        }
        return type;

    }
    vector <string> subtype2operation(string subtype1, string subtype2) {
       string type1= subtype2typef(subtype1);
       string type2= subtype2typef(subtype2);
        vector< string> validOperations = {};
        auto itt = operations.find({ type1, type2 });
        if (itt != operations.end()) {

            validOperations = itt->second;
        }
        return validOperations;
    }

    unique_ptr<BaseObject> Create(string subtype) {
        try {
            string type=subtype2typef(subtype);
           
            auto it = type2object.find(type);
            if (it != type2object.end()) {
                
              return  it->second();

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

    unordered_map<string, function<unique_ptr<BaseObject>() >> type2object; // Use function to store lambdas
    unordered_map <pair<string, string>, vector<string>, pair_hash> operations;



};

#endif // TYPEFACTORY_H
