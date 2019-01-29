- Hypha: Use Perlin noise to change speed according to position
- Hyphae: Get rid of the bold cross that appears at the xy axis
- Perimeter event args are currently static and probably should not be. Also the ofRemoveListener is missing
- Hypha: trident at its tip?

- Implement collision detection between families

- Change Element cursor algorithm to tend towards the center so that the perimeter becomes less scattered

- Create the concept of a Family "strength"

- Rings: Remove hard coded 200 in the array allocation
- Holes: Remove hard coded ANGLE_RESOLUTION 10
- Mycelium.cpp remove hard codede HYPHAE_INK_TRANSPARENCY
- Rings: Replace array with std::vector<*Ring> https://stackoverflow.com/questions/21387670/pointer-to-array-of-pointers-dynamic-allocation
- Holes: Replace array with std::vector<*Hole> https://stackoverflow.com/questions/21387670/pointer-to-array-of-pointers-dynamic-allocation

- How to avoid drawing outside the visible area. Use a polygon and the isInsideOf() method (not sure it is called like this)
- Try Retina mode again with the hack suggested in the OF forum

- ? Get rid of Surface FBO
- ? Add mask to Surface and get rid of MaskedSurface
