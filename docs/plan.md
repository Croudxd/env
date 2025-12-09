
Environment simulator. 

Several Objects:
Plants - trees, grass, flowers
Insects - ants, worms, spiders, bees 
Mammals - rabbits, pigs, sheep, foxes, wolfs, bears 
Birds - pigeons, raven, hawk

Then different types which inherit from above. Or we dont need to do that ig

Each polymorphism of the objects above will have variables such as:

Type of eater (carnivore, herbivore, omnivore)
Max speed
Energy
Rate of growth
age limit (rand number between x-y)
(maybe size)
perception in day
perception at night
hour of sleep needed
sleeps during night or day
endurance
sprinting
walking

Each object needs to do a couple of things:

Find food,
Sleep,
Reproduce,
 
We can make this more advanced later.

We can then run these objects through an algorithm to simulate an enviroment, then later display with diretx.

In terms of Food:

herbivores: 

Will have to find certain species of plants or just eat grass. will have groups of the plants.

carnivores:

Will chase and try eat anything, can hunt and track down other animals. We can leave footprints which all animals can see and so can be followed. Animals will have sprint and walk features rather than full speed 24.7 with endurance

Plants:

Photosynthsis levels, crowded area = less sun. Being eaten buy bugs and herbivores. 


So how are we going to make them actually move and what not. So we first need to set up an enviroment.
once we have that we can use pixels or something to calculate the movement of the objects.
This way we can display footprints etc.

We will start with just 1 thing. So we will add a white block, that moves to the left and stops at the edge.

Then we can add full 4d movement, then we can randomise it.

We can then create certain areas in the enviroment which will have lots of food, places good for sleeping, good for drinking, etc and use some form of math so the animals will choose what they need/want.

I think the most key algorithm here is going to be a monte carlo..

Graphics:

We have a main renderer loop.
We have RenderObject class takes the VBO, VAO and vectrices with some other functions.
We have shaders.h to just keep shaders config easily.
glad.c needed boilerplate.
and main.cpp calling everything/defining vectors.
just need vertices update function in renderObject.




