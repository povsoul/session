#include <iostream>
#include <vector>
#include <unordered_set>

int countDistinctNumbers(const std::vector<int>& arr) {
    std::unordered_set<int> uniqueNumbers;
    for (int num : arr) {
        uniqueNumbers.insert(num);
    }
    return uniqueNumbers.size();
}

std::vector<int> transformArray(const std::vector<int>& arr) {
    std::vector<int> positiveNumbers;
    std::vector<int> negativeNumbers;
    for (int num : arr) {
        if (num >= 0) {
            positiveNumbers.push_back(num);
        }
        else {
            negativeNumbers.push_back(num);
        }
    }
    positiveNumbers.insert(positiveNumbers.end(), negativeNumbers.begin(), negativeNumbers.end());
    return positiveNumbers;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    int size;
    std::cout << "Введiть розмiр масиву: ";
    std::cin >> size;

    std::vector<int> array(size);
    std::cout << "Введiть елементи масиву: \n";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    int distinctCount = countDistinctNumbers(array);

    std::cout << "Кiлькiсть рiзних чисел: " << distinctCount << std::endl;

    std::vector<int> transformedArray = transformArray(array);

 
    std::cout << "Трансформований масив: ";
    for (int num : transformedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> positiveTestArray = { 5, 7, 5 };
    int positiveTestDistinctCount = countDistinctNumbers(positiveTestArray);
    std::cout << "Позитивний тест - кiлькiсть рiзних чисел: " << positiveTestDistinctCount << std::endl;

    std::vector<int> positiveTestTransformedArray = transformArray(positiveTestArray);
    std::cout << "Позитивний тест - трансформований масив: ";
    for (int num : positiveTestTransformedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> negativeTestArray = { 1, 1, 1, 1, 1 };
    int negativeTestDistinctCount = countDistinctNumbers(negativeTestArray);
    std::cout << "Негативний тест - кiлькiсть рiзних чисел: " << negativeTestDistinctCount << std::endl;

    std::vector<int> negativeTestTransformedArray = transformArray(negativeTestArray);
    std::cout << "Негативний тест - трансформований масив: ";
    for (int num : negativeTestTransformedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
