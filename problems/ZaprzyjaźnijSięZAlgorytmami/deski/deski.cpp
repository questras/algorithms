#include<iostream>
using namespace std;

int main() {
    int boardNum;
    cin>>boardNum;
    int nailsNum;
    cin>>nailsNum;

    int *boardBeg = new int[boardNum];
    int *boardEnd = new int[boardNum];

    int lastBoardNumb = 0;

    for (int i = 0; i < boardNum; i++)
    {
        cin>>boardBeg[i]>>boardEnd[i];
        lastBoardNumb = max(lastBoardNumb, boardEnd[i]);
    }

    int *nails = new int[nailsNum];
    for (int i = 0; i < nailsNum; i++)
    {
        cin>>nails[i];
    }

    int beg = 0;
    int end = nailsNum-1;
    int answer = -1;
    while (beg <= end) {
        int mid = (beg + end) / 2;

        int *prefixes = new int[lastBoardNumb + 1];
        for (int i = 0; i < lastBoardNumb + 1; i++)
        {
            prefixes[i] = 0;
        }   

        for (int i = 0; i < mid + 1; i++)
        {
            prefixes[nails[i]]++;
        }

        for (int i = 1; i < lastBoardNumb+1; i++)
        {
            prefixes[i] += prefixes[i-1];
        }

        bool result = true;
        for (int i = 0; i < boardNum; i++)
        {
            if (prefixes[boardEnd[i]] - prefixes[boardBeg[i]-1] < 1) {
                result = false;
            }
        }
        
        if (result) {
            answer = mid;
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }

        free(prefixes);

    }

    cout<<answer+1<<endl;
    
}
