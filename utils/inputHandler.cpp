#include <iostream>
#include "../include/inputHandler.h"

using namespace std;

void Input::getIntegerVector(vector<int> &inputVector, int size)
{
    if (size <= 0)
    {
        cout << "Size can't be zero lil bro, hit the road.." << endl;
        EXIT_FAILURE;
    }

    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        inputVector.push_back(element);
    }
}

void Input::getString(std::string &inputString)
{
    cout << "Enter the string : " << endl;
    cin >> inputString;
}