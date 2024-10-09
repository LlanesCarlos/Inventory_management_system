#include <iostream>   // For standard I/O operations
#include <fstream>    // For file handling
#include <vector>     // To use the vector container
#include <stdexcept>  // For exception handling

using namespace std;  // Use the standard namespace

// Define a Product class that represents an individual item in the inventory
class Product {
private:
    int id;               // Unique product ID
    string name;          // Product name
    int quantity;         // Available quantity of the product
    double price;         // Price of the product

public:
    // Constructor to initialize product details
    Product(int id, const string& name, int quantity, double price) 
        : id(id), name(name), quantity(quantity), price(price) {}

    // Function to display product details
    void display() const {
        cout << "ID: " << id << ", Name: " << name 
             << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }

    // Getter functions for product properties
    int getId() const { return id; }
    int getQuantity() const { return quantity; }
    
    // Setter function to update product quantity
    void setQuantity(int newQuantity) { quantity = newQuantity; }
};

// Define an Inventory class to manage multiple products
class Inventory {
private:
    vector<Product> products;  // Vector to store all products

public:
    // Function to add a product to the inventory
    void addProduct(const Product& product) {
        products.push_back(product);  // Add product to the vector
    }

    // Function to display all products in the inventory
    void displayProducts() const {
        for (const auto& product : products) {  // Loop through each product
            product.display();  // Display details of the current product
        }
    }

    // Function to update the quantity of a specific product by its ID
    void updateQuantity(int productId, int newQuantity) {
        for (auto& product : products) {  // Loop through each product
            if (product.getId() == productId) {  // Find the product with the matching ID
                product.setQuantity(newQuantity);  // Update its quantity
                return;  // Exit the function once the product is updated
            }
        }
        // Throw an exception if the product with the given ID is not found
        throw runtime_error("Product not found!");
    }

    // Function to save product data to a file
    void saveToFile(const string& filename) const {
        ofstream file(filename);  // Open a file in write mode
        if (!file) throw runtime_error("Failed to open file.");  // Handle file open failure
        
        // Write each product's ID and quantity to the file
        for (const auto& product : products) {
            file << product.getId() << " " << product.getQuantity() << endl;
        }
        file.close();  // Close the file after writing
    }

    // Function to load product data from a file and update quantities
    void loadFromFile(const string& filename) {
        ifstream file(filename);  // Open a file in read mode
        if (!file) throw runtime_error("Failed to open file.");  // Handle file open failure

        // Read the product ID and quantity from the file
        int id, quantity;
        while (file >> id >> quantity) {
            // Update the quantity of the corresponding product
            for (auto& product : products) {
                if (product.getId() == id) {
                    product.setQuantity(quantity);
                }
            }
        }
        file.close();  // Close the file after reading
    }
};

// Main function to run the program
int main() {
    Inventory inventory;  // Create an Inventory object

    // Add products to the inventory
    inventory.addProduct(Product(1, "Laptop", 10, 999.99));
    inventory.addProduct(Product(2, "Phone", 20, 499.99));
    inventory.addProduct(Product(3, "Tablet", 15, 299.99));

    // Display the initial inventory
    cout << "Initial Inventory:" << endl;
    inventory.displayProducts();

    try {
        // Update the quantity of the product with ID 2 (Phone) to 25
        inventory.updateQuantity(2, 25);
        // Save the updated inventory to a file
        inventory.saveToFile("inventory.txt");
    } catch (const exception& e) {
        // Handle any errors that occur during the update or file operation
        cerr << "Error: " << e.what() << endl;
    }

    // Display the updated inventory
    cout << "\nUpdated Inventory:" << endl;
    inventory.displayProducts();

    return 0;  // Exit the program
}
