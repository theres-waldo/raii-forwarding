# raii-forwarding
Demonstrates how to forward a RAII helper class across a wrapper that doesn't expose the definition of the wrapped class

In this example:

* `AsyncPanZoomController` is the wrapped class
* `APZSampler` is the wrapper class
* `AutoApplyTestAttributesInternal` is the RAII helper class
* `AutoApplyTestAttributes` is a wrapper for the RAII helper class
* `AsyncCompositionManager.cpp` is the client code that doesn't have access to the definition of `AsyncPanZoomController`

The key insights are:

* `AutoApplyTestAttributesInternal` cannot be nested inside `AsyncPanZoomController`, because nested classes cannot be forward-declared, and we need `APZSampler.h` to only forward-declare `AutoApplyTestAttributesInternal`.
* The destructor of `AutoApplyTestAttributes` needs to be defined out of line. This ensures that the destructor of `unique_ptr<AutoApplyTestAttributesInternal>`, which requires `AutoApplyTestAttributesInternal` to be complete, is instantiated only in `APZSampler.cpp` and not in `AsyncCompositionManager.cpp`. (This is also why we need the wrapper `AutoApplyTestAttributes` in the first place, and can't just have the client code use `unique_ptr<AutoApplyTestAttributesInternal>` directly; there would be no way to avoid the client code trying to instantiate the destructor of `unique_ptr<AutoApplyTestAttributesInternal>` in `AsyncCompositionManager.cpp`.)
