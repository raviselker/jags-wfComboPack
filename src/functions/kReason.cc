#include <config.h>
#include "kReason.h" // class header file
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
#define bound (*args[3]) // upper bound

namespace jags {
namespace wfComboPack {

    kReason::kReason() :VectorFunction ("kReason", 4)
    {}

    void kReason::evaluate (double *value, vector <double const *> const &args,
                         vector<unsigned int> const &lengths) const
    {
        int N = lengths[0];
        std::vector<int> index (N, 0);
        for (unsigned int i = 0; i < N; i++) {
            index[i] = (int)s[i]-1;
        }

        double evA = 0; // bias = 0
        double evB = 0;
        for (unsigned int i = 0; i < N; i++) {
            if (stimA[index[i]] == 1) {
                evA++;
            }
            if (stimB[index[i]] == 1) {
                evB--;
            }

            if (evA >= bound && evB <= -bound) {
                value[0] = 0.5;
                value[1] = i + 1;
                value[2] = evA;
                value[3] = evB;
                break;
            } else if (evA >= bound) {
                value[0] = 1;
                value[1] = i + 1;
                value[2] = evA;
                value[3] = evB;
                break;
            } else if (evB <= -bound) {
                value[0] = 0;
                value[1] = i + 1;
                value[2] = evA;
                value[3] = evB;
                break;
            } else if (i == (N - 1)) {
                value[0] = 0.5;
                value[1] = N;
                value[2] = evA;
                value[3] = evB;
                break;
            }
        }
    }

    unsigned int kReason::length (vector<unsigned int> const &parlengths,
                               vector<double const *> const &parvalues) const
    {
        return 4;
    }

    bool kReason::isDiscreteValued(vector<bool> const &mask) const
    {
        return allTrue(mask);
    }
}}
