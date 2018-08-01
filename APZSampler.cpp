#include "APZSampler.h"
#include "AsyncPanZoomController.h"

APZSampler::AutoApplyTestAttributes::AutoApplyTestAttributes(APZSampler* aSampler)
    : mImpl(std::make_unique<AutoApplyTestAttributesInternal>(aSampler->mApzc))
{
}

APZSampler::AutoApplyTestAttributes::~AutoApplyTestAttributes()
{
}