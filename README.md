# 📌 Sales Management System – Byapar

## 📖 Overview
**Byapar** is a Sales Management System built in **C++** with **MySQL (MariaDB)** and **wxWidgets**.  
It is designed for **small and medium-sized businesses** to manage inventory, sales, and transactions digitally.  
Byapar replaces traditional handwritten record-keeping with a secure, user-friendly system that improves productivity and accuracy.

---

## ✨ Features
- 🗂️ **Inventory Management**
  - Add, update, or remove products.
  - Track stock levels and manage replenishments.
- 💰 **Sales & Purchase Transactions**
  - Record transactions and auto-update stock.
  - Save invoices digitally.
- 📝 **Modify Inventory**
  - Adjust product details (e.g., damaged items, price changes).
- 🔎 **Search Products**
  - Quickly find details using search (CTRL+F or menu).
- 🖥️ **User-Friendly GUI**
  - Built with **wxWidgets** for cross-platform use.
  - Simple design for non-technical users.

---

## 🛠️ Tech Stack
- **Language:** C++  
- **Database:** MySQL (MariaDB via XAMPP)  
- **GUI Framework:** wxWidgets  
- **Tools/IDE:** Visual Studio Code, XAMPP  

---

## 📦 Dependencies / Libraries
Make sure to install the following libraries:

### C++ Standard Libraries
- `<iostream>`
- `<fstream>`
- `<string>`
- `<vector>`
- `<map>`
- `<array>`
- `<tuple>`
- `<iomanip>`
- `<chrono>`
- `<ctime>`

### MySQL Connector/C++ Libraries
- `<mysql_driver.h>`
- `<mysql_connection.h>`
- `<cppconn/statement.h>`
- `<cppconn/sqlstring.h>`
- `<cppconn/prepared_statement.h>`

### wxWidgets (GUI)
- `<wx/wx.h>`
- `<wx/menu.h>`
- `<wx/artprov.h>`
- `<wx/bitmap.h>`
- `<wx/textctrl.h>`
- `<wx/statline.h>`

✅ Install:
- **MySQL Connector/C++** → [Download](https://dev.mysql.com/downloads/connector/cpp/)  
- **wxWidgets** → [Docs & Install Guide](https://www.wxwidgets.org/downloads/)  

On Ubuntu/Debian:
  ```bash
  sudo apt-get install libmysqlcppconn-dev libwxgtk3.2-dev
  ```
---

## 🛠️ Setup Database
1. Start **Apache** and **MySQL** in **XAMPP**.  
2. Import the schema file into MySQL:
   ```bash
   mysql -u root -p < db/schema.sql
   ```
---
## 🏗️ Build the Project
Compile the source code with g++ (make sure wxWidgets and MySQL Connector are installed):
   ```bash
   g++ main.cpp -o main `wx-config --cxxflags --libs` -lmysqlclient
   ```
---
## ▶️ Run
Compile the source code with g++ (make sure wxWidgets and MySQL Connector are installed):
   ```bash
   ./main
   ```
---
## ⚠️ Limitations
- No profit/loss calculation.
- No CRM (Customer Relationship Management).
- Only basic payment method (cash).
---
## 🔮 Future Enhancements
- Add billing system with monthly profit/loss reports.
- Support card & QR-based payments.
- Integrate CRM for customer tracking.
- Advanced analytics & reporting.
---
  
## 👨‍💻 Authors
- [Inisha Maharjan](https://github.com/Inisha08)
- [Nischal Dangol](https://github.com/Nischal-D)
- [Pankaj Kumar Mehta](https://github.com/pankajmehta07)
- [Pramit Khatri](https://github.com/Pramitkhatri1)
