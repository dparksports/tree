#include <bits/stdc++.h>

using namespace std;

double factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    double result = n * factorial(n - 1);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double result = factorial(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
