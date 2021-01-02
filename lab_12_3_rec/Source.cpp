//рекурсивний спос≥б 
#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
using namespace std;
struct Elem
{
    Elem* next;
    Elem* prev;
    int info;
};
void AddDoubleList(Elem*& first, Elem*& last, int N, int Low, int High, int i);
void Print(Elem* first);
int Sum(Elem* first, int S);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    Elem* first = NULL;
    Elem* last = NULL;
    int N, Low, High;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в списку: "; cin >> N;
    cout << "¬вед≥ть найменше значенн€ елементу: "; cin >> Low;
    cout << "¬вед≥ть найб≥льше елементу: "; cin >> High;
    cout << "—писок:" << endl;
    AddDoubleList(first, last, N, Low, High, 1);
    Print(first);
    cout << endl;
    cout << "—ума додатн≥х елемент≥в списку:" << endl;
    cout << "Sum = " << Sum(first, 0) << endl;
    cout << endl;
    system("pause");
    return 0;
}
void AddDoubleList(Elem*& first, Elem*& last, int N, int Low, int High, int i)
{
    if (i <= N)
    {
        int infoElem = Low + rand() % (Low - High + 1);
        Elem* tmp = new Elem;
        tmp->info = infoElem;
        tmp->next = NULL;
        if (last != NULL)
            last->next = tmp;
        tmp->prev = last;
        last = tmp;
        if (first == NULL)
            first = tmp;
        AddDoubleList(first, last, N, Low, High, i + 1);
    }
}
void Print(Elem* first)
{
    if (first != NULL)
    {
        cout << first->info << "  ";
        Print(first->next);
    }
}
int Sum(Elem* first, int S)
{
    if (first != NULL)
    {
        if (first->info > 0)
            S += first->info;
        return Sum(first->next, S);
    }
    else
        return S;
}
