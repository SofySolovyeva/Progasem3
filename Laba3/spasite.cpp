#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
public:
    Vehicle() {
        brand = "не знаю я";
    }

    Vehicle(std::string b) {
        brand = b;
    }

    std::string getBrand() {
        return brand;
    }

    void setBrand(std::string b) {
        brand = b;
    }
};

class Company {
private:
    std::string companyName;
public:
    Company() {
        companyName = "не знаю я";
    }

    Company(std::string name) {
        companyName = name;
    }

    std::string getCompanyName() {
        return companyName;
    }

    void setCompanyName(std::string name) {
        companyName = name;
    }
};

class Employee {
private:
    std::string name;

public:
    int age;

    Employee() {
        name = "не знаю я";
        age = 0;
    }

    Employee(std::string n, int a) {
        name = n;
        age = a;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(std::string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void displayInfo() {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Возраст: " << age << " лет" << std::endl;
    }
};

class Truck : public Vehicle {
private:
    int maxLoad;
public:
    Truck() : Vehicle() {
        maxLoad = 0;
    }

    Truck(std::string b, int load) : Vehicle(b) {
        maxLoad = load;
    }

    Truck(std::string b) : Vehicle(b) {
        maxLoad = 0;
    }

    void setMaxLoad(int load) {
        maxLoad = load;
    }

    int getMaxLoad() {
        return maxLoad;
    }

    void displayInfo() {
        std::cout << "Бренд: " << getBrand() << std::endl;
        std::cout << "Максимальный тоннаж: " << maxLoad << std::endl;
    }
};

class Model : public Vehicle {
private:
    int maxSpeed;

public:
    Model() : Vehicle() {
        maxSpeed = 0;
    }
    
    Model(std::string b, int speed) : Vehicle(b) {
        maxSpeed = speed;
    }
    
    Model(int speed) : Vehicle() {
        maxSpeed = speed;
    }
    
    void setMaxSpeed(int speed) {
        maxSpeed = speed;
    }
    
    int getMaxSpeed() {
        return maxSpeed;
    }
    
    void displayInfo() {
        std::cout << "Модель: " << getBrand() << std::endl;
        std::cout << "Максимальная скорость: " << maxSpeed << " км/ч" << std::endl;
    }
};

int main() {   
    setlocale(LC_CTYPE, "rus");
    
    Truck truck1("Nissan", 4);
    truck1.displayInfo();

    Model model1("X-trail", 190);
    model1.displayInfo();

    Employee employee1("Иванов Иван", 30);
    employee1.displayInfo();

    return 0;
}