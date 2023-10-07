#include <iostream>
#include <cstring>

using namespace std;

class Person
{
protected:
    char *name;
    int age;

public:
    Person() : name(nullptr), age(0) {}
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    void print()
    {
        cout << "Name: " << name << "\tAge: " << age << "\t";
    }

    void input()
    {
        char buff[20];
        cout << "Enter Name: ";
        cin.getline(buff, 20);
        delete[] name;
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }

    ~Person()
    {
        delete[] name;
    }

    const char *get_name() const
    {
        return name;
    }

    void set_name(const char *n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    int get_age() const
    {
        return age;
    }

    void set_age(int a)
    {
        age = a;
    }
};

class Student : public Person
{
    char *university;

public:
    Student() : university(nullptr) {}
    Student(const char *n, int a, const char *obj) : Person(n, a)
    {
        university = new char[strlen(obj) + 1];
        strcpy_s(university, strlen(obj) + 1, obj);
    }

    ~Student()
    {
        delete[] university;
    }

    void input(const char *obj)
    {
        delete[] university;
        university = new char[strlen(obj) + 1];
        strcpy_s(university, strlen(obj) + 1, obj);

        Person::input();
    }

    void print()
    {
        Person::print();
        cout << "University: " << university << endl;
    }

    const char *get_university() const
    {
        return university;
    }

    void set_university(const char *obj)
    {
        delete[] university;
        university = new char[strlen(obj) + 1];
        strcpy_s(university, strlen(obj) + 1, obj);
    }
};

class Teacher : public Person
{
    char *school;
    double salary;
    char **subjects;
    int num;

public:
    Teacher() : school(nullptr), subjects(nullptr), num(0) {}
    Teacher(const char *n, int a, const char *school, double salary) : Person(n, a), salary(salary), school(nullptr), subjects(nullptr), num(0)
    {
        set_school(school);
    }

    ~Teacher()
    {
        delete[] school;
        if (subjects)
        {
            for (int i = 0; i < num; i++)
            {
                delete[] subjects[i];
            }
            delete[] subjects;
        }
    }

    void input(const char *school, double salary)
    {
        set_school(school);
        this->salary = salary;
        Person::input();

        cout << "Enter the number of subjects: ";
        cin >> num;
        cin.ignore();
        subjects = new char *[num];
        for (int i = 0; i < num; i++)
        {
            char subject[50];
            cout << "Enter subject " << i + 1 << ": ";
            cin.getline(subject, 50);
            subjects[i] = new char[strlen(subject) + 1];
            strcpy_s(subjects[i], strlen(subject) + 1, subject);
        }
    }

