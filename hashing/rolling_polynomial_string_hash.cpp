#include <string>
#include <iostream>

using namespace std;

unsigned long rolling_polynomial_string_hash(string s)
{
    int mod = 1e9 + 9;
    int prime = 53;
    unsigned long current_prime_value = 1;
    unsigned long hash = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        unsigned int c = s.at(i);
        hash = (hash + current_prime_value * c) % mod;
        current_prime_value = (current_prime_value * prime) % mod;
    }

    return hash;
}

int main()
{
    string aba = "aba";
    cout << rolling_polynomial_string_hash(aba) << endl;

    aba = "I am a programmer.";
    cout << rolling_polynomial_string_hash(aba) << endl;

    aba = "asdsadfjsdjfhksdhfkjsahf234uifheirfhrei$%u#$5fhe#rkfhksajrhfaisrfhsafrhkajrfh";
    cout << rolling_polynomial_string_hash(aba) << endl;
}
