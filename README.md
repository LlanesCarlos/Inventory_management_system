# Inventory Management System

This is a C++ console application that simulates an **Inventory Management System**. It allows users to manage an inventory of products, update their quantities, and save/load product data to/from a file.

## Features

- Add new products to the inventory.
- Display the current inventory of products.
- Update the quantity of specific products using their ID.
- Save the inventory data to a text file (`inventory.txt`).
- Load the inventory data from a file and update quantities.

## Technologies Used

- **C++**: Core programming language used.
- **Object-Oriented Programming (OOP)**: Implements classes like `Product` and `Inventory`.
- **File Handling**: Reads from and writes to a file to persist inventory data.
- **Exception Handling**: Handles errors like file access issues and missing products.

## Code Structure

- **Product Class**: Represents an individual product with attributes like ID, name, quantity, and price.
- **Inventory Class**: Manages a collection of products and provides functionality to add, update, and save/load products.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/inventory-management-system.git
   cd inventory-management-system
   ```

2. Compile the code using a C++ compiler, e.g., g++:
  ```bash
  g++ inventory.cpp -o inventory
  ```

3. Run the application:
  ```bash
  ./inventory
  ```
