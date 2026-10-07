#include "OrderBook.h"
#include <iostream>
#include <algorithm>
using namespace std;

void OrderBook::addOrder(Order o) {
    if (o.side == "buy") {
        buyOrders.push_back(o);
    } else if (o.side == "sell") {
        sellOrders.push_back(o);
    }
}

void OrderBook::printBook() {
    cout << "----- BUY ORDERS -----" << endl;
    for (int i = 0; i < buyOrders.size(); i++) {
        buyOrders[i].print();
    }

    cout << "----- SELL ORDERS -----" << endl;
    for (int i = 0; i < sellOrders.size(); i++) {
        sellOrders[i].print();
    }
}

void OrderBook::matchOrders() {
    for (int i = 0; i < buyOrders.size(); i++) {
        for (int j = 0; j < sellOrders.size(); j++) {

            if (buyOrders[i].isCancelled || sellOrders[j].isCancelled) {
                continue;
            }

            if (buyOrders[i].quantity == 0 || sellOrders[j].quantity == 0) {
                continue;
            }

            if (buyOrders[i].price >= sellOrders[j].price) {
                int matchedQty = min(buyOrders[i].quantity, sellOrders[j].quantity);

                cout << "Trade executed: " << matchedQty << " shares at price "
                     << sellOrders[j].price << " (Buy #" << buyOrders[i].id
                     << " x Sell #" << sellOrders[j].id << ")" << endl;

                buyOrders[i].quantity -= matchedQty;
                sellOrders[j].quantity -= matchedQty;
            }
        }
    }
}