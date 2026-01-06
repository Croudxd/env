#pragma once
#include "ecs/Entity_data.h"

/*
 *
 * We can change where this function / possibly class sits, but for now just gonna contain in this class.
 *
 * This function should take an entity N and its data, formulate an assesment and risk evaluation of each decision
 * N entity could make.
 * Okay so first things first, we need a formula which we can use to calculate our decisions.    
 *
 * we can use something like D (descision) = size * aggression * typeofeater * ... 
 * then maybe divided by n elements of the formula.
 * realistically we either want a number between 0 and 1 so id have to figure out that algorithm later
 * Problem with all of this tho is that when you see or another animal sees another animal. We don't know exactly,
 * The aggression level, the size, the type of eater etc. So we will have to have form of perception layer that the entitys
 * have so we can get a rough guide of the entity rather than using the direct data. Which i think is the harder part.
 * i think that a few of the n inputs, like size, we take the size of entity b and apply some noise to the size, then we can possibly
 * do the same for aggression etc.
 * 
 * Okay so below here i am going to add all of the inputs we will use to calculate the decision/Risk of each animal within the perception of entity N:
 *
 * Size of animal (kg / float)
 * Aggression (float 0.0 to 1.0)
 * I think when an animal gets low hp we can add a map which shows injuries, If something is visablyInjured, we then can use that in the algorithm.
 * I will use a Exponential decay function on the sum of all inputs. This way we can normalise the inputs.
 *
 * Then we will also need to have a noise function on each of the inputs. We can do this via gaussian bell curve, so we can have a more natural way to 
 * calculate the noise.
 *
 */

