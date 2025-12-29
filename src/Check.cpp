#include "Check.h"


    void Check::printCheck() const {
        displayProductInfo();
        std::cout << "Количество: " << getQuantity() << ", Общая цена: " << getTotalPrice() << ", Общий вес: "
                  << getTotalWeight() << std::endl;
    }
