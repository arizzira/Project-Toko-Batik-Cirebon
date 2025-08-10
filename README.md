```markdown
# 🏬 Project Toko Batik Cirebon (C++)

A console-based simulation of a **Batik store management system**, built with C++.  
It includes features for shopping, payment with discounts, order history tracking, membership management, and more.

---

## 📌 Overview

This project simulates the workflow of a batik store in Cirebon, allowing customers to:
- Browse available batik items
- Add orders to their cart
- Process payments with automatic discounts
- Track purchase history
- Manage membership status

It’s designed as a menu-driven CLI application, suitable for learning data structures, queues, linked lists, and basic business logic in C++.

---

## ✨ Features

| Menu Option | Description |
|-------------|-------------|
| 1️⃣ **Belanja Barang** | Add selected batik items to a customer's cart |
| 2️⃣ **Bayar Barang** | Process payment, calculate discount, update membership |
| 3️⃣ **Hapus Pesanan** | Remove the last added order from a customer's cart |
| 4️⃣ **Tampilkan Pesanan** | View all items currently in the customer's cart |
| 5️⃣ **History Pemesanan** | Show all past orders stored in a queue |
| 6️⃣ **Membering dan Edit Member** | Check membership status and (in future) edit member details |
| 7️⃣ **Keluar** | Exit the program |

---

## 🛠 Technology Used

- **Language:** C++
- **Data Structures:**  
  - Linked List (`Keranjang`) for cart management  
  - Queue (`historyPemesananQueue`) for purchase history
- **OS Commands:** Uses `system("cls")` for screen clearing (Windows only)

---

## 📂 Folder Structure

```

Project-Toko-Batik-Cirebon/
├── toko\_batik\_cirebon.cpp  # Main program source code
└── README.md               # Project documentation

````

---

## 🚀 How to Run

### 1️⃣ Requirements
- A C++ compiler (e.g., g++, MinGW, MSVC)
- Windows OS (for `cls` command in `clearScreen`)

### 2️⃣ Compile the Program
```bash
g++ toko_batik_cirebon.cpp -o toko_batik
````

### 3️⃣ Run the Program

```bash
./toko_batik
```

---

## 💰 Discount Rules

* **2–4 items:** 10% discount
* **5–6 items:** 15% discount
* **7+ items:** 20% discount
* **Member bonus:** Additional 5% off

---

## 🗂 Data Structures in Action

* **Linked List:**
  Each customer has a linked list of orders in their cart.

* **Queue:**
  All completed orders are pushed into a history queue for later viewing.

---

## 🧩 Possible Improvements

* Add **address storage** for members (currently placeholder)
* Allow **editing quantity** instead of only deleting the last order
* Implement **data persistence** (save orders to file)
* Make it cross-platform (replace `system("cls")`)

---

## 📜 License

This project has no license yet — add one if you want others to reuse it.

---

## 👤 Author

**arizzira**
GitHub: [@arizzira](https://github.com/arizzira)
Mau gue bikin sekalian?
```
