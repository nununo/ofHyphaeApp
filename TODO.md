-Convert all MyceliumSettings into ranges so that params can be calculated randomly between those ranges

- The Hypha deathBorder must be calculated based on its actual position and only on its initial direction (or we'll end up with a circle anyway)
- Save set of parameters to file
- Load set of parameters from file
- Review Hypha nextForkDistance
- Try to make Hyphae looks not depend on its growth speed
- Add circle mask
- Detect other hyphae?

- Make Conidium create more pixels per frame (since we now have 10fps)
- Use realistic Conidia colors
- Conidia: use 3D perlin noise to move between 3 colors (2 seems poor)
