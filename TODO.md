- Check why the Perimeter growth is gradually slowing down when DistortedCircle is active (now it's not)
- Fractor out Element's moving algorithm into Dance which will be the one receiving the Ink
- Solve weird circle bug that happen at the radius where 360 Elements are created
- Change Element cursor algorithm to tend towards the center so that the perimeter becomes less scattered
- Experiment with new Dances (filaments moviment away)
- Prevent Family from becoming so distorted. Ideally by reducing the perlin scale more or, if this doesn't do it, by controlling somehow how much distortion can happen
- Manage to overimpose Families keeping transparency and preserving colors correctly 

- Family decay (fade to black)
- Create the concept of a Family "strength"

- How to avoid drawing outside the visible area
- Try Retina mode again with the hack suggested in the OF forum

