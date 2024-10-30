#include <iostream>
#include <string>

std::string find_most_short_word(std::string line)
{
    int most_short_word_length = 0, most_short_word_start_index = 0;
    int current_word_length = 0, current_word_start_index = 0;

    int i = 0; // current index
    for (auto it = line.begin();; it++, i++)
    {
        if ((it == line.end()) || (*it == ' '))
        {

            if (current_word_length == 0)
            {
            }
            else if ((current_word_length <= most_short_word_length) || (most_short_word_length == 0))
            {
                most_short_word_length = current_word_length, most_short_word_start_index = current_word_start_index;
            }

            if (it == line.end())
                break;

            current_word_start_index =
                i + 1 // skip current whitespace
                ,
            current_word_length = 0;
        }
        else
        {
            current_word_length++;
        }
    }

    return line.substr(most_short_word_start_index, most_short_word_length);
}

int main(int argc, char const *argv[])
{
    std::string line;

    std::getline(std::cin, line);

    std::cout << "Most short word: " << find_most_short_word(line) << std::endl;

    return 0;
}
