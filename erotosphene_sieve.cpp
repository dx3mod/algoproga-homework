#include <iostream>
#include <vector>

using namespace std;

vector<bool> primes(int n)
{

    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i <= n; ++i)

        if (prime[i])

            for (int j = 2 * i; j <= n; j += i)

                prime[j] = false;

    return prime;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    int current_number = 0;
    for (auto x : primes(n))
    {
        if (x)
            cout << current_number << " ";

        current_number++;
    }

    cout << endl;

    return 0;
}
