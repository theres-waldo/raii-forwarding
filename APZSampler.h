#ifndef APZSAMPLER_H_
#define APZSAMPLER_H_

#include <memory>  // for unique_ptr

class AsyncPanZoomController;
class AutoApplyTestAttributesInternal;

class APZSampler {
public:
    class AutoApplyTestAttributes {
    public:
	AutoApplyTestAttributes(APZSampler* aSampler);
	~AutoApplyTestAttributes();
    private:
	std::unique_ptr<AutoApplyTestAttributesInternal> mImpl;
    };
private:
    AsyncPanZoomController* mApzc;
};

#endif
