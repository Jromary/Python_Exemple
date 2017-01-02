#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "heure.h"

using namespace std;

/* void debug(string var, unsigned long value)
{
    cout << var << ": " << to_string(value) << endl;
}

void debugt(string var, string message)
{
    cout << var << ": " << message << endl;
} */

int main()
{
    unsigned long n(0);
    cin >> n;

    bool print(false);
    cin >> print;

    unsigned long size(0);

    size = (unsigned long) (ceil((n - 3) / 2) + 1);
    /* debug("size", size); */
    vector<bool> tab(size, true);
    vector<unsigned long> prime_list(1, 2);

    double t_start(give_time());

    for (unsigned long i(0); i < size; i++)
    {
        /* debug("i", i); */
        if (tab[i])
        {
            /* debugt("tab[i]", "true"); */
            unsigned long current_nb(2 * i + 3);
            /* debug("current_nb", current_nb); */
            prime_list.push_back(current_nb);
            /* debugt("current_nb", "[x] push_back"); */
            for (unsigned long k(i + current_nb); k < size; k += current_nb)
            {
                tab[k] = false;
                /* debug("k", k);
                debugt("tab[k]", "-> false"); */
            }
        }
        /* else
        {
            debugt("tab[i]", "false");
            unsigned long current_nb(2 * i + 3);
            debug("current_nb", current_nb);
            debugt("current_nb", "[ ] no push_back");
        } */
    }

    double t_end(give_time());
    double t_elapsed(t_end - t_start);

    cout << "Time: " << to_string(t_elapsed) << endl;

    if (print)
    {
        for (unsigned long p(0); p < prime_list.size(); p++)
        {
            cout << prime_list[p] << " ";
        }
        cout << endl;
    }

    else
    {
        cout << prime_list[prime_list.size() - 1] << endl;
    }

    return 0;
}
