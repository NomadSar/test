#include "Products.h"
#include "Buy.h"
#include "Check.h"

Buy bay_product(std::vector<Product> &products, std::string productName, float quantity) {
    for (auto &product: products) { //Проходим по вектору по ссылке(&) для изменения продуктов
        if (product.getName() == productName) {
            if (product.getTotal_weight() >= quantity * product.getWeight()) {
                product.setTotal_weight(product.getTotal_weight() - quantity * product.getWeight());
                std::cout << "Куплено " << quantity << " " << productName << std::endl;
                return Buy(product, quantity);
            } else {
                std::cout << "Недостаточно товара " << productName << " есть только "
                          << product.getTotal_weight() / product.getWeight() << " штук. " << std::endl;
                float availableQuantity = product.getTotal_weight() / product.getWeight();
                product.setTotal_weight(0);
                return Buy(product, availableQuantity);
            }
        }
    }
    std::cout << "Такого продукта нет." << std::endl;
    Product dummyProduct("undefind", "undefind", 0, 0, 0); // Dummy продукт для возврата
    return Buy(dummyProduct, 0);
}

void checking_number(int &i) {
    while (!(std::cin >> i)) {

        std::cin.clear(); // Clear error flag

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // неверный ввод игнорируется

        std::cout << "Не правильный воод." << std::endl;
    }
}

void checking_number(float &i) {
    while (!(std::cin >> i)) {

        std::cin.clear(); // Clear error flag

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // неверный ввод игнорируется

        std::cout << "Не правильный воод." << std::endl;
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Здраствуйте вас приветсвтует тестовый вариант магазина." << std::endl;

    Product product;
    product.load_base();
    int i;
    std::cout
            << "Меню:"
            << std::endl
            << "Если хотите изменить цену, вес и название товара нажмите 1."
            << std::endl
            << "Если хотите совершить покупку товара нажмите 2."
            << std::endl
            << "Если хотите отсортировать товары по цене 3."
            << std::endl
            << "Если хотите отсортировать товары по названию 4."
            << std::endl
            << "Если хотите отсортировать товары по категории 5."
            << std::endl
            << "Если хотите найти товар по названию и по категории 6."
            << std::endl
            << "Если хотите найти товары с одинаковой стоимостью 7."
            << std::endl
            << "Если хотите закончить 0."
            << std::endl;;

    checking_number(i);
    std::string name_of_product;
    std::string category;
    int quantity;
    float price;

    try {
        while (i != 0) {
            if (i == 1) {
                std::cout << "Введите продукт который хотите изменить." << std::endl;
                std::cin >> name_of_product;
                product.change_product(name_of_product);
            } else if (i == 2) {
                std::cout << "Введите название продукта." << std::endl;
                std::cin >> name_of_product;
                std::cout << "Количество штук." << std::endl;
                checking_number(quantity);
                Buy result = bay_product(product.getProducts(), name_of_product, quantity);
                Check ckeq1(result);
                ckeq1.printCheck();
            } else if (i == 3) {
                product.sort_prise();
                product.show_base_products();
            } else if (i == 4) {
                product.sort_Category_or_name(i);
                product.show_base_products();
            } else if (i == 5) {
                product.sort_Category_or_name(i);
                product.show_base_products();
            } else if (i == 6) {
                std::cout << "Введите название продукта." << std::endl;
                std::cin >> name_of_product;
                std::cout << "Введите категорию." << std::endl;
                std::cin >> category;
                product.shou_product(name_of_product, category);
            } else if (i == 7) {
                std::cout << "Введите цену по которой хотите искать похожие продукты." << std::endl;
                checking_number(price);
                product.sort_prise();
                product.findProductsWithSamePrice(price);
            } else {
                std::cout << "Такой функции нет. " << std::endl;
            }

            std::cout << "***************************************" << std::endl;
            std::cout
                    << "Меню:"
                    << std::endl
                    << "Если хотите изменить цену, вес и название товара нажмите 1."
                    << std::endl
                    << "Если хотите совершить покупку товара нажмите 2."
                    << std::endl
                    << "Если хотите отсортировать товары по цене 3."
                    << std::endl
                    << "Если хотите отсортировать товары по названию 4."
                    << std::endl
                    << "Если хотите отсортировать товары по категории 5."
                    << std::endl
                    << "Если хотите найти товар по названию и по категории 6."
                    << std::endl
                    << "Если хотите найти товары с одинаковой стоимостью 7."
                    << std::endl
                    << "Если хотите закончить 0."
                    << std::endl;

            checking_number(i);
        }
        product.recording_database();
    } catch (const std::invalid_argument &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }


}