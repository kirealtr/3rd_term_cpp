#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
  string name;
  int price;
  string has_cashback;
  int max_temperature;
};

int main() {
  struct Product imported_product;
  // Ввод
  cout << "Product's name: ";
  cin >> imported_product.name;
  cout << "Product's price: ";
  cin >> imported_product.price;
  cout << "Is cash-back available for this product? (true/false) ";
  cin >> imported_product.has_cashback;
  cout << "Maximum storing temperature: ";
  cin >> imported_product.max_temperature;
  // Вывод
  cout << imported_product.name << endl;
  cout << "Price:..........." << setfill('0') << setw(8) << 
    uppercase << hex << imported_product.price << endl;
  cout << "Has cash-back:" << setfill('.') << setw(11) <<
    imported_product.has_cashback << endl;
  cout << "Max temperature:" << setfill('.') << setw(9) <<
    showpos << dec << imported_product.max_temperature << endl;
}