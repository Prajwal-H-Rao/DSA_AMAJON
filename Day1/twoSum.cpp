#include "../Utils/Input.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum
{
public:
    // The bruteforce approcach
    vector<int> twoSum(const vector<int> &values, int target)
    {
        // for (int i = 0; i < values.size(); i++)
        // {
        //     for (int j = i + 1; j < values.size(); j++)
        //     {
        //         if (values[i] + values[j] == target)
        //         {
        //             return {values[i], values[j]};
        //         }
        //     }
        // }
        // return {-1, -1};
    }
};

int main()
{
    vector<int> elements;
    cout << "Enter the size of the elements vector" << endl;
    int size;
    cin >> size;
    Input inputHandler;
    inputHandler.acceptIntegerArray(elements, size);

    TwoSum ts;
    int target;
    cout << "Enter the target sum" << endl;
    cin >> target;
    vector<int> result = ts.twoSum(elements, target);

    cout << "The two values whos sum is equal to the target is\n";
    for (int element : result)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}