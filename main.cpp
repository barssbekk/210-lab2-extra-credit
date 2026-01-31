#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
    void setFirstName(string firstName) { this->firstName = firstName; }
    void setLastName(string lastName) { this->lastName = lastName; }
    
    virtual ~Person() = default;
    Person(string firstName, string lastName) : firstName(firstName), lastName(lastName) {}
    
    string getName() const { return firstName + " " + lastName; };
    
    void printFullName() {
        cout << firstName << " " << lastName << '\n';
    }
    
    virtual void printInfo() {
        cout << "First name: " << firstName << '\n';
        cout << "Last name: " << lastName << '\n';
    }
    
    static void printPeople(vector<Person*> people) {
        for (auto person : people) {
            person->printInfo();
        }
    }
    
protected:
    string firstName, lastName;

};

class Employee : public Person {
public:
    Employee(string firstName, string lastName, string department) : Person(firstName, lastName), department(department) {}
    
    void setDepartment(string department) { this->department = department; };
    string getDepartment() { return department; };
    
    void printInfo() override {
        Person::printInfo();
        cout << "Department: " << getDepartment() << '\n';
    }
    
private:
    string department;
};

int main() {
    // Testing
    Person meLikePerson{"Barsbek", "Azamatov"};
    Employee me{"Kirito", "Ashito", "SWE"};
    
    vector<Person*> people{};
    people.push_back(&meLikePerson);
    people.push_back(&me);
    
    Person::printPeople(people);
  
    return 0;
}

