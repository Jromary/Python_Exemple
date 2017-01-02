#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

typedef int myint;

std::vector<myint> tri_pivot(std::vector<myint> liste)
{
    std::srand(std::time(NULL));
    myint n(liste.size());
    myint elt_tri(liste[rand() % n]);
    std::vector<myint> tab_inf, tab_egal, tab_sup;
    for (myint i(0); i < n; i++)
    {
        myint elt(liste[i]);
        if (elt < elt_tri)
        {
            tab_inf.push_back(elt);
        }
        else if (elt > elt_tri)
        {
            tab_sup.push_back(elt);
        }
        else
        {
            tab_egal.push_back(elt);
        }
    }
    if (tab_inf.size() > 0)
    {
        tab_inf = tri_pivot(tab_inf);
    }
    if (tab_sup.size() > 0)
    {
        tab_sup = tri_pivot(tab_sup);
    }
    tab_egal.insert(tab_egal.begin(), tab_inf.begin(), tab_inf.end());
    tab_egal.insert(tab_egal.end(), tab_sup.begin(), tab_sup.end());

    return tab_egal;
}

int main(int argc, char *argv[])
{
    /// Définition des variables
    std::srand(std::time(NULL));
    myint n(20), m(20);
    std::string liste_string(""), liste_string_s("");
    bool ok(true);

    /// Corps du programme
    std::vector<myint> liste_test(n, 0), liste_test_v(n, 0);
    for (myint i(0); i < n; i++)
    {
        myint nombre(rand() % m + 1);
        liste_test[i] = nombre;
        liste_test_v[i] = nombre;
        liste_string += (std::to_string(nombre) + " ");
    }
    std::sort(liste_test_v.begin(), liste_test_v.end());
    liste_test = tri_pivot(liste_test);
    for (myint i(0); i < n; i++)
    {
        myint elt(liste_test[i]);
        liste_string_s += (std::to_string(elt) + " ");
        if (elt != liste_test_v[i])
        {
            ok = false;
        }
    }
    std::cout << liste_string << std::endl;
    std::cout << liste_string_s << std::endl;
    std::cout << std::to_string(ok) << std::endl;

    return 0;
}

