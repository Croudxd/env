
# Environment simulator. 
- - - 

### 14/dec
- - - 
Alright this time we are trying something new.

So OOP has a weakness in this situation especially in cpp is that we cant store a species in a animal type (mammal, bird) inside an entity vector without losing data and its not very dynamic and will introduce redundent code.

So we can use ECS

We are gonna have components/the data be stored with just an id of the entity. this way we can be alot more dynamic

we can then loop over this data, find out the proximity of each entity, but by only using the component of position meaning we can do it for every single entity as we are not restricted via the type.
after we calculate we can then go to the monte carlo sitatuion.

Once we have the entity we want to calculate, the entities the main entity can see. We can then calculate a decision for the main entity.
We have to make this function very dynamic, but we pretty much HAVE to code every single decision, as thats the limitation of programming. we cant have the code
make up its own decision, (neither can ai which i thought about.)

Then it returns a decision and we can calculate what to do in terms of x and y.

and any other data that needs to get updated.

So steps.

1. Calculate ECS
2. Dynamicly loop over all entities.
3. Calculate monte carlo.

- - - 

Alright so we will have 2 Main loops:

Renderer Loop which will update the screen every frame, which will also call the engine loop.
The engine loop will host our models, and our math.
Every loop we calculate probability of each objects next decision etc, then we calculate the movement they will make.
Which we will then update via the renderObject inside each model. And then return to the renderer loop which
will update the screen.


Main 
Call renderer, make list of things we want in the simulator.
-------------------

Renderer
Call gflw and opengl for the display setup, draw inital values to opengl from the list of things from main and call the engine loop.
-------------------

engine loop
We are gonna call math on each object inside the object list from main.
predict the things the objects will do such as sleep or eat or hunt and move to where etc.
change the x and y values of each object every frame which then gets updated when we call back to the 
renderer.
-------------------


Okay one problem i am thinking of rn is if we have a rabbit, and nothing is in its perception window/area.
No Food
No mates
No predators,
No water

what does the rabbit do?

So we need to have the rabbit kind of learn/remember where things are. But when a rabbit or n object is born,
they know nothing, we can then update the rabbits memory.

So to make things less memory intensive. We can have an idle status.

we will have a hashmap or some data structure that stores memories such as "woodlands here: lots of food and safer." something like this right we can say give a score to each general nxn area so if a rabbit is in a area of maybe 1 it will try and move to a 10 area if it starts to idle.

But only when idling will we look inside the ds for the memories.


This means we need to give the objects memories.


# OLD 
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
