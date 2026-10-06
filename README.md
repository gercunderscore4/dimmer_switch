# Project Dimmer Switch

Gaslighting my friends with techonology and science for Halloween.

## Forest Eyes

Use a microcontroller, two LEDs and a coin cell battery to make glowing eyes in the forest.
Microncontroller chip soldered directly to the LEDS.
No resistors, the high internal resistance of the battery will limit the currect.
Microcontroller in low power mode.
Wake up for 3 ~ 10 seconds every 15 ~ 30 minutes.
PWM to turn on.
1/7 chance to add an animation to blink both eyes, blink right then left, left then right.
Amber LEDs.
One set of red.
Probably ATtiny84/85.

### TODO
- program T85/T84
- buy CR2032 batteries
- test circuit


## VHS

Before friends arrive.
Record scenes in the TV room from the perspective of the TV, wide angle.
Move furniture for more space.
Flip the footage (mirror).
Add low fidelity filter.
Add static before and after.
Load into a small computer (e.g. RPi).
Connect to the TV via USB.
Leave the computer on.
Have it load up a video.
Use HDMI CEC commands to turn on and switch source.
Pause any other media if possible.
Let it play for several seconds.
Switch back to previous source and resume playback (or power off)
Have it activate every few hours
Hide it inside a VHS or similar box if possible.

### TODO
- look for box with HDMI and power(something from pawn shop)
- test HDMI CEC codes using RPi


## Firewood

Try saturating firewood in the following water solutions:
- potassium chloride (purple)
- sodium chloride (orange)
- sugar (sparkles)
- epsom salts (white)
- borax

https://sciencenotes.org/how-to-make-colored-fire/

https://sciencenotes.org/how-to-make-colored-fire-pinecones/

Only use once food cooking is done.
Remove ashes after (salts remain, bad for food, mostly harmless to environment)

### TODO
- buy potassium chloride online
- buy borax
- collect firewood or pinecones


## Bird House

Build a directional speaker using an array of ultrasonic speakers.
Indoors it would bounce too many times, use outside.
Place it into a birdhouse-like enclosure with the front removed.
Cover the front with a thin mesh.
Paint it dark.
Place in forest, aimed at a common walking spot.
Have it play for 3 ~ 5 seconds of every 3 ~ 5 minutes.
Animal noises, chanting, loud ambience.

https://www.youtube.com/watch?v=9hD5FPVSsV0
based on "Audio Spotlight" originally from MIT
H-bridge amplifier
pre-amp: LM358 (had them) (has circuit)
audio driver: TC4426A
6 years old
Comments:
Someone used a L293DNE for the driver and TL082 for the pre-amp

https://www.youtube.com/watch?v=B8ss4KqcuXU
Great Scott's circuit

https://www.youtube.com/watch?v=Z8Ur3uuD610
spacing = (1/2 + N) * lambda
lambda = v / f = (343 m/s) / (40 kHz) = 8.56 mm

https://www.youtube.com/watch?v=aBdVfUnS-pM
555 envelope circuit

https://www.youtube.com/watch?v=8wJ5Eff7hx0
Freeze-framing at 5:13 shows a possibly hex grid, spaced out

https://www.explainthatstuff.com/directional-loudspeakers.html
parametric arrays with sonar
HyperSonic Sound
patent links
https://patents.google.com/patent/US20090116660
rectangular grid
https://patents.google.com/patent/US20140104988
shows a hex grid and might have good details
https://www.youtube.com/watch?v=HF9G9M0cR0E

Not as useful:
https://www.youtube.com/watch?v=0NwX8F1YZIc
https://www.youtube.com/watch?v=Be5woNXoiBs
https://www.youtube.com/watch?v=TQOabMOMGoE
https://www.youtube.com/watch?v=hmNzf9ztnAk

Bought 50 transducers.
Let's try a hexagonal lattice of 37.
Split the cable evenly to ensure that they all arrive exactly.
Or not, lambda = v / f, v = a*c, f = 40kHz, lambda is about 10km
So as long as my wiring isn't on the order of km, I'm good.
Let's use the 555 circuit, it's simple.
The sound will be tinny, but that's okay.
We'll save time and effort and it will still freak people out.

### TODO
- look into pre-amp
- look into audio amp
- set up 555 circuit


## Parabola

Build a parabolic reflector dish.
Make it look like a satellite dish.
Place it away from the directional speaker.
Aim it at where people walk past the line of the directional speaker.
If it picks up speech while the directional speaker is off, record 2s and send to directional speaker.
Play back on directional speaker with a roar at the end.

Build the parabola out to where the line meets the point.
Have a single arm reach diagonally forward and the straight back for the mic, like a TV satellite dish.
Make the dish look broken with (fake) exposed wires to explain why it's aimed at the ground
Sound wave sizes:
lambda = 343 / 20k = 17mm
lambda = 343 / 2k = 17cm
lambda = 343 / 200 = 1.7m
So let's go with about 30cm in diameter, 
catch the higher frequencies and still be reasonably sized.
Build a grid of cross sections.
Plug gaps with tape.
Or 3D print?
Heat worbla over it.
Add metal wire for re-inforcement.

### TODO
- draw parabola in CAD
- buy/find mic
- ESP8266 comms


## Polaroid

Buy a polaroid camera.
Take a few pictures.
Re-load the already exposed pictures back to the top of the roll.
For extra fun, load them into random positions in a dark room.

### TODO
- buy camera


## Box

Buy a food tin.
Line it with fabric.
Verify that it works as a Faraday cage.
Consider adding a lock.

### TODO
- buy tin


## Scene

Film and photograph a ritual.
Move furniture.
Make a summoning circle on the floor.
Try making one with red fabric and a tulle backing.
Candles burned down to different levels.
Dark robes and masks for anyone on screen.
Animal faces or skulls for the masks.
E.g. human skull, deer skull, bird face, wolf face

Videos:
- just the circle, blow our the candles with fans, reverse the footage
- one person with candles lit, turns to camera, grabs a candle, blows it out as video stops
- one person chanting, second person's face rapids enters frame from the side (twist if you can)
- two people chanting, knife present
- two chanting (one with bloody knife), one laying down in center
- no one present, bloody hand reaches in to extinguish a candle
- take a bow

Photos:
- the circle, no people
- extreme close-up of masked face (flash if possible)
- bloody knife in motion towards camera (need light)
- liquid latex wound and knife

Chants:
- lorem ipsum
- try reversing short phrases and saying them backwards (without reversing footage)
- dies irae
- erlkonig elf lines

### TODO
- write chants
- draw circle
- calculate floor space
- buy tulle

