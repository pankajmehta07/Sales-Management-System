class Product;
// Product getProductDetailsOnNameGiven(std::string name);
Product getInventoryOnName(std::string name);
void BuyUpdateDB(std::vector<Product>& buyVector);
void updateDatabase(Product p);
void SellUpdateDB(std::vector<Product> products);
wxArrayString getNameChoices();
void connectToDatabase();






// Some Commands:

// sudo systemcti stop apache2.server
// sudo mysql -u root -p
// use SMS 
// GRANT ALL PRIVILEGES ON SMS.* TO 'pankaj'@'192.168.1.119';
// UPDATE mysql.user SET host='192.168.1.119' WHERE user='pankaj';
// SELECT user, host FROM mysql.user;