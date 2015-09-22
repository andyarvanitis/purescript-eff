///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Eff.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Eff FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef EffFFI_HH
#define EffFFI_HH

#include "PureScript/PureScript.hh"

namespace Control_Monad_Eff {
  using namespace PureScript;

  inline auto returnE(const any& a) -> any {
    return [=]() -> any {
      return a;
    };
  }

  inline auto bindE(const any& a) -> any {
    return [=](const any& f) -> any {
      return [=]() -> any {
        return f(a())();
      };
    };
  }

  inline auto runPure(const any& f) -> any {
    return f();
  }

  inline auto untilE(const any& f) -> any {
    return [=]() -> any {
      while (!(f()).cast<bool>());
      return Prelude::unit;
    };
  }

  inline auto whileE(const any& f) -> any {
    return [=](const any& a) -> any {
      return [=]() -> any {
        while (f().cast<bool>()) {
          a();
        }
        return Prelude::unit;
      };
    };
  }

  inline auto forE(const any& lo) -> any {
    return [=](const any& hi) -> any {
      return [=](const any& f) -> any {
        return [=]() -> any {
          for (auto i = lo.cast<double>(); i < hi.cast<double>(); i++) {
            f(i)();
          }
          return Prelude::unit;
        };
      };
    };
  }

  inline auto foreachE(const any& as_) -> any {
    return [=](const any& f) -> any {
      return [=]() -> any {
        const any::vector& as = as_;
        for (auto it = as.begin(); it != as.end(); ++it) {
          f(*it)();
        }
        return Prelude::unit;
      };
    };
  }
}


#endif // EffFFI_HH
