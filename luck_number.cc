#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int random_unint(unsigned int min, unsigned int max)
{
    static default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

int main()
{
    unsigned int count = random_unint(1,INT8_MAX);
    cout << count << endl;
    vector<vector<vector<unsigned>>> brVec(count);
    for(unsigned int i = 0;i < count;++i)
    {
        vector<vector<unsigned>> br(2);
        vector<unsigned> b(5);
        vector<unsigned> r(2);
        for(unsigned blue = 0;blue < 5;++blue)
        {
            b[blue] = random_unint(1,35);
        }
        for(unsigned red = 0;red < 2;++red)
        {
            r[red] = random_unint(1,12);
        }

        br[0] = b;;
        br[1] = r;
        brVec[i] = br;
    }

    unsigned int luckNum = random_unint(1,count);
    vector<unsigned> b = brVec[luckNum-1][0];
    vector<unsigned> r = brVec[luckNum-1][1];
    sort(b.begin(),b.end());
    cout << "blue:";
    for(unsigned blue = 0;blue < 5;++blue)
        cout << b[blue] << " ";
    sort(r.begin(),r.end());
    cout << "red:";
    for(unsigned red = 0;red < 2;++red)
        cout << r[red] << " ";
    cout << endl;

    return 0;
}
