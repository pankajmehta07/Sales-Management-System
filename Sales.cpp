#include <iostream>
#include <vector>
#include <string>

class Product {
    friend class DatabaseManager;
public:
    std::string name;
    double price;
    int quantity;

    Product();

    Product(const std::string& n, double p, int q) : name(n), price(p), quantity(q) {}

    void displayProduct() const {
        std::cout << "Product: " << name << ", Price: $" << price << ", Quantity: " << quantity << std::endl;
    }

    std::vector<Product> products;

public:

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.price * product.quantity;
        }
        return totalSales;
    }

    bool purchaseProduct(const std::string& productName, int quantity) {
        for (auto& product : products) {
                if (product.name == productName && product.quantity >= quantity) {
                    product.quantity += quantity;
                    std::cout << "Purchase successful. Total cost: $" << (product.price * quantity) << std::endl;
                    return true;
                }
            }
            std::cout << "Product not found or insufficient quantity." << std::endl;
            return false;
    }
    void BuyDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);

        }
            double Purchase = 0.0;
        for (const auto& details : detailsVector) {
            int rateValue = std::get<2>(details);
            int qtyValue = std::get<3>(details);
            total += rateValue * qtyValue;
        }
        return total;
    }
    void SellDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);

        // Process the details or print them
        std::cout << "ID: " << IDValue << "\tName: " << nameValue
                  << "\tRate: " << rateValue << "\tQuantity: " << qtyValue << std::endl;
    }
}
};
