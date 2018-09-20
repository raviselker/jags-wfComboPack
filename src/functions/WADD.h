#ifndef WADD_FUNC_H_
#define WADD_FUNC_H_

#include <function/VectorFunction.h>

namespace jags {
namespace wfComboPack {

    class WADD : public VectorFunction
    {
    public:
        WADD();

        void evaluate(double *value, std::vector <double const *> const &args,
                      std::vector <unsigned int> const &lengths) const;

        unsigned int length(std::vector<unsigned int> const &parlengths,
                            std::vector<double const *> const &parvalues) const;

        bool isDiscreteValued(std::vector<bool> const &mask) const;
    };

}}

#endif /* WADD_FUNC_H_ */
