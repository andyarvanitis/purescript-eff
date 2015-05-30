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

#include "Purescript/Purescript.hh"

namespace Control_Monad_Eff {
  using namespace PureScript;

  template <typename A, typename B>
  inline auto bindE(eff_fn<A> a) -> fn<fn<A,eff_fn<B>>,eff_fn<B>> {
    return [=](fn<A,eff_fn<B>> f) {
      return [=]() {
        return f(a())();
      };
    };
  }

  template <typename A>
  inline auto returnE(A a) -> eff_fn<A> {
    return [=]() {
      return a;
    };
  }
}


#endif // EffFFI_HH
