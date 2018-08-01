#ifndef ASYNCPANZOOMCONTROLLER_H_
#define ASYNCPANZOOMCONTROLLER_H_

class AsyncPanZoomController;

class AutoApplyTestAttributesInternal {
public:
    AutoApplyTestAttributesInternal(AsyncPanZoomController* aApzc);
    ~AutoApplyTestAttributesInternal();
private:
    AsyncPanZoomController* mApzc;
    int mPreviousScrollOffset;
};

class AsyncPanZoomController {
    friend class AutoApplyTestAttributesInternal;
private:
    int mScrollOffset;
    int mTestOffset;
};

#endif
