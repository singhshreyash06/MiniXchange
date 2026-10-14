#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <queue>
#include <vector>
using namespace std;

// Buy side: highest price first. If prices tie, earlier order first.
struct BuyComparator {
    bool operator()(const Order& a, const Order& b) const {
        if (a.price != b.price) {
            return a.price < b.price;
        }
        return a.timestamp > b.timestamp;
    }
};

// Sell side: lowest price first. If prices tie, earlier order first.
struct SellComparator {
    bool operator()(const Order& a, const Order& b) const {
        if (a.price != b.price) {
            return a.price > b.price;
        }
        return a.timestamp > b.timestamp;
    }
};

class OrderBook {
private:
    priority_queue<Order, vector<Order>, BuyComparator> buyOrders;
    priority_queue<Order, vector<Order>, SellComparator> sellOrders;

public:
    void addOrder(Order o);
    void printBook();
    void matchOrders();
};

#endif