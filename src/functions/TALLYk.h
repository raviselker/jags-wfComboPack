#ifndef TALLYk_FUNC_H_
#define TALLYk_FUNC_H_

#include <function/VectorFunction.h>

namespace jags {
namespace wfComboPack {

    class TALLYk : public VectorFunction
    {
    public:
        TALLYk();

        void evaluate(double *value, std::vector <double const *> const &args,
                      std::vector <unsigned int> const &lengths) const;

        unsigned int length(std::vector<unsigned int> const &parlengths,
                            std::vector<double const *> const &parvalues) const;

        bool isDiscreteValued(std::vector<bool> const &mask) const;
    };

}}

#endif /* TALLYk_FUNC_H_ */
