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

  template <typename A>
  inline auto returnE(A a) -> eff_fn<A> {
    return [=]() {
      return a;
    };
  }

  template <typename A, typename B>
  inline auto bindE(eff_fn<A> a) -> fn<fn<A,eff_fn<B>>,eff_fn<B>> {
    return [=](fn<A,eff_fn<B>> f) {
      return [=]() {
        return f(a())();
      };
    };
  }

  template <typename A>
  inline auto runPure(eff_fn<A> f) -> A {
    return f();
  }

  template <typename A>
  inline auto untilE(eff_fn<bool> f) -> Prelude::Unit {
    return [=]() {
      while (!f());
      return Prelude::unit;
    };
  }

  template <typename A>
  inline auto whileE(eff_fn<bool> f) -> fn<eff_fn<A>,Prelude::Unit> {
    return [=](eff_fn<A> a) {
      return [=]() {
        while (f()) {
          a();
        }
        return Prelude::unit;
      };
    };
  }

  template <typename A>
  inline auto forE(double lo) {
    return [=](double hi) {
      return [=](fn<double,eff_fn<Prelude::Unit>> f) {
        return [=]() {
          for (auto i = lo; i < hi; i++) {
            f(i)();
          }
        };
      };
    };
  }

  template <typename A>
  inline auto foreachE(list<A> as) {
    return [=](fn<A,eff_fn<Prelude::Unit>> f) {
      return [=]() {
        for (auto it = as.begin(); it != as.end(); ++it) {
          f(as(*it))();
        }
      };
    };
  }
}


#endif // EffFFI_HH
