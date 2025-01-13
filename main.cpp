#include <iostream>
#include <string>
using namespace std;

struct Autor {
private:
    string *_name = nullptr;
    int *_year = nullptr;

public:
    string getName() const {
        return (_name == nullptr) ? "No name" : *_name;
    }
    int getYear() const {
        return (_year == nullptr) ? 0 : *_year;
    }

    void setName(const string& name) {
        if (_name != nullptr) {
            delete _name;
        }
        _name = new string(name);
    }
    void setYear(const int year) {
        if (_year != nullptr) {
            delete _year;
        }
        _year = new int(year);
    }
    ~Autor() {
        delete _year;
        delete _name;
    }
};

struct Book {
private:
    string *_title = nullptr;
    int *_publication = nullptr;
    Autor *_autor = nullptr;

public:
    string getTitle() const {
        return (_title == nullptr) ? "No title" : *_title;
    }
    int getPublication() const {
        return (_publication == nullptr) ? 0 : *_publication;
    }

    void setTitle(const string& title) {
        if (_title != nullptr) {
            delete _title;
        }
        _title = new string(title);
    }
    void setPublication(const int publication) {
        if (_publication != nullptr) {
            delete _publication;
        }
        _publication = new int(publication);
    }

    void setAutor(const Autor& autor) {
        if (_autor != nullptr) {
            delete _autor;
        }
        _autor = new Autor(autor);
    }

    ~Book() {
        delete _autor;
        delete _publication;
        delete _title;
    }

    void about() const {
        cout << "Title: " << getTitle() << ", Author: " << _autor->getName()
             << ", Year: " << _autor->getYear() << endl;
    }
};

int main() {
    Autor a1;
    a1.setName("John Doe");
    a1.setYear(1980);

    Book b1;
    b1.setTitle("C++ Programming");
    b1.setPublication(2021);
    b1.setAutor(a1);

    b1.about();

    return 0;
}
