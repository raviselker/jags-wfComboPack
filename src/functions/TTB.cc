#include <config.h>
#include "TTB.h" // class header file
#include <util/nainf.h> // provides na and inf functions

#include <cmath> // basic math operations
#include <iostream>
#include <typeinfo>

#include <algorithm>

#include <util/dim.h>
#include <util/logical.h>

using std::vector; // vector is used in the code
using std::string; // string is used in the code

#define stimA (args[0])
#define stimB (args[1])
#define s (args[2]) // order of validities

namespace jags {
namespace wfComboPack {

    TTB::TTB() :ScalarVectorFunction ("TTB", 3)
    {}

    double TTB::scalarEval (vector <double const *> const &args,
                            vector<unsigned int> const &lengths) const
    {
        int N = lengths[0];
        std::vector<int> index (N, 0);
        for (unsigned int i = 0; i < N; i++) {
            index[i] = (int)s[i]-1;
        }

        double value;
        for (unsigned int i = 0; i < N; i++) {
            if (stimA[index[i]] > stimB[index[i]]) {
                value = 1;
                break;
            } else if (stimB[index[i]] > stimA[index[i]]) {
                value = 0;
                break;
            }

            if (i == (N - 1)) {
                value = 0.5;
                break;
            }
        }

        return(value);
    }

    bool TTB::checkParameterLength (vector<unsigned int> const &lengths) const
    {
        return lengths[0] >= 2;
    }

    bool TTB::isDiscreteValued(vector<bool> const &mask) const
    {
        return allTrue(mask);
    }
}}
