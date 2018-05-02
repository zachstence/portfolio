#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NAME_WIDTH = 18;
const int SKU_WIDTH = 6;
const int QUANT_WIDTH = 10;
const int PRICE_WIDTH = 8;

//Define Product structure
struct Product {
  string name;
  int sku;
  int quantity;
  double price;
};

/////////////////////////////////////////////////////////////////////70
//
//
void sortBySKU(Product inventory[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < size-1; startScan++) {
    minIndex = startScan;
    minValue = inventory[startScan].sku;
    for (int index = startScan + 1; index < size; index++) {
      if (inventory[index].sku < minValue) {
        minValue = inventory[index].sku;
        minIndex = index;
      }
    }
    Product temp = inventory[minIndex];
    inventory[minIndex] = inventory[startScan];
    inventory[startScan] = temp;
  }
}

int skuBinarySearch(Product inventory[], int size, int target) {
  int first = 0;
  int last = size - 1;
  int middle;
  int position = -1;
  bool found = false;
  while (first <= last && !found) {
    middle = (first + last) / 2;
    if (inventory[middle].sku == target) {
      found  = true;
      position = middle;
    }
    else if (target < inventory[middle].sku) {
      last = middle - 1;
    }
    else {
      first = middle + 1;
    }
  }
  return position;
}

int nameSearch(Product inventory[], int size, string target) {
  for (int i = 0; i < size; i++) {
    if (inventory[i].name == target)
      return i;
  }
  return -1;
}

int main () {
  //Array of structs
  Product inventory[100];

  ifstream inputFile;
  string name;
  int sku;
  int quantity;
  double price;

  //Open the file
  inputFile.open("inventory.dat");

  //Read from the file
  int count = 0;
  while (inputFile >> inventory[count].name) {
    inputFile >> inventory[count].sku;
    inputFile >> inventory[count].quantity;
    inputFile >> inventory[count].price;
    count++;
  }

  //Close the file
  inputFile.close();

  int choice;
  do {
    cout << "\n--------------------------------------------------\n" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Display the inventory sorted by SKU." << endl;
    cout << "2. Lookup a product by SKU." << endl;
    cout << "3. Lookup a product by name." << endl;
    cout << "4. Quit." << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
      sortBySKU(inventory, count);
      cout << "\nSKU   Name              Quantity  Price" << endl;
      for (int i = 0; i < count; i++) {
        cout << left << setw(SKU_WIDTH) << inventory[i].sku;
        cout << left << setw(NAME_WIDTH) << inventory[i].name;
        cout << left << setw(QUANT_WIDTH) << inventory[i].quantity;
        cout << left << setw(PRICE_WIDTH) << inventory[i].price << endl;
      }
    }
    else if (choice == 2) {
      int searchSKU = 0;
      cout << "Enter the SKU of the product you would like to lookup: ";
      cin >> searchSKU;
      sortBySKU(inventory, count);
      if (skuBinarySearch(inventory, count, searchSKU) == -1)
        cout << "No product found with this SKU" << endl;
      else {
        int pos = skuBinarySearch(inventory, count, searchSKU);
        cout << "\nName:\t\t" << inventory[pos].name << endl << "SKU:\t\t"
          << inventory[pos].sku << endl << "Quantity:\t"
          << inventory[pos].quantity << endl << "Price:\t\t"
          << inventory[pos].price << endl;
      }
    }
    else if (choice == 3) {
      string searchName;
      cout << "Enter the name of the product you would like to lookup: ";
      cin >> searchName;
      if (nameSearch(inventory, count, searchName) == -1)
        cout << "No product found with this name." << endl;
      else {
        int pos = nameSearch(inventory, count, searchName);
        cout << "\nName:\t\t" << inventory[pos].name << endl << "SKU:\t\t"
          << inventory[pos].sku << endl << "Quantity:\t"
          << inventory[pos].quantity << endl << "Price:\t\t"
          << inventory[pos].price << endl;
      }
    }
    else if (choice == 4) {
      cout << "Program ended.\n" << endl;
    }
    else {
      cout << "Please enter a valid choice (1, 2, 3, or 4)." << endl;
    }
  } while(choice != 4);
}
