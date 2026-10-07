#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <vector>
using namespace std;

class OrderBook {
private:
    vector<Order> buyOrders;
    vector<Order> sellOrders;

public:
    void addOrder(Order o);
    void printBook();
    void matchOrders();
};

#endif