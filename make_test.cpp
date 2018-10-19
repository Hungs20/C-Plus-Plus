#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int NTEST = 50;
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        cerr << "Make test " << iTest << " : ";
        string nTest = "";
        int buffer = iTest;
        while(buffer > 0)
        {
            nTest += char(buffer%10 + '0');
            buffer /= 10;
        }
        reverse(nTest.begin(), nTest.end());
        CreateDirectory(nTest.c_str(), NULL);

		ofstream inp, out;
        string inName = nTest + "/NAME.inp";
        string outName = nTest + "/NAME.out";
        inp.open(inName.c_str());
        out.open(outName.c_str());
        // Code phần sinh test ở đây
        

        // End code
        inp.close();
        out.close();
        cerr << "Done\n";
    }
    return 0;
}
