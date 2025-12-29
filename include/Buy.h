#pragma once

#include "Products.h"

class Buy : public Product {
private:
    int quantity{};
    float totalPrice{};
    float totalWeight{};


public:
    Buy() = default;

    // Конструктор класса Buy
    Buy(const Product &prod, int q) : Product(prod.getName(), prod.getCategory(), prod.getPrice(), prod.getWeight(),
                                              prod.getTotal_weight()), quantity(q) {
        totalPrice = prod.getPrice() * quantity;
        totalWeight = prod.getWeight() * quantity;
    }

    // Get-методы
    int getQuantity() const ;

    float getTotalPrice() const ;

    float getTotalWeight() const ;

};



