#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>

void print_char_n_times(char c, int n);

/*
    Работает только для английского языка.

    P.S.
    Чтобы это сделать нормально, то надо работать с кодировкой, а это уже бред для 
    задачи на один балл. 

    Я и так потратил слишком много сил и времени на эти трешовые задачи.  
*/

int main(int argc, char const *argv[])
{

    // Input values

    std::cout << "Введите ваше ФИО: ";

    std::string first_name, last_name, surname;
    std::cin >> first_name >> last_name >> surname;

    std::cout << "Введите вашу группу: ";

    std::string group;
    std::cin.ignore(255, '\n'); // hack for call getline after cin
    std::getline(std::cin, group);

    // Display code block

    std::cout << "\n";

    std::array<std::string, 3> lines({"Laboratory work (num. 1)",
                                      ("Done by: " + group),
                                      (first_name + " " + last_name + " " + surname)});

    auto widest_line = *std::max_element(lines.begin(), lines.end(), [](std::string &lhs, std::string &rhs)
                                         { return lhs.size() < rhs.size(); });
    auto widest_line_length = widest_line.length();

    std::cout << "/";
    print_char_n_times('*', widest_line_length + 4);
    std::cout << "\n";

    for (auto it = lines.begin(); it != lines.end(); it++)
    {
        std::cout << " * " << *it;
        print_char_n_times(' ', widest_line_length - it->length());
        std::cout << " *\n";
    }

    std::cout << " ";
    print_char_n_times('*', widest_line_length + 4);
    std::cout << "/" << std::endl;

    return 0;
}

void print_char_n_times(char c, int n)
{
    while ((n--) > 0)
        std::cout << c;
}
