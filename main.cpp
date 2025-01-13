#include <iostream>
#include <string>
using namespace std;

struct Book {
private:
    string* _name = nullptr;
    string* _autor = nullptr;
    int* _year = nullptr;

public:
    // Геттери
    string getName() const {
        return (_name == nullptr) ? "No name" : *_name;
    }
    string getAvtor() const {
        return (_autor == nullptr) ? "No author" : *_autor;
    }
    int getYear() const {
        return (_year == nullptr) ? 0 : *_year;
    }

    // Сеттери
    void setName(const string& name) {
        if (_name != nullptr) {
            delete _name;
        }
        _name = new string(name);
    }
    void setAutor(const string& autor) {
        if (_autor != nullptr) {
            delete _autor;
        }
        _autor = new string(autor);
    }
    void setYear(int year) {
        if (_year != nullptr) {
            delete _year;
        }
        _year = new int(year);
    }

    // Деструктор
    ~Book() {
        delete _name;
        delete _autor;
        delete _year;
    }

    // Водоспадні конструктора
    Book() : _name(new string("No name")), _autor(new string("No author")), _year(new int(1900)) {}

    Book(string name) : _name(new string(name)), _autor(new string("No author")), _year(new int(1900)) {}

    Book(string name, string autor) : _name(new string(name)), _autor(new string(autor)), _year(new int(1900)) {}

    Book(string name, string autor, int year) : _name(new string(name)), _autor(new string(autor)), _year(new int(year)) {}

    // Метод для виведення інформації
    void about() const {
        cout << "Name: " << getName() << ", Author: " << getAvtor() << ", Year: " << getYear() << endl;
    }
};

int main() {

    Book b1;
    Book b2("1984");
    Book b3("To Kill a Mockingbird", "Harper Lee");
    Book b4("Dune", "Frank Herbert", 1965);

    b1.about();
    b2.about();
    b3.about();
    b4.about();

    return 0;
}
