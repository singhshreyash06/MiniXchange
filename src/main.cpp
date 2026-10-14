#include "Order.h"
#include "OrderBook.h"
#include <iostream>
using namespace std;

int main() {
    OrderBook book;

    // Sell orders (added in a deliberately "wrong" order)
    book.addOrder(Order(1, "sell", 505.0, 10, 1001));
    book.addOrder(Order(2, "sell", 500.0, 5, 1002));
    book.addOrder(Order(3, "sell", 502.0, 8, 1003));

    // Buy orders
    book.addOrder(Order(4, "buy", 503.0, 12, 1004));
    book.addOrder(Order(5, "buy", 499.0, 10, 1005));

    cout << "=== BEFORE MATCHING ===" << endl;
    book.printBook();

    cout << endl << "=== MATCHING ===" << endl;
    book.matchOrders();

    cout << endl << "=== AFTER MATCHING ===" << endl;
    book.printBook();

    return 0;
}