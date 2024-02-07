#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    std::string name;
    int quantity,id,rate;
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const std::string& name, int quantity) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item) {
            return item.name == name;
        });

        if (it != items.end()) {
            it->quantity += quantity;
        } else {
            items.push_back({name, quantity});
        }

        std::cout << "Item added to inventory.\n";
    }

    void displayInventory() {
        if (items.empty()) {
            std::cout << "Inventory is empty.\n";
        } else {
            std::cout << "Inventory:\n";
            for (const auto& item : items) {
                std::cout << item.name << ": " << item.quantity << "\n";
            }
        }
    }

    void updateQuantity(int id,const std::string& name,int rate ,int quantity) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item) {
            return item.name == name;
        });

        if (it != items.end()) {
            it->quantity = quantity;
            it->rate = rate;
            it->id=id;
            std::cout << "Quantity updated.\n";
        } else {
            std::cout << "Item not found in inventory.\n";
        }
    };
    void displayItem(const std::string& name) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item) {
            return item.name == name;
        });

        if (it != items.end()) {
            std::cout << "Item Details:\n";
            std::cout << "Name: " << it->name << "\n";
            std::cout << "Quantity: " << it->quantity << "\n";
        } else {
            std::cout << "Item not found in inventory.\n";
        }
    }
};

void runInventory() {
    Inventory inventory;

    while (true) {
        std::cout << "\n1. Add Item\n2. Display Inventory\n3. Update Quantity\n4. Display Item Details\n5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                std::cout << "Enter item name: ";
                std::cin >> name;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                inventory.addItem(name, quantity);
                break;
            }
            case 2:
                inventory.displayInventory();
                break;
            case 3: {
                std::string name;
                int quantity;
                std::cout << "Enter item name: ";
                std::cin >> name;
                std::cout << "Enter new quantity: ";
                std::cin >> quantity;
                inventory.updateQuantity(name, quantity);
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Enter item name: ";
                std::cin >> name;
                inventory.displayItem(name);
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // return 0;
}
