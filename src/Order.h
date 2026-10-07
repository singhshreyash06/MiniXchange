#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;

class Order {
public:
    int id;
    string side;    
    double price;
    int quantity;
    long timestamp;
    bool isCancelled;

    Order(int id, string side, double price, int quantity, long timestamp);
    void print();
};

#endif