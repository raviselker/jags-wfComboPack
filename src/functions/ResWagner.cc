#include <config.h>
#include "ResWagner.h" // class header file
#include <util/nainf.h> // provides na and inf functions

#include <cmath> // basic math operations
#include <iostream>
#include <typeinfo>

#include <algorithm>

#include <util/dim.h>
#include <util/logical.h>

using std::vector; // vector is used in the code
using std::string; // string is used in the code

#define choice (args[0])
#define reward (args[1])
#define va0 (*args[2])
#define vb0 (*args[3])
#define a (*args[4])
#define beta (*args[5])

namespace jags {
namespace wfComboPack {

    ResWagner::ResWagner() :VectorFunction ("reswagner", 6)
    {}

    void ResWagner::evaluate (double *value, vector <double const *> const &args,
                              vector<unsigned int> const &lengths) const
    {
        int N = lengths[0];
        std::vector<double> va (N + 1, 0.0);
        std::vector<double> vb (N + 1, 0.0);
        va[0] = va0;
        vb[0] = vb0;

        for (unsigned int i = 0; i < N; i++) {
            if (choice[i] == 0) {
                va[i + 1] = va[i] + a * (reward[i] - va[i]);
                vb[i + 1] = vb[i];
            } else {
                va[i + 1] = va[i];
                vb[i + 1] = vb[i] + a * (reward[i] - vb[i]);
            }

            value[i] = exp(beta * (vb[i + 1] - va[i + 1])) / (1 + exp(beta * (vb[i + 1] - va[i + 1])));
        }

        // std::cout << "va0: " << va[0] << '\n';
    }

    unsigned int ResWagner::length (vector<unsigned int> const &parlengths,
                                    vector<double const *> const &parvalues) const
    {
        return parlengths[0];
    }

    bool ResWagner::isDiscreteValued(vector<bool> const &mask) const
    {
        return allTrue(mask);
    }
}}
