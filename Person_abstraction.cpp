#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Person {
    
    char* firstname = new char[20];
    char* lastname = new char[20];
    char* profession = new char[20];
    int b_year;
    int b_month;
    int b_day;
    double salary;
    bool is_stable;

    void set_b_year(int year) {
        if (year >= 1903 && year <= 2005) {
            b_year = year;
        }
        else {
            cout << "Invalid year." << endl;
        }
    }
    void set_b_month(int month) {
        if (month > 0 && month < 13) {
            b_month = month;
        }
    }
    void set_b_day(int day) {
        if (day > 0) {
            if (b_month == 2) {
                if (b_year % 4 == 0 && day <= 29) {
                    b_day = day;
                }
                else {
                    cout << "Invalid day." << endl;
                }
            }
            else if (b_month == 4 || b_month == 9 || b_month == 11) {
                if (day <= 30) {
                    b_day = day;
                }
                else {
                    cout << "Invalid day." << endl;
                }
            }
            else {
                if (day <= 31) {
                    b_day = day;
                }
                else {
                    cout << "Invalid day." << endl;
                }
            }
        }
        else {
            cout << "Invalid day." << endl;
        }
    }

    bool is_valid_string(char str[], int size = 20) {
        bool is_valid = true;
        for (int i = 0; i < size; i++) {
            if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
                return is_valid;
            }
        }
        return is_valid;
    }

    void title_case(char str[], int size) {
        if (str[0] >= 97 && str[0] <= 122) {
            str[0] -= 32;
        }
        for (int i = 1; i < size; i++) {
            if (str[i] >= 65 && str[i] <= 90) {
                str[i] += 32;
            }
        }
    }

public:
    Person() {
        cout << "Please, enter valid data." << endl
            << "Person firstname, lastname and profession must have less than 20 characters." << endl
            << "Person birth day and month must be real and birth year must be between 1903 and 2005." << endl
            << "Salary must be more than 50.000 drams." << endl << endl;
    }
    void set_firstname(char* f_name) {
        int size = sizeof(f_name);
        if (size > 20) {
            cout << "Firstname is too long." << endl;
        }
        else {
            if (is_valid_string(f_name, size)) {
                title_case(f_name, size);
                firstname = f_name;
            }
            else {
                cout << "Firstame is invalid." << endl;
            }
        }
    }
    void set_lastname(char* l_name) {
        int size = sizeof(l_name);
        if (size > 20) {
            cout << "Lastname is too long." << endl;
        }
        else {
            if (is_valid_string(l_name, size)) {
                title_case(l_name, size);
                lastname = l_name;
            }
            else {
                cout << "Lastame is invalid." << endl;
            }
        }
    }
    void set_birth_date(int day, int month, int year) {
        set_b_year(year);
        set_b_day(day);
        set_b_month(month);
    }
    

    void set_salary(double sal) {
        if (sal > 50000) {
            salary = sal;
        }
        else {
            cout << "Invalid salary" << endl;
        }
    }
    void set_stable(bool st) {
        is_stable = st;
    }

    void set_profession(char* prof) {
        int size = sizeof(prof);
        if (size > 20) {
            cout << "Profession is too long." << endl;
        }
        else {
            if (is_valid_string(prof, size)) {
                title_case(prof, size);
                profession = prof;
            }
            else {
                cout << "Profession is invalid." << endl;
            }
        }
    }
    void output_data() {
        cout << "Firstname: " << firstname << endl << "Lastname: " << lastname << endl << "Born on: " << b_day << "/" << b_month << "/" << b_year << endl << "Profession: " << profession << endl << "Salary: " << salary << " AMD" << endl;
        if (is_stable) {
            cout << "Salary is stable" << endl;
        }
        else {
            cout << "Salary isn't stable" << endl;
        }
    }
    ~Person() {
        delete[] firstname, lastname, profession;
    }

};


int main(){
    srand(time(nullptr));
   
    

    Person person;

    char* firstname = new char[20];

    cout << "Enter firstname: ";
    cin >> firstname;
  
    person.set_firstname(firstname);
    
    
    char* lastname = new char[20];
    
    cout << "Enter lastname: ";
    cin >> lastname;

    person.set_lastname(lastname);


    int day;
    cout << "Enter your birth" << endl;
    cout << "Day: ";
    cin >> day;

    int month;
    cout << "Month: ";
    cin >> month;

    int year;
    cout << "Year: ";
    cin >> year;

    person.set_birth_date(day, month, year);

    char* prof = new char[20];
    cout << "Enter your profession: " << endl;
    cin >> prof;

    person.set_profession(prof);

    double salary;
    cout << "Enter your salary in drams: " << endl;
    cin >> salary;

    person.set_salary(salary);

    char s;
    cout << "Enter stability of salary (if is stable enter Y else enter N: ";
    cin >> s;

    if (s == 'Y' || s == 'y') {
        person.set_stable(true);
    }
    else if (s == 'N' || s == 'n') {
        person.set_stable(false);
    }
    else {
        cout << "Incorrect answer" << endl;
    }

    cout << endl;
    person.output_data();

    delete[] firstname, lastname, prof;

    return 0;
}