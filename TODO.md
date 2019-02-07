- Why does it start doing 350fps and then goes up to 700fps and then down again?
- Add mask to Surface and get rid of MaskedSurface
- Create ink that reads a random color from an image (regardless of its position)

- How to avoid drawing outside the visible area. Use a polygon and the isInsideOf() method (not sure it is called like this)

- ? Change Element cursor algorithm to tend towards the center so that the perimeter becomes less scattered
- Perimeter event args are currently static and probably should not be. Also the ofRemoveListener is missing
- Rings: Remove hard coded 200 in the array allocation
- Holes: Remove hard coded ANGLE_RESOLUTION 10
- Rings: Replace array with std::vector<*Ring> https://stackoverflow.com/questions/21387670/pointer-to-array-of-pointers-dynamic-allocation
- Holes: Replace array with std::vector<*Hole> https://stackoverflow.com/questions/21387670/pointer-to-array-of-pointers-dynamic-allocation

- ? Get rid of Surface FBO
