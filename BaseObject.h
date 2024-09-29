#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <exception>
class BaseObject
{
public:
    virtual ~BaseObject() = default;
    virtual void initialize() = 0;  // Pure virtual function for initialization
    virtual void print() const = 0;  // Pure virtual function for printing
};

// Derived class for unsignedint
class SIntObject : public BaseObject {
public:
    int value;

    void initialize() override {
        value = 42; // Example initialization
    }

    void print() const override {
        std::cout << "Initialized  int: " << value << std::endl;
    }
};

// Derived class for signedint
class UIntObject : public BaseObject {
public:
    int value;

    void initialize() override {
        value = -42; // Example initialization
    }

    void print() const override {
        std::cout << "Initialized unsigned int: " << value << std::endl;
    }
};
// Derived class for  boolean
class BooleanObject : public BaseObject {
public:
    int value;

    void initialize() override {
        value = true; // Example initialization
    }

    void print() const override {
        std::cout << "Initialized boolean: " << value << std::endl;
    }
};
// Derived class for float
class FloatObject : public BaseObject {
public:
    float value;

    void initialize() override {
        value = 3.14f; // Example initialization
    }

    void print() const override {
        std::cout << "Initialized float: " << value << std::endl;
    }
};

// Derived class for double
class DoubleObject : public BaseObject {
public:
    double value;

    void initialize() override {
        value = 2.718; // Example initialization
    }

    void print() const override {
        std::cout << "Initialized double: " << value << std::endl;
    }
};

// Derived class for char
class CharObject : public BaseObject {
public:
    char value;

    void initialize() override {
        value = 'A'; // Example initialization
    }

    void print() const override {
        std::cout << "Initialized char: " << value << std::endl;
    }
};



