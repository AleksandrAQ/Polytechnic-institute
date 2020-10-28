/*
Autor - Golishev Roman, 22.09.2014

В очередь могут быть добавлены элементы, каждому
 элементу при добавлении присваивается один 
 из трех уровней приоритета (low, normal, high)

Элементы из очереди извлекаются в соответствии с их
 приоритетами (сначала извлекаются элементы с приоритетом high
 , потом normal, потом low), элементы с одинаковыми приоритетами
  извлекаются из очереди в порядки их поступления. 

В очереди также может происходить операция акселерации – все
 элементы с приоритетом low находящиеся в момент акселерации в 
 очереди увеличивают свой приоритет до high и «обгоняют» элементы с
  приоритетом normal.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <list>

using namespace std;

typedef enum 
{
    LOW, 
    NORMAL,
    HIGH 
} ElementPriority;

typedef struct
{ 
    string name;
} QueueElement;

class Element
{
public:
    ElementPriority prior;
    string name;

    Element (const Element &t)
    {
        prior   = t.prior;
        name    = t.name;
    };

    Element (string n, ElementPriority p)
    {
        prior   = p;
        name    = n;
    };

    string GetPriority()
    {
        switch (prior)
        {
            case LOW:return "LOW";  
            case NORMAL: return "NORMAL";
            case HIGH: return "HIGH";
        }
    };

    friend ostream& operator <<(ostream &s, Element &t)
    {
        return s<<t.name<<" "<<t.GetPriority();
    };
};

class QueueWithPriority
{
    list<Element> ls;
    int high_numb,norm_numb;
public:

    // Конструктор, создает пустую очередь
    QueueWithPriority()
    {
        high_numb = 0;
        norm_numb = 0;
    };

    // Деструктор
   ~QueueWithPriority(){};

    // Добавить в очередь элемент element с приоритетом priority
    void PutElementToQueue(const string &name, ElementPriority priority);
    void PutElementToQueue(const Element& element);

    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    Element GetElementFromQueue();

    typedef list<Element>::iterator Qiterator;
    
    void PrintAll()
    {
        for(Qiterator it = ls.begin(); it != ls.end(); it++)
            cout<<*it<<endl;
    };

    Qiterator begin(){return ls.begin();}
    Qiterator end(){return ls.end();}

    // Выполнить акселерацию
    void Accelerate();
};

Element QueueWithPriority::GetElementFromQueue()
{
    if (!ls.empty())
    {
        if(high_numb)
        {
            for(Qiterator it = begin(); it!=end(); it++)
            {
                if (it->prior == HIGH)
                {
                    Element t = *it;
                    ls.erase(it);
                    high_numb--;
                    return t;
                }
            }
        }
        else
            if(norm_numb)
            {
                for(Qiterator it = begin(); it!=end(); it++)
                {
                    if (it->prior == NORMAL)
                    {
                        Element t = *it;
                        ls.erase(it);
                        norm_numb--;
                        return t;
                    }
                }
            }
            else
            {
                Element t = *begin();
                ls.erase(begin());
                return t;
            };
    }
};   

void QueueWithPriority::PutElementToQueue(const string &name, ElementPriority priority)
{
    if (priority == HIGH)
        high_numb++;
    if (priority == NORMAL)
        norm_numb++;
    Element el(name, priority);
    ls.push_back(el);
};

void QueueWithPriority::PutElementToQueue(const Element &element)
{
    if (element.prior == HIGH)
        high_numb++;
    if (element.prior == NORMAL)
        norm_numb++;
    ls.push_back(element);
};

void QueueWithPriority::Accelerate()
{
    for (Qiterator it = begin(); it!=end(); it++)
    {
        if (it->prior == LOW)
        {
            it->prior = HIGH;
            high_numb++;
        }
    }
}    

int main ()
{
    QueueWithPriority q;
    q.PutElementToQueue("nikolay",HIGH);
    q.PutElementToQueue("Petr",LOW);
    q.PutElementToQueue("Sergey",NORMAL);
    q.PutElementToQueue("Viktor",LOW);
    q.PutElementToQueue("Mike",LOW);


    q.PrintAll();
    cout<<endl;
    Element t = q.GetElementFromQueue();
    cout<<t<<endl<<endl;
    t = q.GetElementFromQueue();
    q.PrintAll();
    q.Accelerate();
    cout<<endl;
    q.PrintAll();

    return 0;
}
