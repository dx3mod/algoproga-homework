#include <iostream>
#include <string>
#include <tuple>

std::tuple<unsigned int, std::string> find_most_long_word_with_order(std::string line)
{
    int most_long_word_length = 0, most_long_word_start_index = 0;
    int current_word_length = 0, current_word_start_index = 0;
    int current_order = 0, most_long_word_order = 0;

    int i = 0; // current index
    for (auto it = line.begin();; it++, i++)
    {
        if ((it == line.end()) || (*it == ' '))
        {

            if (current_word_length == 0)
            {
            }
            else if ((current_word_length >= most_long_word_length) || (most_long_word_length == 0))
            {
                most_long_word_length = current_word_length,
                most_long_word_start_index = current_word_start_index,
                most_long_word_order = current_order;
            }

            if (it == line.end())
                break;

            current_word_start_index =
                i + 1 // skip current whitespace
                ,
            current_word_length = 0;

            current_order++;
        }
        else
        {
            current_word_length++;
        }
    }

    auto word = line.substr(most_long_word_start_index, most_long_word_length);

    return std::make_tuple(most_long_word_order, std::move(word));
}

int main(int argc, char const *argv[])
{
    std::string line;

    std::getline(std::cin, line);

    unsigned int order;
    std::string most_long_word;
    std::tie(order, most_long_word) = find_most_long_word_with_order(line);

    std::cout << "Most long word: '" << most_long_word << "', order: " << order << std::endl;

    return 0;
}
