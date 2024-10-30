#include <iostream>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    int summa = 0;
    for (size_t x = 0; x <= n; x += 5)
        summa += x;

    std::cout << "summa = " << summa << std::endl;

    return 0;
}
