# 🏭 Warehouse Management System

A console-based **C++ Warehouse Management System** that combines multiple data structures to manage inventory, process orders, and visualize warehouse layout.

---

## 📋 Table of Contents

- [Features](#features)
- [Data Structures Used](#data-structures-used)
- [Getting Started](#getting-started)
- [Menu Options](#menu-options)
- [Project Structure](#project-structure)
- [Example Usage](#example-usage)

---

## ✨ Features

- Add, update, delete, and search inventory items
- Sorted inventory view using a Binary Search Tree (BST)
- Order queue with stock validation and automatic inventory deduction
- Recent items tracking via a stack
- Visual 3×3 warehouse grid layout

---

## 🗃️ Data Structures Used

| Structure | Purpose |
|---|---|
| **Linked List** | Primary inventory storage — insert, delete, update, display |
| **Binary Search Tree (BST)** | Sorted inventory view and fast O(log n) search by item ID |
| **Queue** | FIFO order processing with stock validation |
| **Stack** | Tracks recently added/updated items (LIFO) |
| **2D Array (Grid)** | Physical warehouse layout visualization |

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`)

### Build & Run

```bash
# Clone the repository
git clone https://github.com/your-username/warehouse-management-system.git
cd warehouse-management-system

# Compile
g++ -std=c++11 -o wms main.cpp

# Run
./wms
```

---

## 🖥️ Menu Options

```
====== WAREHOUSE MANAGEMENT ======
 1.  Add Item
 2.  Delete Item
 3.  Update Item
 4.  Display Inventory (Linked List)
 5.  Display Inventory (BST Sorted)
 6.  Display Warehouse Grid
 7.  Add Order
 8.  Process Order
 9.  Display Orders
10.  Display Recent Items (Stack)
11.  Search Item (BST)
 0.  Exit
```

### Option Details

| Option | Description |
|---|---|
| **Add Item** | Inserts item into the linked list, BST, and recent items stack |
| **Delete Item** | Removes item from the linked list and BST by ID |
| **Update Item** | Updates name, quantity, and location across the linked list, BST, and stack |
| **Display Inventory (Linked List)** | Prints all items in insertion order |
| **Display Inventory (BST Sorted)** | Prints all items sorted by item ID (ascending) |
| **Display Warehouse Grid** | Shows the 3×3 grid with item names or "Empty" |
| **Add Order** | Enqueues a customer order (Order ID, customer name, item ID, quantity) |
| **Process Order** | Dequeues the next order; validates stock and deducts quantity on success |
| **Display Orders** | Lists all pending orders in the queue |
| **Display Recent Items** | Shows the stack of recently added/updated items |
| **Search Item (BST)** | Searches for an item by ID in the BST and displays its details |

---

## 🗂️ Project Structure

```
main.cpp
│
├── Item               — Inventory item (ID, name, quantity, location)
├── Node               — Linked list node
├── LinkedList         — Singly linked list for inventory management
│
├── Order              — Customer order (order ID, customer, item ID, quantity)
├── QueueNode          — Queue node for orders
├── OrderQueue         — FIFO queue for order processing
│
├── StackNode          — Stack node for recent items
├── ItemStack          — LIFO stack tracking recently modified items
│
├── BSTNode            — BST node storing an Item
├── InventoryBST       — BST sorted by item ID; supports insert, delete, search, update
│
├── WarehouseGrid      — 3×3 2D grid for physical warehouse layout
│
└── main()             — Console menu loop driving all operations
```

---

## 💡 Example Usage

```
Enter your choice: 1
Enter Item ID: 101
Enter Item Name: Widget A
Enter Quantity: 50
Enter Location: Aisle 3
Item added successfully.

Enter your choice: 7
Enter Order ID: 1
Enter Customer Name: Alice
Enter Item ID: 101
Enter Quantity: 10

Enter your choice: 8
Order processed successfully.
Order processed and inventory updated.
```

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
