test : AsyncPanZoomController.cpp APZSampler.cpp AsyncCompositionManager.cpp
	g++ -o $@ $^ 