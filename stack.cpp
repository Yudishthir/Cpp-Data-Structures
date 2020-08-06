#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> mainStack;
    int maxHeight;
    int curr = -1;

public:
    Stack(int limit);
    void push(int data);
    void pop();
    void display();
    bool isEmpty();
    int getTop();
    int getHeight();
};

Stack::Stack(int limit)
{
    maxHeight = limit;
}

void Stack::push(int data)
{
    if (curr == maxHeight)
    {
        cout << "Stack is full\n";
        return;
    }
    mainStack.push_back(data);
    ++curr;
}

void Stack::pop()
{
    if (curr == 0)
    {
        cout << "Stack is empty\n";
        return;
    }
    mainStack.pop_back();
    --curr;
}

void Stack::display()
{
    cout << "\t";
    for (vector<int>::iterator i = mainStack.begin(); i < mainStack.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}

bool Stack::isEmpty()
{
    if (curr == 0)
        return true;
    return false;
}

int Stack::getTop()
{
    if (isEmpty())
    {
        cout << "Cannot get top element of empty stack";
    }
    return mainStack[curr];
}

int Stack::getHeight()
{
    return maxHeight;
}

int main(int argc, char const *argv[])
{
    Stack test(3);
    cout << "Stack of height : " << test.getHeight() << endl;
    cout << "Pushing 5, 4, 3 ... \n";
    test.push(5);
    test.push(4);
    test.push(3);
    test.display();
    cout << "Popping 3 ... \n";
    test.pop();
    test.display();
    cout << "Top most element of the stack : " << test.getTop() << endl;
    cout << "Is the stack empty? : " << test.isEmpty();
    return 0;
}
