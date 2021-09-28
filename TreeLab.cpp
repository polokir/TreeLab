#include <iostream>
#include <vector>
#include <string>
#include "Trees.h"
#include "BinSearch.h"
#include "Binary.h"

using namespace std;



int main()
{
    BinTree tree(1);

    tree.push_back(2);
    tree.push_back(3);
    tree.push_back(4);
    tree.push_back(5);
    tree.push_back(6);
    cout << "----------" << endl;
    tree.output();
    cout << "----------" << endl;
    tree.symetricaloutput();
    cout << "----------" << endl;
    tree.reverseoutput();
}


