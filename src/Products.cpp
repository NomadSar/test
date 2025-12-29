#include "Products.h"

    std::string Product::getName() const { return name; }

    std::string Product::getCategory() const { return category; }

    float Product::getPrice() const { return price; }

    float Product::getWeight() const { return weight; }

    float Product::getTotal_weight() const { return total_weight; }

    std::vector<Product> & Product::getProducts() { return products; }



    void Product::setName(const std::string &set_name) {
        if (set_name.empty() || set_name.length() > 30) {
            throw std::invalid_argument("Некорректное имя продукта.");
        }
        name = set_name;
    }

    void Product::setCategory(const std::string &set_category) {
        if (set_category.empty() || set_category.length() > 30) {
            throw std::invalid_argument("Некорректная категория продукта.");
        }
        category = set_category;
    }

    void Product::setPrice(float set_price) {
        if (set_price < 0) {
            throw std::invalid_argument("Цена продукта не может быть отрицательной.");
        }
        price = set_price;
    }

    void Product::setWeight(float set_weight) {
        if (set_weight < 0) {
            throw std::invalid_argument("Вес продукта не может быть отрицательным.");
        }
        weight = set_weight;
    }

    void Product::setTotal_weight(float set_weight) {
        if (total_weight <= 0) {
            throw std::invalid_argument("Вес продукта не может быть отрицательным.");
        }
        total_weight = set_weight;
    }

    void Product::show_base_products() const {
        for (const auto &product: products) {
            std::cout << "Название: " << product.name << ", Категория: " << product.category
                      << ", Цена: " << product.price << ", Вес за штуку: " << product.weight << ", Общий вес на складе: "
                      << product.total_weight << std::endl;
        }
    }

    void Product::load_base() {
        std::ifstream file(R"(..\..\json_file\product.json)"); // Открываем файл json для чтения
        json data;

        if (!file.is_open()) {
            throw std::invalid_argument("Не удалось открыть файл products.json");
        }

        file >> data;

        for (auto &item: data["products"]) {

            Product product(item["name"], item["category"], item["price"], item["weight"], item["total_weight"]);

            products.push_back(product);
        }
        file.close();
    }

    void Product::recording_database() {
        json jsonArray;


        for (const auto &record: products) {
            json jsonRecord;
            jsonRecord["name"] = record.name;
            jsonRecord["category"] = record.category;
            jsonRecord["price"] = record.price;
            jsonRecord["weight"] = record.weight;
            jsonRecord["total_weight"] = record.total_weight;
            jsonArray["products"].push_back(jsonRecord);
        }
        std::ofstream outputFile(R"(..\..\json_file\product.json)");

        if (outputFile.is_open()) {
            outputFile << jsonArray.dump(4); // Записываем JSON массив в файл с отступами для красоты (4 пробела).
            outputFile.close(); // Закрываем файл.
            std::cout << "Данные успешно записаны в файл data.json" << std::endl;
        } else {
            throw std::invalid_argument("Не удалось открыть файл для записи.");
        }
    }

    void Product::sort_prise() {
        int n = products.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (products[j].price > products[j + 1].price) {
                    std::swap(products[j], products[j + 1]);
                }
            }
        }
    }

    void Product::sort_Category_or_name(int x) {
        if (x == 4) {
            int n = products.size();
            for (int i = 1; i < n; ++i) {
                Product key = products[i];
                int j = i - 1;

                while (j >= 0 && products[j].name > key.name) {
                    products[j + 1] = products[j];
                    j = j - 1;
                }
                products[j + 1] = key;
            }
        } else if (x == 5) {
            int n = products.size();
            for (int i = 1; i < n; ++i) {
                Product key = products[i];
                int j = i - 1;

                while (j >= 0 && products[j].category > key.category) {
                    products[j + 1] = products[j];
                    j = j - 1;
                }
                products[j + 1] = key;
            }

        }
    }

    void Product::shou_product(const std::string &in_name, const std::string &in_category) {
        bool find = true;
        for (const auto &product: products) {
            if (product.name == in_name && product.category == in_category) {
                std::cout << "Название: " << product.name << ", Категория: " << product.category
                          << ", Цена: " << product.price << ", Вес за штуку: " << product.weight << ",Общий вес на складе: "
                          << product.total_weight << std::endl;
                find = false;
            }
        }
        if (find) std::cout << "Такого продукта нет." << std::endl;
    }

    void Product::displayProductInfo() const {
        std::cout << "Товар: " << name << ", Категория: " << category << ", Цена: " << price << ", Вес: " << weight
                  << std::endl;
    }

    void Product::change_product(std::string productName) {
        bool productFound = false;
        int i;
        for (auto &product: products) {
            if (product.name == productName) {
                productFound = true;
                std::cout
                        << "Что вы хотите поменять. Если название то введите цифру 1 если цену то цифра 2 если вес то то цифру 3. Если хотите выйти введите 0"
                        << std::endl;
                std::cin >> i;
                while (i != 0) {
                    if (i == 1) {
                        std::string new_name;
                        std::cout << "Введите новое имя." << std::endl;
                        std::cin >> new_name;
                        product.setName(new_name);
                    } else if (i == 2) {
                        float new_price;
                        std::cout << "Введите новую цену." << std::endl;
                        std::cin >> new_price;
                        product.setPrice(new_price);
                    } else if (i == 3) {
                        float new_weight;
                        std::cout << "Введите новый вес." << std::endl;
                        std::cin >> new_weight;
                        product.setWeight(new_weight);
                    }
                    std::cout
                            << "Что вы хотите поменять. Если название то введите цифру 1 если цену то цифра 2 если вес то то цифру 3. Если хотите выйти введите 0"
                            << std::endl;
                    std::cin >> i;
                }

            }
        }
        if (!productFound) {
            std::cout << "Такого продукта нет." << std::endl;
        }
    }

    void Product::findProductsWithSamePrice(float targetPrice) {
        std::vector<Product> result;
        for (const auto &product: products) {
            if (product.price == targetPrice) {
                result.push_back(product);
            }
            if (product.price > targetPrice) {
                break;
            }
        }
        if (result.empty()) {
            std::cout << "Товары с ценой " << targetPrice << " не найдены." << std::endl;
        } else {
            std::cout << "Товары с ценой " << targetPrice << ":" << std::endl;
            for (const auto &product: result) {
                std::cout << " Name: " << product.getName() << std::endl;
            }
        }
    }

