#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <nlohmann/json.hpp>
#include <fstream>


using json = nlohmann::json;

class Product {
private:
    std::string name;
    std::string category;
    float price{};
    float weight{};
    std::vector<Product> products;
    float total_weight{};


public:
    // Конструктор класса Product
    Product() = default;

    Product(const std::string &giv_name, const std::string &giv_category, float giv_price, float giv_weight,
            float giv_total_weight) {
        // Проверка имени: не пустое и не более 30 символов
        if (giv_name.empty() || giv_name.length() > 30) {
            throw std::invalid_argument("Некорректное имя продукта.");
        }
        // Проверка категории: не пустая и не более 30 символов
        if (giv_category.empty() || giv_category.length() > 30) {
            throw std::invalid_argument("Некорректная категория продукта.");
        }
        // Проверка цены: не отрицательная
        if (giv_price < 0) {
            throw std::invalid_argument("Цена продукта не может быть отрицательной.");
        }
        // Проверка веса: не отрицательный
        if (giv_weight < 0) {
            throw std::invalid_argument("Вес продукта не может быть отрицательным.");
        }
        // Проверка веса: не отрицательный
        if (giv_total_weight < 0) {
            throw std::invalid_argument("Общий вес продукта не может быть отрицательным.");
        }

        name = giv_name;
        category = giv_category;
        price = giv_price;
        weight = giv_weight;
        total_weight = giv_total_weight;

    }


    // Get-методы
    std::string getName() const;

    std::string getCategory() const;

    float getPrice() const;

    float getWeight() const;

    float getTotal_weight() const;

    std::vector<Product> &getProducts();


    //Set-методы
    void setName(const std::string &set_name);

    void setCategory(const std::string &set_category);

    void setPrice(float set_price);

    void setWeight(float set_weight);

    void setTotal_weight(float set_weight);

    //Показывает базу данных.
    void show_base_products() const;
    //Загружает базу из файла Json
    void load_base();
    //Записываем в базз у данных в файл.
    void recording_database();
    //Сортировка по цене.
    void sort_prise();
    //Сортировка по названию и по категории.
    void sort_Category_or_name(int x);
    // Показывает продукт.
    void shou_product(const std::string &in_name, const std::string &in_category);
    // Показывает продукт.
    void displayProductInfo() const ;
    //Изменение продукта
    void change_product(std::string productName);
    //Поиск продуктов с одинаковой ценой.
    void findProductsWithSamePrice(float targetPrice);
};