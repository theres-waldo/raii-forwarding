#include "AsyncPanZoomController.h"

AutoApplyTestAttributesInternal::AutoApplyTestAttributesInternal(AsyncPanZoomController* aApzc)
    : mApzc(aApzc)
    , mPreviousScrollOffset(aApzc->mScrollOffset)
{
    mApzc->mScrollOffset += mApzc->mTestOffset;
}

AutoApplyTestAttributesInternal::~AutoApplyTestAttributesInternal()
{
    mApzc->mScrollOffset = mPreviousScrollOffset;
}
