#include "Order.h"
#include "OrderBook.h"
#include <iostream>
using namespace std;

int main() {
    OrderBook book;

    Order o1(1, "buy", 500.0, 10, 1001);
    Order o2(2, "sell", 498.0, 5, 1002);
    Order o3(3, "buy", 495.0, 20, 1003);
    Order o4(4, "sell", 505.0, 8, 1004);

    book.addOrder(o1);
    book.addOrder(o2);
    book.addOrder(o3);
    book.addOrder(o4);

    book.matchOrders();

    book.printBook();

    return 0;
}