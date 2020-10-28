#ifndef QUEUEWITHPRIORITY_H
#define QUEUEWITHPRIORITY_H

#include <QString>
#include <string>   // Для строк

typedef enum
{
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

typedef struct
{
    QString name;
} QueueElement;

class QueueWithPriority
{
public:
    QueueWithPriority();
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);
    QueueElement GetElementFromQueue();
    void Accelerate();
};

#endif // QUEUEWITHPRIORITY_H
