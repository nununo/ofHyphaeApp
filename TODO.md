- Perimeter event args are currently static and probably should not be. Also the ofRemoveListener is missing
- Hypha: each one must start from a different position in a central area of the Mycelium
- Hypha: implement forks
- Hypha: it must die

- Implement collision detection between families
- Consider 2-phased design: 1st hyphae, 2nd spores 

- Change Element cursor algorithm to tend towards the center so that the perimeter becomes less scattered
- Manage to overimpose Families keeping transparency and preserving colors correctly 

- Create the concept of a Family "strength"

- How to avoid drawing outside the visible area. Use a polygon and the isInsideOf() method (not sure it is called like this)
- Try Retina mode again with the hack suggested in the OF forum

- ? Get rid of Surface FBO
- ? Add mask to Surface and get rid of MaskedSurface
