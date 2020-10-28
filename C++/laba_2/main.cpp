/*
Авферонок Александр в3530904/80022

Разработать программу, которая должна сделать следующее:
1.	Прочитать содержимое текстового файла. Файл может содержать:
    a.	Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
    b.	Знаки препинания – «.», «,» «!» «?» «:» «;»
    c.	Пробельные символы – пробел, табуляция, символ новой строки.

2.	Отформатировать текст следующим образом:
    a.	Не должно быть  пробельных символов отличных от пробела
    b.	Не должно идти подряд более одного пробела
    c.	Между словом и знаком препинания не должно быть пробела
    d.	После знака препинания всегда должен идти пробел
    e.	Слова длиной более 10 символов заменяются на слово «Vau!!!»

3.	Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно целиком находиться в строке) и ее длинна не превышает 40 символов.

*/

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/*!
 *  \brief получение строки из файла.
 */

void reading(ifstream& f, string &s)
{
    string ss;

    while(getline(f,ss))
    {
        s = s + ss+'\n';
    }
}

/*!
 *  \brief замена длинных слов и проверка на лишние пробелы.
 */

void replace_long(string& s, int max_len, string change, string const &liters)//max_len - длина заменяемого слова
{
    string ss 	= s; //временная строка
    s 			= "";

    int last_pos 			= 0;											//указатель на последнюю позицию поиска
    int first_liter_pos 	= ss.find_first_of(liters, last_pos);
    int first_not_liter_pos	= ss.find_first_not_of(liters, first_liter_pos);
    int word_len 			= first_not_liter_pos - first_liter_pos;

    while ((first_liter_pos != string::npos) && (first_not_liter_pos != string::npos))
    {
        if (word_len <= max_len)
        {
            s = s + ss.substr(last_pos, (first_liter_pos - last_pos) + word_len);
        }
        else
        {
            s = s + ss.substr(last_pos, first_liter_pos - last_pos) + change;
        }

        last_pos			= first_not_liter_pos;
        first_liter_pos 	= ss.find_first_of(liters, last_pos);
        first_not_liter_pos	= ss.find_first_not_of(liters, first_liter_pos);
        word_len 			= first_not_liter_pos - first_liter_pos;
    }

    s = s + ss.substr(last_pos, ss.length()-last_pos);
}

/*!
 *  \brief добавление отступа от заданног осимвола.
 */
void marks_right_frame(string& s, string marks, char frame)
{
    string ss = s;
    int last_pos = 0;

    while (ss.find_first_of(marks, last_pos)!=string::npos)
    {
        int first_mark_pos = ss.find_first_of(marks, last_pos);
        int start_frame_pos = first_mark_pos;

        for(; ((start_frame_pos>0)&&(ss[start_frame_pos-1]==frame)); start_frame_pos--);

        ss.erase(start_frame_pos, first_mark_pos - start_frame_pos);
        ss.insert(start_frame_pos+1, 1, frame);

        last_pos = start_frame_pos+2;
    };

    s = ss;
}

/*!
 *  \brief добавление переноса после 40 символов.
 */
vector<string> devide_to_substrings(string& s, int max_len, string const &liters)
{
    string ss = s;
    vector<string> v;

    while (ss.length()>max_len)
    {
        int len = max_len;
        while (liters.find(ss[len-1]) != string::npos)
        {
            len--;
        };
        v.push_back(ss.substr(0,len));
        ss = ss.substr(len, ss.length()-len);
    }

    v.push_back(ss);

    return v;
}

int main()
{
    ifstream f;
    f.open("text.txt");

    string liters = "_абвгдеёжзийклмнопрстуфхчщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЧЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string marks = ":;?!.,()[]{}/&#";
    string str;
    reading(f,str);
    cout<<str<<endl;

    replace_long(str, 0, " ", "\t\n");
    replace_long(str, 10, "WOW!", liters);
    marks_right_frame(str, ":;?!.,", ' ');
    replace_long(str, 1, " ", " ");
    cout<<str<<endl;

    vector<string> vec = devide_to_substrings(str, 40, liters);
    for(auto i: vec)
    {
        cout<<i<<endl;
    };

    f.close();
    return 0;
}
