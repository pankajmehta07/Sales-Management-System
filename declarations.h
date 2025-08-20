class Product;
Product getInventoryOnName(std::string name);
void BuyUpdateDB(std::vector<Product>& buyVector);
void updateDatabase(Product p);
void SellUpdateDB(std::vector<Product> products);
wxArrayString getNameChoices();
void connectToDatabase();
