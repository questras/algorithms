#include <iostream>
using namespace std;

int main()
{
    int howMany, scope, modulo;
    cin >> howMany >> scope >> modulo;

    int questions[howMany];
    int maxQuestionValue = 0;
    for (int i = 0; i < howMany; i++)
    {
        cin >> questions[i];
        maxQuestionValue = max(maxQuestionValue, questions[i]);
    }

    // first cell is last number of series of length of second cell.
    int answers[scope + 1][maxQuestionValue + 1];

    for (int i = 0; i < scope + 1; i++)
    {
        // There are no series of length 0.
        answers[i][0] = 0;
        // There is only one series of length 1 ending with ith number.
        answers[i][1] = 1;
    }

    for (int i = 2; i < maxQuestionValue + 1; i++)
    {
        answers[0][i] = (answers[0][i - 1] + answers[1][i - 1]) % modulo;
        answers[scope][i] = (answers[scope - 1][i - 1] + answers[scope][i - 1]) % modulo;

        for (int k = 1; k < scope; k++)
        {
            answers[k][i] = (answers[k - 1][i - 1] + answers[k][i - 1] + answers[k + 1][i - 1]) % modulo;
        }
    }

    for (int i = 0; i < howMany; i++)
    {
        int result = 0;
        for (int k = 0; k < scope + 1; k++)
        {
            result = (result + answers[k][questions[i]]) % modulo;
        }
        cout << result << " ";
    }
}
