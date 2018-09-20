#include <config.h>
#include "generalAccumulator.h" // class header file
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
#define v (args[2]) // validities
#define s (args[3]) // order of validities
#define k (*args[4]) // number of cues before decision is made
#define bias (*args[5]) // bias stimulus A
#define lower (*args[6]) // lower boundry
#define upper (*args[7]) // upper boundry

namespace jags {
namespace wfComboPack {

    generalAccumulator::generalAccumulator() :VectorFunction ("generalAccumulator", 8)
    {}

    void generalAccumulator::evaluate (double *value, vector <double const *> const &args,
                         vector<unsigned int> const &lengths) const
    {
        int N = lengths[0];
        std::vector<int> index (N, 0);
        for (unsigned int i = 0; i < N; i++) {
            index[i] = (int)s[i]-1;
        }

        double evA = bias;
        double evB = bias;
        for (unsigned int i = 0; i < k; i++) {
            if (stimA[index[i]] == 1) {
                evA += v[ index[i] ];
            }
            if (stimB[index[i]] == 1) {
                evB -= v[ index[i] ];
            }

            if (evA >= upper && evB <= lower) {
                value[0] = 0.5;
                value[1] = i + 1;
                value[2] = evA;
                value[3] = evB;
                break;
            } if (evA >= upper) {
                value[0] = 1;
                value[1] = i + 1;
                value[2] = evA;
                value[3] = evB;
                break;
            } else if (evB <= lower) {
                value[0] = 0;
                value[1] = i + 1;
                value[2] = evA;
                value[3] = evB;
                break;
            } else if (i == (k - 1)) {
                value[0] = 0.5;
                value[1] = k;
                value[2] = evA;
                value[3] = evB;
                break;
            }
        }
    }

    unsigned int generalAccumulator::length (vector<unsigned int> const &parlengths,
                               vector<double const *> const &parvalues) const
    {
        return 4;
    }

    bool generalAccumulator::isDiscreteValued(vector<bool> const &mask) const
    {
        return allTrue(mask);
    }
}}
