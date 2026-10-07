#include "Order.h"
#include <iostream>
using namespace std;

Order::Order(int id, string side, double price, int quantity, long timestamp) {
    this->id = id;
    this->side = side;
    this->price = price;
    this->quantity = quantity;
    this->timestamp = timestamp;
    this->isCancelled = false;
}

void Order::print() {
    cout << "Order #" << id << " | " << side << " | price: " << price
         << " | qty: " << quantity << " | time: " << timestamp << endl;
}