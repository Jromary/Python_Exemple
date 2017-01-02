#include <iostream>
#include <cmath>
#include <vector>
#include <string>

int main()
{
    /// On demande le nombre max
    unsigned long n(0);
    std::cin >> n;
    /// On demande si on doit afficher les résultats
    bool print(false);
    std::cin >> print;

    /// Déclaration des variables
    unsigned long size(0);

    size = (unsigned long) (std::ceil((n - 3) / 2) + 1);
    std::vector<bool> tab(size, true);
    std::vector<unsigned long> prime_list(1, 2);

    for (unsigned long i(0); i < size; i++)
    {
        if (tab[i])
        {
            unsigned long current_nb(2 * i + 3);
            prime_list.push_back(current_nb);
            for (unsigned long k(i + current_nb); k < size; k += current_nb)
            {
                tab[k] = false;
            }
        }
    }

    if (print)
    {
        for (unsigned long p(0); p < prime_list.size(); p++)
        {
            std::cout << prime_list[p] << " ";
        }
        std::cout << std::endl;
    }

    else
    {
        std::cout << prime_list[prime_list.size() - 1] << std::endl;
    }

    return 0;
}