    void print()
    {
        Person::print();
        cout << "School: " << school << "\tSalary: " << salary << endl;
        cout << "Subjects: ";
        for (int i = 0; i < num; i++)
        {
            cout << subjects[i];
            if (i < num - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }

    const char *get_school() const
    {
        return school;
    }

    void set_school(const char *s)
    {
        delete[] school;
        school = new char[strlen(s) + 1];
        strcpy_s(school, strlen(s) + 1, s);
    }

    double get_salary() const
    {
        return salary;
    }

    void set_salary(double s)
    {
        salary = s;
    }

    const char **get_subjects() const
    {
        return (const char **)subjects;
    }

    void set_subjects(const char **sub, int num_2)
    {
        if (subjects)
        {
            for (int i = 0; i < num; i++)
            {
                delete[] subjects[i];
            }
            delete[] subjects;
        }
        num = num_2;
        subjects = new char *[num];
        for (int i = 0; i < num; i++)
        {
            subjects[i] = new char[strlen(sub[i]) + 1];
            strcpy_s(subjects[i], strlen(sub[i]) + 1, sub[i]);
        }
    }
};

class Driver : public Person
{
    char *car_num;
    char *license_num;
    char *series;

public:
    Driver() : car_num(nullptr), license_num(nullptr), series(nullptr) {}
    Driver(const char *n, int a, const char *car, const char *lic_num, const char *ser) : Person(n, a)
    {
        car_num = new char[strlen(car) + 1];
        strcpy_s(car_num, strlen(car) + 1, car);

        license_num = new char[strlen(lic_num) + 1];
        strcpy_s(license_num, strlen(lic_num) + 1, lic_num);

        series = new char[strlen(ser) + 1];
        strcpy_s(series, strlen(ser) + 1, ser);
    }

    ~Driver()
    {
        delete[] car_num;
        delete[] license_num;
        delete[] series;
    }

    void input(const char *car, const char *lic_num, const char *ser)
    {
        delete[] car_num;
        delete[] license_num;
        delete[] series;

        car_num = new char[strlen(car) + 1];
        strcpy_s(car_num, strlen(car) + 1, car);

        license_num = new char[strlen(lic_num) + 1];
        strcpy_s(license_num, strlen(lic_num) + 1, lic_num);

        series = new char[strlen(ser) + 1];
        strcpy_s(series, strlen(ser) + 1, ser);

        Person::input();
    }

    void print()
    {
        Person::print();
        cout << "Car Number: " << car_num << "\tLicense Number: " << license_num << "\tSeries: " << series << endl;
    }

    const char *get_car_number() const
    {
        return car_num;
    }

    void set_car_number(const char *car)
    {
        delete[] car_num;
        car_num = new char[strlen(car) + 1];
        strcpy_s(car_num, strlen(car) + 1, car);
    }

    const char *get_license_number() const
    {
        return license_num;
    }

    void set_license_number(const char *lic_num)
    {
        delete[] license_num;
        license_num = new char[strlen(lic_num) + 1];
        strcpy_s(license_num, strlen(lic_num) + 1, lic_num);
    }

    const char *get_series() const
    {
        return series;
    }

    void set_series(const char *ser)
    {
        delete[] series;
        series = new char[strlen(ser) + 1];
        strcpy_s(series, strlen(ser) + 1, ser);
    }
};

class Doctor : public Person
{
    char *specialty;
    int experience;
    bool family_or_not;

public:
    Doctor() : specialty(nullptr), experience(0), family_or_not(false) {}
    Doctor(const char *n, int a, const char *spec, int exp, bool family) : Person(n, a), experience(exp), family_or_not(family)
    {
        specialty = new char[strlen(spec) + 1];
        strcpy_s(specialty, strlen(spec) + 1, spec);
    }

    ~Doctor()
    {
        delete[] specialty;
    }

    void input(const char *spec, int exp, bool family)
    {
        delete[] specialty;
        specialty = new char[strlen(spec) + 1];
        strcpy_s(specialty, strlen(spec) + 1, spec);
        experience = exp;
        family_or_not = family;

        Person::input();
    }

    void print()
    {
        Person::print();
        cout << "Specialty: " << specialty << "\tExperience: " << experience << " years\tFamily Doctor: " << (family_or_not ? "Yes" : "No") << endl;
    }

    const char *get_specialty() const
    {
        return specialty;
    }

    void set_specialty(const char *spec)
    {
        delete[] specialty;
        specialty = new char[strlen(spec) + 1];
        strcpy_s(specialty, strlen(spec) + 1, spec);
    }

    int get_experience() const
    {
        return experience;
    }

    void set_experience(int exp)
    {
        experience = exp;
    }

    bool family_or_not() const
    {
        return family_or_not;
    }

    void set_family_or_not(bool family)
    {
        family_or_not = family;
    }
};

int main()
{
    Student student("Irina", 18, "ITStep");
    student.print();
    student.input("New University");
    student.print();

    Teacher teacher("Max", 20, "School", 15000.0);
    teacher.print();
    teacher.input("Elementary School", 20000.0);
    teacher.print();

    Driver driver("Kate", 40, "X1627", "123456", "AB");
    driver.print();
    driver.input("ABC456", "654321", "CD");
    driver.print();

    Doctor doctor("Ken", 45, "surgeon", 15, true);
    doctor.print();
    doctor.input("pediatrician", 10, false);
    doctor.print();

    return 0;
}
