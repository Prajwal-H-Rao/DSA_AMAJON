#include <iostream>
#include <vector>
#include "Input.h"

using namespace std;

void Input::acceptIntegerArray(vector<int> &elements, int size)
{
    if (size <= 0)
    {
        cout << "The size cannot be less than 0" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        elements.push_back(element);
    }
}
