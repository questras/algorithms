#include <string>
#include <iostream>

using namespace std;

unsigned long djb2_string_hash(string s)
{
    unsigned long hash = 5381;

    for (int i = 0; i < s.length(); ++i)
    {
        unsigned int c = s.at(i);
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main()
{
    string aba = "aba";
    cout << djb2_string_hash(aba) << endl;

    aba = "I am a programmer.";
    cout << djb2_string_hash(aba) << endl;

    aba = "asdsadfjsdjfhksdhfkjsahf234uifheirfhrei$%u#$5fhe#rkfhksajrhfaisrfhsafrhkajrfh";
    cout << djb2_string_hash(aba) << endl;
}
