#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <ctime>

const std::string high_scores_filename = "high_scores.txt";
const int max_value = 100;

int main() {
    // Инициализация генератора случайных чисел
    std::srand(std::time(nullptr));
    const int random_value = std::rand() % max_value;

    // Запрос имени игрока
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;

    // Основной игровой цикл
    int attempts_count = 0;
    int current_value = 0;
    std::cout << "Enter your guess (0-" << max_value - 1 << "):" << std::endl;

    while (true) {
        std::cin >> current_value;
        attempts_count++;

        if (current_value < random_value) {
            std::cout << "less than " << current_value << std::endl;
        }
        else if (current_value > random_value) {
            std::cout << "greater than " << current_value << std::endl;
        }
        else {
            std::cout << "you win! attempts = " << attempts_count << std::endl;
            break;
        }
    }

    // Запись результата в файл
    {
        std::ofstream out_file(high_scores_filename, std::ios_base::app);
        if (!out_file.is_open()) {
            std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
            return -1;
        }
        out_file << user_name << ' ' << attempts_count << std::endl;
    }

    // Чтение и вывод таблицы рекордов
    {
        std::ifstream in_file(high_scores_filename);
        if (!in_file.is_open()) {
            std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
            return -1;
        }

        std::cout << "High scores table:" << std::endl;
        std::string username;
        int high_score;
        while (in_file >> username >> high_score) {
            std::cout << username << '\t' << high_score << std::endl;
        }
    }

    return 0;
}