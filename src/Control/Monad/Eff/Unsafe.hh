///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unsafe.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Control.Monad.Eff.Unsafe FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Control_Monad_Eff_UnsafeFFI_HH
#define Control_Monad_Eff_UnsafeFFI_HH

#include "PureScript/PureScript.hh"

namespace Control_Monad_Eff_Unsafe {
  using namespace PureScript;

  template <typename A>
  inline auto unsafeInterleaveEff(const eff_fn<A>& f) -> eff_fn<A> {
    return f;
  }
}


#endif // Control_Monad_Eff_UnsafeFFI_HH
