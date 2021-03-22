#include<iostream>
#include<algorithm>
using namespace std;


long long int howManyLargerOrEqual(long long int givenSize, long long int sizesTopAndBot[], long long int sizesSides[], long long int sideParts) {
    long long int howMany = 0;
    long long int heightIndex = sideParts - 1;
    for (long long int i = 0; i < sideParts; i++)
    {
        while(heightIndex >= 0 && (sizesTopAndBot[i] * sizesSides[heightIndex]) >= givenSize) {
            heightIndex--;
        }
        howMany += sideParts - (heightIndex + 1);
    }
    
    return howMany;
}

int main() {
    long long int a, b, cuts; 
    long long int desiredNumberOfLarger;
    cin>>a>>b>>cuts>>desiredNumberOfLarger;

    long long int *cutOnTopAndBot = new long long int[cuts];
    long long int *cutOnSides = new long long int[cuts];

    for (long long int i = 0; i < cuts; i++)
    {
        cin>>cutOnTopAndBot[i];
    }

    for (long long int i = 0; i < cuts; i++)
    {
        cin>>cutOnSides[i];
    }

    long long int *sizesTopAndBot = new long long int[cuts + 1];
    long long int *sizesSides = new long long int[cuts + 1];

    sizesTopAndBot[0] = cutOnTopAndBot[0];
    sizesTopAndBot[cuts] = a - cutOnTopAndBot[cuts - 1];
    for (long long int i = 1; i < cuts; i++) {
        sizesTopAndBot[i] = cutOnTopAndBot[i] - cutOnTopAndBot[i-1];
    }

    sizesSides[0] = cutOnSides[0];
    sizesSides[cuts] = b - cutOnSides[cuts - 1];
    for (long long int i = 1; i < cuts; i++) {
        sizesSides[i] = cutOnSides[i] - cutOnSides[i-1];
    }

    sort(sizesTopAndBot, sizesTopAndBot + (cuts+1));
    sort(sizesSides, sizesSides + (cuts+1));

    long long int beg = 1;
    long long int end = a * b;
    long long int result;
    while (beg <= end) {
        long long int mid = (beg + end) / 2;

        if (howManyLargerOrEqual(mid, sizesTopAndBot, sizesSides, cuts+1) >= desiredNumberOfLarger) {
            result = mid;
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout<<result<<endl;
    
}
