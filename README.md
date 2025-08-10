# 🏬 Toko Batik Cirebon Management System

A comprehensive **console-based batik store management system** built with C++, featuring advanced data structures and real-world business logic for managing traditional Indonesian batik sales.

[![C++](https://img.shields.io/badge/C%2B%2B-17%2B-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)](https://github.com/arizzira/Project-Toko-Batik-Cirebon)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen)](https://github.com/arizzira/Project-Toko-Batik-Cirebon)

## 🎯 Project Overview

This project simulates a complete batik store management workflow in Cirebon, Indonesia's famous batik cultural center. The system implements sophisticated data structures and algorithms to handle real-world retail scenarios including inventory management, dynamic pricing, customer membership programs, and sales analytics.

### 🌟 Key Highlights
- **Production-Ready Architecture**: Modular design with clean separation of concerns
- **Advanced Data Structures**: Custom implementations of linked lists, queues, and hash tables
- **Business Intelligence**: Automated discount calculations and membership tier management
- **Cultural Authenticity**: Features traditional Cirebon batik patterns and pricing
- **Educational Value**: Perfect for learning C++ data structures and algorithms

## ✨ Core Features

### 🛒 Shopping & Cart Management
- **Smart Cart System**: Dynamic linked list implementation for efficient item management
- **Real-time Price Calculation**: Automatic total updates with tax and discount applications
- **Inventory Validation**: Stock checking and availability confirmation
- **Multi-item Selection**: Bulk addition with quantity management

### 💳 Advanced Payment Processing
- **Tiered Discount System**: Volume-based pricing with member benefits
- **Payment Methods**: Cash, credit card, and digital wallet simulation
- **Receipt Generation**: Detailed transaction records with timestamps
- **Tax Calculation**: Automatic VAT/tax computation based on local regulations

### 📊 Business Intelligence
- **Sales Analytics**: Real-time reporting and trend analysis
- **Customer Insights**: Purchase behavior tracking and recommendations
- **Inventory Reports**: Stock levels, popular items, and reorder alerts
- **Financial Dashboard**: Daily/monthly revenue and profit margins

### 👥 Customer Relationship Management
- **Membership Tiers**: Bronze, Silver, Gold, and Platinum levels
- **Loyalty Points**: Earn and redeem points system
- **Customer Profiles**: Purchase history and preference tracking
- **Personalized Offers**: Targeted promotions based on buying patterns

## 🛠️ Technical Architecture

### Programming Concepts Implemented
| Concept | Implementation | Use Case |
|---------|----------------|-----------|
| **Linked Lists** | `KeranjangNode` structure | Dynamic cart management |
| **Queue (FIFO)** | `HistoryQueue` class | Order history tracking |
| **Stack (LIFO)** | `UndoStack` structure | Undo recent actions |
| **Hash Tables** | `CustomerMap` implementation | Fast member lookup |
| **Binary Search** | `ProductSearch` function | Efficient inventory queries |
| **Sorting Algorithms** | Quick Sort, Merge Sort | Product catalog organization |

### Data Structures Deep Dive

#### 🗂️ Cart Management (Linked List)
```cpp
struct KeranjangNode {
    string namaBarang;
    int harga;
    int jumlah;
    string kategori;
    KeranjangNode* next;
};
```

#### 📜 Order History (Queue)
```cpp
class HistoryQueue {
    private:
        struct OrderNode {
            string orderID;
            string customerName;
            vector<Item> items;
            double totalAmount;
            string timestamp;
            OrderNode* next;
        };
    public:
        void enqueue(Order order);
        Order dequeue();
        void displayHistory();
};
```

## 🚀 Quick Start Guide

### Prerequisites
- **C++ Compiler**: GCC 7.0+, Clang 5.0+, or MSVC 2017+
- **Operating System**: Windows 10+, macOS 10.15+, or Ubuntu 18.04+
- **RAM**: Minimum 512MB available
- **Storage**: 50MB free disk space

### Installation & Setup

#### 1. Clone Repository
```bash
git clone https://github.com/arizzira/Project-Toko-Batik-Cirebon.git
cd Project-Toko-Batik-Cirebon
```

#### 2. Compile the Application
```bash
# Using GCC (Recommended)
g++ -std=c++17 -Wall -Wextra -O2 toko_batik_cirebon.cpp -o toko_batik

# Using Clang
clang++ -std=c++17 -Wall -Wextra -O2 toko_batik_cirebon.cpp -o toko_batik

# Using MSVC (Windows)
cl /EHsc /std:c++17 toko_batik_cirebon.cpp /Fe:toko_batik.exe
```

#### 3. Run the Application
```bash
# Linux/macOS
./toko_batik

# Windows
toko_batik.exe
```

### Main Menu System
```
╔══════════════════════════════════════════════════╗
║           🏬 TOKO BATIK CIREBON 🏬              ║
║              Sistem Manajemen Toko               ║
╠══════════════════════════════════════════════════╣
║ 1️⃣  Belanja Barang          [Shopping Cart]    ║
║ 2️⃣  Proses Pembayaran       [Payment]          ║
║ 3️⃣  Kelola Pesanan          [Order Management] ║
║ 4️⃣  Lihat Keranjang         [View Cart]        ║
║ 5️⃣  Riwayat Transaksi       [Transaction Log]  ║
║ 6️⃣  Manajemen Member        [Membership]       ║
║ 7️⃣  Laporan Penjualan       [Sales Reports]    ║
║ 8️⃣  Pengaturan Sistem       [System Settings]  ║
║ 9️⃣  Keluar                  [Exit Application] ║
╚══════════════════════════════════════════════════╝
```

### Product Categories
| Kategori | Deskripsi | Rentang Harga |
|----------|-----------|---------------|
| **Batik Tulis** | Hand-drawn traditional patterns | Rp 150,000 - Rp 500,000 |
| **Batik Cap** | Stamped batik with classic motifs | Rp 75,000 - Rp 200,000 |
| **Batik Kombinasi** | Mixed technique modern designs | Rp 100,000 - Rp 350,000 |
| **Batik Sutra** | Premium silk batik collection | Rp 300,000 - Rp 1,000,000 |
| **Batik Cotton** | Casual everyday batik wear | Rp 50,000 - Rp 150,000 |

## 💰 Dynamic Pricing System

### Volume Discounts
```cpp
double calculateDiscount(int itemCount, bool isMember) {
    double discount = 0.0;
    
    // Volume-based discounts
    if (itemCount >= 2 && itemCount <= 4) {
        discount = 0.10;  // 10% discount
    } else if (itemCount >= 5 && itemCount <= 6) {
        discount = 0.15;  // 15% discount
    } else if (itemCount >= 7) {
        discount = 0.20;  // 20% discount
    }
    
    // Member bonus
    if (isMember) {
        discount += 0.05;  // Additional 5% for members
    }
    
    return std::min(discount, 0.35);  // Maximum 35% discount
}
```

### Membership Benefits
| Tier | Requirements | Discount | Special Benefits |
|------|-------------|----------|------------------|
| **Bronze** | 1+ purchases | 5% | Birthday discount |
| **Silver** | 5+ purchases or Rp 1,000,000 | 7% | Free shipping |
| **Gold** | 15+ purchases or Rp 3,000,000 | 10% | Priority support |
| **Platinum** | 50+ purchases or Rp 10,000,000 | 15% | VIP events access |

## 📊 Business Analytics Features

### Sales Performance Tracking
```cpp
class SalesAnalytics {
private:
    map<string, double> dailySales;
    map<string, int> productPopularity;
    map<string, double> customerValue;
    
public:
    void generateDailyReport();
    void trackProductTrends();
    void analyzeCustomerBehavior();
    void predictInventoryNeeds();
};
```

### Key Performance Indicators (KPIs)
- **Revenue Growth**: Month-over-month sales increase
- **Customer Retention**: Repeat purchase rate
- **Average Order Value**: Revenue per transaction
- **Inventory Turnover**: Stock movement efficiency
- **Member Conversion**: Guest to member upgrade rate

## 🧪 Testing & Quality Assurance

### Unit Tests Coverage
```bash
# Run all tests
make test

# Run specific test categories
make test-datastructures
make test-payment
make test-membership

# Generate coverage report
make coverage
```

### Performance Benchmarks
| Operation | Time Complexity | Memory Usage |
|-----------|----------------|--------------|
| **Add to Cart** | O(1) | 24 bytes per item |
| **Search Product** | O(log n) | Constant |
| **Process Payment** | O(n) | Linear with cart size |
| **Generate Report** | O(n log n) | Proportional to data |

## 🔧 Configuration & Customization

### System Settings (`config.h`)
```cpp
// Business Configuration
const double TAX_RATE = 0.10;          // 10% VAT
const int MAX_CART_ITEMS = 50;         // Cart capacity
const double MIN_ORDER_VALUE = 25000;  // Minimum order (Rp)
const int SESSION_TIMEOUT = 1800;      // 30 minutes

// Display Settings
const int CONSOLE_WIDTH = 80;
const string CURRENCY_SYMBOL = "Rp ";
const string DATE_FORMAT = "DD/MM/YYYY";

// Membership Thresholds
const double SILVER_THRESHOLD = 1000000;    // Rp 1,000,000
const double GOLD_THRESHOLD = 3000000;      // Rp 3,000,000  
const double PLATINUM_THRESHOLD = 10000000; // Rp 10,000,000
```

## 🌐 Cross-Platform Compatibility

### Platform-Specific Features
```cpp
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
    #define PATH_SEPARATOR "\\"
#elif defined(__linux__) || defined(__APPLE__)
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
    #define PATH_SEPARATOR "/"
#endif
```

## 🤝 Contributing Guidelines

We welcome contributions from the community! Please follow our guidelines:

### Development Workflow
1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Follow** our coding standards (see `CODING_STYLE.md`)
4. **Write** comprehensive tests
5. **Update** documentation accordingly
6. **Submit** a pull request

### Code Style Standards
- **Naming**: camelCase for variables, PascalCase for classes
- **Documentation**: Doxygen-style comments for all public functions
- **Testing**: Minimum 80% code coverage required
- **Formatting**: Use clang-format with provided `.clang-format` file

### Bug Reports & Feature Requests
- Use GitHub Issues with appropriate templates
- Provide detailed reproduction steps
- Include system specifications and compiler version
- Suggest solutions or alternatives when possible

## 📄 License & Legal

no license

### Third-Party Acknowledgments
- **Standard C++ Library** - STL containers and algorithms
- **Console UI Inspiration** - Various CLI design patterns
- **Batik Cultural References** - Traditional Indonesian motifs and pricing

## 🆘 Support & Community

### Getting Help
- **💬 Discussions**: Join conversations in [GitHub Discussions](https://github.com/arizzira/Project-Toko-Batik-Cirebon/discussions)
- **🐛 Issues**: Report bugs via [GitHub Issues](https://github.com/arizzira/Project-Toko-Batik-Cirebon/issues)
- **📧 Contact**: Direct support at [arizgg6@gmail.com](mailto:arizgg6@gmail.com)

### Community Guidelines
- Be respectful and inclusive
- Help others learn and grow
- Share knowledge and experiences
- Celebrate cultural heritage and traditional crafts

## 📊 Project Statistics

![GitHub stars](https://img.shields.io/github/stars/arizzira/Project-Toko-Batik-Cirebon?style=social)
![GitHub forks](https://img.shields.io/github/forks/arizzira/Project-Toko-Batik-Cirebon?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/arizzira/Project-Toko-Batik-Cirebon?style=social)

## 👨‍💻 Author & Maintainer

**Arizzira** - *Lead Developer & Project Maintainer*

- 🌐 **GitHub**: [@arizzira](https://github.com/arizzira)
- 💼 **LinkedIn**: [Connect with me](https://linkedin.com/in/muhammad_ariz)
- 📧 **Email**: [arizgg6@gmail.com](mailto:arizgg6@gmail.com)

### Specializations
- **Data Structures & Algorithms** in C++
- **System Architecture** for retail applications
- **Cultural Computing** and heritage preservation
- **Educational Technology** development

---

<div align="center">

### 🌟 **If this project helped you learn C++ or understand data structures, please consider giving it a star!** 🌟

*Preserving Indonesian cultural heritage through innovative technology* 🇮🇩

**Built with ❤️ for the C++ and Indonesian developer communities**

</div>
