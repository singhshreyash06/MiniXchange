#include "OrderBook.h"
#include <iostream>
#include <algorithm>
using namespace std;

void OrderBook::addOrder(Order o) {
    if (o.side == "buy") {
        buyOrders.push(o);
    } else if (o.side == "sell") {
        sellOrders.push(o);
    }
}

void OrderBook::printBook() {
    // A heap can't be looped over, so we print from a COPY
    // and pop the copy empty. The real book is untouched.
    cout << "----- BUY ORDERS (best first) -----" << endl;
    auto tempBuy = buyOrders;
    while (!tempBuy.empty()) {
        tempBuy.top().print();
        tempBuy.pop();
    }

    cout << "----- SELL ORDERS (best first) -----" << endl;
    auto tempSell = sellOrders;
    while (!tempSell.empty()) {
        tempSell.top().print();
        tempSell.pop();
    }
}

void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        Order buy = buyOrders.top();
        Order sell = sellOrders.top();

        // Skip cancelled orders sitting at the top
        if (buy.isCancelled) {
            buyOrders.pop();
            continue;
        }
        if (sell.isCancelled) {
            sellOrders.pop();
            continue;
        }

        // Best buy can't afford best sell -> nothing else can match
        if (buy.price < sell.price) {
            break;
        }

        int matchedQty = min(buy.quantity, sell.quantity);

        cout << "Trade executed: " << matchedQty << " shares at price "
             << sell.price << " (Buy #" << buy.id
             << " x Sell #" << sell.id << ")" << endl;

        // Take both off the heap, reduce quantities, put back leftovers
        buyOrders.pop();
        sellOrders.pop();
        buy.quantity -= matchedQty;
        sell.quantity -= matchedQty;

        if (buy.quantity > 0) {
            buyOrders.push(buy);
        }
        if (sell.quantity > 0) {
            sellOrders.push(sell);
        }
    }
}