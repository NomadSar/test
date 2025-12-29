#pragma once

#include "Buy.h"

class Check : public Buy {
public:
    Check() = default;

    Check(const Buy &buy) : Buy(buy, buy.getQuantity()) {}

    //Вывод информации о покупке.
    void printCheck() const ;
};