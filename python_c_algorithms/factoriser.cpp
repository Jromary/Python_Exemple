#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    assert (argc > 1);
    char *p_end(NULL);
    unsigned long long n(std::strtoull(argv[1], &p_end, 10));
    /// Corps du programme
    std::vector<std::string> liste_diviseurs;

    double t_depart(clock());

    unsigned long long puissance_2(0);
    while (n % 2 == 0)
    {
        puissance_2++;
        n /= 2;
    }

    if (puissance_2)
    {
        std::string chaine("(2, " + std::to_string(puissance_2) + ")");
        liste_diviseurs.push_back(chaine);
    }

    unsigned long long i(3);
    while (n > 1)
    {
        bool trouve_diviseur(false);
        unsigned long long limite((unsigned long long) (sqrt(n)));
        while (i <= limite and not trouve_diviseur)
        {
            if (n % i == 0)
            {
                trouve_diviseur = true;
                unsigned long long puissance_i(0);
                while (n % i == 0)
                {
                    puissance_i++;
                    n /= i;
                }
                std::string chaine("(" + std::to_string(i) + ", " +
                    std::to_string(puissance_i) + ")");
                liste_diviseurs.push_back(chaine);
            }
            i += 2;
        }
        if (not trouve_diviseur)
        {
            std::string chaine("(" + std::to_string(n) + ", 1)");
            liste_diviseurs.push_back(chaine);
            n = 1;
        }
    }

    double t_fin(clock());

    unsigned long long lliste_diviseurs(liste_diviseurs.size());
    for (unsigned long long iliste_diviseurs(0); iliste_diviseurs < lliste_diviseurs;
         iliste_diviseurs++)
    {
        std::cout << liste_diviseurs[iliste_diviseurs] << " ";
    }
    std::cout << std::endl;

    double temps((t_fin - t_depart) / CLOCKS_PER_SEC);
    std::cout << "Temps : " << std::to_string(temps) << std::endl;
}
