#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <exception>
#include <string>
using namespace std ;
    class BaseObject
    {
    public:
        virtual ~BaseObject() = default;
        virtual void initialize() = 0;  // Pure virtual function for initialization
        virtual string print() const = 0;  // Pure virtual function for printing
    };

    // Derived class for unsignedint
    class SIntObject : public BaseObject {
    public:
        int value;

        void initialize() override {
            value = 42; // Example initialization
        }

        string print() const override {
            std::cout << "Initialized  int: " << value << std::endl;
            return to_string(value);
        }
    };

    // Derived class for signedint
    class UIntObject : public BaseObject {
    public:
        int value;

        void initialize() override {
            value = -42; // Example initialization
        }

        string print() const override {
            std::cout << "Initialized unsigned int: " << value << std::endl;
            return to_string(value);

        }
    };
    // Derived class for  boolean
    class BooleanObject : public BaseObject {
    public:
        bool value;

        void initialize() override {
            value = true; // Example initialization
        }

        string print() const override {
            std::cout << "Initialized boolean: " << value << std::endl;
            return to_string(value);

        }
    };
    // Derived class for float
    class FloatObject : public BaseObject {
    public:
        float value;

        void initialize() override {
            value = 3.14f; // Example initialization
        }

        string print() const override {
            std::cout << "Initialized float: " << value << std::endl;
            return to_string(value);
        }
    };

    // Derived class for double
    class DoubleObject : public BaseObject {
    public:
        double value;

        void initialize() override {
            value = 2.718; // Example initialization

        }

        string print() const override {
            std::cout << "Initialized double: " << value << std::endl;
            return to_string(value);

        }
    };

    // Derived class for char
    class CharObject : public BaseObject {
    public:
        char value;

        void initialize() override {
            value = 'A'; // Example initialization
        }

        string print() const override {
            std::cout << "Initialized char: " << value << std::endl;
            return to_string(value);

        }
    };



