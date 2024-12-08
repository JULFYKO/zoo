#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::cin;

class Animal {
protected:
    string name;
    size_t age;

public:
    Animal(const string& name, size_t age) : name(name), age(age) {}
    virtual ~Animal() {}
    string getName() const { return name; }
    size_t getAge() const { return age; }
    void setName(const string& newName) { name = newName; }
    void setAge(size_t newAge) { age = newAge; }
    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const = 0;
};

class Cat : public Animal {
    string color;

public:
    Cat(const string& name, size_t age, const string& color)
        : Animal(name, age), color(color) {}

    void sound() const override { cout << "Meow\n"; }
    void type() const override { cout << "Cat\n"; }
    void show() const override {
        cout << "Type: Cat, Name: " << name << ", Age: " << age
            << ", Color: " << color << '\n';
    }
};

class Dog : public Animal {
    string breed;

public:
    Dog(const string& name, size_t age, const string& breed)
        : Animal(name, age), breed(breed) {}

    void sound() const override { cout << "Bark\n"; }
    void type() const override { cout << "Dog\n"; }
    void show() const override {
        cout << "Type: Dog, Name: " << name << ", Age: " << age
            << ", Breed: " << breed << '\n';
    }
};

class Parrot : public Animal {
    string language;

public:
    Parrot(const string& name, size_t age, const string& language)
        : Animal(name, age), language(language) {}

    void sound() const override { cout << "Carrr\n"; }
    void type() const override { cout << "Parrot\n"; }
    void show() const override {
        cout << "Type: Parrot, Name: " << name << ", Age: " << age
            << ", Language: " << language << '\n';
    }
};
class HomeZoo {
    vector<Animal*> zoo;

public:
    HomeZoo() = default;

    ~HomeZoo() {
        for (Animal* animal : zoo) {
            delete animal;
        }
        zoo.clear();
    }

    void add() {
        string type, name, extra;
        size_t age;

        cout << "Enter animal type (Cat, Dog, Parrot): ";
        cin >> type;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        if (type == "Cat") {
            cout << "Enter color: ";
            cin >> extra;
            zoo.push_back(new Cat(name, age, extra));
        }
        else if (type == "Dog") {
            cout << "Enter breed: ";
            cin >> extra;
            zoo.push_back(new Dog(name, age, extra));
        }
        else if (type == "Parrot") {
            cout << "Enter language: ";
            cin >> extra;
            zoo.push_back(new Parrot(name, age, extra));
        }
        else {
            cout << "Invalid type.\n";
        }
    }

    void addRandom() {
        zoo.push_back(new Cat("murchik", 2, "gray"));
        zoo.push_back(new Dog("sharik", 4, "Labrador"));
        zoo.push_back(new Parrot("kesha", 1, "polish"));
    }

    void showAll() const {
        for (const Animal* animal : zoo) {
            animal->show();
        }
    }

    void edit(size_t index) {
        if (index >= zoo.size()) {
            cout << "Invalid index.\n";
            return;
        }
        string newName;
        size_t newAge;
        cout << "Enter new name: ";
        cin >> newName;
        cout << "Enter new age: ";
        cin >> newAge;

        zoo[index]->setName(newName);
        zoo[index]->setAge(newAge);
    }

    void remove(size_t index) {
        if (index >= zoo.size()) {
            cout << "Invalid index.\n";
            return;
        }
        delete zoo[index];
        zoo.erase(zoo.begin() + index);
    }

    void removeAll() {
        for (Animal* animal : zoo) {
            delete animal;
        }
        zoo.clear();
    }
};
