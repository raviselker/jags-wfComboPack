#include <module/Module.h> // include JAGS module base class
#include <functions/TTB.h> // include Take The Best function class
#include <functions/TALLY.h> // include TALLY function class
#include <functions/TALLYk.h> // include TALLYk function class
#include <functions/WADD.h> // include WADD function class
#include <functions/randomWalk.h> // include general random walk class
#include <functions/generalAccumulator.h> // include general accumulator class
#include <functions/kReason.h> // include k-reason class


namespace jags {
namespace wfComboPack { // start defining the module namespace

  // Module class
  class WFCOMBOPACKModule : public Module {
    public:
      WFCOMBOPACKModule(); // constructor
      ~WFCOMBOPACKModule(); // destructor
  };

  // Constructor function
  WFCOMBOPACKModule::WFCOMBOPACKModule() : Module("wfComboPack") {
    insert(new TTB);
    insert(new TALLY);
    insert(new TALLYk);
    insert(new WADD);
    insert(new randomWalk);
    insert(new generalAccumulator);
    insert(new kReason);
  }

  // Destructor function
  WFCOMBOPACKModule::~WFCOMBOPACKModule() {
    std::vector<Distribution*> const &dvec = distributions();
    for (unsigned int i = 0; i < dvec.size(); ++i) {
      delete dvec[i]; // delete all instantiated distribution objects
    }

    std::vector<Function*> const &fvec = functions();
    for (unsigned int i = 0; i < fvec.size(); ++i) {
      delete fvec[i];
    }
  }

} // end namespace definition
}

jags::wfComboPack::WFCOMBOPACKModule _wfComboPack_module;
