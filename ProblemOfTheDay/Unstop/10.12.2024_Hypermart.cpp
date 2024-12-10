/*
Problem Link: https://unstop.com/code/practice/299973
*/

/*Hypermart

Problem Statement
In a hypermart that starts off empty, you can perform two types of actions:

Add a New Product: You can add a product with a specified quantity.
Sell a Product: You can sell the product that has the lowest quantity in stock. If there are multiple products with the same lowest quantity, the one that was added first will be sold.
 

Note: It is guarenteed that if a Type 2 query comes, then inventory will not be empty.

Input Format
The first line contains an integer Q, which represents the number of actions to be performed.

The next Q lines will describe the actions, which can be of two types:

Action Type 1: (space-separated) ProductName x - This action adds a product with the name ProductName and a quantity of x (space-separated) to the inventory.
Action Type 2: This action sells the product with the lowest quantity in the inventory.
Output Format
For Action Type 1: when a product is added, the product is simply added to the inventory.

For Action Type 2: when a product is sold, remove the product with the lowest quantity from the inventory and print the name of that product in new line.

Constraints
2 ≤ Q ≤ 5×10^5

Sample Testcase 0
Testcase Input
2
1 Bubaloo 5
2
Testcase Output
Bubaloo
Explanation
The first query is, adding Bubaloo of quantity 5.
The second query is whether we have to remove the product which has the minimum quantity, and that is Bubaloo, so remove it and print the product name.
Sample Testcase 1
Testcase Input
3
1 Chips 3
1 Coke 4
2
Testcase Output
Chips
Explanation
The first query is adding Chips of quantity 3.
The Second query is adding Coke of quantity 4.
The third query is of the second type, so out of Chips and Coke, the quantity of Chips is less, so remove it from the mart and print the product name.

*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;


struct Product {
    int quantity;
    int order;
    string name;
    bool operator<(const Product& other) const {
        if (quantity == other.quantity)
            return order > other.order;
        return quantity > other.quantity; 
    }
};

int main() {
    int Q;
    cin >> Q;

    priority_queue<Product> minHeap; 
    int order = 0;
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            string productName;
            int quantity;
            cin >> productName >> quantity;
            minHeap.push({quantity, order++, productName});
        } else if (type == 2) {
           
            Product topProduct = minHeap.top();
            minHeap.pop();

            cout << topProduct.name << endl;
        }
    }

    return 0;
}