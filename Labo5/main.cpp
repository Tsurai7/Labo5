#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdexcept>


class InvalidKeyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Key already exists in the dictionary.";
    }
};

class KeyNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Delete error";
    }
};


template <typename K, typename V>
class Dictionary {
public:
    std::vector<std::pair<K, V>> buckets;

    void Insert(K key, V val) {
        for (const auto& entry : buckets) {
            if (entry.first == key) {
                throw InvalidKeyException();
            }
        }
        buckets.push_back(std::make_pair(key, val));
    }

    std::pair<K, V> Find(K key) {
        try {
            size_t index = std::hash<K>{}(key) % buckets.size();

            for (const auto& entry : buckets) {
                if (entry.first == key)
                    return entry;
            }
            throw std::out_of_range("Key not found");
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return std::make_pair(K(), V());
        }
    }

    void Delete(K key) {
        try {
            size_t index = std::hash<K>{}(key) % buckets.size();

            auto it = std::remove_if(
                buckets.begin(), buckets.end(), [key](const std::pair<K, V>& entry) { return entry.first == key; });

            if (it != buckets.end()) {
                buckets.erase(it, buckets.end());
            }
            else {
                throw std::out_of_range("Out of range");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict) {
        for (const auto& entry : dict.buckets) {
            os << "Key: " << entry.first << ", Value: " << entry.second << std::endl;
        }
        return os;
    }
};

int main() {
    Dictionary<int, std::string> myDictionary;

    while (true) {
        std::cout << "Choose an action:" << std::endl;
        std::cout << "[1] Insert" << std::endl;
        std::cout << "[2] Find" << std::endl;
        std::cout << "[3] Delete" << std::endl;
        std::cout << "[4] Print" << std::endl;
        std::cout << "[5] Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            std::string value;
            std::cout << "Enter key: ";

            while (!(std::cin >> key)) {
                std::cout << "Invalid input for key. Please enter a valid integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter key: ";
            }

            std::cout << "Enter value: ";
            std::cin >> value;
            try {
                myDictionary.Insert(key, value);
            }

            catch (const InvalidKeyException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            break;
        }
        case 2: {
            if (myDictionary.buckets.size() == 0) {
                std::cout << "No elements" << std::endl;
                break;
            }

            int key;
            std::cout << "Enter key: ";

            while (!(std::cin >> key)) {
                std::cout << "Invalid input for key. Please enter a valid integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter key: ";
            }

            auto result = myDictionary.Find(key);

            if (result.first != int() || result.second != std::string()) {
                std::cout << "Key: " << result.first << ", Value: " << result.second << std::endl;
            }

            else {
                std::cout << "Key not found." << std::endl;
            }
            break;
        }
        case 3: {
            int key;
            std::cout << "Enter key to delete: ";
            std::cin >> key;

            try {
                myDictionary.Delete(key);
            }

            catch (const KeyNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            std::cout << "Dictionary contents:" << std::endl;
            std::cout << myDictionary << std::endl;
            break;
        }
        case 5: {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}
