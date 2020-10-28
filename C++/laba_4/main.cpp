/*
 *
Авферонок Александр в3530904/80022

Напишите программу – «телефонную книжку».
Записи (имя и телефон) должны хранится в каком-либо STL-контейнере (vector или
list), причем крайне желательно, чтобы от типа контейнера не зависело ничего, кроме
одной строки в программе – объявления этого контейнера (указание: используйте
typedef).
Программа должна поддерживать следующие операции:
Просмотр текущей записи
Переход к следующей записи
Переход к предыдущей записи
Вставка записи перед/после просматриваемой
Замена просматриваемой записи
Вставка записи в конец базы данных
Переход вперед/назад через n записей.
Помните, что после вставки элемента итераторы становятся недействительными,
поэтому после вставки целесообразно переставлять итератор на начало базы данных.
Постарайтесь реализовать операции вставки и замены с помощью одной и той же
функции, которой в зависимости от требуемого действия передается либо обычный
итератор, либо адаптер – один из итераторов вставки: void modifyRecord(iterator
pCurrentRecord, CRecord newRecord).
Программа может сразу после запуска сама (без команд пользователя) заполнить
записную книжку некоторым количеством записей.
 *
*/

#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

// Класс, представляющий запись в телефонной книге
class CRecord {
    string name, phone;
public:
    CRecord() :name("<unknown>"), phone("<unknown>") {}
    CRecord(const CRecord &r) :name(r.getName()), phone(r.getPhone()) {}
    CRecord(const string &n,const string &p) :name(n), phone(p) {}
    ~CRecord() {}

    CRecord& operator=(const CRecord &r) {
        setName(r.getName());
        setPhone(r.getPhone());
        return *this;
    }

    string getName() const {return name;}
    void setName(const string &n) {name=n;}
    string getPhone() const {return phone;}
    void setPhone(const string &n) {phone=n;}

    string toString() const {
        return "Имя: "+getName()+"; Телефон: "+getPhone()+"\n";
    }
};

typedef vector<CRecord> TDatabase;

TDatabase db;
TDatabase::iterator i;

// Команды:

string help() { // помошь
    return
            "Список команд:\n"
            "help - показать помошь\n"
            "reset - Сбросить итератор к началу базы данных\n"
            "curr - Показать текущую запись\n"
            "next - Перейти к следующей записи и показать ее\n"
            "prev - Перейти к предыдущей записи и показать ее\n"
            "nextn <n> - Пропустить N записей и показать Nную\n"
            "prevn <n> - Пропустить N записей назад\n"
            "before <name> <phone> - вставить запись до текущей\n"
            "after <name> <phone> - insert a record after the current\n"
            "back <name> <phone> - вставить запись после текущей \n"
            "change <name> <phone> - изменить текущую запись\n";
}

template<class iter>
string modifyRecord(iter it) { // Изменить запись, на которую указывает указанный итератор
    string name,phone;
    cin>>name>>phone;	// Введите новое имя и телефон
    CRecord rec(name,phone);
    *it=rec;
    // Сбросьте итератор к началу базы данных от устаревшего
    i=db.begin();

    return "Value: "+rec.toString();
}

string reset() { // Сбросить итератор к началу базы данных
    i=db.begin();
    return i->toString();
}
string curr() {	// Показать текущую запись
    return i->toString();
}
string next() {	// Перейти к следующей записи и показать ее
    ++i;
    return i->toString();
}
string prev() {	// Перейти к предыдущей записи и показать ее
    --i;
    return i->toString();
}
string nextn() { // Пропустить N записей и показать Nную
    int pos;
    cin>>pos; // Read N
    advance(i,pos);
    return i->toString();
}
string prevn() { //Пропустить N записей назад
    int pos;
    cin>>pos;
    advance(i,pos);
    return i->toString();
}

// обработка введенных команд
string cmdHandler(string cmd) {
    try {
        if(cmd=="help") {
            return help();
        } else if(cmd=="reset") {
            return reset();
        } else if(cmd=="curr") {
            return curr();
        } else if(cmd=="next") {
            return next();
        } else if(cmd=="prev") {
            return prev();
        } else if(cmd=="nextn") {
            return nextn();
        } else if(cmd=="prevn") {
            return prevn();
        } else if(cmd=="before") {
            // Вставить запись до текущей::
            // использовать итератор вставки в позицию, предшествующую текущей.
            return modifyRecord(inserter<TDatabase,TDatabase::iterator>(db,--i));
        } else if(cmd=="after") {
            return modifyRecord(inserter<TDatabase,TDatabase::iterator>(db,i));
        } else if(cmd=="back") {
            return modifyRecord(back_inserter<TDatabase>(db));
        } else if(cmd=="change") {
            return modifyRecord(i);
        } else {
            return "Неверная команда! Введите 'help'\n";
        }
    } catch(...) {
        return "Последний элемент!\n";
    }
}

int main() {
    string command;
    cout<<help();
    i=db.begin();
    //чтение строк до eof
    transform(istream_iterator<string>(cin), istream_iterator<string>(),
              ostream_iterator<string>(cout), cmdHandler);
    return 0;
}
