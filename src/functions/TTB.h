#ifndef TTB_FUNC_H_
#define TTB_FUNC_H_

#include <function/ScalarVectorFunction.h>

namespace jags {
namespace wfComboPack {

    class TTB : public ScalarVectorFunction
    {
    public:
        TTB();

        double scalarEval(std::vector <double const *> const &args,
                          std::vector <unsigned int> const &lengths) const;

        bool checkParameterLength(std::vector<unsigned int> const &lengths) const;

        bool isDiscreteValued(std::vector<bool> const &mask) const;
    };

}}

#endif /* TTB_FUNC_H_ */
